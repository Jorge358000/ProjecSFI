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
                    Debug.Log("Entra");
                        mensaje = System.Text.Encoding.ASCII.GetBytes("read\n"); 
                        Enviar();
                        _serialPort.Read(buffer, 0, 20);
                        Debug.Log("Receive Data: " + System.Text.Encoding.ASCII.GetString(buffer));
                        comando = ""; 
                        break;

                       
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
        comando = "read";
    }

   
}
