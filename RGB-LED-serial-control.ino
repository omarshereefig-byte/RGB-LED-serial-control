const int redLight   = 11;
const int greenLight = 10;
const int blueLight  = 9;

void setup() {
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(blueLight, OUTPUT);

  // Start with LED off
  digitalWrite(redLight, LOW);
  digitalWrite(greenLight, LOW);
  digitalWrite(blueLight, LOW);

  Serial.begin(9600);
  delay(1000);
  Serial.println("READY");
  Serial.println("Type: red, green, blue, cyan,magenta,foucha,orange, off");
}

void loop() {
  if (Serial.available() > 0) {
    String colour = Serial.readStringUntil('\n');
    colour.trim();
    colour.toLowerCase();   // makes input case-insensitive

    Serial.print("Received: [");
    Serial.print(colour);
    Serial.println("]");

    if (colour == "red") {
      digitalWrite(redLight, HIGH);
      digitalWrite(greenLight, LOW);
      digitalWrite(blueLight, LOW);
      Serial.println("-> RED");
    }
    else if (colour == "green") {
      digitalWrite(redLight, LOW);
      digitalWrite(greenLight, HIGH);
      digitalWrite(blueLight, LOW);
      Serial.println("-> GREEN");
    }
    else if (colour == "blue") {
      digitalWrite(redLight, LOW);
      digitalWrite(greenLight, LOW);
      digitalWrite(blueLight, HIGH);
      Serial.println("-> BLUE");
    }
    else if (colour == "cyan") {
      digitalWrite(redLight, LOW);
      analogWrite(greenLight, 180);
      analogWrite(blueLight, 180);
      Serial.println("-> CYAN");
    }
    else if (colour == "off") {
      digitalWrite(redLight, LOW);
      digitalWrite(greenLight, LOW);
      digitalWrite(blueLight, LOW);
      Serial.println("-> OFF");
    }
    else if (colour == "magenta") {
      analogWrite(redLight, 255);
      digitalWrite(greenLight, LOW);
      analogWrite(blueLight, 10);
      Serial.println("->  MAGENTA");
    }
    else if (colour == "foucha") {
      analogWrite(redLight, 255);
      digitalWrite(greenLight, LOW);
      analogWrite(blueLight, 50);
      Serial.println("-> FOUCHA");
    }
     else if (colour == "orange") {
      analogWrite(redLight, 180);
      analogWrite(greenLight,10 );
      digitalWrite(blueLight, LOW);
      Serial.println("-> ORANGE ");
    }
    else {
      Serial.println("Unknown colour");
    }

    Serial.println("Type: red, green, blue, cyan,magenta,foucha,orange, off");
  }
}