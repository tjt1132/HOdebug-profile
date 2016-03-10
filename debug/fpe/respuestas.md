### 1. Qué función requiere agregar -DTRAPFPE?
La fucnion que se agrega con TRAPFPE es `et_fpe_x87_sse_();`

### 2. Cómo pueden hacer que el programa linkee adecuadamente?
Habia que corregir el codigo en unos cuantos lugares:

test_fpe1.c:
- `#include "fpe_x87_sse/fpe_x87_sse.h"` -> `#include "fpe_x87_sse/fpe_x87_sse.h"`
- `gcc fpe_x87_sse/fpe_x87_sse.o test_fpe1_trap.o -lm -o test_fpe1_trap.e`

test_fpe2.c:
- `#include "fpe_x87_sse/fpe_x87_sse.h"` -> `#include "fpe_x87_sse/fpe_x87_sse.h"`
- Sin -DTRAPFPE `gcc test_fpe2.o -o test_fpe2.e`
- Con -DTRAPFPE `gcc fpe_x87_sse/fpe_x87_sse.o test_fpe2_trap.o -lm -o test_fpe2_trap.e`

test_fpe3.c:
- agrege `#include <math.h>`
- `#include "fpe_x87_sse/fpe_x87_sse.h"` -> `#include "fpe_x87_sse/fpe_x87_sse.h"`
- `printf("c = %f \n", tmp);` -> `printf("c = %f \n", c);`
- Sin -DTRAPFPE `gcc test_fpe3.o -lm -o test_fpe3.e`
- Con -DTRAPFPE `gcc fpe_x87_sse/fpe_x87_sse.o test_fpe3_trap.o -lm -o test_fpe3_trap.e`

### 3. Qué hace agregar la opción -DTRAPFPE al compilar?
La flag -D para el `gcc` define una macro para el preprocesador. En este caso la macro para definir es TRAPFPE.

### 4. En qué se diferencian los mensajes de salida con y sin esa opción?
Con TRAPFPE: Cuando se divide por 0, el programa mestra al variable c con valor inf (undefined).
Con TRAPFPE: Cuando lo mismo, el programa detecta una 'Floating point exception' y termina.
