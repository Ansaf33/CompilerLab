lex lexical.l

yacc -d parser.y

gcc AST.c typesatisfy/typesatisfy.c reghandling.c symbol_table/Gsymbol.c symbol_table/Lsymbol.c symbol_table/varList.c symbol_table/paramlist.c operators/optrans.c functions/checker.c typetable/typetable.c udt/fieldlist.c class/classtable.c class/classmember.c class/classmethod.c inheritance/copier.c y.tab.c lex.yy.c -o program

./program sample_programs/STAGE\ 8/vft_setup.txt assembly_code.xsm

cd label_translation
./script.sh

cd ../../xsm_expl
./xsm -l library.lib -e ../code/proper_assembly_code.xsm

