#/bin/sh
if [ "$#" -ne 1 ]
then
	echo "命令行输入参数不对,使用方法: ./judge.sh 参数"
	exit 1
fi

case "$1" in
	[0-9]) echo 数字;;
	[a-z]) echo 小写字母;;
	[A-Z]) echo 大写字母;;
	*) echo 其他字符;;
esac
