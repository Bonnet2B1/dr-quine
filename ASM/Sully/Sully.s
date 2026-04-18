%define I 5

global main
extern sprintf
extern fopen
extern fprintf
extern fclose
extern system

section .data
    source_code db "%%define I %4$d%2$c%2$cglobal main%2$cextern sprintf%2$cextern fopen%2$cextern fprintf%2$cextern fclose%2$cextern system%2$c%2$csection .data%2$c    source_code db %1$c%3$s%1$c, 0%2$c    file_format db %1$cSully_%%d.s%1$c, 0%2$c    compile_cmd db %1$cnasm -f elf64 Sully_%%1$d.s -o Sully_%%1$d.o && gcc Sully_%%1$d.o -o Sully_%%1$d && ./Sully_%%1$d%1$c, 0%2$c    write_mode db %1$cw%1$c, 0%2$c    read_mode db %1$cr%1$c, 0%2$c%2$csection .bss%2$c    filename resb 64%2$c    cmd resb 256%2$c%2$csection .text%2$cmain:%2$c    push rbp%2$c%2$c    ; Stop if I < 0%2$c    mov r12, I%2$c    cmp r12, 0%2$c    jle .end%2$c%2$c    ; Prepare filename (Sully_X.s)%2$c    lea rdi, [rel filename]%2$c    lea rsi, [rel file_format]%2$c    mov rdx, r12%2$c    xor rax, rax%2$c    call sprintf wrt ..plt%2$c%2$c    ; Check if file exists to prevent double decrement%2$c    lea rdi, [rel filename]%2$c    lea rsi, [rel read_mode]%2$c    call fopen wrt ..plt%2$c%2$c    mov r14, r12%2$c    cmp rax, 0%2$c    je .write_file%2$c%2$c    ; File exists, we are Sully_X, decrement I%2$c    mov rdi, rax%2$c    call fclose wrt ..plt%2$c    dec r14%2$c%2$c.write_file:%2$c    ; Prepare new filename (Sully_X.s or Sully_X-1.s)%2$c    lea rdi, [rel filename]%2$c    lea rsi, [rel file_format]%2$c    mov rdx, r14%2$c    xor rax, rax%2$c    call sprintf wrt ..plt%2$c%2$c    ; Open file in write mode%2$c    lea rdi, [rel filename]%2$c    lea rsi, [rel write_mode]%2$c    call fopen wrt ..plt%2$c    cmp rax, 0%2$c    je .end%2$c    mov r13, rax%2$c%2$c    ; Write source code with fprintf%2$c    mov rdi, r13%2$c    lea rsi, [rel source_code]%2$c    mov rdx, 34%2$c    mov rcx, 10%2$c    lea r8, [rel source_code]%2$c    mov r9, r14%2$c    xor rax, rax%2$c    call fprintf wrt ..plt%2$c%2$c    ; Close file%2$c    mov rdi, r13%2$c    call fclose wrt ..plt%2$c%2$c    ; Prepare compile and execute command%2$c    lea rdi, [rel cmd]%2$c    lea rsi, [rel compile_cmd]%2$c    mov rdx, r14%2$c    xor rax, rax%2$c    call sprintf wrt ..plt%2$c%2$c    ; Execute command via system()%2$c    lea rdi, [rel cmd]%2$c    call system wrt ..plt%2$c%2$c.end:%2$c    pop rbp%2$c    xor rax, rax%2$c    ret%2$c", 0
    file_format db "Sully_%d.s", 0
    compile_cmd db "nasm -f elf64 Sully_%1$d.s -o Sully_%1$d.o && gcc Sully_%1$d.o -o Sully_%1$d && ./Sully_%1$d", 0
    write_mode db "w", 0
    read_mode db "r", 0

section .bss
    filename resb 64
    cmd resb 256

section .text
main:
    push rbp

    ; Stop if I < 0
    mov r12, I
    cmp r12, 0
    jle .end

    ; Prepare filename (Sully_X.s)
    lea rdi, [rel filename]
    lea rsi, [rel file_format]
    mov rdx, r12
    xor rax, rax
    call sprintf wrt ..plt

    ; Check if file exists to prevent double decrement
    lea rdi, [rel filename]
    lea rsi, [rel read_mode]
    call fopen wrt ..plt

    mov r14, r12
    cmp rax, 0
    je .write_file

    ; File exists, we are Sully_X, decrement I
    mov rdi, rax
    call fclose wrt ..plt
    dec r14

.write_file:
    ; Prepare new filename (Sully_X.s or Sully_X-1.s)
    lea rdi, [rel filename]
    lea rsi, [rel file_format]
    mov rdx, r14
    xor rax, rax
    call sprintf wrt ..plt

    ; Open file in write mode
    lea rdi, [rel filename]
    lea rsi, [rel write_mode]
    call fopen wrt ..plt
    cmp rax, 0
    je .end
    mov r13, rax

    ; Write source code with fprintf
    mov rdi, r13
    lea rsi, [rel source_code]
    mov rdx, 34
    mov rcx, 10
    lea r8, [rel source_code]
    mov r9, r14
    xor rax, rax
    call fprintf wrt ..plt

    ; Close file
    mov rdi, r13
    call fclose wrt ..plt

    ; Prepare compile and execute command
    lea rdi, [rel cmd]
    lea rsi, [rel compile_cmd]
    mov rdx, r14
    xor rax, rax
    call sprintf wrt ..plt

    ; Execute command via system()
    lea rdi, [rel cmd]
    call system wrt ..plt

.end:
    pop rbp
    xor rax, rax
    ret
