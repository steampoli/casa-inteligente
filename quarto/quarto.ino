// Pinos configurados conforme a sua montagem
const int echoPin = 3;
const int trigPin = 2;
const int ledPin = 13; // Mude este número se o LED estiver em outro pino

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Dispara o pulso do sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo de retorno no pino Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Se o objeto estiver a menos de 13cm, acende o LED por 5 segundos
  if (distance > 0 && distance < 13) {
    digitalWrite(ledPin, HIGH); // Liga o LED
    delay(5000);                // Mantém o programa pausado com o LED aceso por 5 segundos
    digitalWrite(ledPin, LOW);  // Apaga o LED após os 5 segundos
  } else {
    digitalWrite(ledPin, LOW);  // Garante que o LED fique apagado caso não tenha movimento
  }

  // Pequena pausa antes da próxima leitura do sensor
  delay(100);
}
