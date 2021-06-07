all: prog

prog: Main.o Func.o
	gcc -o prog.o Main.o Func.o -m32
Main.o: Main.c
	gcc -c -o Main.o Main.c -m32
Func.o: Func.asm
	nasm -f  elf32 -o Func.o Func.asm
clean:
	rm -f *.o prog
