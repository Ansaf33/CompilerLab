#!/bin/bash

lex expression_tree.l
yacc -d expression_tree.y
gcc tree_generator.c reghandling.c lex.yy.c y.tab.c -o program
./program input.txt assembly_code.xsm
cd ../xsm_expl
./xsm -l library.lib -e ../T1EX1/assembly_code.xsm 

