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
bool Bandera = 1;
bool PrimeraVez = 1;

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
    if(PrimeraVez == 1)
    {
      PrimeraVez = 0;
      digitalWrite(_Enable_A, LOW);
      delay(1000);      
    }
    
    // Establezco sentido de giro horario
    digitalWrite(_IN1, LOW);   
    digitalWrite(_IN2, HIGH);  

    if(Bandera == 0)
    {
      Bandera = 1;
      digitalWrite(_Enable_A, LOW);             
      delay(1000);
    }   
  }
  else
  {
    if(Bandera == 1)
    {
      Bandera = 0;
      digitalWrite(_Enable_A, LOW);             
      delay(1000);
    }

    // Establezco sentido de giro antihorario
    digitalWrite(_IN1, HIGH);   
    digitalWrite(_IN2, LOW);  
  }

  // Activo el Enable, lo pongo en HIGH
  digitalWrite(_Enable_A, HIGH); 
}
