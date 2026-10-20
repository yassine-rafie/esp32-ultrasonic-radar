# ESP32 Ultrasonic Radar — Step-by-Step Guide

This guide explains how to wire, upload, test, and publish the ESP32 ultrasonic proximity detector. Follow the steps in order and read the warnings before powering the circuit.

## 1. What You Need

- ESP32 development board and a USB data cable
- HC-SR04 ultrasonic distance sensor
- One red LED and one green LED
- Two 220 Ω resistors for the LEDs
- One 1 kΩ resistor and one 2 kΩ resistor for the ECHO voltage divider
- A compatible buzzer
- Breadboard and jumper wires
- Arduino IDE
- A GitHub account, if you want to publish the project

## 2. Wire the Components

**Disconnect the USB cable before changing any wiring.**

### HC-SR04 ultrasonic sensor

| HC-SR04 pin | Connection |
|---|---|
| VCC | ESP32 5V/VIN |
| GND | ESP32 GND |
| TRIG | GPIO 12 (D12) |
| ECHO | Voltage divider, then GPIO 14 (D14) |

### Important: Protect the ESP32 ECHO pin

The HC-SR04 ECHO output can be around 5 V, while ESP32 GPIO pins are designed for 3.3 V logic. **Do not connect ECHO directly to GPIO 14.** Use the resistor divider:

1. Connect the sensor's **ECHO** pin to one end of the **1 kΩ** resistor.
2. The other end of the 1 kΩ resistor is the junction point.
3. Connect that junction to **GPIO 14 (D14)**.
4. Connect a **2 kΩ** resistor from the junction to **GND**.
5. Connect the other end of the 2 kΩ resistor to **GND**.

This reduces the voltage reaching the ESP32 pin.

### LEDs

| Component | Connection |
|---|---|
| Red LED anode (long leg) | GPIO 18 (D18), through a 220 Ω resistor |
| Red LED cathode (short leg) | GND |
| Green LED anode (long leg) | GPIO 19 (D19), through a 220 Ω resistor |
| Green LED cathode (short leg) | GND |

Each LED must have its **own series resistor** to limit current.

### Buzzer

- Positive terminal (+) → **GPIO 23 (D23)**
- Negative terminal (−) → **GND**

**Warning:** This wiring matches the buzzer used in the working setup. Some buzzers draw more current than an ESP32 GPIO can safely provide. If your buzzer requires more current or does not work with this connection, use a suitable driver circuit instead of connecting it directly.

## 3. Check the Wiring Before Powering On

- [ ] All components share a common GND.
- [ ] There are no loose wires or shorts between 5V/VIN and GND.
- [ ] HC-SR04 VCC is connected to 5V/VIN, not to a GPIO pin.
- [ ] HC-SR04 ECHO reaches GPIO 14 through the resistor divider.
- [ ] Each LED has a 220 Ω series resistor.
- [ ] The buzzer polarity is correct.

**Never change the wiring while the ESP32 is powered.**

## 4. Open the Project in Arduino IDE

1. Open Arduino IDE.
2. Create a new sketch and save it as `radar_esp32`.
3. Paste the complete, working radar code into the editor.
4. Under **Tools → Board**, select the board that matches your ESP32.
5. Under **Tools → Port**, select the serial port assigned to the ESP32.

Menu names can vary slightly between Arduino IDE versions. If no ESP32 board is available, install the ESP32 board support package using the Boards Manager.

## 5. Upload and Test the Code

1. Connect the ESP32 using a USB cable that supports data, not just charging.
2. Click **Verify** (the checkmark) to compile the sketch.
3. If compilation succeeds, click **Upload**.
4. Open **Serial Monitor** and set the baud rate to **115200**.
5. Move an object closer to and farther from the sensor.
6. Check the distance readings and LED/buzzer behavior.

### Expected behavior

- **More than 10 cm:** green LED ON, red LED OFF, buzzer silent.
- **10 cm or less:** red LED ON, green LED OFF, buzzer beeps for 300 ms and pauses for 300 ms.
- **No valid reading:** both LEDs OFF and buzzer silent.

### If something does not work

- Check the power, GND, pin numbers, and ECHO voltage divider first.
- If no distance appears, confirm that TRIG is on GPIO 12 and ECHO's divided output is on GPIO 14.
- If the buzzer is silent, check its polarity and whether it is compatible with direct GPIO control.
- If uploading fails, check the selected board and port, and make sure the USB cable supports data.
- Disconnect power before correcting any wiring.

## 6. Prepare the GitHub Files

Create a folder named `esp32-ultrasonic-radar` containing:

- `radar_esp32.ino` — the complete Arduino sketch.
- `README.md` — the project overview, wiring table, behavior, and safety warning.

Make sure the `.ino` file contains the full code, not a screenshot. Do not upload passwords, private keys, or personal information.

## 7. Upload the Project to GitHub

1. Go to [GitHub](https://github.com) and sign in.
2. Click **+ → New repository**.
3. Name the repository `esp32-ultrasonic-radar`.
4. Add a short description, such as: `ESP32 proximity detector using an HC-SR04, two LEDs and a buzzer.`
5. Choose **Public** if you want anyone to view the project, or **Private** if you want to restrict access.
6. Click **Create repository**.
7. In the repository, choose **Add file → Upload files**.
8. Upload `radar_esp32.ino` and `README.md`.
9. Enter a commit message, for example: `Add ESP32 ultrasonic radar project`.
10. Click **Commit changes**.

After uploading, open the repository page and check that both files are visible and the README displays correctly.

## 8. Final Checklist

- [ ] The sketch compiles and uploads to the ESP32.
- [ ] Distance readings appear in Serial Monitor at 115200 baud.
- [ ] The green LED turns on when the distance is greater than 10 cm.
- [ ] The red LED and buzzer activate at 10 cm or less.
- [ ] The repository contains `radar_esp32.ino` and `README.md`.
- [ ] The README documents the wiring and warns against connecting ECHO directly to an ESP32 GPIO.

## Project Summary

This project is an ESP32-based proximity detector using an HC-SR04 ultrasonic sensor. It measures the distance to nearby objects and uses red and green LEDs plus a buzzer to indicate when an object is 10 cm away or closer.
