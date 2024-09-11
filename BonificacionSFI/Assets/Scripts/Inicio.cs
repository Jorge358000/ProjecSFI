using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Inicio : MonoBehaviour
{
    private SerialPort _serialPort = new SerialPort();
    private string comando = ""; // Para controlar qué comando se envía
    static byte[] mensaje;
    private byte[] buffer = new byte[32];

    void Start()
    {
        _serialPort.PortName = "COM3";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.ReadTimeout = 1000; // Agregando un timeout para evitar bloqueo indefinido
        _serialPort.Open();
    }

    void Update()
    {
        switch (comando)
        {
            case "read":
                StartCoroutine(EnviarYLeer("read\n"));
                comando = "";
                break;

            case "outON":
                StartCoroutine(EnviarYLeer("outON\n"));
                comando = "";
                break;

            case "outOFF":
                StartCoroutine(EnviarYLeer("outOFF\n"));
                comando = "";
                break;
        }
    }

    private IEnumerator EnviarYLeer(string mensajeAEnviar)
    {
        // Enviar el mensaje
        mensaje = System.Text.Encoding.ASCII.GetBytes(mensajeAEnviar);
        Enviar();

        // Esperar un poco para asegurarse de que la respuesta se reciba
        yield return new WaitForSeconds(0.1f); // Ajusta el tiempo si es necesario

        // Leer la respuesta
        if (_serialPort.IsOpen)
        {
            int bytesRead = _serialPort.Read(buffer, 0, buffer.Length);
            string receivedData = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Debug.Log("Receive Data: " + receivedData);
        }
    }

    public void Enviar()
    {
        if (_serialPort.IsOpen)
        {
            _serialPort.Write(mensaje, 0, mensaje.Length);
            Debug.Log("Mensaje enviado: " + System.Text.Encoding.ASCII.GetString(mensaje));
        }
    }

    public void read()
    {
        Debug.ClearDeveloperConsole();
        comando = "read";
    }

    public void outON()
    {
        Debug.ClearDeveloperConsole();
        comando = "outON";
    }

    public void outOFF()
    {
        Debug.ClearDeveloperConsole();
        comando = "outOFF";
    }
}
