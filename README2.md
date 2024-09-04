## Ejercicio 1
# ¿Por qué es importante considerar las propiedades PortName y BaudRate?
- Con *PortName* le damos el nombre del puerto, es decir, el puerto dónde está el microcontrolador, al usar "COM3", le decimos el nombre del puerto en el que está el controlador, y 
el *BaudRate* se encarga de tomar la velocidad del monitor serial, la cual debe ser la misma con la que se inicializa el microcontrolador, en este caso, 115200.

# ¿Qué relación tienen las propiedades anteriores con el controlador?
- Pues como se menciono con anterioridad, el *PortName* es el nombre del puerto, aquí en el arduino se le asigna un puerto automaticamente, mientras que la velocidad, nosotros se la
establecemeos en el setup, aclaro, ambas deben tener la misma velocidad.

## Ejercicio 2
``` C#
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Serial : MonoBehaviour
{
	private SerialPort _serialPort =new SerialPort();
	private byte[] buffer =new byte[32];

	public TextMeshProUGUI myText;

	private static int counter = 0;

	void Start()
    {
        _serialPort.PortName = "COM3";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable =true;
        _serialPort.Open();
        Debug.Log("Open Serial Port");
    }

void Update()
    {
        myText.text = counter.ToString();
        counter++;

				if (Input.GetKeyDown(KeyCode.A))
        {
            byte[] data = {0x31};// or byte[] data = {'1'};            
						_serialPort.Write(data,0,1);
            int numData = _serialPort.Read(buffer, 0, 20);
            Debug.Log(System.Text.Encoding.ASCII.GetString(buffer));
            Debug.Log("Bytes received: " + numData.ToString());
        }
    }
}
```
Este código hace algo similar al anterior, pero, este hace una cuenta excesivamente rápida del tiempo que trasncurre en el Update.

```
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Serial : MonoBehaviour
{
		private SerialPort _serialPort =new SerialPort();
		private byte[] buffer =new byte[32];

		public TextMeshProUGUI myText;

		private static int counter = 0;

		void Start()
		{
		    _serialPort.PortName = "COM3";
		    _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable =true;
        _serialPort.Open();
        Debug.Log("Open Serial Port");
		}

		void Update()
		{
        myText.text = counter.ToString();
        counter++;

				if (Input.GetKeyDown(KeyCode.A))
				{
            byte[] data = {0x31};// or byte[] data = {'1'};
            _serialPort.Write(data,0,1);
        }
				if (_serialPort.BytesToRead > 0)
			  {
	          int numData = _serialPort.Read(buffer, 0, 20);
            Debug.Log(System.Text.Encoding.ASCII.GetString(buffer));
            Debug.Log("Bytes received: " + numData.ToString());
        }
		}
```
Este código funciona y además, a ver, el código de por si cuando lee el buffer, siempre trata de leer hasta el máximo que se le indiquen, en este caso, es 20 bytes, el tratará de leer 
los 20 bytes, si se da el caso en el que no tenemos estos 20 bytes y tenemos menos, el pondrá el valor, es decir, si tenemos solo 15, el pondrá 15, si tenemos 11, el pondrá 11, y así
sucesivamente.
ya para verificar el tema del buffer depedne mucho de la persona, de si quiere empezar desde 0 o no, o si quiere poner un límtie de 20 o no, depende mucho de la persona que desarrolle
el programa.

## Ejercicio 3

# Analicemos el asunto. Cuando preguntas _serialPort.BytesToRead > 0 lo que puedes asegurar es que al MENOS tienes un byte del mensaje, pero no puedes saber si tienes todos los bytes que lo componen. Una idea para resolver esto, sería hacer que todos los mensajes tengan el mismo tamaño. De esta manera solo tendrías que preguntar _serialPort.BytesToRead > SIZE, donde SIZE sería el tamaño fijo; sin embargo, esto le resta flexibilidad al protocolo de comunicación. Nota que esto mismo ocurre en el caso del programa del controlador con Serial.available() > 0. ¿Cómo podrías solucionar este problema?

-Bueno, una forma para verificar todo lo que hay para leer sería usando delimitadores, hacer que el programa lea los bytes que hay para leer y una vez los lea todos, que verifique el mensaje y mande todos los bytes que pueda, algo así 
``` C#
switch (taskState)
    {
        case TaskState.WAIT_EVENTS:
            if (_serialPort.BytesToRead > 0)
            {
                int numData = _serialPort.Read(buffer, 0, _serialPort.BytesToRead);
                incomingMessage += System.Text.Encoding.ASCII.GetString(buffer, 0, numData);

                // Check for start and end delimiters
                int startIndex = incomingMessage.IndexOf('<');
                int endIndex = incomingMessage.IndexOf('>');

                if (startIndex != -1 && endIndex != -1 && endIndex > startIndex)
                {
                    string completeMessage = incomingMessage.Substring(startIndex + 1, endIndex - startIndex - 1);
                    Debug.Log("Received Complete Message: " + completeMessage);
                    incomingMessage = incomingMessage.Substring(endIndex + 1); // Remove the processed part
                }
            }
            break;
    }
```
Dónde se usa el indexOf para encontrar el valor mínimo y el valor final, y se compara con el "-1", que este valor se lo devuelve el index cuando no hay nada en esa parte.

## Ejercicio 4
-Este cuarto ejercicio nos muestra un uso sencillo de los leds, el como el unity al pusar cierta tecla, lee el valor de que hay en el
buffer y lo pasa a un string para mostrarlo en el debug, y según la tecla que pulsemos hará la acción
A para encender, S para apagar y R para mostrar el estado de los leds

