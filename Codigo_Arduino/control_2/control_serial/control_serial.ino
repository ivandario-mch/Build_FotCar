int motorA1=5;
int motorA2=18;

int motorB1=19;
int motorB2=21;

int frecuencia=5000;
int resolucion=10;

int canal0=0;
int canal1=1;
int canal2=2;
int canal3=3;
void setup() {
  Serial.begin(9600);
  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);

  ledcSetup(canal0,frecuencia,resolucion);
  ledcSetup(canal1,frecuencia,resolucion);
  ledcSetup(canal2,frecuencia,resolucion);
  ledcSetup(canal3,frecuencia,resolucion);
  ledcAttachPin(motorA1,canal0);
  ledcAttachPin(motorA2,canal1);
  ledcAttachPin(motorB1,canal2);
  ledcAttachPin(motorB2,canal3);

}

void loop() {
  
  Serial.println("comandos para mover el motor:");
  Serial.print("w  ->adelante, ");
  Serial.print("s  ->atras, ");
  Serial.print("d  ->derecha, ");
  Serial.print("a  ->Izquierda, ");
  Serial.print("k  ->detener, ");

 if (Serial.available()) { // Detecta si hay datos del monitor serial.

    char comando = Serial.read(); // Leer el carácter ingresado
    Serial.print("Comando recibido: ");
    Serial.println(comando);  

    switch (comando) {
      case 'w':
        adelante();
        break;
      case 's':
        atras();
        break;
      case 'd':
        derecha();
        break;
      case 'a':
        izquierda();
        break;
      case 'k':
        detener();
        break;
      default:
        Serial.println("Comando no válido.");
        break;
    }
  }
}


void atras(){
  // depende de la coneccion al motor, pero deberia ir hacia adelante.
ledcWrite(canal0,700);
  ledcWrite(canal1,0);

  ledcWrite(canal2,700);
  ledcWrite(canal3,0);
}
void adelante(){
  // hacia atras.
  
ledcWrite(canal0,0);
  ledcWrite(canal1,700);

  ledcWrite(canal2,0);
  ledcWrite(canal3,700);
}
void izquierda(){
  // hacia la derecha, con una sola rueda,  .
ledcWrite(canal0,0);
  ledcWrite(canal1,700);

  ledcWrite(canal2,0);
  ledcWrite(canal3,0);
}
void derecha(){
  // hacia la izquierda
ledcWrite(canal0,0);
  ledcWrite(canal1,0);

  ledcWrite(canal2,0);
  ledcWrite(canal3,700);
}
void detener() {
  // Detener los motores 
  ledcWrite(canal0, 0);
  ledcWrite(canal1, 0);

  ledcWrite(canal2, 0);
  ledcWrite(canal3, 0);
}