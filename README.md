# Smart Silver Catfish (Patin) Pond Monitoring System

## Overview

The Smart Silver Catfish Pond Monitoring System is designed to enhance the aquaculture of Silver Catfish, also known as Patin, by providing real-time monitoring and automated control of water quality parameters crucial for the fish's growth and sustainability. This project addresses the need for efficient, cost-effective, and user-friendly technology in aquaculture farms, particularly in Malaysian regions where Patin is economically significant.

## Project Objectives

- **Monitor Water Quality**: Continuously monitor parameters like water temperature, level, and turbidity.
- **Automated Control**: Automate water conditioning processes to maintain optimal conditions for Patin's growth.
- **Real-Time Alerts**: Implement feedback mechanisms to inform farmers about critical water quality changes.
- **Accessibility and Affordability**: Utilize readily available and cost-effective components to ensure wide accessibility for farmers.

## System Requirements & Specifications

- **Microcontroller**: ESP8266 NodeMCU
- **Sensors**:
  - Ultrasonic Range Detector (HC-SR04)
  - DS18B20 Waterproof Temperature Sensor
  - Water Turbidity Sensor Module
- **Actuators**:
  - Micro Submersible Water Pumps (DC 3V-5V)
- **Additional Components**:
  - HL-51 3.3v Relay
  - Jumper Wires
- **Platform**:
  - Blynk IoT Platform for integration and real-time monitoring

## Schematic Circuit Design
![](https://github.com/NexFrosty/AutomatedPondMonitoringSystem/assets/74113883/ce4cd2b3-550b-4e1d-8ee5-5f9d55e7e22a)

The system integrates various sensors and actuators through the NodeMCU, controlled via the Blynk IoT platform to ensure real-time data acquisition and response.

### Configuration

- Integration with the Blynk platform using unique identifiers for secure and reliable communication.
- Setup and initialization of all sensors and actuaries to ensure proper functioning from the start.

### Main Functionality

![image](https://github.com/NexFrosty/AutomatedPondMonitoringSystem/assets/74113883/6d2d392d-b6e3-421d-b68d-bdede8e0be13)

- Continuous monitoring of sensor data to check for any deviations from the set thresholds.
- Automated control logic to activate water pumps and other corrective mechanisms based on real-time sensor data.
