# ESP32 Zephyr RTOS GPIO Demo for ESP32 DevKitC & ESP32-CAM

| Property       | Value                        |
|----------------|------------------------------|
| **Author**     | Nguyễn Minh Quân             |
| **Platform**   | ESP32 DevKitC v4 / ESP32-CAM |
| **Framework**  | Zephyr RTOS v4.4.0           |
| **Language**   | C                            |
| **Toolchains** | west + CMake + Zephyr SDK    |

---

# Project Overview

This project demonstrates a portable **GPIO LED Blink** application developed with **Zephyr RTOS** for two ESP32 development boards:

- ESP32 DevKitC v4
- ESP32-CAM

The application uses **DeviceTree overlays** to separate hardware configuration from application logic, allowing the same firmware source to run on multiple boards without modification.

This project demonstrates practical experience with:

- Zephyr RTOS
- Embedded C programming
- DeviceTree customization
- GPIO Driver API
- ESP32 Board Support Package (BSP)
- Cross-board firmware portability

---

# Demonstration

## ESP32-CAM LED Blink

[Watch the demo video](https://github.com/user-attachments/assets/403be507-46ce-4f00-a691-2bfa5d5892ec)

---

# Hardware Used

| Board            | Purpose                      |
| ---------------- | ---------------------------- |
| ESP32 DevKitC v4 | Zephyr GPIO demonstration    |
| ESP32-CAM        | GPIO LED Blink demonstration |
| USB-UART Adapter | Flashing and Serial Monitor  |
| On-board LEDs    | Blink indicator              |

---

# Software Stack

```text
Zephyr RTOS 4.4.0
├── Kernel
├── DeviceTree
├── GPIO Driver API
├── ESP32 BSP
└── west Build System
```

---

# GPIO Blinking Application

## Main Source

- `src/main.c`

The application configures the built-in LED using Zephyr's GPIO Driver API and toggles it every 5 seconds through a DeviceTree alias (`led0`).

### Features

* Uses DeviceTree alias (`led0`)
* Uses Zephyr GPIO Driver API
* Board-independent application
* LED toggles every 5 seconds

---

# DeviceTree Overlay — ESP32 DevKitC v4

File:

boards/esp32_devkitc_esp32_procpu.overlay

### Description

* Creates a logical LED node
* Exposes alias `led0`
* Maps LED to GPIO2

---

# DeviceTree Overlay — ESP32-CAM

File:

boards/esp32_cam_esp32_procpu.overlay

### Description

* Defines the LED used on ESP32-CAM
* Reuses the same alias (`led0`)
* Allows the same application to run without code modification

---

# Build Instructions

## Build for ESP32 DevKitC

```bash
west build -b esp32_devkitc/esp32/procpu
```

## Build for ESP32-CAM

```bash
west build -b esp32_cam/esp32/procpu
```

## Flash

```bash
west flash
```

## Serial Monitor

```bash
west espressif monitor
```

---

# Project Structure

```text
project/
├── boards/
│   ├── esp32_devkitc_esp32_procpu.overlay
│   └── esp32_cam_esp32_procpu.overlay
├── src/
│   └── main.c
├── prj.conf
├── CMakeLists.txt
├── media/
│   └── esp32cam_blink_demo.mp4
└── docs/
    └── portfolio_esp32_zephyr.md
```

---

# Engineering Notes

## DeviceTree Portability

Instead of hardcoding GPIO numbers in the application, hardware information is described in DeviceTree overlays. The firmware accesses peripherals through logical aliases, allowing the same source code to be reused across different ESP32 boards.

## GPIO Driver Abstraction

The application interacts with GPIO using Zephyr's driver model rather than direct register manipulation, improving portability, readability, and maintainability.

---

# Contact

**Nguyễn Minh Quân**

Embedded Systems • Robotics • Navigation & Control

Ho Chi Minh City, Vietnam
