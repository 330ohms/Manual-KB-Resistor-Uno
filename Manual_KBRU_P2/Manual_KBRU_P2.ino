


//Declaración de constantes
const int leds[] = {8, 9, 10, 11, 12};//Arreglo para contener varios valores
const int cantidadDeLeds = 5;
const int tiempoEncendido = 500; //En milisegundos
const int tiempoApagado = 0; //En milisegundos

void setup() 
{
 //La estructura de control “for(){}” permite repetir un cierto número de veces la 
 //instrucción o el conjunto de instrucciones que se agrupan dentro de sus llaves.
 
//Realiza el conjunto de instrucciones desde que “numeroDeLed” es igual a cero y
 //mientras “numeroDeLed” sea menor que “cantidadDeLeds”, en cada repetición del ciclo se incrementará
 //de uno en uno “numeroDeLed”.
 for(int numeroDeLed = 0; numeroDeLed < cantidadDeLeds; numeroDeLed++)
 {
   //Configura los elementos del arreglo "leds" como salidas digitales.
   pinMode(leds[numeroDeLed], OUTPUT);
 }
}
void loop() 
{
 for(int numeroDeLed = 0; numeroDeLed < cantidadDeLeds; numeroDeLed++)
 {
  digitalWrite(leds[numeroDeLed], HIGH); //Establece el edo del pin en alto (5V)
  delay(tiempoEncendido); //Espera el Tiempo de encendido
  digitalWrite(leds[numeroDeLed], LOW); //Establece el edo del pin en bajo (0V)
  delay(tiempoApagado);                             //Espera el Tiempo de apagado
 }
}
