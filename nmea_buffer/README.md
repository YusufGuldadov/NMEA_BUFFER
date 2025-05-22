
# NMEA Buffer Project

## Overview
This project implements a simple NMEA buffer system using two Arduino boards: an Arduino Mega and an Arduino Uno. The system is designed to take serial input (simulating NMEA data) from the Uno and distribute it to multiple serial outputs on the Mega. This mimics a 1-input to 3-output buffer configuration due to a damaged serial port on the Mega.

## Features
- Compatible with RS232/RS422-style communication
- Baud rate up to 115200 (tested at 9600)
- Simple serial forwarding with isolation simulated by dedicated serial ports
- Easily extendable to 2x8 configuration on fully functional hardware

## File Structure
```
nmea-buffer/
│__industry_photo.jpg     # A sample photo 
|
|__industry_photo2.jpg     # A sample photo 
|
|__Problem_Statement.jpg  # Detailed project requirements 
|
|__NMEA_Buffer_Project_Description  # Final project description
|
|__README.md
|
├── one_four/
│   └── one_four.ino        # Arduino Mega code (1 input → 3 outputs)
│
└── uno_send/
    └── send/
        └── uno_send.ino    # Arduino Uno code (sends data to Mega)
```

## How It Works
- The **Uno** runs `uno_send.ino`, sending a "Hello Yusuf" message every 5 seconds over serial.
- The **Mega** runs `one_four.ino`, receives the message via Serial3, and forwards it to Serial, Serial2, and echoes back to Serial3.
- Diagnostic messages are printed to the Serial Monitor for verification.

## Notes
- Serial1 on the Mega is disabled in the sketch due to hardware damage.
- You can restore full functionality by enabling and wiring Serial1 if available.
