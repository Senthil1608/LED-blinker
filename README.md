# LED Control System in C

This project implements an LED control system in C, which simulates managing individual and group LED settings, including the LED state (ON/OFF), brightness, and color (in RGB format). The program provides a console interface for users to modify and view LED settings dynamically.

## Features

- **Individual LED Control**: Set the state, brightness, and color of a single LED.
- **Group LED Control**: Control the entire group of LEDs with a separate brightness and state configuration.
- **Interactive User Interface**: Command-line interaction allowing users to update settings and view the status of the LEDs.
  
## Program Details

The program consists of two main structures:
- `LEDSettings`: Defines the state, brightness, and color of an individual LED.
- `LEDGroup`: Defines the state and brightness of an LED group, and contains an instance of `LEDSettings`.

The user can perform the following actions:
1. **Update LED Group Settings**: Modify the state, brightness, and color of the individual LED and the group.
2. **Display LED Group Status**: View the current status of both the individual LED and the group.
3. **Exit**: Close the application.

## Getting Started

### Prerequisites

- A C compiler (such as `gcc` or `clang`) installed on your system.
- Basic understanding of how to compile and run C programs.

### Compilation

To compile the program, run the following command in the terminal:

gcc -o led_control led_control.c

Usage
Once compiled, run the program using:
./led_control

Code Structure
LEDSettings struct: Stores individual LED properties (state, brightness, color).
LEDGroup struct: Stores group properties and contains an instance of LEDSettings.
Functions:
initLEDGroup(): Initializes the group and LED settings.
updateLEDGroupSettings(): Updates the group and individual LED properties.
displayLEDGroupStatus(): Prints the current LED and group status to the console.
userInteraction(): Interacts with the user to take input and update LED settings.
License
This project is licensed under the MIT License - see the LICENSE file for details.
