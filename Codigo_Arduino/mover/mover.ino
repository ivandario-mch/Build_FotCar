iint motorA1=5;
int motorA2=18;
int motorB1=21;
int motorB2=19;

//Modificacion

int frecuencia=5000;
int resolucion=10;

int canal0=0;
int canal1=1;
int canal2=2;
int canal3=3;
void setup() {
  
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
arriba();
delay(20000);
atras();
delay(2000);
derecha();
delay();
izquierda();
  
}

void adelante(){
  // depende de la coneccion al motor, pero deberia ir hacia adelante.
ledcWrite(canal0,1000);
  ledcWrite(canal1,0);

  ledcWrite(canal2,100);
  ledcWrite(canal3,0);
}
void atras(){
  // hacia atras.
  
ledcWrite(canal0,0);
  ledcWrite(canal1,1000);

  ledcWrite(canal2,0);
  ledcWrite(canal3,1000);
}
void derecha(){
  // hacia la derecha, con una sola rueda,  .
ledcWrite(canal0,1000);
  ledcWrite(canal1,0);

  ledcWrite(canal2,0);
  ledcWrite(canal3,0);
}
void izquierda(){
  // hacia la izquierda
ledcWrite(canal0,);
  ledcWrite(canal1,0);

  ledcWrite(canal2,0);
  ledcWrite(canal3,1000);
}
