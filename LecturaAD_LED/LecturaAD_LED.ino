/*
  Leo una entrada analógica con el conversor AD y enciendo un LED según el valor leído.
*/

// Constantes utilizadas para los pines.
const int AnalogInput = A0;   // Entrada analógica
int Salida = 0;               // Valor que representa la tensión leida
int ValorLeidoAD = 0;         // Valor analógico leido desde el conversor AD

void setup() {
  // Inicializo el pin del led como salida
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // Leo un valor del conversor AD
  ValorLeidoAD = analogRead(AnalogInput);
  // Mapeo el valor leido que tiene un rango de 1024 valores (el conversor AD es de 10 bits) a un rango de cero a 5000 donde 5000 representa 5V (5000 mV)
  Salida = map(ValorLeidoAD, 0, 1023, 0, 5000);
  
  if(Salida >= 2500)
    // Enciendo led
    digitalWrite(LED_BUILTIN, LOW);   
   else
    // Apago led
    digitalWrite(LED_BUILTIN, HIGH);
    
  // Espero 10 milisegundos antes de volver a adquirir una muestra del conversor AD
  delay(10);
}
