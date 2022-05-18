#!/bin/sh
moring()
{
	echo "Good morning!" 
	echo "back form function moring..."
	return
}
afternoon()
{
	echo "Good afternoon!" 
	echo "back form function afternoon..."
	return
}
evening()
{
	echo "Good evening!" 
	echo "back form function evening..."
	return
}

greeting()
{
	hour=$(date +%H)
	if [ "$hour" -ge 0 -a "$hour" -le 11 ]
	then
		morning
	elif [ "$hour" -ge 12 -a "$hour" -le 17 ]
	then
		afternoon
	else
		evening
	fi

	echo "back from function greeting..."
	return
}

echo "the time is:`date`"
greeting
echo "back from function greeting_again..."
