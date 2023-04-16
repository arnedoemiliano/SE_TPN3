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

#ifndef ALUMNO_H
#define ALUMNO_H

/** \brief Declaraciones públicas del módulo Alumnos
 **
 ** \addtogroup alumno Alumnos
 ** \brief Modulo para gestión de alumnos
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
#include <stdint.h>

/**
 * @brief Define el tamaño de los campos de texto de la estructura
 *
 * Este paramatro define el tamaño de los campos de texto "nombre" y "apellido" de la estructura
 * alumno @ref(alumno) "Estructura alumno"
 */
#define FIELD_SIZE 30
/* === Public data type declarations =========================================================== */

//! Estructura para almacenar los datos de un alumno
typedef struct {
    char nombre[FIELD_SIZE];   //!< Almacena el nombre del alumno
    char apellido[FIELD_SIZE]; //!< Almacena el apellido del alumno
    uint32_t documento;        //!< Almacena el documento del alumno
} alumno;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
// Uso const porque no voy a modificar la variable alumno (la estructura alumno es la constante)

/**
 * @brief Funcion para serializar los datos de un alumno
 *
 * @param alumno_s //!<
 * @param cadena_final
 * @param bytes_disp
 * @return int
 */
int Serializar(const alumno * alumno_s, char * cadena_final, int bytes_disp);
/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */
