<div align="center">

# 🛡️ ARM Embedded Systems Mini Project

### *Bare-Metal Firmware for NXP LPC2124 Microcontroller*

![ARM](https://img.shields.io/badge/ARM-ARM7TDMI-orange?style=for-the-badge&logo=arm&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Assembly](https://img.shields.io/badge/Assembly-ARM%20ASM-blueviolet?style=for-the-badge)
![Keil](https://img.shields.io/badge/Keil_uVision-0096D9?style=for-the-badge&logo=keil&logoColor=white)
![LPC2124](https://img.shields.io/badge/MCU-LPC2124-green?style=for-the-badge&logo=nxp&logoColor=white)

![Stars](https://img.shields.io/github/stars/saivikram03/mini-project-ARM?style=social)
![Forks](https://img.shields.io/github/forks/saivikram03/mini-project-ARM?style=social)

---

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=28&duration=3000&pause=1000&color=00D4FF&center=true&vCenter=true&multiline=true&repeat=true&width=700&height=100&lines=%F0%9F%A7%A0+Bare-Metal+ARM7+Programming%3B%0A%F0%9F%92%BB+C+%26+Assembly+for+Embedded+Systems%3B%0A%F0%9F%9A%80+NXP+LPC2124+Microcontroller" alt="Typing SVG" />

</div>

<br>

---

## 📋 Table of Contents

> *Navigate through the project with ease*

| 📌 Section | 📖 Description |
|:----------|:---------------|
| [🎯 Overview](#-overview) | What this project is all about |
| [✨ Features](#-features) | Key highlights and capabilities |
| [🛠️ Tech Stack](#️-tech-stack) | Technologies & tools used |
| [📁 Project Structure](#-project-structure) | Directory layout & file organization |
| [⚙️ Hardware Specs](#️-hardware-specifications) | MCU memory map & configuration |
| [🔧 Prerequisites](#-prerequisites) | What you need before getting started |
| [🚀 Getting Started](#-getting-started) | Step-by-step build & run guide |
| [💡 How It Works](#-how-it-works) | Execution flow & architecture |
| [📡 Flash Programming](#-flash-programming) | Deploying firmware to hardware |
| [📚 Resources](#-resources) | Helpful references & documentation |
| [👨‍💻 Author](#-author) | Creator information |

<br>

---

## 🎯 Overview

<div align="center">

![Overview](https://img.shields.io/badge/STATUS-ACADEMIC%20PROJECT-blue?style=for-the-badge)

</div>

This is a **bare-metal embedded systems mini project** targeting the **NXP (Philips) LPC2124** microcontroller powered by the **ARM7TDMI** core. Built entirely from scratch using the **Keil uVision IDE**, this project demonstrates low-level hardware programming without any operating system or RTOS dependency.

> ### 🔍 What is ARM7TDMI?
> The **ARM7TDMI** is a 32-bit RISC processor core designed by ARM Holdings. It features a **3-stage pipeline**, **von Neumann architecture**, and operates in both **ARM** (32-bit) and **Thumb** (16-bit instruction) modes — making it one of the most widely used cores in embedded education.

```
┌─────────────────────────────────────────────────────┐
│                    ARCHITECTURE                      │
│                                                     │
│   ┌──────────┐    ┌──────────┐    ┌──────────┐     │
│   │  Startup │───▶│  C Core  │───▶│ Hardware │     │
│   │    .s    │    │   .c     │    │  LPC2124 │     │
│   └──────────┘    └──────────┘    └──────────┘     │
│                                                     │
│   Assembly      Application     Target MCU          │
│   Bootstrap     Logic           Execution            │
└─────────────────────────────────────────────────────┘
```

<br>

---

## ✨ Features

<div align="center">

![Features](https://img.shields.io/badge/KEY-HIGHLIGHTS-purple?style=for-the-badge)

</div>

| 🏷️ Feature | 📝 Description |
|:-----------|:---------------|
| 🔩 **Bare-Metal Programming** | No OS, no RTOS — direct hardware manipulation |
| 🧩 **Mixed C & Assembly** | Startup code in ASM, application logic in C |
| 🧠 **ARM7TDMI Targeting** | 32-bit RISC processor with 3-stage pipeline |
| 💾 **Flash Programming** | ISP bootloader for serial UART deployment |
| 🔬 **Simulation Ready** | Built-in Keil simulator support for debugging |
| 📐 **Optimized Build** | `-O1` size optimization for compact firmware |
| 🔄 **Hex File Export** | Intel HEX output for universal programmer support |
| 🧹 **Clean Architecture** | Simple flat memory model, no scatter files needed |

<br>

---

## 🛠️ Tech Stack

<div align="center">

![Tech Stack](https://img.shields.io/badge/TOOLS_%26_TECHNOLOGIES-POWERING%20THIS%20PROJECT-red?style=for-the-badge)

</div>

```
╔══════════════════════════════════════════════════════════════╗
║                      TECH STACK                              ║
╠════════════════╦═════════════════════════════════════════════╣
║   Category     ║   Technology                               ║
╠════════════════╬═════════════════════════════════════════════╣
║   Language     ║   C (Application) + ARM Assembly (Boot)     ║
║   IDE          ║   Keil uVision (MDK-ARM)                    ║
║   Toolchain    ║   ARM-ADS (ARM Developer Suite)             ║
║   Target CPU   ║   ARM7TDMI (ARM7 Core)                     ║
║   Target MCU   ║   NXP LPC2124                               ║
║   Simulator    ║   Keil SARM.DLL (LPC2100 Simulator)         ║
║   Programmer   ║   LPC210x_ISP.EXE (UART ISP Flash)         ║
║   Debug        ║   Keil Simulator (Built-in)                 ║
╚════════════════╩═════════════════════════════════════════════╝
```

### 🧩 Component Breakdown

```
        ┌─────────────────────────────────────────────┐
        │            COMPONENTS USED                   │
        ├─────────────┬───────────────────────────────┤
        │             │                               │
        │    ┌────────┴────────┐   ┌──────────────┐  │
        │    │  Keil uVision   │   │  ARM-ADS     │  │
        │    │  IDE (Editor    │   │  Compiler +  │  │
        │    │  + Debugger)    │   │  Linker      │  │
        │    └────────┬────────┘   └──────┬───────┘  │
        │             │                   │          │
        │             └─────────┬─────────┘          │
        │                       │                    │
        │              ┌────────▼────────┐           │
        │              │  LPC2124 MCU    │           │
        │              │  (ARM7TDMI)     │           │
        │              └────────┬────────┘           │
        │                       │                    │
        │              ┌────────▼────────┐           │
        │              │  ISP Bootloader │           │
        │              │  (Flash via     │           │
        │              │   UART)         │           │
        │              └─────────────────┘           │
        └─────────────────────────────────────────────┘
```

<br>

---

## 📁 Project Structure

<div align="center">

![Structure](https://img.shields.io/badge/DIRECTORY-LAYOUT-green?style=for-the-badge)

</div>

```
📦 mini project-ARM/
│
├── 📄 2.uvproj          ← Keil uVision project file (XML config)
├── 📄 Startup.s          ← ARM Assembly startup code (bootstrap)
├── 📄 2.c                ← Main C application source
│
├── 📂 Output/            ← Build artifacts (auto-generated)
│   ├── 📄 2.axf          ← ARM executable (debug format)
│   ├── 📄 2.hex          ← Intel HEX (for flash programming)
│   └── 📄 2.lnp          ← Linker output log
│
└── 📄 README.md          ← You are here!
```

<br>

> **📝 Note:** The `.uvproj` file is the heart of the project — it contains all build configurations, compiler flags, memory layouts, and debug settings in XML format.

<br>

---

## ⚙️ Hardware Specifications

<div align="center">

![Hardware](https://img.shields.io/badge/LPC2124-SPECIFICATIONS-blueviolet?style=for-the-badge)

</div>

### 🧠 NXP LPC2124 Memory Map

```
┌────────────────────────────────────────────────────────────┐
│                    MEMORY MAP                               │
│                                                            │
│  ┌──────────────────────────────────────────────────────┐  │
│  │  IROM (Internal Flash)                               │  │
│  │  0x00000000 ──────────────────────── 0x0003FFFF      │  │
│  │  Size: 256 KB                                         │  │
│  │  Purpose: Code + Constants Storage                    │  │
│  └──────────────────────────────────────────────────────┘  │
│                                                            │
│  ┌──────────────────────────────────────────────────────┐  │
│  │  IRAM (Internal SRAM)                                │  │
│  │  0x40000000 ──────────────────────── 0x40003FFF      │  │
│  │  Size: 16 KB                                          │  │
│  │  Purpose: Stack + Variables + Heap                    │  │
│  └──────────────────────────────────────────────────────┘  │
│                                                            │
│  ┌──────────────────────────────────────────────────────┐  │
│  │  ENDIANNESS: Little-Endian                            │  │
│  │  STACK GROWTH: Downward (Full Descending)            │  │
│  └──────────────────────────────────────────────────────┘  │
└────────────────────────────────────────────────────────────┘
```

### 📊 Configuration Summary

| 📌 Parameter | 📝 Value |
|:------------|:--------|
| **Flash Size** | 256 KB (`0x00000000` - `0x0003FFFF`) |
| **RAM Size** | 16 KB (`0x40000000` - `0x40003FFF`) |
| **Code Start** | `0x00000000` |
| **Data Start** | `0x40000000` |
| **Endianness** | Little-Endian |
| **Compiler Optimization** | `-O1` (Size Optimized) |
| **Debug Target** | Keil Simulator (`SARM.DLL`) |

<br>

---

## 🔧 Prerequisites

<div align="center">

![Prerequisites](https://img.shields.io/badge/BFORE_YOU-START-yellow?style=for-the-badge&color=orange)

</div>

> ⚠️ **Make sure you have the following before proceeding:**

- [x] **Keil uVision** — Download from [keil.com](https://www.keil.com/)
- [x] **NXP LPC21xx Device Pack** — Install via Keil Pack Manager
- [x] **Serial Cable** *(optional)* — For ISP flash programming
- [x] **LPC2124 Development Board** *(optional)* — For hardware testing

```
┌─────────────────────────────────────────┐
│         SETUP CHECKLIST                  │
│                                         │
│  ✅ Keil uVision installed              │
│  ✅ LPC21xx Device Pack added           │
│  ✅ Source files present (Startup.s,    │
│     2.c)                                │
│  ✅ Serial connection (if flashing)     │
│  ✅ LPC2124 board (if testing HW)      │
└─────────────────────────────────────────┘
```

<br>

---

## 🚀 Getting Started

<div align="center">

![Getting Started](https://img.shields.io/badge/SETUP-GUIDE-blue?style=for-the-badge)

</div>

### 📦 Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/mini-project-ARM.git
cd "mini project-ARM"
```

### 📂 Step 2: Open the Project

```
Double-click → 2.uvproj → Opens in Keil uVision
```

### 🔨 Step 3: Build the Project

```
Press F7  →  or  →  Project Menu → Build Target
```

### 🐛 Step 4: Debug / Simulate

```
Press F5  →  Enters debug mode using Keil Simulator
```

### Step-by-Step Visual Flow

```
╔══════════╗    ╔══════════╗    ╔══════════╗    ╔══════════╗
║  CLONE   ║──▶║  OPEN    ║──▶║  BUILD   ║──▶║  DEBUG   ║
║   Repo   ║    ║  .uvproj ║    ║   F7     ║    ║   F5     ║
╚══════════╝    ╚══════════╝    ╚══════════╝    ╚══════════╝
                                                        │
                                                        ▼
                                                  ╔══════════╗
                                                  │  FLASH   │
                                                  │  to MCU  │
                                                  ╚══════════╝
```

<br>

---

## 💡 How It Works

<div align="center">

![Workflow](https://img.shields.io/badge/EXECUTION-FLOW-critical?style=for-the-badge)

</div>

### 🔄 Boot Sequence

```
    🔌 Power On / Reset
            │
            ▼
    ┌───────────────┐
    │ Exception     │     ← ARM7 Vector Table (at 0x00000000)
    │ Vector Table  │
    └───────┬───────┘
            │
            ▼
    ┌───────────────┐
    │ Startup.s     │     ← Assembly: Stack init, BSS clear,
    │ (ASM Bootstrap│        Data copy (ROM → RAM)
    │  & Init)      │
    └───────┬───────┘
            │
            ▼
    ┌───────────────┐
    │ main()        │     ← C: Application logic begins
    │ (2.c)         │
    └───────┬───────┘
            │
            ▼
    ┌───────────────┐
    │ Hardware      │     ← Direct register manipulation
    │ I/O Control   │        (GPIO, UART, Timers, etc.)
    └───────────────┘
```

### ⚡ Execution Pipeline

```
    Instruction 1  │  Instruction 2  │  Instruction 3
    ───────────────┼─────────────────┼────────────────
    ┌──────────┐   │                 │
    │  FETCH   │──▶│  DECODE         │
    └──────────┘   │                 │
                   │  ┌──────────┐   │
                   │  │ EXECUTE  │──▶│  MEMORY
                   │  └──────────┘   │  ACCESS
                   │                 │
                                      │  ┌──────────┐
                                      │  │ WRITE-BK │
                                      │  └──────────┘

           ARM7TDMI 3-Stage Pipeline
```

<br>

---

## 📡 Flash Programming

<div align="center">

![Flash](https://img.shields.io/badge/DEPLOY-TO-HARDWARE-red?style=for-the-badge)

</div>

> Deploy the compiled `.hex` file to physical LPC2124 hardware using the **ISP (In-System Programming)** bootloader.

```
┌──────────────────────────────────────────────────────┐
│              ISP FLASH PROCESS                       │
│                                                      │
│   PC ◄──── Serial UART (COM1) ────► LPC2124 Board   │
│         (9600 baud, 8-N-1)                           │
│                                                      │
│   Step 1: Pull P0.14 LOW during reset               │
│           → Enters ISP Bootloader Mode               │
│                                                      │
│   Step 2: Connect serial cable                       │
│           → COM1 @ 9600 baud                         │
│                                                      │
│   Step 3: Run ISP utility                            │
│           → LPC210x_ISP.EXE 2.hex                   │
│                                                      │
│   Step 4: Flash verification                         │
│           → Auto CRC check after write               │
└──────────────────────────────────────────────────────┘
```

| 📌 Parameter | 📝 Value |
|:------------|:--------|
| **ISP Utility** | `LPC210x_ISP.EXE` |
| **Serial Port** | COM1 |
| **Baud Rate** | 9600 |
| **Protocol** | NXP ISP (UART) |
| **Entry Pin** | P0.14 (Active LOW) |

<br>

---

## 📚 Resources

<div align="center">

![Resources](https://img.shields.io/badge/HELPFUL-REFERENCES-teal?style=for-the-badge)

</div>

| 📌 Resource | 🔗 Link |
|:-----------|:--------|
| 📖 LPC2124 Datasheet | [NXP Official Docs](https://www.nxp.com/docs/en/data-sheet/LPC2121_22_24_25_26.pdf) |
| 🧠 ARM7TDMI Reference | [ARM Developer Documentation](https://developer.arm.com/documentation/dui0021/latest) |
| 🛠️ Keil uVision Docs | [ARM Keil MDK](https://www.keil.com/support/man_docs/uv4/) |
| 📐 LPC21xx User Manual | [NXP User Manual](https://www.nxp.com/docs/en/user-guide/UM10139.pdf) |
| 🔌 ISP Programming Guide | [NXP ISP Application Note](https://www.nxp.com/docs/en/application-note/AN10457.pdf) |
| 💡 ARM Assembly Tutorial | [tutorialspoint ARM Assembly](https://www.tutorialspoint.com/assembly_programming/) |


