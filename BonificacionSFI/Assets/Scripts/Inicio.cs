using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using TMPro;
using UnityEngine.UI;

public class Inicio : MonoBehaviour
{
    private SerialPort _serialPort = new SerialPort();
    private byte[] buffer = new byte[32];
    public Text responseText;
    // Start is called before the first frame update
    void Start()
    {
        _serialPort.PortName = "COM3";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.Open();

    }

    // Update is called once per frame
    void Update()
    {

    }
    private void OnApplicationQuit()
    {
        if (_serialPort.IsOpen)
        {
            _serialPort.Close();
        }

    }

    public void Enviar(string mensaje)
    {
        if (_serialPort.IsOpen)
        {
            _serialPort.WriteLine(mensaje);  
            Debug.Log("Command sent: " + mensaje);
        }
    }
}
