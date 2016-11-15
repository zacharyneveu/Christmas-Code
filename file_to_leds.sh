#!/bin/bash
while true; do
	FILENAME=test.txt
	FILEID=0B1EKxju8UUxAM3VXWEMwa3VvNjA
	CPROGRAM=leds
	./gdrive download --force $FILEID
	tac $FILENAME>reverse.txt
	grep -m1 katy reverse.txt>status.txt
	grep -m1 bob reverse.txt>>status.txt
	grep -m1 zach reverse.txt>>status.txt
	grep -m1 nick reverse.txt>>status.txt
	grep -m1 matt reverse.txt>>status.txt
	#cat status.txt

	#take just last character of each line
	cat status.txt | grep -o '..$'>line_endings.txt
	KATYSTATUS=$(sed '1q;d' line_endings.txt)
	BOBSTATUS=$(sed '2q;d' line_endings.txt)
	ZACHSTATUS=$(sed '3q;d' line_endings.txt)
	NICKSTATUS=$(sed '4q;d' line_endings.txt)
	MATTSTATUS=$(sed '5q;d' line_endings.txt)
	./$CPROGRAM $KATYSTATUS $BOBSTATUS $ZACHSTATUS $NICKSTATUS $MATTSTATUS
	sleep 30
done
