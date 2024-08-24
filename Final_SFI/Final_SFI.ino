void mision(){
  enum class TaskStates    
  {
        CONFIG,
        TIMER,
        CAMERA,
        REACTION_NUCLEAR,
        ACCESS,
        SAVE_THE_WORD
      
    };
    static TaskStates states = TaskStates::CONFIG;
    static bool entrada = false;
    static uint32_t Time = 5 * 1000;
    static char Value;
    static uint32_t lastime = 0;

    switch(states)
    {
      case TaskStates::CONFIG:
      {
        Serial.begin(115200);
        Value = Serial.read();
        if (Value == 'S' || Value == 's' || Value == 'B' || Value == 'b' )
        {
          
          states = TaskStates::TIMER;
          
          
        }
        
        break;
      }
      case TaskStates::TIMER:
      {
        if(Value == 'S' || Value == 's')
        {
          if(!entrada)
         {
            Serial.print("Escriba un número mayor al actual y menor al 40, número actual: " );
            Serial.println(Time/1000);
            entrada = true;
            
         }
         if(Serial.available() > 0)
            {
              String dato = "";
              while(Serial.available() > 0)
              {
                
              dato += (char)Serial.read();
              delay(5);
              }
              

              int value = dato.toInt();
              if(value > Time/1000 && value <= 40)
              {
                Time = value * 1000;
                Serial.print("El tiempo actualizado es de: ");
                Serial.println(Time/1000);
                Serial.print(" segundos");
                Serial.print("Para salir pulse L");
                break;
              }
            
             break;
             
            }

             if(Serial.available() > 0)
            {
              char Exit = Serial.read();
              if (Exit == 'L' || Exit == 'l') 
                {
                   states = TaskStates::CAMERA;
                }
            }
        }
        else if(Value == 'B' || Value == 'b')
        {
           if(!entrada)
         {
            Serial.print("Escriba un número menor al actual y mayor al 1, número actual: " );
            Serial.println(Time);
            entrada = true;
            
         }
         if(Serial.available() > 0)
            {
              String dato = "";
              dato += (char)Serial.read();
              delay(5);

              int value = dato.toInt();
              if(value > 1 && value < Time/1000)
              {
                Time = value * 1000;
                Serial.print("El tiempo actualizado es de: ");
                Serial.println(Time/1000);
                Serial.print(" segundos");
                Serial.print("Para salir pulse L");
                
                break;
               
                
                
              }
              break;
                
                
                
           
            }
            if(Serial.available() > 0)
            {
              char Exit = Serial.read();
              if (Exit == 'L' || Exit == 'l') 
                {
                   states = TaskStates::CAMERA;
                }
            }
            

             
        }
         
            break;
      }
      case TaskStates::CAMERA:
      {
        
          uint32_t tiempo = millis();
          if((tiempo - lastime) >= 1000)
          {
            lastime = tiempo;
            if(Time > 0)
            {
               Time -= 1000;
            Serial.print("Tiempo restante");
            Serial.println(Time/1000);
            }
            else
            {
              Serial.print("Que gay");
              states = TaskStates::REACTION_NUCLEAR;
            }
          }
          if(Serial.available() > 0)
          {
            char acces = Serial.read();
            if(acces == 'c' || acces == 'C')
            {
              states = TaskStates::ACCESS;
            }
          }
           
            
          
          
        
        break;
      }
      case TaskStates::REACTION_NUCLEAR:
      {

        break;
      }
      case TaskStates::ACCESS:
      {
        
        break;
      }
    
    
    }
    
  
}
void setup() {
  // put your setup code here, to run once:
  mision();
}

void loop() {
  // put your main code here, to run repeatedly:
  mision();
}
