# STM32F411RE LED Toggle & Motor Control System

A comprehensive embedded system project for the STM32F411RE microcontroller (NUCLEO-F411RE board) that implements multi-LED control, button-triggered interrupts, and bidirectional motor control with limit switch protection.

## Overview

This project demonstrates direct register manipulation for GPIO control, external interrupts (EXTI), timer-based LED management, and motor direction control with safety limit switches. The system features:

- **11 LED outputs** with independent timing control
- **6 pushbutton inputs** with interrupt-driven detection
- **Bidirectional motor control** (LED C/D) with forward/reverse operation
- **Limit switch protection** for motor direction reversal
- **Random sequence triggers** for diagnostic testing
- **Cooldown mechanisms** to prevent rapid LED activations

## Hardware Requirements

- **STM32 NUCLEO-F411RE** development board
- **LEDs** (11 total):
  - 1x Onboard LED (PA5 - LD2)
  - 4x Primary LEDs: PA6, PA7, PB6, PC7
  - 4x Diagnostic LEDs: PB9, PB10, PB12, PB13
  - 2x Motion LEDs: PC0 (LED A), PC1 (LED B)
  - 2x Motor Control LEDs: PC5 (LED C - Forward), PC6 (LED D - Reverse)
- **Pushbuttons** (6 total):
  - PA0, PA1, PA3, PA4, PC2, PC13 (onboard USER button)
- **Limit Switches** (2 total):
  - PB0 (Forward limit switch)
  - PB1 (Reverse limit switch)

## Pin Configuration

### LED Outputs

| Pin | Function | Description |
|-----|----------|-------------|
| PA5 | Onboard LED | Built-in green LED (LD2) |
| PA6 | LED0 | Primary LED 0 |
| PA7 | LED1 | Primary LED 1 |
| PB6 | LED2 | Primary LED 2 |
| PC7 | LED3 | Primary LED 3 |
| PB9 | LED4 | Diagnostic LED (Button 0) |
| PB10 | LED5 | Diagnostic LED (Button 1) |
| PB12 | LED6 | Diagnostic LED (Button 2) |
| PB13 | LED7 | Diagnostic LED (Button 3) |
| PC0 | LED A | Motion LED A (0.6s on-time) |
| PC1 | LED B | Motion LED B (0.6s on-time) |
| PC5 | LED C | Motor Forward (1.5s on-time) |
| PC6 | LED D | Motor Reverse (2.0s on-time) |

### Button Inputs (Pull-up, Falling Edge Trigger)

| Pin | Function | Description |
|-----|----------|-------------|
| PA0 | Button 0 | Triggers LED0 + LED4 |
| PA1 | Button 1 | Triggers LED1 + LED5 |
| PA3 | Button PA3 | Triggers LED A → LED B sequence |
| PA4 | Button 2 | Triggers LED2 + LED6 |
| PC2 | Button 3 | Triggers LED3 + LED7 |
| PC13 | USER Button | Triggers Onboard LED + LED4 |

### Limit Switch Inputs (Pull-up, Polled)

| Pin | Function | Description |
|-----|----------|-------------|
| PB0 | Forward Limit | Reverses motor if forward (LED C) is active |
| PB1 | Reverse Limit | Reverses motor if reverse (LED D) is active |

## Features

### LED Control System

- **Independent LED timers**: Each LED has its own timer for precise on-duration control
- **0.1-second on-time**: Primary LEDs (LED0-LED7, Onboard) stay on for 0.1 seconds
- **0.6-second sequence**: LED A and B sequence (A for 0.6s, then B for 0.6s)
- **Motor control timing**: LED C (1.5s) and LED D (2.0s) for motor direction control
- **1-second cooldown**: Minimum 1 second between activations for each LED
- **Diagnostic outputs**: Each button press also activates a corresponding diagnostic LED

### Interrupt System

- **Hardware interrupts**: All buttons use EXTI (External Interrupt) for immediate response
- **Mutual exclusion**: Only one interrupt handler processes at a time (prevents race conditions)
- **Debouncing**: Built-in software debouncing delays in interrupt handlers
- **Falling edge detection**: All buttons trigger on falling edge (button press pulls pin LOW)

### Motor Control

- **Bidirectional operation**: LED C (PC5) = Forward, LED D (PC6) = Reverse
- **Mutual exclusion**: Motor can only run in one direction at a time
- **Limit switch protection**: 
  - If motor is running forward (LED C ON) and PB0 or PB1 is pressed → immediately reverse (LED D)
  - If motor is running reverse (LED D ON) and PB0 or PB1 is pressed → immediately forward (LED C)
- **Polling-based**: Limit switches are checked in the main loop for responsive direction changes

### Random Sequence Triggers

- **LED A/B random trigger**: Randomly activates LED A→B sequence (~1/1024 chance per loop iteration)
- **LED C/D random trigger**: Randomly activates motor test sequence (LED C → pause → LED D)
- **LFSR-based**: Uses Linear Feedback Shift Register for pseudo-random number generation

### Startup Diagnostics

- **LED A/B test**: Brief flash of LED A (0.1s) and LED B (0.1s) during startup
- **LED C/D test**: Motor test sequence (C for 1.5s, pause 1s, D for 2s)
- **All LED blink test**: Each LED blinks 3 times at 3 Hz during initialization

## Building the Project

### Prerequisites

- **STM32CubeIDE** (version 1.19.0 or compatible)
- **STM32F4 HAL/LL** libraries (included with STM32CubeIDE)
- **ARM GCC toolchain** (included with STM32CubeIDE)

### Build Steps

1. **Open the project**:
   ```bash
   # In STM32CubeIDE
   File → Open Projects from File System
   # Navigate to project directory
   ```

2. **Build the project**:
   - Right-click project → **Build Project**
   - Or use keyboard shortcut: `Ctrl+B` (Windows/Linux) or `Cmd+B` (Mac)

3. **Flash to board**:
   - Connect NUCLEO-F411RE via USB
   - Right-click project → **Run As** → **STM32 MCU C/C++ Application**

## Project Structure

```
1_led_toggle_addr/
├── Src/
│   ├── main.c              # Main application code
│   ├── syscalls.c          # System call stubs
│   └── sysmem.c            # Memory management
├── Inc/                    # Header files directory
├── Startup/
│   └── startup_stm32f411retx.s  # Startup assembly code
├── STM32F411RETX_FLASH.ld  # Flash linker script
├── STM32F411RETX_RAM.ld    # RAM linker script
└── README.md               # This file
```

## Usage

### Basic Operation

1. **Power on**: The board will run startup diagnostic sequences
2. **Press buttons**: Each button (PA0, PA1, PA3, PA4, PC2, PC13) triggers its assigned LED(s)
3. **Motor control**: 
   - Motor sequences can be triggered randomly
   - Use limit switches (PB0/PB1) to reverse direction during operation

### Button Functions

| Button | Action |
|--------|--------|
| PA0 | Activates LED0 (0.1s) + LED4 (diagnostic) |
| PA1 | Activates LED1 (0.1s) + LED5 (diagnostic) |
| PA3 | Activates LED A (0.6s) → LED B (0.6s) sequence |
| PA4 | Activates LED2 (0.1s) + LED6 (diagnostic) |
| PC2 | Activates LED3 (0.1s) + LED7 (diagnostic) |
| PC13 | Activates Onboard LED (0.1s) + LED4 (diagnostic) |

### Motor Control

- **LED C (PC5)**: Motor forward direction (1.5 seconds when activated)
- **LED D (PC6)**: Motor reverse direction (2.0 seconds when activated)
- **Limit switches**: PB0 or PB1 pressed during motor operation reverses direction immediately

## Technical Details

### Timing Specifications

- **Main loop delay**: 10,000 iterations (~1ms per loop)
- **LED on-duration**: 
  - Primary LEDs: 100 iterations = 0.1 seconds
  - LED A/B: 600 iterations = 0.6 seconds
  - LED C: 1500 iterations = 1.5 seconds
  - LED D: 2000 iterations = 2.0 seconds
- **Cooldown period**: 1000 iterations = 1 second minimum between activations

### Register-Level Programming

This project uses **direct register manipulation** rather than HAL libraries:
- Direct GPIO register access (`GPIOx_MODE_R`, `GPIOx_OD_R`, etc.)
- Direct EXTI configuration (`EXTI_FTSR`, `EXTI_IMR`, `EXTI_PR`)
- Direct NVIC interrupt enable (`NVIC_ISER0`, `NVIC_ISER1`)
- Direct SYSCFG routing (`SYSCFG_EXTICR1`, `SYSCFG_EXTICR2`, `SYSCFG_EXTICR4`)

### Interrupt Priorities

- **EXTI0** (PA0): IRQ 6
- **EXTI1** (PA1): IRQ 7
- **EXTI2** (PC2): IRQ 8
- **EXTI3** (PA3): IRQ 9
- **EXTI4** (PA4): IRQ 10
- **EXTI13** (PC13): IRQ 40 (shared with EXTI10-15)

## Wiring Diagrams

### Button Wiring (All Buttons)
```
Button Terminal 1 ──── GPIO Pin (PA0, PA1, PA3, PA4, PC2, PC13)
Button Terminal 2 ──── GND
```
*No external pull-up resistor needed (internal pull-up enabled)*

### Limit Switch Wiring
```
PB0/PB1 ──── Limit Switch Terminal 1
Limit Switch Terminal 2 ──── GND
```
*No external pull-up resistor needed (internal pull-up enabled)*

### LED Wiring
```
GPIO Pin ──── [Current Limiting Resistor ~220Ω-1kΩ] ──── LED Anode
LED Cathode ──── GND
```

### Motor Control (LED C/D)
```
PC5 (LED C) ──── Motor Forward Control
PC6 (LED D) ──── Motor Reverse Control
```
*These pins control motor direction via external driver circuit*

## Troubleshooting

### LEDs Not Lighting
- Check wiring connections
- Verify GPIO pins are configured as outputs
- Check that alternate function registers are cleared (especially PC0, PC1, PC5, PC6)

### Buttons Not Responding
- Verify pull-up configuration
- Check EXTI interrupt enable in NVIC
- Ensure SYSCFG routing is correct
- Check for interrupt processing lock (only one interrupt at a time)

### Motor Not Reversing
- Verify PB0/PB1 limit switches are wired correctly
- Check that limit switches are configured as inputs with pull-up
- Ensure polling loop is checking limit switches when motor is active

## License

This project is provided as-is for educational and development purposes.

## Author

STM32 Embedded Systems Project

## Version History

- **v1.0**: Initial implementation with LED control, button interrupts, and motor control with limit switch protection

