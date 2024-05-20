int ldrPin = A0;       // LDR analog pin
int pirPin = 2;        // PIR sensor digital pin
int ledPin1 = 3;       // LED 1 digital pin
int ledPin2 = 5;       // LED 2 digital pin
int brightness = 128;  // Initial brightness level (0-255)

void setup() {
    pinMode(ldrPin, INPUT);
    pinMode(pirPin, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop() {
    int ldrValue = analogRead(ldrPin);
    int pirValue = digitalRead(pirPin);
    static bool motionDetected = false; // Track motion detection

    // If it's dark and motion is detected, turn on the LEDs at full brightness
    if (ldrValue > 1000 && pirValue == HIGH) {
        analogWrite(ledPin1, 255); // Set LED 1 brightness to full
        analogWrite(ledPin2, 255); // Set LED 2 brightness to full
        motionDetected = true; // Motion detected
    } else if (ldrValue > 1000 && !motionDetected) {
        // If it's dark and no motion is detected, keep LEDs on at reduced brightness
        analogWrite(ledPin1, brightness); // Set LED 1 brightness
        analogWrite(ledPin2, brightness); // Set LED 2 brightness
    } else {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        motionDetected = false; // Reset motion detection status
    }
}
