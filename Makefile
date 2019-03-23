all:
	gcc -Wall -pedantic main.c -o utils/blasphemy-generator

clean:
	rm utils/blasphemy-generator