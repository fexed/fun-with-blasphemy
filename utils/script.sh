#!/bin/sh
for j in {1..100}
do
	mkfifo my-pipe
	telegram-cli < my-pipe & :
	exec 3> my-pipe # open file descriptor 3 writing to the pipe
	# < P tail -n +1 -f | program
	echo "contact_list" > my-pipe
	sleep 2s
	for i in {1..50}
	do
		./blasphemy-generator < input.txt > msg.txt
		sleep 2s
		echo "send_text $1 ./msg.txt" > my-pipe
		sleep 0.1
		#echo "msg $1 ".$i > my-pipe	
	done
	exec 3>&- # close file descriptor 3
	rm my-pipe
done

