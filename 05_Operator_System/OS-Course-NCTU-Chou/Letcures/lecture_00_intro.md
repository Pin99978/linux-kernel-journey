# OS: Historical Prospective

## Mainframe Systems Overview
Mainframe systems evolved through several stages:
- **Batch Processing**
- **Multiprogramming**
- **Time-Sharing**

These systems were crucial for:
- Handling **bulk data processing**
- Supporting **critical applications** (e.g., servers) with high **reliability** and **security**

---

## Mainframe: Batch Systems
- Users submit jobs (program, data, control card)
- Job is loaded into memory and executed by the CPU
- Input handled → Output printed

### 缺點
1. **Single-job execution:** One job runs at a time  
2. **No user interaction** during job execution  
3. **CPU often idle** due to slow I/O devices (e.g., card readers, printers, tapes)

### 如何改善?

## Shift to Multiprogramming
> **Goal:** Maximize utilization of CPU and I/O devices

### How?
By **overlapping I/O and computation** using **Spooling**  
(*Simultaneous Peripheral Operation On-Line*)

- I/O operations occur **without continuous CPU involvement**  
  **e.g.: 搬移 1GB 檔案從磁碟到記憶體，資料傳輸交由硬體（如 DMA）處理，CPU 可同時執行其他任務**
- CPU is only notified **once I/O completes**

![Spooling Illustration](https://hackmd.io/_uploads/BJlYVFvIel.png)  
[Spooling Video - 周志遠 OS Chapter 0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

---

##  Mainframe: Multiprogramming System

### 前因：Batch 系統的限制
- 同一時間只執行一個作業（job）  
- 作業彼此之間沒有互動或並行  
- 遇到 I/O 等待時，CPU 無事可做 → 資源利用率低  
→ 導致整體效能不彰，尤其在資料處理量大或等待時間長時更加明顯

---

### 為了解決以上問題，系統引入「Multiprogramming」機制

- Multiple jobs are kept in memory simultaneously  
- CPU **multiplexes** between jobs，根據狀態切換執行不同作業

> 目的：多個 jobs 同時常駐於記憶體，讓 CPU 可以輪流執行它們  
> 避免 CPU 因等待 I/O 而閒置，提高整體運算效率

![Multiprogramming Illustration](https://hackmd.io/_uploads/rJyd_KwUxg.png)  
[Multi-Programming System - 周志遠 OS Chapter 0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

---

### 衍生任務
- **Job Scheduling**
- **CPU Scheduling**

### OS Responsibilities 由 Multiprogramming 引發的新挑戰
- **Memory Management**: 將記憶體分配給多個作業  
- **CPU Scheduling**: 從 ready jobs 中挑選一個交給 CPU 執行  
- **I/O Management**: 提供 I/O 程式，並負責裝置分配  

> ✅ 作業系統變得至關重要，需掌控所有資源分配與作業狀態


---

##  Mainframe: Time-sharing System (Multi-tasking System)

### 前因：雖具 Multi-tasking 效果，但單一程序仍非互動式 (non-interactive)

### 目的：提高互動性與回應時間

* An interactive system provides direct communication between users and the system (用「時間切割」概念實現)  
    * CPU switches jobs frequently → 使用者可即時互動  
    * 使用者能立刻看到結果（response time < 1s）  
    * 常見互動介面：**鍵盤 / 螢幕**

* 多位 **使用者可同時共享電腦**

* CPU 會在下列情況切換作業：
    - Job 完成
    - 等待 I/O
    - 執行一小段時間（time slice 到期）
---

### 🧩 OS Responsibilities 因 Time-sharing 引發的新挑戰

- **Virtual Memory**: 將 jobs 換入/換出記憶體，以維持合理回應時間  
  — 需同時載入更多程式，使得 CPU 空轉時間越來越少  
- **File System and Disk Management**: 管理使用者資料檔案與儲存空間  
- **Process Synchronization and Deadlock**:  
  支援多程式並行執行，處理互相存取同一資源（e.g., memory counter）

---
Mainframe 章節整理
![Time-sharing Illustration](https://hackmd.io/_uploads/Ska5-9DLgx.png)  
[P2. Summary of MainFrame : 周志遠 OS Ch0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

---

## 🧬 Computer System Architecture 系統架構概論

---

### 🖥️ Desktop Systems: Personal Computer（桌面系統）
- Personal computers: dedicated to a single user  
  eg. Linux, Windows, IOS...
- Owns GUI（圖形介面）
- I/O Devices: Keyboards, mice, screens（鍵盤、滑鼠、螢幕等）
- Lack of file and OS protection from users: Warm, Virus（缺乏檔案與作業系統防護，容易遭受病毒）

---

### 🤝 Parallel Systems（並行系統）

**Multiprocessor** or **tightly coupled system**  
- more than one CPU/core in close communication  
- uses shared memory to communicate  
- Purposes: Throughput, Economical, Reliability（目的：處理量、成本效益、可靠性）

#### Parallel Systems 可以再細分成:

- **Symmetric multiprocessor system (SMP)**  
    - Each processor runs the same OS  
    - 各個 processor 扮演的角色完全相同，沒有任何人是 master or slave  
    - 目前 CPU 大都是這種形式，每個 core 都可計算，不會某一個負責管理 → 提高使用率  
    - 缺點: synchronize processor 時需要做 locking → scale core 相對低  
    - 最常見的多處理器架構

- **Asymmetric multiprocessor system**  
    - Each processor is assigned a specific task  
    - One Master CPU & multiple slave CPUs  
    - 更常見於大型系統

#### Parallel Systems Processor
- A CPU with multiple cores on the same die (chip)  
- On-chip communication is faster than between-chip communication  
- One chip with multiple cores uses less power than multiple single-core chips

<div align="center">
  <img src="https://hackmd.io/_uploads/BkCrhKdUxe.png" alt="CSAPP Memory Hierarchy" width="400"/>
</div>

P3 Ref: CSAPP: 當所有核心都在同一個晶片上，彼此間的訊號傳遞只需透過內部匯流排（如 L2/L3 cache、interconnect），速度快且延遲低。

<div align="center">
  <img src="https://hackmd.io/_uploads/SJd-sFdIee.png" alt="P3. Multiple-Core Processor" width="400"/>
</div>

[P4. Multi-Core Processorref: 周志遠 OS: Ch0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

#### Many-Core Processor
- GPU
- Intel Xeon Phi
- TILE64

#### Parallel Systems : Memory Access Architecture

1. **Uniform Memory Access (UMA)**
   - Most commonly represented today by Symmetric Multiprocessor(SMP) machines  
   - identical processors  
   - Equal access times to memory

2. **Non-Uniform Memory Access (NUMA)**
   - Often made by physically linking two or more SMPs  
   - One SMP can directly access memory of another SMP  
   - Memory access across link is slower

---

### 🌐 Distributed System（分散式系統）

Also known as loosely coupled system  
- Each processor has its own local memory  
- Processors communicate with one another through various communication lines (I/O bus or network)  
- Easy to scale to large number of nodes（容易擴展成大型節點系統）

#### distributed System : purposes
- Resource sharing（資源共享）
- Load sharing（負載分散）
- Reliability（可靠性）

#### distributed System : Architecture
- peer-to-peer（點對點）
- client-server（FTP & SSH 等）

#### distributed System : Client-Server 架構
- Easier to manage and control resources（易於管理與控制資源）
- 但 server 會成為 **瓶頸** 和 **單點失效**  

<div align="center">
  <img src="https://hackmd.io/_uploads/ryrmNq_8xl.png" alt="Client-Server Architecture" width="400"/>
</div>

#### distributed System : Peer-to-Peer (P2P)
- Every machine is identical in its role in the distributed system - decentralized  
- 範例: ppStream, Internet

#### distributed System : Clustered system
- Cluster computers share storage  
- Closely linked via a local area network (LAN) or a faster interconnect, such as **InfiniBand**

#### System Architecture Summary

<div align="center">
  <img src="https://hackmd.io/_uploads/HkUILcOLxl.png" alt="System Architecture Summary" width="400"/>
</div>


## Speical-purpose System 以使用者角度的特殊系統 
* Real-Time OS 
* Multimedia Systems
* Handheld Systems

### Real-time OS
* **Define**: Well-defined fixed-time constraints 
       -- 在deadlines 前做完即可 **(algorithm: early deadlines first)**

* 應用: 現代武器，醫療.....
* 分類: Soft & Hard

#### Soft Real time

* A critical real-time task gets priority over other tasks, and retains that priority until it completes

* ex: multimedia streaming

#### Hard real-time requirements
* Missing the deadline results in a fundamental failure : deadline 後直接crash掉 (**secondary algorithm**)
* Seconday storage limited or absent, data stored in short term memory , read-only memory

### Multimedia Systems
A wide range of applications includeing audio & video files

* Timeing constraints : 24~30 FPS
* On-demand / live straming 
* Compression: size& rate of multimedia systems

### handheld/Embedded Systems

HW specialized OS
