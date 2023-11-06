# ASCII character manipulation example
CC=gcc -std=c99

change_case: test.c change_case.c
	${CC} -o change_case test.c change_case.c

clean:
	rm change_case
