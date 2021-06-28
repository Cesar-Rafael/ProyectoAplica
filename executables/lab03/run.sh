yacc -v ../../source/lab03/base.y
gcc y.tab.c -o base -lm -lfl
./base > ../../outputs/lab03/test04.out