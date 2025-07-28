# OS: Ch2 Operating System Structure

## Outline

* OS Services
* OS-Application interface
* OS Structure

## OS Services

* 為何稱Operating System 為 Services?
因為OS本質是幫助User program做處理，透過system call()方式呼叫Services


    <div align="center">
      <img src="https://hackmd.io/_uploads/BJH90u2Ilg.png" alt="System Architecture Summary" width="400"/>
    </div>

### User inferface

* CLI(command line interface)
    * Fetch the command from user and executes it : 下指令並不是直接至OS，而是執行一程式，統稱為Shell
    **User下指令 -> Shell -> OS**  
    * Shell: Cshell / Bash: 為何需要這層?
    調整使用者不同的行為與喜好(介面,指令...)  
    
* GUI(Graphic User Interface)

### Communication Models
不論是跨電腦or本機電腦，訊息傳遞透過memory的使用可以區分成兩類:
:::info
為何是透過memory? 因memory是CPU唯一可以access的東西，即如何透過memroy讓兩隻程式來溝通
:::
* message passing
以下圖示說明訊息傳遞， 從 memory A位址copy process A 到OS的 memory 再copy到 process B 的B位址。 而**為何需copy 到 OS? Protection**
    * 缺點: 慢(copy)
* shared memory
A & B 都有權利看到shared memory 的content，且都有W/R的權限時，即可操作此memeory。**但一樣需要跟OS要求create 此 shared memory**。
    * 缺點: deadlock sychronization 

        <div align="center">
          <img src="https://hackmd.io/_uploads/Syi_zK3Ull.png" alt="System Architecture Summary" width="400"/>
        </div>
        
## OS-Application interface

### System call & API(此章節重要)
當program要執行在電腦上時，透過的是function call or API(system call)

<div align="center">
  <img src="https://hackmd.io/_uploads/SJe3VY2Ugx.png" alt="System Architecture Summary" width="400"/>
</div>

* system calls(一定是進到kernel mode)
    * OS interface 下執行的程式
    * 是software interrupt 
    * 通常是用 **assembly-language** (效能)

* API: Application Program interface:
    * 在system call的上層
    * 通常定義在language libraries, e.g C Library
    * 一個API的function call，可能對應到**多個** 或是**0個** system call (* \API 只是方便使用者寫program)
        *    e.g malloc() & free() 皆使用了system call brk()
        *    Math.c裡的abs()，未用到任何system call

**因此，執行API不一定會進到kernel mode，除非API使用到system call後用到interrupt**

<div align="center">
      <img src="https://hackmd.io/_uploads/Hy8WLK3Uel.png" alt="System Architecture Summary" width="400"/>
</div>

### API: Application Program interface:

3 common APIs

-- **Win32 API**  for Windows
-- **POSIX API** for POSIX-based systems(Unix, Linux, MacOS)
-- **Java API** for Java virtual machine (JVM)
    <div align="center">
          <img src="https://hackmd.io/_uploads/rJXqsF3Ill.png" alt="System Architecture Summary" width="400"/>
    </div>

### Why use API?
* 簡單: 方便使用者開發程式 C, JAVA)
* 可攜性: 易整合
* 效率: 讓使用者用最有效率的方式執行program

### System Calls : passing Prameters
三種方法傳遞執行中的程式(running program)與OS之間的參數
* Pass paramters from registers: 直觀，CPU直接access register上的entry
* Store the paramters in a table in memory(就是傳遞pointer的概念): 當system call要參數時，建立一個Data structure的poniter傳進function call裡，就可以讀data structure的值
* Stack : 一般的function call都會有個stack
  push(), pop()取值
 
 ![image](https://hackmd.io/_uploads/S1LjTYhLxg.png)


## OS Structure

### System Structure
* Simple OS architecture : 自由度高，但可靠性不高
* Layer OS architecture  : 易debug，每層中的component只會影響上層。
* Microkernel OS : **盡量將OS的一些function跑在User Space**，只留下重要component在kernal
    * 優點: User端容易替換需求的component，更reliable
    * 缺點: 過多的component需要以message pass的方式來與kernel傳遞，因此效能相對差
* Modular OS Structure: 以下詳敘。
* Virtual machine
* Java Virtual Machine 

### User goals & System goals
* User goals:
    * 簡單可用
    * 可靠性高
    * 安全性
    * I/O 快
* System goals:
    * 簡單可維護(debug, design)
    * 可靠性高
    * efficient

![image](https://hackmd.io/_uploads/SyA81qn8ee.png)


### Modular OS Architecture
目前大多OS以kernel modules為主
* 使用 Object-oriented approach
* 各個核心是獨立的

#### Modular OS Architecture 下的 kernel modules 怎麼運作?
基本概念
1. 同interrupt任何OS的每個 system call（例如 read()、write()）在 kernel 中對應一個 function pointer table，通常稱作 syscall table。
2. 每個 entry 是一個 kernel function 的指標，負責處理該 system call 的請求
3. 使用insert module (insmod) 將定義的kernel module載入系統
4. 在串接回原來的system call

![image](https://hackmd.io/_uploads/B1CEM5n8ll.png)


### Virtual Machine:

將底層的硬體以及實際的OS皆視為硬體
**困難點:**
1. 在 **"privileged instruction"** : 當 VM kernel 執行 "privileged instruction" 時 OS 要介入處理。
**問題點:** 
虛擬機器（VM）中的 kernel 屬於 VM 使用者空間（user space )，對 VM 來說它在 kernel mode，但對底層 OS 來說它仍是 user program 
Solution:
* VM kernel 嘗試執行 privileged instruction ⟶ 被底層 OS 視為 非法指令
* 底層 OS 會觸發 interrupt / trap 來捕捉這個異常
* OS 的 trap handler 會辨識這是 VM 的行為
* 轉而由底層 OS 幫 VM 執行該 instruction，模擬其效果
* VM就能成功「間接」執行原本受限的指令

2. **Critical instruction**中，user space也是可以執行，但問題是在x86系統下 user space與kernel space下執行結果會有差異

![image](https://hackmd.io/_uploads/r1fXsc38eg.png)

#### Usage of Virtual Machine

* high protection
* 高相容性
* 易作為開發環境(不會整個crash)
* 雲端計算

#### full virtualization
define: 上面的guest OS的程式碼完全不用修正，e.g VMware

![image](https://hackmd.io/_uploads/ryoimj2Lee.png)


#### Para-vitualization

多了一個master Server 知道各個guest OS的存在，此master Server是可以被修改的。


![image](https://hackmd.io/_uploads/HkG27sh8xe.png)
