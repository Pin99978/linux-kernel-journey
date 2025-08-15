#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t wrt, mutex;
int readcount = 0;

void* reader(void* arg) {
    while (1) {                            // Reader 會不斷嘗試讀（模擬連續需求）
        sem_wait(&mutex);                 // 鎖定 readcount 互斥存取
        readcount++;                      // Reader 數量加一
        if (readcount == 1)               // 第一個 Reader 抵達 → 阻擋 Writer
            sem_wait(&wrt);              // 拿走 Writer 的 lock，阻止它進入 CS
        sem_post(&mutex);                 // 解鎖 readcount 存取

        printf("Reader %ld is reading\n", (long)arg);
        sleep(1);                         // 模擬讀取時間（可調短來加快衝突）

        sem_wait(&mutex);                 // 鎖定 readcount
        readcount--;                      // Reader 離開 → 數量減一
        if (readcount == 0)               // 最後一個 Reader 離開 → 釋放 Writer 鎖
            sem_post(&wrt);              // Writer 可以進入 critical section
        sem_post(&mutex);                 // 解鎖 readcount 存取
    }
}

void* writer(void* arg) {
    while (1) {                            // Writer 不斷嘗試寫（模擬寫需求）
        sem_wait(&wrt);                   // 嘗試取得 Writer 專屬鎖，如果有 Reader → 卡住
        printf("Writer %ld is writing\n", (long)arg);
        sleep(2);                         // 模擬寫入時間（可以故意設長讓餓死更明顯）
        sem_post(&wrt);                   // 寫完釋放鎖 → 給 Reader
    }
}

int main() {
    pthread_t r1, r2, r3, w1;             // 建立三個 Reader thread、一個 Writer thread

    sem_init(&wrt, 0, 1);                 // 初始化 wrt 為 binary semaphore（值 = 1）
    sem_init(&mutex, 0, 1);               // 初始化 mutex 為 binary semaphore（值 = 1）

    pthread_create(&r1, NULL, reader, (void*)1);
    pthread_create(&r2, NULL, reader, (void*)2);
    pthread_create(&r3, NULL, reader, (void*)3);
    pthread_create(&w1, NULL, writer, (void*)1);    // Writer 只有一個

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(w1, NULL);               // 所有 thread join，防止 main 結束
    return 0;
}