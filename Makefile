default: asm kernel io
	ld -m elf_i386 -T link.ld -o kernel kasm.o kernel.o io.o

clean:
	rm *.o kernel

asm:
	nasm -f elf32 kernel.asm -o kasm.o

kernel:
	gcc -m32 -c kernel.c -o kernel.o

io:
	gcc -m32 -c kio.c -o io.o

run: default
	qemu-system-i386 -kernel kernel
