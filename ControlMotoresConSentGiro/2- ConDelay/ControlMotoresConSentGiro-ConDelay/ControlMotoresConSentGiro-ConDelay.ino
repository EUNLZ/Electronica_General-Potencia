/*
  Control de motor por PWM.
  Uso funcion digitalWrite para controlar el Enable.
  El sentido de giro lo controla el micro con una llave externa conectada a una entrada del micro
*/

// Constantes utilizadas para los pines.
// El pin de Enable se conecta al pin 5.
#define _Enable_A 5

// El sentido de giro se controla con los pines 10 y 11.
#define _IN1 10
#define _IN2 11

// Entrada digital que conecto a una llave para controlar el sentido de giro
#define DigitalInput A1

// Variables
int SentidoGiro = 0;
int SentidoHorario = 0;

void setup() {
  // Inicializo los pines de Enable y de sentido de giro como salidas
  pinMode(_Enable_A, OUTPUT);
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);

  pinMode(DigitalInput, INPUT);
}

void loop() {
  // Leo el switch conectado a la entrada digital para saber el sentido de giro que debo setear
  SentidoGiro = digitalRead(DigitalInput);
  if (SentidoGiro == HIGH)
  {
    // Establezco sentido de giro horario
    digitalWrite(_IN1, LOW);   
    digitalWrite(_IN2, HIGH);  

    // Detecto cuando invierto el sentido de giro para agregar un delay
    if(SentidoHorario == 0)
    {
      /*Al usar SentidoHorario == 0, estoy verificando si la llave cambió de sentido, lo tenía girando en antihorario y 
      ahora lo paso a horario.*/
      SentidoHorario = 1; 
      // Apago el motor antes de invertir el sentido de giro: pongo en cero el Enable
      digitalWrite(_Enable_A, LOW);             
      delay(1000);
    }
  }
  else
  {
    // Establezco sentido de giro antihorario
    digitalWrite(_IN1, HIGH);   
    digitalWrite(_IN2, LOW);   
    SentidoHorario = 0;

    // Detecto cuando invierto el sentido de giro para agregar un delay
    if(SentidoHorario == 1)
    {
      /*Al usar SentidoHorario == 1, estoy verificando si la llave cambió de sentido, lo tenía girando en horario y 
      ahora lo paso a antihorario.*/
      SentidoHorario = 0; 
      // Apago el motor antes de invertir el sentido de giro: pongo en cero el Enable
      digitalWrite(_Enable_A, LOW);       
      delay(1000);
    }
    
  }

  // Activo el Enable, lo pongo en HIGH
  digitalWrite(_Enable_A, HIGH); 
}
