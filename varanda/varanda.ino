// Definição dos pinos baseada na sua montagem
const int pinoLED = 13;
const int pinoBotao = 11;

void setup() {
  // Configura o pino do LED como SAÍDA (enviar energia)
  pinMode(pinoLED, OUTPUT);
  
  // Configura o pino do botão como ENTRADA (ler o estado)
  pinMode(pinoBotao, INPUT);
}

void loop() {
  // Lê o estado atual do botão
  int estadoBotao = digitalRead(pinoBotao);

  // Verifica se o botão está sendo pressionado (recebendo 5V / HIGH)
  if (estadoBotao == HIGH) {
    // Liga o LED
    digitalWrite(pinoLED, HIGH);
  } else {
    // Desliga o LED
    digitalWrite(pinoLED, LOW);
  }
}

