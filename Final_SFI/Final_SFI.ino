void mision() {
    enum class TaskStates {
        CONFIG,
        TIMER,
        CAMERA,
        REACTION_NUCLEAR,
        SAVE_THE_WORLD
    };

    static TaskStates states = TaskStates::CONFIG;
    static bool entrada = false;
    static uint32_t Time = 5 * 1000;
    static char Value;
    static uint32_t lastime = 0;
    static const String ACCESS_CODE = "C1245";  
    static int value = 1000;
    static char newValue;
    
    switch(states) {
        case TaskStates::CONFIG: {
            Serial.begin(115200);
            Value = Serial.read();
            if (Value == 'S' || Value == 's' || Value == 'B' || Value == 'b') {
                newValue = Value;
                states = TaskStates::TIMER;
            } else if(Value == 'L' || Value == 'l') {
                newValue = Value;
                states = TaskStates::CAMERA;
            }
            break;
        }
        
        case TaskStates::TIMER: {
            if (Serial.available() > 0) {
                char newValue = Serial.read(); // Lee el nuevo valor

                if (newValue == 'S' || newValue == 's') {
                    if (Time < 40000) { // Asegura que no exceda los 40 segundos
                        Time += 1000; // Incrementa en 1 segundo (1000 ms)
                        if (!entrada) {
                            Serial.print("Se actualizó el tiempo a ");
                            Serial.print(Time / 1000);
                            Serial.println(" segundos");
                            Serial.println("L para finalizar, S para subir más y B para bajar");
                            entrada = true;
                        }
                    }
                    entrada = false; // Permite otra operación
                } else if (newValue == 'B' || newValue == 'b') {
                    if (Time > 1000) { // Asegura que no baje de 1 segundo
                        Time -= 1000; // Decrementa en 1 segundo (1000 ms)
                        if (!entrada) {
                            Serial.print("Se actualizó el tiempo a ");
                            Serial.print(Time / 1000);
                            Serial.println(" segundos");
                            Serial.println("L para finalizar, S para subir más y B para bajar");
                            entrada = true;
                        }
                    }
                    entrada = false; // Permite otra operación
                } else if (newValue == 'L' || newValue == 'l') {
                    states = TaskStates::CAMERA; // Cambia el estado si se presiona 'L'
                }
            }
            break;
        }

        case TaskStates::CAMERA: {
            uint32_t tiempo = millis();
            if ((tiempo - lastime) >= 1000) {
                lastime = tiempo;
                if (Time > 0) {
                    Time -= 1000;
                    Serial.print("Tiempo restante: ");
                    Serial.println(Time / 1000);
                } else {
                    states = TaskStates::REACTION_NUCLEAR;
                }
            }

            if (Serial.available() > 0) {
                 String codigo = "";
                while (Serial.available() > 0) {
                    codigo += (char)Serial.read();
                    delay(5);
                }

                if (codigo == ACCESS_CODE) {
                    Serial.println("SALVASTE AL MUNDO");
                    states = TaskStates::SAVE_THE_WORLD;
                } else {
                    Serial.println("Código incorrecto, la cuenta regresiva continúa...");
                    states = TaskStates::CAMERA;
                }
            }
            break;
        }

        case TaskStates::REACTION_NUCLEAR: {
            Serial.println("RADIACIÓN NUCLEAR ACTIVA");
            delay(2000);
            Serial.print("Estás en la configuración");
            entrada = false;
            states = TaskStates::CONFIG; 
            break;
        }


        case TaskStates::SAVE_THE_WORLD: {
            delay(10);
            exit(0);
            break;
        }
    }
}

void setup() {
    delay(4000);
    Serial.print("Estás en la configuración");
    mision();
}

void loop() {
    mision();
}