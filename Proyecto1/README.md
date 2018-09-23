En este repositorio se encuentran todos los archivos creados
para el Proyecto 1 del curso:

IE-0724 Laboratorio de Programación y Microcomputadores

Estudiante: Alonso Espinoza Barboza
Carné: B22356

Para ejecutar el programa deberá contar con el estándar
C++ 14 instalado, además de un compilador de C++ y la herramienta "Make"

Las opciones a ejecutar son:

    1. Correr el programa principal, el cual creará los árboles
       con base en los datos dados por los archivos de la carpeta
       misc/inputs.
       En esta corrida se guardarán los tiempos de ejecución de la
       creación de cada árbol en el archivo "misc/outputs/running_times.txt"
       y los nodos mayor y menor de cada árbol en el archivo
       "misc/outputs/max_and_min_id.txt"
       Para hacer esto:
       1- Colóquese, con la terminal, en la carpeta "build"
       2- Ejecute el comando: $ make
       3- Ejecute el comando: $ make run

    2. Correr los test creados para probar algunas partes del código.
       En este caso, al correr el programa se desplegará un menú con Las
       opciones disponibles. Sea cuidadoso al momento de seleccionar una opción,
       al programador le caen mal los errores tontos y se lo hará saber.
       Para hacer esto:
       1- Colóquese, con la terminal, en la carpeta "build"
       2- Ejecute el comando: $ make unittest
       3- Ejecute el comando: $ make run_unittest

Una estructura general de las carpetas y archivos presentes en este repositorio:

    1. build
        Contiene el Makefile necesario para la ejecución automática del programa
    2. include
        Posee los encabezados de las clases AVL y Node, utilizadas en el Proyecto
        - AVL.hpp
        - Node.hpp
    3. misc
        Archivos miscelaneos de entrada y salida del programa principal
        - inputs
            * lista_10.txt
            * lista_100.txt
            * lista_1000.txt
            * lista_5000.txt
            * lista_10000.txt
        - outputs
            * max_and_min_id.txt
            * running_times.txt
    4. src
        Código fuente de las clases y del programa principal
        - AVL.cpp
        - main.cpp
        - Node.cpp
    5. test
        Código fuente del programa de pruebas
        -mainTest.cpp
    6. README.md
