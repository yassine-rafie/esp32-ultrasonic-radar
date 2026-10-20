Project for proximity detection using an ESP32 and an HC-SR04 ultrasonic sensor.

## Functions

- Measures the distance to objects using ultrasound.
- Turns on the green LED when the distance is greater than 10 cm.
- Turns on the red LED when it detects an object at 10 cm or less.
- Activates a buzzer with intervals of 0.3 seconds of sound and 0.3 seconds of pause.
- Displays the measurements in the Serial Monitor.

## Components

- ESP32 Dev Module
- HC-SR04 ultrasonic sensor
- Red and green LED
- Two 220 Ω resistors for the LEDs
- 1 kΩ resistor and 2 kΩ resistor for the ECHO voltage divider
- Buzzer
- Breadboard and wires

## Connections

| **Component** | **ESP32 Pin**                         |
| -------------- | ------------------------------------- |
| HC-SR04 TRIG   | GPIO 12                               |
| HC-SR04 ECHO   | GPIO 14, through voltage divider      |
| Red LED        | GPIO 18                               |
| Green LED      | GPIO 19                               |
| Buzzer         | GPIO 23                               |

The HC-SR04 is powered from 5V/VIN. All components share GND. The voltage divider protects the ESP32 ECHO input from the sensor's 5 V.

## How to use it

1. Open `radar_esp32.ino` in Arduino IDE.
2. Select the ESP32 Dev Module board and the corresponding port.
3. Upload the program.
4. Open the Serial Monitor at 115200 baud.

## Operation

The system uses a 10 cm threshold to switch between the visual and audible warning states.
