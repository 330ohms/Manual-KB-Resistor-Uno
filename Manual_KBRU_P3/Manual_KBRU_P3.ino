//Declaración de constantes
const int boton = 2; //Da el nombre “boton” al pin 2
void setup()
{
 //Inicializa la comunicación serial a 9600 bits por segundo
 Serial.begin(9600);
 pinMode(boton, INPUT); //Configura el pin "boton" como entrada digital
}
void loop()
{
 //Almacena la información de la entrada digital en la variable “estadoDeBoton”
 int estadoDeBoton = digitalRead(boton);
 //Envia por el puerto serial la información almacenada en “estadoDeBoton”,
 //esta información será visualizada en el monitor serial.
 Serial.println(estadoDeBoton);
 //Espera 100 milisegundos entre cada lectura
 delay(100);
}
