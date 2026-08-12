#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configura o endereço I2C do display (0x27 é o padrão mais comum)
LiquidCrystal_I2C lcd(0x20, 16, 2);

#define TMP36         A1
#define LED_VERMELHO  8

void setup() {
  Serial.begin(9600);
  
  // Configura os pinos
  pinMode(TMP36, INPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Inicializa o LCD e liga a luz de fundo
  lcd.init();
  lcd.backlight();
}

void loop() { 
  int Valor;
  float Temperatura;

  // 1. Faz a leitura do sensor
  Valor = analogRead(TMP36);
  
  // 2. Converte a leitura para Graus Celsius (seu cálculo original)
  Temperatura = (Valor - 20) * (125.0 + 40.0) / (358.0 - 20.0) - 40;
  
  // Exibe a temperatura no Monitor Serial
  Serial.print("Temperatura : ");
  Serial.println(Temperatura);

  // --- EXIBINDO NO DISPLAY LCD ---
  lcd.setCursor(0, 0); // Vai para a Coluna 0, Linha 0 (primeira linha)
  lcd.print("Temp: ");
  lcd.print(Temperatura, 1); // Exibe a temperatura com 1 casa decimal
  lcd.print(" C  ");         // Colocamos espaços extras no final para limpar caracteres "fantasmas"

  // 3. Lógica do Alerta (Acender por 5 segundos a partir de 30 graus)
  if (Temperatura >= 30.0) {
    lcd.setCursor(0, 1);             // Vai para a segunda linha
    lcd.print("STATUS: ALERTA! ");   // Mostra aviso no LCD
    
    digitalWrite(LED_VERMELHO, HIGH); // Liga o LED
    delay(5000);                      // Mantém tudo parado (aceso) por 5 segundos
    digitalWrite(LED_VERMELHO, LOW);  // Desliga o LED após o tempo passar
  } else {
    lcd.setCursor(0, 1);             // Vai para a segunda linha
    lcd.print("STATUS: NORMAL  ");   // Mostra status normal no LCD
  }

  delay(100); // Pequena pausa para não travar o simulador com tantas leituras
}