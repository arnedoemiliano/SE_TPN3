/************************************************************************************************
 Copyright (c) 2023, Emiliano Arnedo <emiarnedo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Implementación del módulo Alumnos
 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para gestión de alumnos
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "alumno.h"
#include "stdio.h"
#include "stdbool.h"

/* === Macros definitions ====================================================================== */
#define FIELD_SIZE       30
#define CREACION_OBJETOS dinamica // "dinamica" o cualquier otra cosa para creacion estatica
#define MAX_OBJ          50

/* === Private data type declarations ========================================================== */
struct alumno_s {
    char apellido[FIELD_SIZE];
    char nombre[FIELD_SIZE];
    uint32_t documento;
    bool ocupado // En creacion estatica para saber los lugares disponibles en memoria
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static int SerializarTexto(const char * campo, const char * valor, char * cadena_final,
                           int disponibles);

static int SerializarNumero(const char * campo, const int valor, char * cadena_final,
                            int disponibles);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int SerializarTexto(const char * campo, const char * valor, char * cadena_final, int disponibles) {

    return snprintf(cadena_final, disponibles, "\"%s\":\"%s\",", campo, valor);
}

int SerializarNumero(const char * campo, const int valor, char * cadena_final, int disponibles) {

    return snprintf(cadena_final, disponibles, "\"%s\":\"%d\",", campo, valor);
}

/* === Public function implementation ========================================================== */
int Serializar(const alumno * alumno_s, char * cadena_final, int bytes_disp) {

    /* @var disponibles Almacena la cantidad de bytes disponibles en la cadenadasdopsakdpo **/
    int disponibles = bytes_disp;
    int resultado;
    cadena_final[0] = '{';
    cadena_final++;
    disponibles--;

    // Para acceder a los miembros de un puntero que apunta a una estructura se usa "->"
    // SerializarCampoDeTexto devuelve la cantidad de bytes que escribió y un 0 si hubo error.
    resultado = SerializarTexto("nombre", alumno_s->nombre, cadena_final, disponibles);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena_final += resultado;
        resultado = SerializarTexto("apellido", alumno_s->apellido, cadena_final, disponibles);
    }
    if (resultado > 0) {
        disponibles -= resultado;
        cadena_final += resultado;
        resultado = SerializarNumero("documento", alumno_s->documento, cadena_final, disponibles);
    }
    if (resultado > 0) {

        cadena_final += resultado;
        *(cadena_final - 1) = '}';
        resultado = bytes_disp - disponibles;

        return resultado;
    }

    return -1;
}

// Creacion ESTATICA: en tiempo de COMPILACION
// Creacion DINAMICA: en tiempo de EJECUCION

// Lo visto en clase es creacion DINAMICA de objetos

alumno_t CrearAlumno(char * apellido, char * nombre, uint32_t documento) {
    // En compilacion el compilador decide cual bloque de codigo se ejecuta
    alumno_t resultado; // Puntero a la nueva estructura que devuelvo
#if CREACION_OBJETOS == dinamica

    resultado = malloc(sizeof(struct alumno_s));
    strcpy(resultado->apellido, apellido);
    strcpy(resultado->nombre, nombre);
    resultado->documento = documento;

#else // Creacion estatica de objetos

    // Las variables instancias son locales, solo se ven dentro de la funcion. Al ser convertidas
    // en estaticas guardan su valor entre llamadas. Basicamente, solo en la primera llamada se
    // reserva la memoria y ya no se sobrescriben o borran
    static struct alumno_s instancias[MAX_OBJ];
    // AQUI VA UN WHILE EN DONDE SE RECORRA INSTANCIAS PARA VER CUAL HUECO DE ALUMNO SE PUEDE LLENAR
    // USANDO LA BANDERA "bool ocupado"
    uint8_t i = 0;
    while (instancias[i].ocupado == 0) {

        i++;
        if (i > MAX_OBJ) {
            return NULL; // Verificar en el programa principal que el puntero != NULL
        }
    }
    resultado = &instancias[i];
    strcpy(instancias[i].apellido, apellido);
    strcpy(instancias[i].nombre, nombre);
    instancias[i].documento = documento;
    // Creo que se usa "." en vez de "->" porque la estructura a la que accedo la tengo definida en
    // la propia funcion (en un arreglo de estructuras). En el caso anterior, no tenia acceso a la
    // estructura, solamente al puntero de la estructura. Preguntar.

#endif

    return resultado;
}

int GetCompleto(alumno_t alumno, char * cadena, int espacio) {
}

uint32_t GetDocumento(alumno_t alumno) {
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
