#include <LiquidCrystal.h>

// Initialize the LCD with RS, E, D4-D7 pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define button pins
const int buttonReset = 7;    // Pin for the reset button
const int buttonAction = 8;   // Pin for the action button

// State variables
bool messageDisplayed = false; // Tracks if the second message has been displayed

void setup() {
  // Set up buttons with internal pull-up resistors
  pinMode(buttonReset, INPUT_PULLUP);
  pinMode(buttonAction, INPUT_PULLUP);

  // Initialize the LCD
  lcd.begin(16, 2);           // Set up a 16x2 LCD
  displayWelcomeMessage();    // Show the initial "Welcome!" message
}

void loop() {
  // Check for reset button press
  if (digitalRead(buttonReset) == LOW) { // Reset button pressed
    delay(200); // Debounce delay
    messageDisplayed = false;  // Reset state
    displayWelcomeMessage();   // Show initial message
  }

  // Check for action button press
  if (digitalRead(buttonAction) == LOW) { // Action button pressed
    delay(200); // Debounce delay
    if (!messageDisplayed) {
      messageDisplayed = true; // Update state
      displaySwitchMessage();  // Show the "Flick the switches" message
    }
  }
}

void displayWelcomeMessage() {
  lcd.clear();
  lcd.print("Welcome! Please press");        // First row
  lcd.setCursor(0, 1);          // Move to second row
  lcd.print("the button");
}

void displaySwitchMessage() {
  lcd.clear();
  lcd.print("Flick the switches."); // First row
  lcd.setCursor(0, 1);             // Move to second row
  lcd.print("Good luck!");
}
