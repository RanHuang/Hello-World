简单的flex构建词法分析器示例:
$sudo apt-get install flex
$flex --version

### example.fl

$flex example.fl 
$gcc -o example lex.yy.c -lfl
$./example

联合使用语法与词法分析器
$sudo apt-get install bison

### grammar.y tokens.fl

$bison -d grammar.y
$flex tokens.fl 
$gcc grammar.tab.c lex.yy.c -o parser -lfl
$./parser
set counter = counter + 1;
...

简单的电子邮件防火墙配置解析器

### config.fl config.y config.file

$bison -d config.y
$flex config.fl
$gcc config.tab.c lex.yy.c -o parser -lfl
$./parser

解析的过程：取得输入文件，分解为记号(lexer)，将记号输入词法解析器，生成解析树。
