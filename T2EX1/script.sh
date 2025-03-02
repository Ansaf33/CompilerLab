echo "Lexical"
lex lexical.l
echo "Parser"
yacc -d parser.y
echo "GCC"
gcc AST.c reghandling.c evaluator.c operators/optrans.c y.tab.c lex.yy.c -o program
echo "Running"
./program input.txt assembly_code.xsm
cd ../xsm_expl
./xsm -l library.lib -e ../T2EX1/assembly_code.xsm --debug
