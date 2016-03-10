### add_array_segfault.c

Este codigo tira segmentation fault porque los punteros a* y b* fueron declarados pero no fueron instanciados.

### add_array_dynamic.c y add_array_static.c

Estos dos codigo, aunque dieron el resultado correcto y por ende encubrieron el bug, tienen un error en el `for` loop de la funccion add_array. El termino de terminacion del loop es incorrecto (es `n + 1` y tendria que se simplemente `n`).

## add_array_nobugs
No tiene bugs.
