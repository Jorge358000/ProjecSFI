# Experimento ejercicio 3
## ¿Qué se vio?
Se pudo notar que en el momento en el que se aumento el valor a 500 en vez de 100, se pudo observar como la velocidad del LED verde del Rapsberry disminuyo.
Ya no iba tan rápido como iba al poner el valor en 100.
# Experimento Ejercicio 5
## Documentación
En la documentación nos ofrecen una gran variedad de información sobre el Raspberry; La página de Arduino nos fácilita información acerca del programa y su software, el como nos fácilita el uso de microcontroladores para cualquier usuario.
Otro sitio nos da más información detallada sobre este microcontrolador, a diferencia de la de Arduino que da general para todos, está da especificamente para el microcontrolador Raspberry, dónde nos explican más adetalle como configurar este microcontrolador, algunos ejemplos de código, algunas ayuda, detalles de su estructura, entre otras cosas importantes y de útilidad para el Raspberry.

# Experimento ejercicio 6
## ¿Qué hace el código?
El código básicamente lo que hace es guardar en cada variable el tiempo que transcurre, para luego registrarlo en la pantalla del computador, la Raspberry cada segundo está refrescando la pantalla con el siguiente valor.
## Pudiste ver este mensaje: Serial.print("Task1States::WAIT_TIMEOUT\n");. ¿Por qué crees que ocurre esto?
No, no pude ver el mensaje hasta que lo cambie de caso, lo que ocurre es que al estar en el caso iniciar del enum, y pasar rápidamente al segundo caso de wait_timeout, a no ser que seas muy rápido para abrir el monitor no podrás verlo nunca, debido a que una vez entra en este modo de wait_timeout, no sale,  y ya no se podría ver el mensaje
## ¿Cuántas veces se ejecuta el código en el case Task1States::INIT?
Una única vez al iniciar el código, inicia el task1 en init, pero rápidamente en el caso uno pasa a wait_timeout, por lo que no vuelve a entrar a este lado del código, y se queda en un bucle.
# Ejercicio 8
## Estados.
Consta de cuatro estados, el iniciarl, el de un segundo, el de dos y el de tres.
## Eventos
los tres realmente tienen el mismo evento, esperan que pase el segundo para lanzar el mensaje y cambiar al siguiente estado
## Acciones
Las acciones son escribir el mensaje y cambiar el estado
# Experimento ejercicio 11
## ¿Por qué enviaste la letra con el botón send? ¿Qué evento verifica si ha llegado algo por el puerto serial? 
Lo que ocurre es que en el espacio donde introducimos una tecla el detecta el valor de la tecla, busca el valor y ese valor se lo da a serial.avaliable, si hay alguna tecla presionada que tiene un valor, enviará el mensaje, si no hay nada (los espacios no cuentan como un caracter) no mandará nada
## Analiza los números que se ven debajo de las letras. Nota que luego de la r, abajo, hay un número. ¿Qué es ese número? ¿Cómo se relacionan?
Lo que ocurre con estos números, es que son el valor que se les da, este valor se transforma a un número y que a si mismo a un lenguaje computador para asignarselo, en este caso, la r está con el 72, que pertenece a Hx.
## ¿Qué es el 0a al final del mensaje y para qué crees que sirva?
Ese representa el caracter hacía la nueva línea, es decir, que hará un salto de línia hacía el siguiente renglón

# Experimento Ejercicio 12
## ¿Cómo se declara e inicializa un puntero?
uint32_t *pvar = &var;
Se declará de está manera, siendo pvar el que apunta a la dirección de var.
## ¿Cómo se obtiene la dirección de una variable?
La dirección de una variable es dada de forma automatica por el computador, y con los punteros se puede acceder a lo que hay almacenado en está dirección y el poder manipularlo.
Para poder concerlo se usa el &; en el caso de C++, se usa para conocer la dirección de la memoria RAM.
## ¿Cómo se puede leer el contenido de una variable por medio de un puntero y cómo podemos modificarlo?
Con el puntero, escribiendo el puntero en el monitor serial.
Y par la parte de modificarlo, se iguala el puntero al nuevo valor que se dará a la dirección asignada.

# Experimento Ejercicio 15
Se pueden observar mucho en este código, sobretodo el uso del static, y su vital importancia, el como podemos mantener los valores de la variables por todo el código con él, además de que, también se puede observar como se puede revisar todo el contenido de los arreglos por medio de los punteros, y como revisan lo que hay en esa dirección, en esa parte de la array, también se observa como al pasar el nombre de un Array lo toma desde el valor 0 por defecto (Esto claro haciendolo sin poner valores ni nada, solo el nombre del Array) y por último también nos habla de la conversión de ASCII a número, usando sus valroes en ASCII y el como podemos hacer su conversión.
# Ejercicio 16
## ¿Qué pasa cuando ejecuto Serial.avaliable()?
Este nos da el número de bytes que están disponibles para leer en el buffer en el buffer
## Serial.read()
Lee los bytes que hay en el buffer receptor y devuelve su valor, si está vcacio, devuelve -1, que esto avisa que no hay datos disponibles a leer.
Así mismo este solo lee un valor por cada llamada, y ya cada byte que quieras leer, deberás llamarlo varias veces, algunas formas para hacerlo, es con bucles, para no repetir código una y otra vez, puedes utilizar bucles.
EN un caso de no leer los datos, el bufeer los guardará hasta ser leídos o en el otro extremo, se llenará y no guardará más datos.


Bonificación trabajo final:
##Diagrama de estados:

![image](https://github.com/user-attachments/assets/14becb48-c120-44a9-821c-985f95859d87)

## Proceso de construcción del programa Y explicación:
-Para la construcción de este programa lo que se hizo principalmente fue seguir el diagrama en el orden establecido, iniciando por la parte de configuración del tiempo, para esto primero se establecieron los estados del programa por los que iba a ir pasando el programa.
Una vez está realizado los estados se inicializan y declaran las varibles que serán estaticas y que mantendran su valor al pasar el tiempo de ejecución del código, estás variables las necesitamos para usarlas en los respectivos eventos.
ya luego el switch se usa para generar las condiciones (Entradas) para pasar de evento a evento, como por ejemplo, pulsar las teclas S, B y L, o el digitar la contraseña.
A medida que haciamos el código, tuvimos algunos problemas de interpretación, e hicimos cosas que no se debían, por ejemplo, el tiempo aumentaba en un seg cada que se pulsaba una tecla, nosotros hicimos primero que el usuario pusiera cuánto tiempo iba a poner, lo cual no era lo indicado, ya luego si pusimos, que al pulsar cada tecla, el tiempo solo aumentará en un segundo o disminuyeraá, sin pasar los límites de 1 seg hasta 40 seg.
En este método de tiempo una vez hace la condición por primera vez de pulsar S o B, el espera al siguiente valor, esto pasa porque solo entra una vez al if de S, B o L, y luego vuelve al inicio del evento para esperar la siguiente acción.
Al pulsar L, pensamos como podríamos hacer una cuenta regresiva, y decidimos usar la misma que habíamos usado en el trayecto de actividades, la cual es toamr el tiempo actual en ejecución, restarlo con el anterior, verificar que esto sea mayor a uno. guardar el tiempo actual en el anterior, hacer la resta y repetir este proceso, eso lo hacemos con el fin de que el código viaja a velocidades muy grandes, entonces para que si o si espere un segundo hacemos esto.
Una vez aquí ocurre dos consas al mismo tiempo, ya que es importante que pasen, y es que al mismo tiempo que ocurre esto, nosotros tenemos abajo otro condicional que espera a que escribas la contraseña, para hacer esto nos costo un poco saber como hacerlo, ya que solo con un string no funciona, sin embargo, descubrimos que como usamos char, hacer un bucle, un bucle el cual va agregando el caracter char uno a uno al string hasta que ya no hallan más valores, una vez ocurre eso, el verifica el string del código con la contraseña guardada, y si es correcta saltaria el mensaje y termina el código, ahora, si se pone una contraseña incorrecta y además se acaba el tiempo, el código salta a su parte negativa de la reacción, y esperaría dos segundos para volver a iniciar.







