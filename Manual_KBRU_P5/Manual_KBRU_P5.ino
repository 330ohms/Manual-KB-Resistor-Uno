//Declaración de constantes
const int boton = 2; //Da el nombre “boton” al pin 2
const int led = 12;

bool estadoDeLed = 0;

void setup()
{
 //Inicializa la comunicación serial a 9600 bits por segundo
 Serial.begin(9600);
 pinMode(boton, INPUT_PULLUP); //Configura el pin "boton" como entrada digital
}
void loop()
{
 
 
 int estadoDeBoton = digitalRead(boton);//Almacena la información de la entrada digital en la variable “estadoDeBoton”
 if (estadoDeBoton == 0){//Si el botón es preionado
    estadoDeLed = !estadoDeLed;//Tomamos el valor guardado en "estadoDeLed" invertimos dicho valor para volver a guardarlo en la variable "estadoDeLed"
    digitalWrite(led , estadoDeLed);//Escribimos el nuevo estado del led al pin respectivo
    Serial.println(estadoDeLed);//Envia por el puerto serial la información almacenada en “estadoDeBoton”,
                                //esta información será visualizada en el monitor serial
    delay(300);//Esperamos 300 ms antes de continuar para evitar que una sola pulsación rápida del botón alterne el estado del led más de una vez
 } 
 //Espera 1 milisegundos entre cada lectura
 delay(1);
}
