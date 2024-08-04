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
