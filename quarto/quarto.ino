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
    delay(5000);              // Mantém ligado por 5 segundos (5000 ms)
  } else {
    digitalWrite(led, LOW);   // Desliga o LED se não houver movimento
  }
}
