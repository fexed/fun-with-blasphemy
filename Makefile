all:
	gcc -Wall -pedantic main.c -o utils/blashpemy-generator

clean:
	rm utils/blashpemy-generator