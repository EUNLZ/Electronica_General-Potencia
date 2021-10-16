// Valor de demora
#define Demora 1000

// Numeros de pines a utilizar
#define LED1_ROJO 13
#define LED2_AMARILLO 12
#define LED3_VERDE 11

void setup() {
  // inicializo los pines de leds como salida
  pinMode(LED1_ROJO,OUTPUT);
  pinMode(LED2_AMARILLO,OUTPUT);
  pinMode(LED3_VERDE,OUTPUT);
}

void loop() {
  // Enciendo el led Rojo
  digitalWrite(LED1_ROJO, HIGH);
  digitalWrite(LED2_AMARILLO, LOW);
  digitalWrite(LED3_VERDE, LOW);
  delay(Demora);
  // Enciendo el led Amarillo
  digitalWrite(LED1_ROJO, LOW);
  digitalWrite(LED2_AMARILLO, HIGH);
  digitalWrite(LED3_VERDE, LOW);
  delay(Demora);
  // Enciendo el led Verde
  digitalWrite(LED1_ROJO, LOW);
  digitalWrite(LED2_AMARILLO, LOW);
  digitalWrite(LED3_VERDE, HIGH);
  delay(Demora);
  // Enciendo el led Amarillo
  digitalWrite(LED1_ROJO, LOW);
  digitalWrite(LED2_AMARILLO, HIGH);
  digitalWrite(LED3_VERDE, LOW);
  delay(Demora);
}
