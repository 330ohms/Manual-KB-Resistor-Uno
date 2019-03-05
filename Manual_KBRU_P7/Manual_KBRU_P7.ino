//Declaración de constantes
const int pinLectura = 0; //La lectura analógica la reslizaremos en el pin A0
const int pinLed = 6;
int contadorDeCiclos = 0;


void setup()
{
 //Inicializa la comunicación serial a 9600 bits por segundo
 Serial.begin(9600);
 pinMode(pinLed, OUTPUT);
 
}


void loop()
{
 //Almacena la información de la entrada analógica en la variable “valorSensor”
 int valorSensor = analogRead(pinLectura);//la función devuelve un número que se encuentra entre 0 y 1023 donde 0 corresponde a 0V y 1023 a 5v
 int tiempoDelay = map(valorSensor,0,1023, 1, 10);//Escalamos el "valorSensor" a un valor que se encuentre entre 0 y 10
 Serial.print("valorSensor: ");//Imprimimos los resultados
 Serial.println(valorSensor);
 Serial.print("tiempoDelay: ");
 Serial.println(tiempoDelay);
 Serial.print("Coclo loop#: ");
 Serial.println(contadorDeCiclos++);
 Serial.println("");
 
  for(int i=0; i<256 ; i++){//La variable "i" toma valores entre 0 y 255 iniciando en cero y aumentando de uno en uno
    analogWrite(pinLed,i);
    delay(tiempoDelay);//Esperamos el tiempo que indica la variable "tiempoDelay"
  }
  for(int i=0; i<256 ; i++){//La variable "i" toma valores entre 0 y 255 iniciando en cero y aumentando de uno en uno
    analogWrite(pinLed,255-i);
    delay(tiempoDelay);
  }
 
 
}
