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

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */
/**
 * @brief Funcion para serializar campo de texto. Es llamada por la funcion Serializar.
 *
 * @param campo
 * @param valor
 * @param cadena_final
 * @param disponibles
 * @return int
 */
static int SerializarTexto(const char * campo, const char * valor, char * cadena_final,
                           int disponibles);
/**
 * @brief Funcion para serializar campo numerico. Es llamada por la funcion Serializar.
 *
 * @param campo
 * @param valor
 * @param cadena_final
 * @param disponibles
 * @return int
 */
static int SerializarNumero(const char * campo, const int valor, char * cadena_final,
                            int disponibles);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int SerializarTexto(const char * campo, const char * valor, char * cadena_final, int disponibles) {
    // en vez de disponibles le envia bytes_disp

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
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
