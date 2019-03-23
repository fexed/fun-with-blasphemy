all:
	gcc -Wall -pedantic -g main.c -o utils/blasphemy-generator

clean:
	rm utils/blasphemy-generator