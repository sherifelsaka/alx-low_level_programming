section .data
    msg db "Hello, Holberton", 10, 0
    fmt db "%s", 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rdi, fmt
    mov rsi, msg
    xor rax, rax
    call printf

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret
