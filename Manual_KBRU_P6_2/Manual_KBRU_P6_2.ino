//Declaración de constantes
const int pinLectura = 0; //La lectura analógica la reslizaremos en el pin A0
const int pinLed = 12;

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
 Serial.println(valorSensor);
 if(valorSensor<800){//Modifica el valor con el que se compara la variable "valorSensor" según tus condiciones de iluminación 
  digitalWrite(pinLed, 1);
 }
 else{//si la condición de la estructura "if(){}" no se cumple, se ejecuta el código dela estructura "else{}"
  digitalWrite(pinLed,0);
 }
 delay(10);
}
