#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Structure to define individual LED settings
typedef struct {
    uint8_t state;        // ON/OFF state (1 = ON, 0 = OFF)
    uint8_t brightness;   // Brightness level (0 - 255)
    uint32_t color;       // Color in RGB format (0xRRGGBB)
} LEDSettings;

// Structure to define a group of LEDs
typedef struct {
    LEDSettings singleLED;   // Individual LED settings
    uint8_t groupState;      // Group ON/OFF state (1 = ON, 0 = OFF)
    uint8_t groupBrightness; // Group brightness level (0 - 255)
} LEDGroup;

// Function to initialize the LED group with default values
void initLEDGroup(LEDGroup* group) {
    group->singleLED.state = 0;          // LED OFF
    group->singleLED.brightness = 0;     // Minimum brightness
    group->singleLED.color = 0x000000;   // Default color (black/off)
    group->groupState = 0;               // Group OFF
    group->groupBrightness = 0;          // Minimum brightness for group
}

// Function to update the LED group settings
void updateLEDGroupSettings(LEDGroup* group, uint8_t newGroupState, uint8_t newGroupBrightness,
                            uint8_t newState, uint8_t newBrightness, uint32_t newColor) {
    group->singleLED.state = newState;
    group->singleLED.brightness = newBrightness;
    group->singleLED.color = newColor;

    group->groupState = newGroupState;
    group->groupBrightness = newGroupBrightness;
}

// Function to display the status of the LED group
void displayLEDGroupStatus(const LEDGroup* group) {
    printf("Individual LED Status:\n");
    printf("State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("Brightness: %" PRIu8 "\n", group->singleLED.brightness);
    printf("Color: #%06" PRIx32 "\n", group->singleLED.color);

    printf("\nGroup Settings:\n");
    printf("Group State: %s\n", group->groupState ? "ON" : "OFF");
    printf("Group Brightness: %" PRIu8 "\n", group->groupBrightness);
}

// Function to take user input for LED and group settings
void userInteraction(LEDGroup* group) {
    uint8_t groupState, groupBrightness, ledState, ledBrightness;
    uint32_t ledColor;

    printf("\nEnter Group State (1 for ON, 0 for OFF): ");
    scanf("%" SCNu8, &groupState);

    printf("Enter Group Brightness (0 to 255): ");
    scanf("%" SCNu8, &groupBrightness);

    printf("\nEnter Individual LED State (1 for ON, 0 for OFF): ");
    scanf("%" SCNu8, &ledState);

    printf("Enter Individual LED Brightness (0 to 255): ");
    scanf("%" SCNu8, &ledBrightness);

    printf("Enter LED Color in Hexadecimal (e.g., FF4500 for Orange-Red): ");
    scanf("%" SCNx32, &ledColor);

    updateLEDGroupSettings(group, groupState, groupBrightness, ledState, ledBrightness, ledColor);

    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(group);
}

int main() {
    LEDGroup group;

    // Initialize the LED group
    initLEDGroup(&group);

    // Display the initial status of the LED group
    printf("Initial LED Group Status:\n");
    displayLEDGroupStatus(&group);

    // Interactive loop to continuously update LED settings until the user exits
    while (1) {
        int choice;

        printf("\n-- LED Control System --\n");
        printf("1. Update LED Group Settings\n");
        printf("2. Display LED Group Status\n");
        printf("3. Power OFF (Exit)\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            userInteraction(&group);
        } 
        else if (choice == 2) {
            printf("\nCurrent LED Group Status:\n");
            displayLEDGroupStatus(&group);
        } 
        else if (choice == 3) {
            printf("Powering OFF... Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
