#!/bin/bash
while true; do
	FILENAME=data.txt.asc
	#FILENAME=test.txt
	FILEID=16sdEcviDRA63P4OQMWHsrCAXFLmiIaqh-ZfuJ5kok2c
	#FILEID=0B1EKxju8UUxAM3VXWEMwa3VvNjA
	CPROGRAM=leds
	#./gdrive download --force $FILEID
	./gdrive export --mime text/plain -f 16sdEcviDRA63P4OQMWHsrCAXFLmiIaqh-ZfuJ5kok2c

	echo "" >> $FILENAME #Add newline char to end of downloaded file

	#echo "garbage" > reverse #single > to overwrite prev. contents
	tac $FILENAME > reverse.txt

	#echo "garbage" > status.txt #single > to overwrite prev. contents

	grep -i -m1 katy reverse.txt > status.txt 	
	grep -i -m1 bob reverse.txt >> status.txt
	grep -i -m1 zach reverse.txt >> status.txt
	grep -i -m1 nick reverse.txt >> status.txt
	grep -i -m1 matt reverse.txt >> status.txt
	#echo "garbage" >> status.txt

	echo "Reverse.txt: "
	cat reverse.txt

	echo "Status.txt: "
	cat status.txt

	cat status.txt > data.txt

	./gdrive update $FILEID data.txt

	#take just last character of each line
	cat status.txt | grep -o '..$'>line_endings.txt
	KATYSTATUS=$(sed '1q;d' line_endings.txt)
	BOBSTATUS=$(sed '2q;d' line_endings.txt)
	ZACHSTATUS=$(sed '3q;d' line_endings.txt)
	NICKSTATUS=$(sed '4q;d' line_endings.txt)
	MATTSTATUS=$(sed '5q;d' line_endings.txt)
	./$CPROGRAM $KATYSTATUS $BOBSTATUS $ZACHSTATUS $NICKSTATUS $MATTSTATUS

	sleep 10
done
