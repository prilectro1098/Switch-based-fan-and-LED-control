# Switch-based-fan-and-LED-control
Created an Arduino-based LED &amp; Fan Control System using register-level programming with Timer 2. Users can control LEDs and a fan with switches, utilizing a 1-second delay for smooth toggling. A great example of my skills in embedded systems and low-level programming.
Arduino-based LED & Fan Control System: Register-Level Programming Using Timer 2
This project is an Arduino-based LED and fan control system, designed to respond to user input via push buttons. It utilizes register-level programming with Timer 2 for efficient, real-time control of the connected devices, demonstrating my ability to work with low-level hardware control for embedded systems.

Project Overview
In this project, the system consists of three LEDs and a fan that can be toggled on or off using four separate push buttons. The core of the functionality is powered by Timer 2, which is used to create a 1-second delay to control the switching behavior of the LEDs and fan.

Key Features
Button-Controlled Devices: The system includes three LEDs and a fan, each controlled by individual push buttons.
Timer-based Control: Timer 2 is configured to run in normal mode with a prescaler of 1024, generating an approximate 1-second delay. This delay allows smooth and predictable toggling of the LEDs and fan.
Register-Level Programming: Direct manipulation of Arduino registers ensures efficient handling of the hardware, providing a deeper understanding of the microcontroller’s functionality.
Push-Button Inputs: The input buttons are configured with pull-up resistors to maintain stable readings, and the button presses are used to toggle the states of the LEDs and fan.
Optimized Hardware Control: The project showcases real-time control of hardware devices by utilizing Timer interrupts for non-blocking execution, providing a solid foundation in embedded systems programming.
Components Used
Arduino Board (e.g., Arduino Uno)
3 LEDs
1 Fan (Motor)
4 Push Buttons
Resistors, capacitors, and other basic electronic components
Technologies and Tools
Programming Language: C/C++
Development Environment: Arduino IDE
Core Concepts: Timer 2, Interrupts, Register-Level Programming, Embedded Systems
Project Structure
The project code is divided into the main logic and the Interrupt Service Routine (ISR), which handles Timer 2 overflows and toggles the states of the LEDs and fan.
The main loop reads the state of the push buttons and adjusts the states of the devices accordingly.
How It Works
The user can press any of the four buttons to control the LEDs and fan.
The Timer 2 interrupt triggers every 1 second, toggling the states of the devices based on the button inputs.
The system ensures efficient, non-blocking execution, thanks to Timer 2’s interrupt mechanism.
Future Improvements
Implement a debounce mechanism for the buttons to prevent multiple button presses from being registered unintentionally.
Expand the project to control more devices or use PWM for dimming the LEDs or controlling the fan speed.
Conclusion
This project is a great demonstration of embedded systems development and low-level programming. By utilizing Timer 2 and register-level control, I was able to build a responsive, real-time system with direct hardware manipulation, which is crucial in understanding how microcontrollers work at a deeper level.


