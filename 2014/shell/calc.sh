#########################################################################
# File Name: calc.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Sun 19 Jul 2015 12:04:10 AM CST
# Description: 
#	$# -- 参数个数
#	$0, $1, $2... -- 参数
#	$* -- 所有参数作为一个单词
#	$(<表达式>)  -- 此种表达式求值允许空格
#########################################################################
#!/bin/bash

x=$1
y=$2

let sum=$y+$y
diff=$(($x - $y))
let mul=$x*$y
let div=$x/$y
let mod=$x%$y
let exp=$x**$y

echo "$x + $y = $sum"
echo "$x - $y = $diff"
echo "$x * $y = $mul"
echo "$x / $y = $div"
echo "$x % $y = $mod"
echo "$x ^ $y = $exp"

exit
