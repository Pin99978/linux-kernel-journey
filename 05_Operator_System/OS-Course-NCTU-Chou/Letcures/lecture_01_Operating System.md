# OS: Ch1 Operating System

## Outline

* What is an Operating System?
* Computer-System Organization
* HW Protection

### Computer System

* Four componets 
    * User
    * Application
    * Operating System : 控制(controls) & 協調(coordinate) - 
        * 控制: Driver
        * 協調: 各個process如何協調資源分配
          eg. **time-sharing**
    * Hardware ( CPU , memory , I/O devices) 資源分配 

<div align="center">
  <img src="https://hackmd.io/_uploads/By9BK0K8ex.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P1. ComputerSystem: 周志遠 OS: Ch1](https://www.youtube.com/watch?v=air07XWB27s&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=8)

* Permanent Software 
    * 將下方硬體 **"抽象化"** 後變成一堆的API，讓使用者去執行

ex: 程式A & B 執行instruction , 經由OS決定現在要把time-slot給A or B (coordinate)

<div align="center">
  <img src="https://hackmd.io/_uploads/HJvghRt8gg.png" alt="System Architecture Summary" width="400"/>
</div>
[ref: P2. Multi-tasking: 周志遠 OS: Ch1]

我們以一執行一個程式來說明OS扮演的角色:

1. Hardware 上要執行I/O需要有各個devices driver(part of OS)
2. OS的目的: 執行/提供一堆API(system library / system call())
    *  e.g #include <stdio.h>
3. Complier: 從programming 轉成machine language 
    *  e.g  .o file
4. Linker : 將.o file link一起(去使用別人implmenet好的檔案)，一定會包含system library
5. 成為完整的執行檔 

<div align="center">
  <img src="https://hackmd.io/_uploads/H180p0F8lx.png" alt="System Architecture Summary" width="400"/>
</div>
[ref: P3. General-pu周志遠 OS: Ch1]

### Definition 

* Resoure aoolcator : 管理與分配資源確保效率
* Control Program: 控制執行&操作硬體I/O來預防不適當操作
* **Kernel**: OS的別名: 一個持續執行的程式

### Goals of an OS(kernel)
**開發Kernel or 選擇Kernel的時候**?

* Convenience(方便性) 
* Efficiency(效率)

此兩項通常衝突trade-off (例如圖形化介面會占資源)

### Why OS is so important? 
1. System API 是 **唯一(only)** 一個interface 介於User端與hardware端 : 
2. OS code cannot allow any **bug!!**
    **任何break causes reboot**
3. The owner of OS technology controls the software & hardware industry

4. Operating system & computer architecture influence each other


### Moderen OS
* x86 platform
    * Linux (Centos, Redhat,Ubuntu...)
    * Windows
* PowerPC - Mac OS
* Smartphone - (IOS, Android)
* Embedded OS - (Andriod , WebOS, Raspberry Pi, Xbox...)


---

## Computer- System Organization

Definition : 一個或更多個CPUs, device controllers 透過**common bus**連接來shared memory 

Goal: 同步(concurrent) 執行CPUs & devices competing for memory cycles


<div align="center">
  <img src="https://hackmd.io/_uploads/BJUwUJ9Ugx.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P4. General-pu 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=wUAsgQmMa7I&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=9)

### 基本OS運作

以CPU對一個devices做讀寫(例如Disk)

1. Device Controller 上都會有Buffer，目的是因為單純I/O device copy資料到memroy很慢(CPU很快)，因此需要buffer來避免CPU idle
2. 為了要透過buffer做讀寫，會有Status register & Data register來控制controller來說明目前controller狀態(busy or idle)
3. devices寫資料到buffer只需Device controller執行即可(device controller 本身有簡單的CPU)
4. 因為memory是CPU在控制的(指令)來完成buffer -> memory



<div align="center">
  <img src="https://hackmd.io/_uploads/HJTiPk5Ugg.png" alt="System Architecture Summary" width="400"/>
</div>
[ref: P4. 基本OS運作 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=wUAsgQmMa7I&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=9)


我們以一個簡單的device I/O讀取來看，參考下方程式。
```C
#define OUT_CHAR 0x1000    // device data register
#define OUT_STATUS 0x1001  // device status register

current_char = mystring;
while (*current_char != '\0' ){
    poke(OUT_CHAR, *current_char);
    while (peek(OUT_STATUS) != 0); // busy wating
    current_char++;
}
```
* poke() 是一個例子，將char寫到device controller上的buffer搬出
* 因此需要peek看buffer是否可寫入(?)


`while (peek(OUT_STATUS) != 0);` 此段CPU持續主動詢問裝置狀態，但由於I/O from device相對慢，造成CPU浪費資源等待(持續在peek())，此違背了CPU跟I/O可以overlay，這種模式稱為 **Polling(主動等待**，以現實面通常只在硬體受限上使用。
**為了改善此問題，interrupt的概念可以解決此問題。**

### Interrupt I/O
* **被動觸發** (可以讓CPU在User Program /OS program)依需求作切換
* 可以改變CPU執行的flow

<div align="center">
  <img src="https://hackmd.io/_uploads/ry8Rlx9Uxe.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P4. interrupt I/O Timeline 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=NKCt3nz1uAY&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=10)

<div align="center">
  <img src="https://hackmd.io/_uploads/S1VYml5Igl.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P4. interrupt I/O 流程圖 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=NKCt3nz1uAY&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=10)

* 有多種方式可以觸發Interrupt
    * Hardware(**Signal**) : 任何時間觸發中斷 *訊號* 給CPU
    * Software(**trap**): 
        * Error觸發(ex: segmentation fault)，為何不會整個crash? 當detect到類似訊息時OS(程式)會丟一個interrupt，開始error handling，例如將程式執行到printout的error message狀態後。
        * System call: 全部透過interrupt，等OS去接。(沒有例外，保護系統)


### Hardware interrupt:

1. user program: 硬體觸發interrupt signal去到OS的resident monitor(memory)
    * 中斷訊號是透過 Interrupt Controller（如 PIC, APIC） 傳遞給 CPU。
    * CPU 每執行一條指令時，都會檢查中斷線（Interrupt Line）是否被拉高（asserted）。
    * 當中斷發生，CPU 會暫停目前指令，進入「中斷處理流程」。



2. 確認interrupt vetcor ( array of function pointer )。
    * 每種裝置或事件會分配一個 Interrupt Number，例如：Keyboard → interrupt 0x09
Timer → interrupt 0x08 因每個function call 大小不同(占用記憶體不同)。OS會在啟動階段設定好 vector table。
4. signal中會有定義好的number，會對應到vector中哪些欄位的function call來處理 (Service routine for device)
5. return to user



<div align="center">
  <img src="https://hackmd.io/_uploads/SkIIue58xe.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P4.Hardware Interrupt示意圖 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=NKCt3nz1uAY&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=10)


### Software interrupt:



<div align="center">
  <img src="https://hackmd.io/_uploads/HylTjgqLxe.png" alt="System Architecture Summary" width="400"/>
</div>

[ref: P4.Software Interrupt示意圖 周志遠OS 4A: Ch1](https://www.youtube.com/watch?v=NKCt3nz1uAY&list=PLS0SUwlYe8cxj8FCPRoPHAehIiN9Vo6VZ&index=10)

1. 程式主動要求 OS interrupt
2. software使用`switch case`根據number比對function call來routine 
3. return to user


:::info
補充
不論是 switch 或 vector table，都是透過「編號 → 函式」的方式來處理事件：

(software) switch 是由軟體邏輯進行比對與跳轉。

(Hardware) vector table 是由硬體（CPU）根據 interrupt number 自動跳到記憶體中指定位址。
:::

### Interrupt的問題
* 當兩(多)個程式一直快速互相打斷時，產生嚴重的sychronization問題，為了解決此問題會浪費大量時間
* 因此 大部分的OS，為了保證service routine很快通常只用asyn code寫。所以在注重效能的OS(Linux..) 。incoming interrupts是被disalbed掉的當其他的interrupt正在執行



### Storage-Device Hierarchy
