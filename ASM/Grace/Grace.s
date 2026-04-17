%define EZ "Grace"
%define SOURCE_CODE "%%define EZ %1$cGrace%1$c%2$c%%define SOURCE_CODE %1$c%3$s%1$c%2$c%2$c; Dr-Quine%2$c%2$c%%macro EXEC 0%2$cglobal main%2$cextern fprintf%2$cextern fopen%2$cextern fclose%2$c%2$csection .data%2$c    source_code db SOURCE_CODE, 0%2$c    filename db %1$cGrace_kid.s%1$c, 0%2$c    mode db %1$cw%1$c, 0%2$c%2$csection .text%2$c%2$cmain:%2$c    push rbp%2$c%2$c    lea rdi, [rel filename]%2$c    lea rsi, [rel mode]%2$c    call fopen wrt ..plt%2$c%2$c    mov rbx, rax%2$c%2$c    mov rdi, rbx%2$c    lea rsi, [rel source_code]%2$c    mov rdx, 34%2$c    mov rcx, 10%2$c    lea r8, [rel source_code]%2$c    xor rax, rax%2$c    call fprintf wrt ..plt%2$c%2$c    mov rdi, rbx%2$c    call fclose wrt ..plt%2$c%2$c    pop rbp%2$c    xor rax, rax%2$c    ret%2$c%%endmacro%2$c%2$cEXEC%2$c"

; Dr-Quine

%macro EXEC 0
global main
extern fprintf
extern fopen
extern fclose

section .data
    source_code db SOURCE_CODE, 0
    filename db "Grace_kid.s", 0
    mode db "w", 0

section .text

main:
    push rbp

    lea rdi, [rel filename]
    lea rsi, [rel mode]
    call fopen wrt ..plt

    mov rbx, rax

    mov rdi, rbx
    lea rsi, [rel source_code]
    mov rdx, 34
    mov rcx, 10
    lea r8, [rel source_code]
    xor rax, rax
    call fprintf wrt ..plt

    mov rdi, rbx
    call fclose wrt ..plt

    pop rbp
    xor rax, rax
    ret
%endmacro

EXEC
