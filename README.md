# ESP32 Ultrasonic Radar

Proyecto de detección de proximidad con un ESP32 y un sensor ultrasónico HC-SR04.

## Funciones

- Mide la distancia a los objetos mediante ultrasonidos.
- Enciende el LED verde cuando la distancia es superior a 10 cm.
- Enciende el LED rojo cuando detecta un objeto a 10 cm o menos.
- Activa un buzzer con intervalos de 0,3 segundos de sonido y 0,3 segundos de pausa.
- Muestra las mediciones en el Monitor Serie.

## Componentes

- ESP32 Dev Module
- Sensor ultrasónico HC-SR04
- LED rojo y LED verde
- Dos resistencias de 220 Ω para los LEDs
- Resistencia de 1 kΩ y resistencia de 2 kΩ para el divisor de tensión de ECHO
- Buzzer
- Protoboard y cables

## Conexiones

| Componente | Pin ESP32 |
|---|---|
| HC-SR04 TRIG | GPIO 12 |
| HC-SR04 ECHO | GPIO 14, mediante divisor de tensión |
| LED rojo | GPIO 18 |
| LED verde | GPIO 19 |
| Buzzer | GPIO 23 |

El HC-SR04 se alimenta desde 5V/VIN. Todos los componentes comparten GND. El divisor de tensión protege la entrada ECHO del ESP32 frente a los 5 V del sensor.

## Cómo utilizarlo

1. Abre `radar_esp32.ino` en Arduino IDE.
2. Selecciona la placa ESP32 Dev Module y el puerto correspondiente.
3. Sube el programa.
4. Abre el Monitor Serie a 115200 baudios.

## Funcionamiento

El sistema utiliza un umbral de 10 cm para cambiar entre los estados de aviso visual y acústico.
