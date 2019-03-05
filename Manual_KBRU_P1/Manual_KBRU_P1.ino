//Declaración de constantes
const int led = 13; //Da el nombre “led” para el pin 13
const int tiempoEncendido = 50; //En milisegundos
const int tiempoApagado = 50; //En milisegundos
//La estructura “setup()” se ejecuta una sola vez cada que la tarjeta Arduino es 
//energizada o después de que el botón de reinicio es presionado.
void setup()
{
 pinMode(led, OUTPUT); //Configura el pin "led" como salida digital
}
//La estructura “loop()” se repite indefinidamente mientras la tarjeta se
//mantenga energizada.
void loop()
{
 digitalWrite(led, HIGH); //Establece el estado del pin "led" en alto (5V)
 delay(tiempoEncendido); //Espera el Tiempo de encendido
 digitalWrite(led, LOW); //Establece el estado del pin "led" en bajo (0V)
 delay(tiempoApagado); //Espera el Tiempo de apagado
}
