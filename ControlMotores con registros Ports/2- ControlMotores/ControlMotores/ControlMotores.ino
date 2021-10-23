/*
  Control de motor usando registros de ports.
  El sentido de giro lo controla el micro
*/
 
// Constantes utilizadas para los pines.
// El pin de Enable se conecta al pin 5.
// El sentido de giro se controla con los pines 10 y 11.
#define _Enable_A 5
#define _IN1 10
#define _IN2 11

void setup() {
  // Inicializo los pines de Enable y de sentido de giro como salidas
  DDRD =  B00100000;  //reemplazo pinMode(_Enable_A, OUTPUT);
  DDRB =  B00001100;  //reemplazo pinMode(_IN1, OUTPUT) y pinMode(_IN2, OUTPUT);
}

void loop() {
  // Establezco el sentido de giro escribiendo 1 en el pin 10 y cero en el pin 11.
  PORTB = PORTB | B00001000;    // reemplazo digitalWrite(_IN1, HIGH);  y digitalWrite(_IN2, LOW);  
  
  // Activo el Enable poniendo el pin 5 en HIGH
  PORTD = PORTD | B00100000;    // reemplazo digitalWrite(_Enable_A, HIGH); 
  // Espero 2 milisegundos. 
  delay(20);

  // Desactivo el Enable poniendo en cero el pin 5
  PORTD = PORTD & B11011111;    // reemplazo digitalWrite(_Enable_A, LOW);   
  // Espero 2 milisegundos. 
  delay(2);
}
