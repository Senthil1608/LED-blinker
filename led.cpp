#include <iostream>
#include <cstdint>
#include <iomanip>  // For formatting hexadecimal output

// Class to define individual LED settings
class LEDSettings {
public:
    uint8_t state;        // ON/OFF state (1 = ON, 0 = OFF)
    uint8_t brightness;   // Brightness level (0 - 255)
    uint32_t color;       // Color in RGB format (0xRRGGBB)

    // Constructor to initialize default values
    LEDSettings() : state(0), brightness(0), color(0x000000) {}
};

// Class to define a group of LEDs
class LEDGroup {
public:
    LEDSettings singleLED;  // Individual LED settings
    uint8_t groupState;     // Group ON/OFF state (1 = ON, 0 = OFF)
    uint8_t groupBrightness; // Group brightness level (adjustment 0 - 255)

    // Constructor to initialize default values
    LEDGroup() : groupState(0), groupBrightness(0) {}

    // Function to initialize the LED group with default values
    void initLEDGroup() {
        singleLED.state = 0;          // LED OFF
        singleLED.brightness = 0;     // Minimum brightness
        singleLED.color = 0x000000;   // Default color (black/off)
        groupState = 0;               // All LEDs OFF
        groupBrightness = 0;          // Minimum brightness for group
    }

    // Function to update the LED group settings
    void updateLEDGroupSettings(uint8_t newGroupState, uint8_t newGroupBrightness,
                                uint8_t newState, uint8_t newBrightness, uint32_t newColor) {
        // Update individual LED settings
        singleLED.state = newState;
        singleLED.brightness = newBrightness;
        singleLED.color = newColor;

        // Update group settings
        groupState = newGroupState;
        groupBrightness = newGroupBrightness;
    }

    // Function to display the status of the LED group
    void displayLEDGroupStatus() const {
        // Display individual LED settings
        std::cout << "Individual LED Status:\n";
        std::cout << "State: " << (singleLED.state ? "ON" : "OFF") << std::endl;
        std::cout << "Brightness: " << static_cast<int>(singleLED.brightness) << std::endl;
        std::cout << "Color: #" << std::hex << std::setw(6) << std::setfill('0') << singleLED.color << std::dec << std::endl;

        // Display group settings
        std::cout << "\nGroup Settings:\n";
        std::cout << "Group State: " << (groupState ? "ON" : "OFF") << std::endl;
        std::cout << "Group Brightness: " << static_cast<int>(groupBrightness) << std::endl;
    }
};

// Function to take user input for LED and group settings
void userInteraction(LEDGroup &group) {
    uint8_t groupState, groupBrightness, ledState, ledBrightness;
    uint32_t ledColor;

    std::cout << "\nEnter Group State (1 for ON, 0 for OFF): ";
    std::cin >> groupState;

    std::cout << "Enter Group Brightness (0 to 255): ";
    std::cin >> groupBrightness;

    std::cout << "\nEnter Individual LED State (1 for ON, 0 for OFF): ";
    std::cin >> ledState;

    std::cout << "Enter Individual LED Brightness (0 to 255): ";
    std::cin >> ledBrightness;

    std::cout << "Enter LED Color in Hexadecimal (e.g., FF4500 for Orange-Red): ";
    std::cin >> std::hex >> ledColor;
    std::cin >> std::dec; // Switch back to decimal input mode after hexadecimal

    // Update the LED group with user input
    group.updateLEDGroupSettings(groupState, groupBrightness, ledState, ledBrightness, ledColor);

    // Display the updated settings
    std::cout << "\nUpdated LED Group Status:\n";
    group.displayLEDGroupStatus();
}

int main() {
    // Create an LED group instance
    LEDGroup group;

    // Initialize the LED group
    group.initLEDGroup();

    // Display the initial status of the LED group
    std::cout << "Initial LED Group Status:\n";
    group.displayLEDGroupStatus();

    // Interactive loop to continuously update LED settings until the user exits
    while (true) {
        std::cout << "\n-- LED Control System --\n";
        std::cout << "1. Update LED Group Settings\n";
        std::cout << "2. Display LED Group Status\n";
        std::cout << "3. Power OFF (Exit)\n";
        std::cout << "Choose an option: ";
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Update the LED group settings
            userInteraction(group);
        } 
        else if (choice == 2) {
            // Display the current status of the LED group
            std::cout << "\nCurrent LED Group Status:\n";
            group.displayLEDGroupStatus();
        } 
        else if (choice == 3) {
            // Exit the loop (power off)
            std::cout << "Powering OFF... Goodbye!\n";
            break;
        } 
        else {
            std::cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
