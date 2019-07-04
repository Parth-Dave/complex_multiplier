all: assign3.out

assign3.out: assign3.o
	 gcc -o assign3.out assign3.o

assign3.o: assign3.c
	 gcc -c assign3.c
     
clean:
	 rm assign3.o assign3.out
