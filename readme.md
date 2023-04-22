# Laboratorio de Microprocesadores: Trabajo Práctico N°3

Serializador de objetos en formato JSON usando el patron de programacion ADT.

## Instalación

Usar el programa [make](https://www.gnu.org/software/make/) para compilar y generar en la carpeta <build/bin> el ejecutable 'app.elf'. El comando generará la carpeta build en caso de que no existiera.  
1. Clonar el repositorio desde GitHub:

    ```bash
    git clone https://github.com/arnedoemiliano/SE_TPN3.git
    ```
2. Acceder a la ubicacion del proyecto:
     ```bash
    cd SE_TPN3
    ```
3. Acceder a la ubicacion del proyecto:
     ```go
    make
    ```
4. Ejecutar el archivo '.elf' generado:
     ```bash
    ./build/bin/app.elf
    ```


## Modo de uso

Se utiliza compilacion condicional para la creacion de objetos de forma dinamica o estatica. En el #define ubicado en el modulo 'alumno.c' cambiar a cualquier otro valor para generar los objetos de forma estática.
```c
#define CREACION_OBJETOS dinamica
```


## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Créditos

Este proyecto forma parte del trabajo práctico N°3 de la asignatura Laboratorio de Microprocesadores de la [Facultad de Ciencias Exactas y Tecnología](https://www.facet.unt.edu.ar/) de la Universidad Nacional de Tucumán.


