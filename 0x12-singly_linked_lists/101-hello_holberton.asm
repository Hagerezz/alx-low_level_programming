section .data
    hello db 'Hello, Holberton', 0Ah

section .text
    global main

extern printf

main:
    mov edi, hello
    xor eax, eax
    call printf
    xor eax, eax
    ret
