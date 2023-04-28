section .data
    hello db 'Hello, Holberton\n', 0

section .text
    global _start

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, 16
	int 0x80
