const int pinLedRojo = 2;
const int pinLedAmarillo = 3;
const int pinLedVerde = 4;

const int pinLedBlanco1 = 5;
const int pinLedBlanco2 = 6;

const int pinBoton = 12;
const int pinFotoresistencia = 0;
const int pinPotenciometro = 1;

unsigned long milisActual =0;
unsigned long milisAnteriorAlumbrado = 0;
unsigned long milisAnteriorSemaforo = 0;

int contadorFade = 0;
int sentidoDeFade = 0;
int estadoDeSemaforo = 1; //1@verde   2@ cuatro parpadeos en verde      3@amarillo    4@rojo

void setup()
{
  Serial.begin(9600);
  pinMode(pinLedRojo,     OUTPUT);  
  pinMode(pinLedAmarillo, OUTPUT);
  pinMode(pinLedVerde,    OUTPUT);
  pinMode(pinLedBlanco1,  OUTPUT);
  pinMode(pinLedBlanco2,  OUTPUT);
  pinMode(pinBoton,       INPUT_PULLUP);
}

void loop()
{
  milisActual = millis();//Cada ciclo loop(){} obtenemos el tiempo en milisegundos que ha transcurrido desde que inicio el programa
  alumbradoPublico();//Función correspondiente a la tarea de alumbrado público
  semaforo();//Fucnión correspondiente a la tarea de atención a las solicitudes de cambio de luces
}

//Función de tipo void (por no regresa ningún valor) que contiene el código necesario para lelvar a cabo la tarea de alumbrado público
//Para usar esta función solo es necesario escribir "alumbradoPublico();" y las líneas de código contenidas en esta declaración se ejecutarán  
void alumbradoPublico(){
    int valorFotoresistencia = analogRead(pinFotoresistencia);//leemos el valor analógico en la fotoresistencia
    if(valorFotoresistencia > 800){//Si l ailuminación detectada es lo suficientemente alta 
        analogWrite(pinLedBlanco1, 0);//Apagamos los leds blanco
        analogWrite(pinLedBlanco2, 0);
      }
    else{//En caso de que la iluminación detectada es baja
      int valorPotenciometro = analogRead(pinPotenciometro);//leemos el valor analógico del potenciómetro
      int tiempoDelay = map(valorPotenciometro,0,1023,1,10);//Escalamos el valor analógico leido del potenciómetro para obtener un npumero del 1 al 10

      if ((milisActual - milisAnteriorAlumbrado) > tiempoDelay ){//Comparamos si el tiempo transcurrido desde la última variación a la variable "contadorFade" 
                                                                 //es mayor al tiempo calculado a partir de la lectura del potenciometro
        milisAnteriorAlumbrado = milisActual;//Actualizamos el tiempo que ha transcurrido desde que inició el programa hasta la ultima variación de "contadorFade"
        if (sentidoDeFade ==0){//La variable sentidoDeFade nos indica si debemos aumentar o disminuir el valor de "contadorFade"
          if(contadorFade<255){// si no se ha llegado al límite superior
            analogWrite(pinLedBlanco1, contadorFade);//
            analogWrite(pinLedBlanco2, contadorFade);
            //analogWrite(pinLedBlanco2, 255- contadorFade);//Descomenta esta línea y comenta la anterior para ver que pasa 
            contadorFade++;//aumentamos
          }
          else{
            sentidoDeFade = 1;//Cambiamos el sentido para que la siguiente ez que se llame a esta función, comience a disminuir el valor de "contadorFade"
          }       
        }
        else{//si el valor de "sentidoFade" no es igual a 0
            if(contadorFade>0){//// si no se ha llegado al límite superior
              analogWrite(pinLedBlanco1, contadorFade);
              analogWrite(pinLedBlanco2, contadorFade);
              //analogWrite(pinLedBlanco2, 255- contadorFade);//Descomenta esta línea y comenta la anterior para ver que pasa
              contadorFade--;// disminuimos
            }
          else{
            sentidoDeFade = 0;//Cambiamos el sentido para que la siguiente ez que se llame a esta función, comience a aumentar el valor de "contadorFade"
          }     
        }
      }    
    }
  
}

//Función de tipo void (por no regresa ningún valor) que contiene el código necesario para llevar a cabo la tarea de atencion a las solicitudes 
//de cambio de luces en el semáforo vehicular
//Para usar esta función solo es necesario escribir "semáforo();" y las líneas de código contenidas en esta declaración se ejecutarán  
void semaforo(){
  switch(estadoDeSemaforo){//Inicio de la estructura de control switch(){} cuya variable de control es "estadoDeSemaforo"
    case 1:
      digitalWrite(pinLedVerde, 1);
      digitalWrite(pinLedAmarillo, 0);
      digitalWrite(pinLedRojo, 0);

      if(digitalRead(pinBoton) == 0){//Cuando el botón se presiona
        estadoDeSemaforo = 2;//Actualizamos el valor de "estadoDeSemaforo" para que la siguiente vez que sea llamada esta 
                            //función se ejecute el bloque de código correspondiente al caso 2
        milisAnteriorSemaforo = milisActual;//Actualizamos el valor de "milisAnteriorSemaforo" 
                                            //Esta variable nos ayudará a cambiar el valor de "estadoDeSemaforo" en los casos 2, 3 y 4
      }
    break;

    case 2:
      
      digitalWrite(pinLedAmarillo, 0);//Mantenemos apagada la luz amarilla
      digitalWrite(pinLedRojo, 0);//mMntenemos apagada la luz roja
      //Generamos 3 parpadeos de la luz vede midiendo el tiempo que ha transcurrido desde uq se oprimió el boton
      if( (milisActual - milisAnteriorSemaforo) < 500){
        digitalWrite(pinLedVerde, 0);
      }
      else if((milisActual - milisAnteriorSemaforo) < 1000){
        digitalWrite(pinLedVerde, 1);
      }
      else if( (milisActual - milisAnteriorSemaforo) < 1500){
        digitalWrite(pinLedVerde, 0);
      }
      else if((milisActual - milisAnteriorSemaforo) < 2000){
        digitalWrite(pinLedVerde, 1);
      }
      else if( (milisActual - milisAnteriorSemaforo) < 2500){
        digitalWrite(pinLedVerde, 0);
      }
      else if((milisActual - milisAnteriorSemaforo) < 3000){
        digitalWrite(pinLedVerde, 1);
      }
      else {
        digitalWrite(pinLedVerde, 0);
        estadoDeSemaforo = 3;//Actualizamos el valor de "estadoDeSemaforo" para que la siguiente vez que sea llamada esta 
                            //función se ejecute el bloque de código correspondiente al caso 3
      }
    break;

    case 3:
      digitalWrite(pinLedVerde, 0);//Apagamos la luz verde
      digitalWrite(pinLedAmarillo, 1);//Encendemos la luz amarilla
      digitalWrite(pinLedRojo, 0);//Mantenemos apagada la luz roja

       if( (milisActual - milisAnteriorSemaforo) > 6000){//Cuando el tiempo transcurrido desde que el btón fue presonado es mayor a 6000 ms 
        estadoDeSemaforo = 4;//Actualizamos el valor de "estadoDeSemaforo" para que la siguiente vez que sea llamada esta 
                            //función se ejecute el bloque de código correspondiente al caso 4
      }
    break;

    case 4:
      digitalWrite(pinLedVerde, 0);//Mantenemos apagada la luz verde
      digitalWrite(pinLedAmarillo, 0);//Apagamos la luz amarilla
      digitalWrite(pinLedRojo, 1);//Encendemos la luz verde

      if( (milisActual - milisAnteriorSemaforo) > 16000){//Cuando el tiempo transcurrido desde que el btón fue presonado es mayor a 16000 ms 
        estadoDeSemaforo = 1;//Actualizamos el valor de "estadoDeSemaforo" para que la siguiente vez que sea llamada esta 
                            //función se ejecute el bloque de código correspondiente al caso 1
      }
    break;

    default:
    break;
    
  }
 
}

