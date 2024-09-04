## Ejercicio 1
# ¿Por qué es importante considerar las propiedades PortName y BaudRate?
- Con *PortName* le damos el nombre del puerto, es decir, el puerto dónde está el microcontrolador, al usar "COM3", le decimos el nombre del puerto en el que está el controlador, y 
el *BaudRate* se encarga de tomar la velocidad del monitor serial, la cual debe ser la misma con la que se inicializa el microcontrolador, en este caso, 115200.

# ¿Qué relación tienen las propiedades anteriores con el controlador?
- Pues como se menciono con anterioridad, el *PortName* es el nombre del puerto, aquí en el arduino se le asigna un puerto automaticamente, mientras que la velocidad, nosotros se la
establecemeos en el setup, aclaro, ambas deben tener la misma velocidad.
