static void printVar(uint32_t value, uint32_t value2)
{
    Serial.print("var content 1: ");
    Serial.print(value);
    Serial.print('\n');
    Serial.print("var content 2: ");
    Serial.print(value2);
    Serial.print('\n');
}

static void Intercambio(uint32_t *pvalor1, uint32_t *pvalor2)
{
    uint32_t cambio = *pvalor1;  // Cambia esto a uint32_t en lugar de uint32_t*
    *pvalor1 = *pvalor2;
    *pvalor2 = cambio;
}

void task1()
{
    enum class Task1States {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        if (Serial.available() > 0)
        {
            Serial.read();
            uint32_t var = 0;
            uint32_t *pvar = &var;
            uint32_t var2 = 3;
            uint32_t *pvar2 = &var2;

            printVar(*pvar, *pvar2);
            Intercambio(pvar, pvar2);  // Cambiado aquí
            printVar(*pvar, *pvar2);
        }
        break;
    }

    default:
    {
        break;
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
