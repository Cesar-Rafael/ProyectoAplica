flex -o grupo5_ER.c grupo5_ER.l
gcc grupo5_ER.c -o grupo5_ER -lfl -lm
./grupo5_ER < tests/palabras_reservadas.raa > outputs/palabras_reservadas_resultado.out
./grupo5_ER < tests/simbolos.raa > outputs/simbolos_resultado.out
