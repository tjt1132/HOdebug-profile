### 1. Identifiquen los errores que devuelven (¡si devuelven alguno!) los ejecutables.
- small.x: ningun error.
- bigx: Segmentacion fault (core dumped)

### 2. Identifiquen los errores que devuelven (¡si devuelven alguno!) los ejecutables con `ulimit -s unlimited`.

#### a. ¿Devuelven el mismo error que antes?
No, ninguno devuelve error.

#### b. Averigüen qué hicieron al ejecutar la sentencia ulimit -s unlimited. Algunas pistas son: abran otra terminal distinta y fíjense si vuelve al mismo error, fíjense la diferencia entre ulimit -a antes y después de ejecutar ulimit -s unlimited, googleen, etcétera.
`ulimit` limita al usuarsio en ciertas characteristicas del sistema, como el stack size (-s). Entonces al ejecutar `ulimit -s unlimited` estoy permitiendo que el stack de un programa ejecutado sea de tamanio ililimutado.

#### c. La "solución" anterior, ¿es una solución en el sentido de debugging?
Para nada. Lo unico que causa es ofuscar el bug. Me imagino que es una de las razones porque el stack size de un programa es limitado.
