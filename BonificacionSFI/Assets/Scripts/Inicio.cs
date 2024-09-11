using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using TMPro; // Importar TextMeshPro

public class Inicio : MonoBehaviour
{
    private SerialPort _serialPort = new SerialPort();
    private string comando = "";
    static byte[] mensaje;
    private byte[] buffer = new byte[32];

    // Variable para el objeto TextMeshPro
    public TextMeshProUGUI estadoText; // Asignar en el Inspector

    void Start()
    {
        _serialPort.PortName = "COM3";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.ReadTimeout = 1000;
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
        mensaje = System.Text.Encoding.ASCII.GetBytes(mensajeAEnviar);
        Enviar();

        yield return new WaitForSeconds(0.1f);

        if (_serialPort.IsOpen)
        {
            int bytesRead = _serialPort.Read(buffer, 0, buffer.Length);
            string receivedData = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            // Actualizar el texto con los datos recibidos
            estadoText.text = "Receive Data: " + receivedData; // Actualiza el texto
        }
    }

    public void Enviar()
    {
        if (_serialPort.IsOpen)
        {
            _serialPort.Write(mensaje, 0, mensaje.Length);
        }
    }

    public void read()
    {
        comando = "read";
    }

    public void outON()
    {
        comando = "outON";
    }

    public void outOFF()
    {
        comando = "outOFF";
    }
}
