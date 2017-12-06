all: life

# hello: try-hello.c hello.o
# 	gcc -o hello try-hello.c hello.o

life: life.c game.o
	gcc -o life life.c game.o


.SECONDARY:

%.o: %.asm
	nasm -f elf64 -F dwarf -g $<


%: %.o
	ld $< -o $@ -lc --dynamic-linker=/lib64/ld-linux-x86-64.so.2


clean:
	rm -f *.o
