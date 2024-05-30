bison -d -v -r all myparser.y
flex lex_anal.l
gcc -o mycomp myparser.tab.c lex.yy.c cgen.c -lfl
