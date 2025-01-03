#define LED_PIN_1 13    // Pin for LED 1
#define LED_PIN_2 8     // Pin for LED 2
#define LED_PIN_3 9     // Pin for LED 3
#define FAN_PIN 12      // Pin for Fan (Motor)

#define BUTTON_LED_1_PIN 2   // Pin for LED 1 Control Button
#define BUTTON_LED_2_PIN 4   // Pin for LED 2 Control Button
#define BUTTON_LED_3_PIN 5   // Pin for LED 3 Control Button
#define BUTTON_FAN_PIN 3     // Pin for Fan Control Button

volatile bool toggleState = false;  // Variable to hold the toggle state for Timer
volatile bool ledButtonState1 = false, ledButtonState2 = false, ledButtonState3 = false, fanButtonState = false;  // To store the state of the buttons

void setup() {
  // Set pin modes for LEDs and Fan
  DDRB |= (1 << DDB5);  // Set Pin 13 as output (PB5 for LED 1)
  DDRB |= (1 << DDB4);  // Set Pin 12 as output (PB4 for Fan)
  DDRB |= (1 << DDB0);  // Set Pin 8 as output (PB0 for LED 2)
  DDRB |= (1 << DDB1);  // Set Pin 9 as output (PB1 for LED 3)

  // Set pin modes for buttons (inputs with pull-ups)
  pinMode(BUTTON_LED_1_PIN, INPUT_PULLUP);  // Button for LED 1
  pinMode(BUTTON_LED_2_PIN, INPUT_PULLUP);  // Button for LED 2
  pinMode(BUTTON_LED_3_PIN, INPUT_PULLUP);  // Button for LED 3
  pinMode(BUTTON_FAN_PIN, INPUT_PULLUP);    // Button for Fan

  // Initialize all pins to LOW (turn off both LEDs and Fan)
  PORTB &= ~(1 << PORTB5);  // Set Pin 13 (PB5) LOW (turn off LED 1)
  PORTB &= ~(1 << PORTB0);  // Set Pin 8 (PB0) LOW (turn off LED 2)
  PORTB &= ~(1 << PORTB1);  // Set Pin 9 (PB1) LOW (turn off LED 3)
  PORTB &= ~(1 << PORTB4);  // Set Pin 12 (PB4) LOW (turn off Fan)

  // Disable global interrupts before configuring the timer
  cli();

  // Set Timer 2 to normal mode (8-bit timer)
  TCCR2A = 0;  // Normal mode (WGM20=0, WGM21=0)
  TCCR2B = 0;  // Clear TCCR2B to reset settings

  // Set prescaler to 1024 (CS22=1, CS21=0, CS20=1)
  TCCR2B |= (1 << CS22) | (1 << CS20);

  // Initialize Timer 2 value to 0
  TCNT2 = 0;

  // Enable Timer 2 Overflow Interrupt
  TIMSK2 |= (1 << TOIE2);

  // Re-enable global interrupts
  sei();
}

// Timer 2 Overflow Interrupt Service Routine (ISR)
ISR(TIMER2_OVF_vect) {
  static int counter = 0;
  counter++;

  // Approximate 1 second delay with 8-bit Timer 2
  if (counter >= 61) {  
    toggleState = !toggleState;  // Toggle the state

    // Toggle LED 1
    if (toggleState && !ledButtonState1) {
      PORTB |= (1 << PORTB5);  // Turn on LED 1
    } else {
      PORTB &= ~(1 << PORTB5);  // Turn off LED 1
    }

    // Toggle LED 2
    if (toggleState && !ledButtonState2) {
      PORTB |= (1 << PORTB0);  // Turn on LED 2
    } else {
      PORTB &= ~(1 << PORTB0);  // Turn off LED 2
    }

    // Toggle LED 3
    if (toggleState && !ledButtonState3) {
      PORTB |= (1 << PORTB1);  // Turn on LED 3
    } else {
      PORTB &= ~(1 << PORTB1);  // Turn off LED 3
    }

    // Toggle Fan
    if (toggleState && !fanButtonState) {
      PORTB |= (1 << PORTB4);  // Turn on Fan
    } else {
      PORTB &= ~(1 << PORTB4);  // Turn off Fan
    }

    counter = 0;
  }
}

void loop() {
  // Read the state of the buttons
  ledButtonState1 = digitalRead(BUTTON_LED_1_PIN) == LOW;  // Button for LED 1
  ledButtonState2 = digitalRead(BUTTON_LED_2_PIN) == LOW;  // Button for LED 2
  ledButtonState3 = digitalRead(BUTTON_LED_3_PIN) == LOW;  // Button for LED 3
  fanButtonState = digitalRead(BUTTON_FAN_PIN) == LOW;     // Button for Fan

  // Button control logic
  if (ledButtonState1) {
    PORTB |= (1 << PORTB5);  // Turn on LED 1
  } else {
    PORTB &= ~(1 << PORTB5);  // Turn off LED 1
  }

  if (ledButtonState2) {
    PORTB |= (1 << PORTB0);  // Turn on LED 2
  } else {
    PORTB &= ~(1 << PORTB0);  // Turn off LED 2
  }

  if (ledButtonState3) {
    PORTB |= (1 << PORTB1);  // Turn on LED 3
  } else {
    PORTB &= ~(1 << PORTB1);  // Turn off LED 3
  }

  if (fanButtonState) {
    PORTB |= (1 << PORTB4);  // Turn on Fan
  } else {
    PORTB &= ~(1 << PORTB4);  // Turn off Fan
  }
}