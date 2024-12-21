# Important Stuff to Note
- run the script.sh / any of the .sh files in each directory to observe the output for that specific stage / partial stage.
- library.lib is present in the xsm_dev directory. test.xsm can be used to test input/output.
- %union is to be used in the parser, not the lex file.
- typecast yylval using yylval.node / yylval.integer wherever necessary.
- better to create a script file to execute the commands instead of invidual commands run on the terminal.


## LEX FILE
- run using ``` lex lexfile.l ```
- include headers, yywrap.

## YACC FILE
- run using ``` yacc -d parser.y ```
- include headers, y.tab.h, yyerror, yylex, yyin (if using file, otherwise it points to console input).

### COMPILATION
Compile using ``` gcc y.tab.c lex.yy.c [ any other c dependencies ] -o program ```

### OUTPUT
run the following : ``` ./program file1 file2 ```
