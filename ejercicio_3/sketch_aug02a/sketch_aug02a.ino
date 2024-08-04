void task1(){
    enum class Task1States{
        INIT,
        WAIT_FOR_TIMEOUT
    };

    static Task1States task1State = Task1States::INIT;
    static uint32_t lastTimeUno;
    static uint32_t lastTimeDos;
    static uint32_t lastTimeTres;
    static constexpr uint32_t INTERVAL_UNO = 1000; // 1 segundo
    static constexpr uint32_t INTERVAL_DOS = 2000; // 2 segundos
    static constexpr uint32_t INTERVAL_TRES = 3000; // 3 segundos

    switch(task1State){
        case Task1States::INIT:{
            Serial.begin(115200);
      

            // Imprimir los mensajes iniciales
           
            
            lastTimeUno = millis();
            lastTimeDos = millis();
            lastTimeTres = millis();
            
            task1State = Task1States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task1States::WAIT_FOR_TIMEOUT:{
            uint32_t currentTime = millis();

            // Verificar el intervalo de 1 segundo
            if( (currentTime - lastTimeUno) >= INTERVAL_UNO ){
                lastTimeUno = currentTime;
                Serial.print("Uno\n");
            }

            // Verificar el intervalo de 2 segundos
            if( (currentTime - lastTimeDos) >= INTERVAL_DOS ){
                lastTimeDos = currentTime;
                Serial.print("Dos\n");
            }

            // Verificar el intervalo de 3 segundos
            if( (currentTime - lastTimeTres) >= INTERVAL_TRES ){
                lastTimeTres = currentTime;
                Serial.print("Tres\n");
            }

            break;
        }

        default:{
            break;
        }
    }
}

void setup(){
             delay(1200); //se usa un delay debido a que en mi computador el monitor serial no logra cargar tan rápido las líneas
            Serial.print("Uno\n");
            Serial.print("Dos\n");
            Serial.print("Tres\n");
             task1();
}

void loop(){
    task1();
}
