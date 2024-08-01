void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_ONE_SECOND,
        WAIT_TWO_SECONDS,
        WAIT_THREE_SECONDS
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan su valor entre llamadas a task1)
    static uint32_t lastTime = 0;

    // Constantes
    constexpr uint32_t ONE_SECOND = 1000;
    constexpr uint32_t TWO_SECONDS = 2000;
    constexpr uint32_t THREE_SECONDS = 3000;

    // MÁQUINA de ESTADOS
    switch (task1State)
    {
    case Task1States::INIT:
    {
        // Acciones:
        Serial.begin(115200);

        // Garantiza los valores iniciales para el siguiente estado.
        lastTime = millis();
        task1State = Task1States::WAIT_ONE_SECOND;

        break;
    }
    case Task1States::WAIT_ONE_SECOND:
    {
        uint32_t currentTime = millis();

        // Evento
        if ((currentTime - lastTime) >= ONE_SECOND)
        {
            // Acciones:
            lastTime = currentTime;
            Serial.print("1 segundo ha pasado\n");
            task1State = Task1States::WAIT_TWO_SECONDS;
        }
        break;
    }
    case Task1States::WAIT_TWO_SECONDS:
    {
        uint32_t currentTime = millis();

        // Evento
        if ((currentTime - lastTime) >= ONE_SECOND)
        {
            // Acciones:
            lastTime = currentTime;
            Serial.print("2 segundos han pasado\n");
            task1State = Task1States::WAIT_THREE_SECONDS;
        }
        break;
    }
    case Task1States::WAIT_THREE_SECONDS:
    {
        uint32_t currentTime = millis();

        // Evento
        if ((currentTime - lastTime) >= ONE_SECOND)
        {
            // Acciones:
            lastTime = currentTime;
            Serial.print("3 segundos han pasado\n");
            task1State = Task1States::INIT; // Volver a comenzar
        }
        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
