# 🚶 Visitor Counter System using ARM7 LPC2129

## 📖 Overview

A Visitor Counter System using the ARM7 LPC2129 microcontroller. The system counts people entering and exiting using IR sensors, displays the current count on a 16×2 LCD, blinks an LED on detection, and shows total entries/exits when a switch is pressed.

---

## ✨ Features

- 🚪 IR1 detects people entering
- 🚶 IR2 detects people exiting
- 📟 16×2 LCD display
- 💡 LED indication
- 🔘 Push button to display totals
- ⚡ External Interrupts (EINT0 & EINT1)
- ⏱️ Timer-based delay

---

## 🛠️ Hardware Used

- 🧠 LPC2129 ARM7 Development Board
- 📟 16×2 LCD
- 👁️ 2 × IR Sensors
- 💡 LED
- 🔘 Push Button
- 🔌 Power Supply

---

## 💻 Software Used

- 🖥️ Keil uVision
- 📥 Flash Magic
- 👨‍💻 Embedded C

---

## 🔌 Pin Configuration

| Device | LPC2129 Pin |
|---------|-------------|
| 📟 LCD RS | P0.8 |
| 📟 LCD EN | P0.9 |
| 📟 LCD D4–D7 | P0.4–P0.7 |
| 🚪 IR1 | EINT0 |
| 🚶 IR2 | EINT1 |
| 💡 LED | P0.13 |
| 🔘 Switch | P0.12 |

---

## 🔄 Project Flow

1. 🔋 Power ON
2. 📟 Initialize LCD
3. 💡 Initialize LED
4. 🔘 Initialize Switch
5. ⚡ Configure Interrupts
6. 🚪 Person enters → IN++
7. 🚶 Person exits → IN--, OUT++
8. 💡 LED blinks
9. 📟 LCD updates
10. 🔘 Switch displays Total IN & Total OUT

---

## 📺 LCD Output

### 🟢 Normal Mode

```text
VISITOR COUNT
IN:1 OUT:0
```

### 🔘 Switch Press

```text
TOTAL IN :2
TOTAL OT :1
```

---

## 📁 Project Structure

```
VisitorCounter/
│── main.c
│── interrupt.c
│── interrupt.h
│── mlcd.c
│── mlcd.h
│── Timer.c
│── Timer.h
│── led.c
│── led.h
│── switch.c
│── switch.h
└── README.md
```

---

## 🎯 Applications

- 🏢 Office Visitor Counter
- 📚 Library
- 🏫 Classroom
- 🛒 Shopping Mall
- 🧪 Laboratory
- 🏥 Hospital

---

## 🚀 Future Enhancements

- 🔔 Buzzer
- 💾 EEPROM Storage
- 🌐 IoT Monitoring
- 📡 Wi-Fi Module
- ☁️ Cloud Dashboard

---

## 👨‍💻 Author

**B. Vishnu**


---

## 📄 License

📚 This project is developed for educational purposes.
