/************************************************************************************************
Copyright (c) 2023, Emiliano Arnedo <emiarnedo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions: The above copyright notice and this
permission notice shall be included in all copies or substantial portions of the
Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO
EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Tercer trabajo práctico
 **
 ** \addtogroup tp3 TPN3
 ** \brief Tercer trabajo practico
 ** @{ */

/* === Headers files inclusions
 * =============================================================== */

#include "alumno.h"
#include "stdio.h"

/* === Macros definitions====================================================================== */

/* === Private data type declarations========================================================== */

/* === Private variable declarations=========================================================== */

/* === Private function declarations=========================================================== */

/* === Public variable definitions============================================================= */

/* === Private variable definitions============================================================ */

/* === Private function implementation========================================================= */

/* === Public function implementation========================================================== */
int main(void) {

    char cadena_final[128];
    alumno_t puntero_alumno = CrearAlumno("Emiliano", "Arnedo", 38745528);
    if (puntero_alumno != NULL) {

        if (Serializar(puntero_alumno, cadena_final, sizeof(cadena_final)) >= 0) {

            printf("Alumno: %s\n", cadena_final);
        } else {

            printf("Error");
        }
    } else {

        printf("Error");
    }
    return 0;
}

/* === End of documentation====================================================================
 */

/** @} End of module definition for doxygen */
