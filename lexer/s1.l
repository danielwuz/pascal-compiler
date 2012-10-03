/* 扫描器 for a toy Pascal-like language */
%{
/* 包含math.h，我们会用到atof() */
#include <math.h>
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%

{DIGIT}+    {
                printf("An integer: %s (%d) \n", yytext,
                        atoi(yytext));
            }

{DIGIT}+"."{DIGIT}*    {
                printf("A float: %s (%g)\n", yytext, 
                        atof(yytext));
            }

if|then|begin|end|procedure|function    {
                printf("A Keyword: %s\n", yytext);   
            }

{ID}        printf("An identifier: %s\n", yytext);

"+"|"-"|"*"|"/"    printf("An operator: %s\n", yytext);

"{"[\^{}\n]*"}"    /* 过滤行注释 */

[ \t\n]+            /* 过滤空白 */

.            printf("Unrecognized character: %s\n", yytext);

%% 

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* 跳过argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }

    return yylex();
}
