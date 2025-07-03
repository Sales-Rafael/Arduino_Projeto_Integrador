#include <LiquidCrystal.h>

// Ordem dos pinos: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);            // Inicia LCD 16 colunas, 2 linhas
  lcd.setCursor(0, 0);         // Linha 0, coluna 0
  lcd.print("Meu nome e");     // Primeira linha
  lcd.setCursor(0, 1);         // Linha 1, coluna 0
  lcd.print("WALL-E");         // Segunda linha
}

void loop() {
  // nada aqui
}
