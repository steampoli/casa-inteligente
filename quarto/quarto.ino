const int sensor = 2;
const int led = 13;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int presenca = digitalRead(sensor);

  if (presenca == HIGH) {
    digitalWrite(led, HIGH);  // Liga o LED
  } else {
    digitalWrite(led, LOW);   // Desliga o LED
  }
}
