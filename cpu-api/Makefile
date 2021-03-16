GCC_OPTIONS = -g
OBJECTS = p1 p2 p3 p4 q1 q2 q2_write write_test q3 q3_signal q4 q5 q7 q8

all: ${OBJECTS}

clean:
	rm -f ${OBJECTS}

p1: p1.c
	gcc -o p1 p1.c -Wall

p2: p2.c
	gcc -o p2 p2.c -Wall

p3: p3.c
	gcc -o p3 p3.c -Wall

p4: p4.c
	gcc -o p4 p4.c -Wall

q1: q1.c
	gcc -o q1 q1.c

q2: q2.c
	gcc -o q2 q2.c

q2_write: q2_write.c
	gcc ${GCC_OPTIONS} -o q2_write q2_write.c

write_test: write_test.c
	gcc ${GCC_OPTIONS} -o write_test write_test.c

q3: q3.c
	gcc ${GCC_OPTIONS} -o q3 q3.c

q3_signal: q3_signal.c
	gcc ${GCC_OPTIONS} -o q3_signal q3_signal.c

q4: q4.c
	gcc ${GCC_OPTIONS} -o q4 q4.c

q5: q5.c
	gcc ${GCC_OPTIONS} -o q5 q5.c

q7: q7.c
	gcc ${GCC_OPTIONS} -o q7 q7.c

q8: q8.c
	gcc ${GCC_OPTIONS} -o q8 q8.c