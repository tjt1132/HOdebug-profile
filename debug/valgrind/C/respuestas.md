#### 1. Open an other shell and check the memory consumption.
La memoria usada por el programa gradualmente incrementaba (un memory Leak).

#### 2. Run the debug using valgrind (possibly at reduced SIZE).
tjt1132@OMNIMOTUS:~/Wd/HOdebug-profile/debug/valgrind/C$ valgrind --leak-check=full --track-origins=yes ./a.out
==30090== Memcheck, a memory error detector
==30090== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==30090== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==30090== Command: ./a.out
==30090==
^C==30090==
==30090== HEAP SUMMARY:
==30090==     in use at exit: 36,000,000 bytes in 9 blocks
==30090==   total heap usage: 9 allocs, 0 frees, 36,000,000 bytes allocated
==30090==
==30090== 4,000,000 bytes in 1 blocks are possibly lost in loss record 3 of 4
==30090==    at 0x4C2AB80: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30090==    by 0x400785: mat_Tmat_mul (source1.c:30)
==30090==    by 0x40064A: main (source1.c:59)
==30090==
==30090== 24,000,000 bytes in 6 blocks are definitely lost in loss record 4 of 4
==30090==    at 0x4C2AB80: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30090==    by 0x400785: mat_Tmat_mul (source1.c:30)
==30090==    by 0x40064A: main (source1.c:59)
==30090==
==30090== LEAK SUMMARY:
==30090==    definitely lost: 24,000,000 bytes in 6 blocks
==30090==    indirectly lost: 0 bytes in 0 blocks
==30090==      possibly lost: 4,000,000 bytes in 1 blocks
==30090==    still reachable: 8,000,000 bytes in 2 blocks
==30090==         suppressed: 0 bytes in 0 blocks
==30090== Reachable blocks (those to which a pointer was found) are not shown.
==30090== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==30090==
==30090== For counts of detected and suppressed errors, rerun with: -v
==30090== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

Arriba es el dump de valgrind. Como se puede ver valgrind detecto un memory leak definitivo en:
==30090==    at 0x4C2AB80: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==30090==    by 0x400785: mat_Tmat_mul (source1.c:30)
==30090==    by 0x40064A: main (source1.c:59)

Esto da indicacion que el malloc usado en la linea 30: `temp = (float *) malloc( SIZE * SIZE * sizeof(float) );` no es liberado. Como la funcion mat_Tmat_mul es infinitamente llamada, cada ves que se la llama, un nuevo malloc es usado y asignado a temp, causando que la previa allocacion de memoria no liberada se convierta en basura.
