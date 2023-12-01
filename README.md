# MQTT-Lab

Welcome to MQTT-Lab! In this practice, we utilize two ESP32 boards to create an interactive and visually system.

## Project Description

In this project, one ESP32 acts as a distance sensor using the HC-SR04 ultrasonic sensor. This ESP32 measures the distance and sends the information via MQTT (Message Queuing Telemetry Transport) to another ESP32.

The second ESP32 acts as a receiver, receiving MQTT messages and controlling a RGB-Led based on the measured distance. The idea is to illuminate the LEDs proportionally to the distance, creating an intuitive visual indicator.

## Components Used

- 2 ESP32 microcontrollers
- HC-SR04 ultrasonic sensor
- RGB-Led
- Cables
- Bread borad

