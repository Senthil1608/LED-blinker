# LED-blinker

Overview
This project implements a simple LED Control System in C++. It allows users to manage the settings of a group of LEDs, including turning them on/off, adjusting their brightness, and setting colors using RGB values in hexadecimal format.

The system is divided into two classes:

LEDSettings: Defines the settings for an individual LED (state, brightness, and color).
LEDGroup: Manages the group settings (group state and group brightness) and contains a single instance of LEDSettings to represent an individual LED.
The program interacts with the user via the console, providing options to update the LED settings or display the current status of the LED group.

Features
Individual LED Settings: Users can control the state (ON/OFF), brightness (0-255), and color (RGB in hexadecimal format) of a single LED.
Group LED Settings: Users can manage the overall state and brightness of the group of LEDs.
Interactive Interface: The program continuously prompts the user for input to update the settings or display the current status.
Hexadecimal Color Input: Colors are entered in RGB hexadecimal format (e.g., FF4500 for Orange-Red).
Classes
1. LEDSettings
This class defines the settings of a single LED:

Attributes:
uint8_t state: ON/OFF state of the LED (1 for ON, 0 for OFF).
uint8_t brightness: Brightness level of the LED (0 to 255).
uint32_t color: Color of the LED in RGB hexadecimal format (0xRRGGBB).
Constructor:
Initializes the LED state to OFF, brightness to 0, and color to black (0x000000).
2. LEDGroup
This class defines the settings for a group of LEDs:

Attributes:

LEDSettings singleLED: An instance of the LEDSettings class to represent individual LED settings.
uint8_t groupState: ON/OFF state of the entire group (1 for ON, 0 for OFF).
uint8_t groupBrightness: Brightness level of the group (0 to 255).
Methods:

void initLEDGroup(): Initializes the LED group with default values.
void updateLEDGroupSettings(): Updates both individual LED and group settings based on user input.
void displayLEDGroupStatus() const: Displays the current status of the LED group and individual LED settings.
How to Use
1. Compile the Program
To compile the program, use the following command:
g++ -o LEDControlSystem LEDControlSystem.cpp

2. Run the Program
Execute the compiled program:
./LEDControlSystem

3. Interaction Options
Once the program is running, you will be prompted to choose one of the following options:

Update LED Group Settings: Allows you to modify the state, brightness, and color of the LED group and the individual LED.
Display LED Group Status: Displays the current settings for both the LED group and the individual LED.
Power OFF (Exit): Exits the program.
