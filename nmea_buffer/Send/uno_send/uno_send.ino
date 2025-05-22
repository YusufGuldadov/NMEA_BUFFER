void setup() {
  Serial.begin(9600); // Initialize Serial communication at 9600 baud (connected to Mega's Serial3)
}

void loop() {
  // Send a test message to the Mega every 5 seconds
  Serial.println("------------->Hello Yusuf \n"); // Send message over Serial
  delay(5000); // Wait 5 seconds before sending again
}

