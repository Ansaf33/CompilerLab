lex lexical.l
yacc -d parser.y
gcc AST.c reghandling.c evaluator.c symbol_table/symbol.c symbol_table/varList.c operators/optrans.c y.tab.c lex.yy.c -o program
./program input.txt assembly_code.xsm
cd label_translation
./script.sh
cd ../../xsm_expl
./xsm -l library.lib -e ../T2EX1/proper_assembly_code.xsm --debug


