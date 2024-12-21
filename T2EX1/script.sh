lex lexical.l
yacc -d parser.y
gcc AST.c y.tab.c lex.yy.c -o program
./program sample.txt
