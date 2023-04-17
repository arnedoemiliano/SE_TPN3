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

/** \brief Segundo trabajo práctico
 **
 ** \addtogroup tp2 TPN2
 ** \brief Segundo trabajo práctico
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

    /*    ***Creacion de una variable "alumno"***     */
    static const alumno alumno_a = {
        .nombre = "Emiliano",
        .apellido = "Arnedo",
        .documento = 38745528,
    };

    // NOTA: la variable local de main() "alumno_a" está en RAM y como es una constante debería
    // estar en FLASH para no desperdiciar memoria. nota: Si la variable es global, usando "const"
    // se almacena la variable en FLASH en la direccion del bloque de constantes.
    // nota: Si la variable es local, usando "static const" la variable pasa a ser global PRIVADA y
    // va a FLASH. Si la variable es la estructura alumno, entonces debo inicializar sus campos
    // porque ya no se podrá modificar.

    /** @var cadena_final[128] variable donde se almacenará la cadena resultante */
    // No documenta el main
    char cadena_final[128];

    if (Serializar(&alumno_a, cadena_final, sizeof(cadena_final)) >= 0) {

        printf("Alumno: %s\n", cadena_final);
    } else {

        printf("Error");
    }

    return 0;
}

/* === End of documentation==================================================================== */

/** @} End of module definition for doxygen */
