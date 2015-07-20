简单的flex构建词法分析器示例:
$sudo apt-get install flex
$flex --version

$flex example.fl 
$gcc -o example lex.yy.c -lfl
$./example
