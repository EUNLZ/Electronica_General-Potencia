/*
  Leo una entrada analógica con el conversor AD.

  Se utiliza el port serie para transmitir los valores correspondientes.
*/

// Constantes utilizadas para los pines.
const int AnalogInput = A0;   // Entrada analógica
float Salida = 0;               // Valor a imprimir por el puerto serie
int ValorLeidoAD = 0;         // Valor analógico leido desde el conversor AD

void setup() {
  // Inicializo el pin del led como salida
  pinMode(LED_BUILTIN, OUTPUT);

  // Se inicializa el puerto serie a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leo un valor del conversor AD
  ValorLeidoAD = analogRead(AnalogInput);
  // Mapeo el valor leido que tiene un rango de 1024 valores (el conversor AD es de 10 bits) a un rango de cero a 5000 donde 5000 representa 5V (5000 mV)
  Salida = map(ValorLeidoAD, 0, 1023, 0, 5000);
  
  if(Salida >= 2500)
    digitalWrite(LED_BUILTIN, LOW);
   else
    digitalWrite(LED_BUILTIN, HIGH);

  // Para imprimir paso el valor de mV a Volts.
  Salida /= 1000;

  // Transmito los resultados por el port serie
  Serial.print("Muestra AD = ");
  Serial.print(ValorLeidoAD);
  Serial.print("\t Tension = ");
  Serial.println(Salida);

  // Espero 1 milisegundo antes de volver a adquirir una muestra del conversor AD
  delay(1);
}
