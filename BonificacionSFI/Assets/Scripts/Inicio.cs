using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Inicio : MonoBehaviour
{

    public TextMeshProUGUI myText;
    private static int counter = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        myText.text = counter.ToString();
        counter++;
    }
}
