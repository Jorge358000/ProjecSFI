int contador = 0;
static uint32_t lastTime = 0;
constexpr uint32_t INTERVAL = 1000;
String datos = "";  // Variable para almacenar el comando
bool led;

void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serial
  pinMode(LED_BUILTIN, OUTPUT);
  led = false;
}

void loop() {
  uint32_t currentTime = millis();

  // Incrementa el contador cada segundo
  if ((currentTime - lastTime) >= INTERVAL) {
    lastTime = currentTime;
    contador++;
  }

  
  if (Serial.available() > 0) {
    char dato = (char)Serial.read();  
    datos += dato;  // Añade el carácter a la cadena

    // Si se recibe un retorno de carro, procesa el comando
    if (dato == '\n') {
      if (datos == "read\n") {
        String response = String(contador) + "," + (led ? "ON" : "OFF") + "\n";
      Serial.print(response);
      }
      datos = ""; // Reinicia la variable para recibir el siguiente comando
    }
  }
}
