## OS: Ch3 Process Concept:

### Outline
* Process Concept
* Process Scheduling
* Operations on Processes
* Interprocess Commnuication

### Process Concept
定義: 一個作業系統同時執行不同的程式(Programs) (e.g : web , text editor)
* Program (程式) : passive entity(被動的) : binary stored in disk
* Process        : activity entity(主動的): a program execute **in memory**

#### A process includes:
* Code segment 程式碼(text section)
* Data section : 全域變數global variables
* Stack : temporary local variables & functions
* Heap  : dynamic allocated variables or classes
* current activity(**program counter**(程式計數器), **register countents**(暫存器狀態))
* A set of associated resources (e.g open file handlers)

#### Process in Memory

![image](https://hackmd.io/_uploads/B16ZGe6Ugg.png)

#### Threads
* A.k.a lightweight process:
    * basic unit of CPU utilization(CPU執行時的單位)
    * All threads beloning to the same process share(當同一個prcoess下，其code section , data section , OS resuorces是共用的). **e.g: Open files and signals**
    * each thread has is own
        * thread ID
        * Program counter
        * register set
        * stack

##### Why need Thread?
目的:為了讓一個 process 內部可以並行地執行多個任務！
* 在多核心系統上，一個程式可以同時執行多個 thread（parallelism）
* 提升反應效率，如 GUI thread 與 background computation thread
* 可透過 global variables 等共用資料溝通（同個 address space）

#### Process State
在管理thread的方式或管理prcoess的方法類似。**在Linux下的file systems**，對OS而已一個process就是一個thread.

**Stetes**:
* **New**: the process is being created(包含把program allocate到memory內，把這五個states initialize)
* **Ready**: process要去競爭的資源就是CPU的core，allocate完後存在memory等著使用CPU的core之前，被放在一個Ready的狀態(管理方式(queue))，等著OS去排程進入到CPU
* **Running**: instructions are being executed by CPU
* **Waiting**: process在做I/O時，狀態即會在waiting，此處同Ready也是用queue管理
* **Terminated**: 釋放資源


![image](https://hackmd.io/_uploads/BJLDFlp8ge.png)

#### Process Control Block (PCB)
OS要如何實現Process State的邏輯? 
當process被create時，OS會去allocate屬於此process 的table(Process Control block)，而 OS 會維護一個 queue 或 list 來串接這些 PCB。OS在排程或狀態管理時，會將此 PCB 放入 ready queue、wait queue 等，但PCB 本身仍是儲存在 kernel-managed memory space

目的:
* 保存 process 狀態與上下文 **（context）**
* 讓 OS 能「中斷/恢復」process 執行 **(context switch)**
* 支持多工排程與記憶體保護

![image](https://hackmd.io/_uploads/rkukjlTLee.png)

而此PCB含有:
* pointer (在queue裡即可知道下一個process是誰)
* process state
* Program counter
* CPU register (priority)
* CPU scheduling info.(base/limit register)
* Memory-management info.
* I/O State info.
* Accounting info.

#### Context Switch
Define: 原來在CPU執行的Process Switch至另一個Process (在sharing CPU時)

![image](https://hackmd.io/_uploads/S1jJAgT8ex.png)

* Context-switch time is purely **overhead** 原因是任何process其實都在idle的狀態

* Switch time(about 1~1000ms) depends on 
    * memory Speed
    * number of registers 
    * **existence of special instuctions**
    * **Hardware support** (多組暫存器集（register sets）能讓切換更快，只需指向不同 register set 而非重新載入)
        * multiple sets of registers

#### OS中的Process Scheduling
* Mulitporgramming: ：最大化 CPU 使用率，減少 idle time（空閒時間），回顧chap0，我們避免CPU不斷去監控**device control(polling)**，而是靠OS **採用裝置觸發中斷（Interrupt）**，被動通知 CPU，以避免 CPU 一直詢問 device status。
* Time sharing: 頻繁的做context switch，才會有interact
* Proceese will have to wait until the CPU is free & **can be re-scheduled**

#### Process Scheduling Queue:有scheduling的地方就會有Queue

* Job queue(New State)      
* Ready queue(Ready State) 
* Device queue(Wait State) 

![image](https://hackmd.io/_uploads/BkyC7-6Uex.png)

#### Schedulers


![image](https://hackmd.io/_uploads/HkUtOna8gl.png)

* **Short-term Schedulers** (CPU scheduler):selects which process should be executed & allocated CPU(**Ready -> Run**) 頻繁高(為了達到time-sharing的關係) 

    * **Execute quite frequently** (e.g 100ms)
    * Must be efficient: schduling Algorithm 執行的時間要非常短。

    ![image](https://hackmd.io/_uploads/rkWea36Lel.png)


* **Long-term Schedulers** : selects which processes should be **loaded into memory** and brought into the ready queue **(New state -> Ready state)** 通常發生在有新的程式產生的時候

    
    * **負責控制Degree of multiprogramming** (Degree 太低: CPU idle ，Degree 太高: Trashing的狀況)
    * Execute less frequently
    * Select a good mix of CPU-bound & I/O-bound processes to increase system overall performance
    * Unix/NT: **no long-term scheduler**(因memory在現代已經夠大了)
    



* **Medium-term Scheduler** : select which processes should be **swapped in/out memory** **(Ready state -> Wait state)**
    * swap out : removing process from memory to reduce the degree of multiprogramming
    * swap in : reintroducing swap-out process intro memory


    ![image](https://hackmd.io/_uploads/SkMnbapIee.png)


##### 總結: 在Ready queue中的process，CPU I/O bound & Degree of multiprogramming 是重要的兩個指標

*  short term Schedulter: 
    * CPU efficient 
    * Process : Ready -> Run
*  long term Scheduler: 
    * control degree of Multiprogramming
    * Process : New -> Ready
*  Medium term Scheduler
    *  control swap memory
    *  Process: Ready -> Wait


### Tree of Process:

Each of Process is identified by a unique processor identifier **(PID)**
  ![image](https://hackmd.io/_uploads/rkM38a68xl.png)
### Process Creation
在現代作業系統中，Process(Parent)跟Child的差異在哪?因Parent & Child之間有關聯性。

關聯性的定義
1.  **Resource sharing** -- 由OS development 定義
    *  **(share all)** Parent & child process share all resources
    *  **(subset)** Child Process shares **subset** of parents  resources, **e.g global variable看得到，但動態variable 看不到**
    * **(no)** Parent and child share no resources

2.  **Two possibilities of execution**(執行順序)
    * Parent & children execute concurrently **(由OS的schedular決定)**
    * Parent waits until children terminate **(children有較高的piority)** .此說明為什麼process做了一個fork後，會進到waiting queue裡。

3. **Two possbilites of address space**
    * **(複製)** Child duplicate of parent.所有狀態完全一樣，但memory位置不同
    * Child has a program loaded into it, commnuication via message passing
    
### (重要) Linux/Uinx process Creation
Linux定義的process creation

* **Fork** System call: **(Linux去create 一個child出來)**
    * **Create a new(child) process**
    * **memory使用Duplicate**
    * **execution使用concurrently**，由OS決定，不須放入waiting state
    * Child return value of fork is 0 
    * Preturn return value of fork 就是child的PID)

* **execlp** System call: **因Linux下的child & parent是 duplicate(content一樣)，目的是inital這個child的程式，使他能執行完全不一樣的程式**
    * Load a **new binary file** into memory - **destroying the old code**
        * replace code segmenet
        * initial Heap & stack
        * reset program counter

* **wait** system call : 因在linux下是concurrently(執行順序由OS決定)，因此為了控制我們須使用此system call來指定現在這隻程式等待某個child program complete，強制將parent 放在queue(waiting)

    * The parent waits for one of its child processes to complete


#### Memory Space of fork()

* Old implementation: A's child is an exact copy of parent (完全複製)
    * drawback : 浪費memory空間
* **Current implementation** : **Copy on write** 只copy一定會被改掉的部分，e.g program counter or initialization ，若不影響執行的，只用pointer指向parents的值

![image](https://hackmd.io/_uploads/r1_Z-06Ixe.png)

#### Example
想像有兩個fork()執行(concurrent)
```C
#include <stdio.h>
void main(){

    int A;
    /* fork another process */
    A = fork()
    
    if (A == 0) { /*child process */
        printf("This is from child process\n");
        execlp("/bin/ls","ls" , NULL);
    } else{ /* parent process */
        printf("This is from parent process\n");
        int pid = wait(&status);
        printf("Child %d completes" , pid);
    }
    printf("process end");
}

```

![image](https://hackmd.io/_uploads/SybW4RTIxl.png)



### Process Termination

Terminate when the last statement is executed or exit() is called
    All resources of the process , including & physical & virtual memory , open files , I/O buffers, are **deallocated by the OS**
    
* Parent may terminate execution of children process by specifiying its PID(abort)

* Cascading termination


### Interprocess Commnuciation (IPC)
**define** : a set of methods for the exchange of data among multiple threads in one or more processes **(process 與 process 之間的溝通)**

**Purpose**:
* information sharing
* computation speedup
* convenience (e.g web server)
* modularity (如microkernal: 把所有的component放在 user space， 透過IPC來溝通。)

### Communication Methods

* **Shared Memory**:
兩個process用pointer去access，同時做read，write都不會違反。
    * **(缺點**) Require more careful user synchronization 
    * implemented by memory access , faster speed
    * Use memory address to access data

* **Message passing**:
用memory copy(send()，recv()...的function call)，如email，socket programming
    * No conflict: more efficient for small data
    * Use send/recv message
    * Implemented by system call，slower speed (缺點)
    
<註:> Shared Memory 下章節在討論    

### Communication Methods: Message passing

* **Sockets**
    * A network connection identified by **IP & port**
    * Exchange unstructed **stream of bytes** (Socket Programming) : e.g. HTTP server , chat app
    * 使用場景：低層網路溝通、如 send() / recv()、Socket Programming。
    
* **Remote Procedure Calls (RPC):**
    * Cause a procedure to execute in another address space (RPC API)
    * Paramters and return values are passed by message

**Socket**
![image](https://hackmd.io/_uploads/Hk0g5-AIle.png)
**RPC**
![image](https://hackmd.io/_uploads/SkSbq-AIxx.png)

### Interprocess Commnuication

* Shared Memory
* Message passing
* Socket
* Remote Procedure Calls


### **Shared Memory**
主要用Thead-programming的方式

* Processes are responsible for
    * Establishing a region of **shared memory** (OS)
        * 基本上，要溝通的process要自己執行system call()去創造此region出來
        * 參與的processes須同意移除此 memroy constraint 
    * Determining the form of the data and the localtion(User)
    * Ensuring data are not written simultaneously by processes(User)) (通常會產生 synchronization 的問題)

### Consumer & Producer Problem
舉例: 如何address synchronization 的樣子

一隻程式負責Producer (產生) & 另一隻負責Consumer  (消耗)

假設以下:
Buffer as circular array with siz B

Producer不斷寫入
Consumer不斷消耗

next free : in
first available : out
empty **in = out** (對 consumer 需要需知道何時空，等producer填入)
full: (in + 1) % B = out (對producer而言需知道何時滿)
![image](https://hackmd.io/_uploads/H16bJ8gvgx.png)


### Message-Passing System
當Scale(溝通人較多時)，較常使用Message-Passing.

因為:
* Mechanism for processes to **commnuicate** & **sychronize** their actions

由OS提供此兩個system call
* IPC facility provides two operations:
    * Send(message) - message size fixed or variable
    * Receive(message) 

* Message system - processes commnuicate without resoring to **shared variables**

* To communicate , processes need to
    * 建立 commnuciation link (ex: http)
    * Exchange a message via **send/receive**

### Message-Passing System : implementation of commnucication link

* physical( e.g , shared memroy , HW bus or network)

* logical
    * (重要)**Direct or indirect commnuication** (有無方向性: 單or雙向)
    * Symmetric or asymmetric commnuication
    * (重要)**Blocking or non-blocking**
        * Blocking: function call 的behavior (完成行為(e.g收到message後在做下一個動作)
    * Automaic or explicit buffering
    * Send by copy or send by reference
    * Fixed-sized or variable-sized messages
     
### Message-Passing System : Direct Message
e.g: 傳統電話

* Processes must **name each other explicitly**(指定對方是誰):
    * Send(P, message) - send a message to proc P
    * Receive(Q, message) - receive a message from process Q

* Properties of **commnuication link** 
    * Links are **established automatically** **(因指定後，已知雙方是誰)**
    * one-to-one relationship between links and processes
    * The link may be unidirectional , but is usually bi-directional

* Drawback: **limited modularity** 

### Message-Passing System : inDirect Message
e.g email

* Messages are directed and received from mailbox ( also referred to as ports)
    * Each mailbox has a unique ID
    * Process can commnunicate if they share a mailbox
    * Send (A , message) - send ma message to mailbox A
    * Receive(A , message) - receive a message from mailbox A


* Properties of **commnuciation link**
    * Link established only if processes share a common mailbox
    * **Many-to-Many** relationship between linkx an processes
    * Link may be unidirectional or bi-directional 
    * Mailbox can be owned either by OS or processes ( 若是OS提供的Process，使用kernel memory )
    
### Message-Passing System : blocking/non-blocking 差異

* Send:
    * blocking send : sender is  blocked until the message is receier or by the mail
    * nonblocking send: sender sends the message and resumes operation

* Receive:
    * blocking receive: receivers is blocked until the message is available
    * Nonblocking receive: receiver receives a valid message or a null (此function call return 之後，可能是原來的值: 通常會視Return一個token

![image](https://hackmd.io/_uploads/HJsrVwePel.png)


### Message-Passing System : RPC

Remote procedure call (RPC) abstracts procedure calls between processes on netwroked systems


![image](https://hackmd.io/_uploads/S1J3SPlDxg.png)

先跳過 ，之後補看
