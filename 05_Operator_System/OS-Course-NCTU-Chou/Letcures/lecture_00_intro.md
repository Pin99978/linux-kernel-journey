# 🕰️ OS: Historical Prospective

## 🖥️ Mainframe Systems Overview
Mainframe systems evolved through several stages:
- **Batch Processing**
- **Multiprogramming**
- **Time-Sharing**

These systems were crucial for:
- Handling **bulk data processing**
- Supporting **critical applications** (e.g., servers) with high **reliability** and **security**

---

## 📦 Mainframe: Batch Systems
- Users submit jobs (program, data, control card)
- Job is loaded into memory and executed by the CPU
- Input handled → Output printed

### 🔄 Drawbacks
1. **Single-job execution:** One job runs at a time  
2. **No user interaction** during job execution  
3. **CPU often idle** due to slow I/O devices (e.g., card readers, printers, tapes)

---

## 💡 Shift to Multiprogramming
> **Goal:** Maximize utilization of CPU and I/O devices

### ❓ How?
By **overlapping I/O and computation** using **Spooling**  
(*Simultaneous Peripheral Operation On-Line*)

- I/O operations occur **without continuous CPU involvement**  
  **e.g.: 搬移 1GB 檔案從磁碟到記憶體，資料傳輸交由硬體（如 DMA）處理，CPU 可同時執行其他任務**
- CPU is only notified **once I/O completes**

![Spooling Illustration](https://hackmd.io/_uploads/BJlYVFvIel.png)  
[Spooling Video - 周志遠 OS Chapter 0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

---

## 📦 Mainframe: Multiprogramming System

### 🧠 前因：Batch 系統的限制
- 同一時間只執行一個作業（job）  
- 作業彼此之間沒有互動或並行  
- 遇到 I/O 等待時，CPU 無事可做 → 資源利用率低  
→ 導致整體效能不彰，尤其在資料處理量大或等待時間長時更加明顯

---

### 💡 為了解決以上問題，系統引入「Multiprogramming」機制

- Multiple jobs are kept in memory simultaneously  
- CPU **multiplexes** between jobs，根據狀態切換執行不同作業

> 🎯 目的：多個 jobs 同時常駐於記憶體，讓 CPU 可以輪流執行它們  
> 避免 CPU 因等待 I/O 而閒置，提高整體運算效率

![Multiprogramming Illustration](https://hackmd.io/_uploads/rJyd_KwUxg.png)  
[Multi-Programming System - 周志遠 OS Chapter 0](https://www.youtube.com/watch?v=ko-AxqDZ1Mw&index=4)

---

### 🔧 衍生任務
- **Job Scheduling**
- **CPU Scheduling**

### 🧩 OS Responsibilities 由 Multiprogramming 引發的新挑戰
- **Memory Management**: 將記憶體分配給多個作業  
- **CPU Scheduling**: 從 ready jobs 中挑選一個交給 CPU 執行  
- **I/O Management**: 提供 I/O 程式，並負責裝置分配  

> ✅ 作業系統變得至關重要，需掌控所有資源分配與作業狀態


---

## 📦 Mainframe: Time-sharing System (Multi-tasking System)

### 🧠 前因：雖具 Multi-tasking 效果，但單一程序仍非互動式 (non-interactive)

### 🎯 目的：提高互動性與回應時間

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



## 🧬 Computer System Architecture

- Programs are loaded into memory → CPU executes instructions
- Batch processing evolved into **multiprogramming**, enabling better efficiency

![Mainframe Batch System](https://hackmd.io/_uploads/SyPueFDUeg.png)  
[Mainframe Video - 周志遠 OS Chapter 0](https://www.youtube.com/watch?v=sCjybHu3lQA&index=3)
這樣的版本保留了你的原始中文標註，也讓段落