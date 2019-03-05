//Declaración de constantes
const int pinLectura = 1; //La lectura analógica la reslizaremos en el pin A0
const int pinLed = 6;


int contadorFade = 0;
int sentidoDeFade = 0;
int contadorDeCiclos = 0;

unsigned long milisActual =0;
unsigned long milisAnterior = 0;

void setup()
{
 //Inicializa la comunicación serial a 9600 bits por segundo
 Serial.begin(115200);//Aumentamos la velocidad de transferencia d elos datos para consumir menos tiempo al 
                      //imprimir en el monitor serie.
                      //Recuerda modificar la velocidad del monitor serie en la esquina inferior derecha de la ventana
                      //para que conicida con la velocidad con la que se inicializa el puerto serie de la tarjeta Resistor UNO
 pinMode(pinLed, OUTPUT);
 
}


void loop()
{
 //Almacena la información de la entrada analógica en la variable “valorSensor”
 
 Serial.print("Coclo loop#: ");//Comenta esta línea para que el efecto fade sea un poco más rápido
 Serial.println(contadorDeCiclos++);//Comenta esta línea para que el efecto fade sea un poco más rápido
 int valorSensor = analogRead(pinLectura);//la función devuelve un número que se encuentra entre 0 y 1023 donde 0 corresponde a 0V y 1023 a 5v
 int tiempoDelay = map(valorSensor,0,1023, 1, 10);//Escalamos el "valorSensor" a un valor que se encuentre entre 0 y 10
 
 
 

  milisActual = millis();//Obtenemos el tiempo en ms que ha transcurrido desde que el programa inicio 
  if ((milisActual - milisAnterior) > tiempoDelay ){//Si el tiempo trancurrido desde la pultima vriación a la variable "contadorFade"
    milisAnterior = milisActual;//Actualizamos el tiempo transcurrido desde que el programa inició hasta la última actualización 
    
    if (sentidoDeFade ==0){
      //Sentido ascendente
      if(contadorFade<255){//Si no se ha alcanzado el límeite superior
        analogWrite(pinLed, contadorFade);
        contadorFade++;
  
      }
      else{
       //Si ya se alcanzó el límite superior
       sentidoDeFade = 1;
      }       
    }
    else{
      //Sentido descendente
        if(contadorFade>0){//Si no se ha alcanzado el límite inferior
          analogWrite(pinLed, contadorFade);
          contadorFade--;
  
        }
      else{
        //Si ya se alzanzó el sentido descendente
        sentidoDeFade = 0;
      }     
    }
  }
 
 
}
