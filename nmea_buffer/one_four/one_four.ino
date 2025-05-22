void setup() {
  Serial.begin(9600);    // Initialize Serial (USB) for monitoring
  Serial3.begin(9600);   // Initialize Serial3 as input (from NMEA device)
  Serial2.begin(9600);   // Initialize Serial2 as one of the outputs
  // Serial1.begin(9600); // Disabled due to damaged serial port
  delay(2000);           // Give time for serial ports to initialize
}



void loop() {
  String message = "";   // Variable to store incoming message
  delay(1000);           // Delay before reading

  // Read data from Serial3 (Input)
  while (Serial3.available()) {
    char c = Serial3.read();  // Read a character
    message += c;             // Append character to message
  }

  // If a message was received
  if (message.length() > 0) {
    Serial.println("Message received: " + String(message));  // Debug: print received message
    delay(1000);

    Serial.print(message);    // Send to Serial (USB)
    delay(1000);
    Serial.println("Message sent to Port 0");

    delay(1000);
    Serial2.print(message);   // Send to Serial2
    Serial.println("Message sent to Port 2");

    delay(1000);
    Serial3.print(message);   // Echo back to Serial3
    Serial.println("Message sent to Port 3");

  } else {
    Serial.println("Nothing available!");  // No input detected
  }

  // Testing: read from Serial2 to verify message was sent correctly
  if (Serial2.available()) {
    String message = Serial2.readStringUntil('\n');  // Read until newline
    Serial.println("Printing sent message to port x..");
    Serial.println(message);  // Display the message
  }
}

