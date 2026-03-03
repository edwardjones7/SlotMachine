# 🎰 Arduino Slot Machine — Rowan ProfHacks

A fully functional physical slot machine built from scratch for Rowan University's ProfHacks hackathon. Every component — from the 3D-printed chassis to the software logic — was designed and built by our team over the course of the hackathon.

![Slot Machine Build]<img width="302" height="296" alt="image" src="https://github.com/user-attachments/assets/097bae37-357a-4d6c-a19a-8d6f31cd1b45" />


---

## 🧠 Project Overview

We designed and built a working casino-style slot machine that physically spins three reels, detects the outcome, and responds accordingly — all driven by an Arduino, custom microcontroller wiring, and a Python detection script.

The goal was to combine hardware engineering, CAD/fabrication, and software to produce an interactive, self-contained game that felt and behaved like the real thing.

---

## 🖨️ Hardware & Fabrication

### 3D Printed Build
- The **entire chassis, reel housings, and structural frame** were modeled in CAD and 3D printed during the hackathon
- The three spinning reels each display classic slot machine symbols: **7s, bells, lions, and hearts**
- The frame holds all three reels in alignment and provides mounting points for the electronics underneath

### Electronics
- **Arduino microcontroller** serves as the central controller managing reel spin timing and game state
- **Stepper motors / servo motors** drive each of the three reels independently
- **Breadboard & wiring harness** connects all components — power, signal lines, and ground rails are color-coded (red, black, blue)
- **LCD display** mounted to the front of the machine shows game state and output (e.g., JACKPOT)
- A custom **button interface** allows the player to trigger a spin

---

## 💻 Software

### Arduino Firmware
- Controls motor actuation for each reel
- Manages spin duration and stopping position for each drum
- Sends reel position data over serial to the Python script

### Python Detection Script
- Reads reel position data from the Arduino over serial
- Determines the combination shown on the three reels
- Checks for winning conditions (three-of-a-kind, partial matches, jackpot)
- Triggers appropriate output responses (LCD message, lights, etc.)

---

## 🎮 How It Works

1. Player presses the button to initiate a spin
2. Arduino activates all three stepper motors, spinning the reels
3. Motors stop sequentially at pseudo-random positions
4. Reel positions are sent via serial to the Python script
5. Python evaluates the outcome and determines if the player wins
6. Result is displayed on the LCD screen — including **JACKPOT** for a perfect match

