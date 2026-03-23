;
; # Tasks
; ## Program
; - [x] The executable must be named Colleen. (makefile)
; - [x] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.
; ## Source code
; - [x] A main function.
; - [x] Two different comments.
; - [x] One of the comments must be present in the main function.
; - [x] One of the comments must be present outside of your program.
; - [x] Another function in addition to the main function (which of course will be called).
;
global main
extern printf

section .data
    source_code db ";%2$c; # Tasks%2$c; ## Program%2$c; - [x] The executable must be named Colleen. (makefile)%2$c; - [x] When executed, the program must display on the standard output an output identical to the source code of the file used to compile the program.%2$c; ## Source code%2$c; - [x] A main function.%2$c; - [x] Two different comments.%2$c; - [x] One of the comments must be present in the main function.%2$c; - [x] One of the comments must be present outside of your program.%2$c; - [x] Another function in addition to the main function (which of course will be called).%2$c;%2$cglobal main%2$cextern printf%2$c%2$csection .data%2$c    source_code db %1$c%3$s%1$c, 0%2$c%2$csection .text%2$c%2$cprint_source_code:%2$c    lea rdi, [rel source_code]%2$c    mov rsi, 34%2$c    mov rdx, 10%2$c    lea rcx, [rel source_code]%2$c    xor rax, rax%2$c    call printf wrt ..plt%2$c    ret%2$c%2$cmain:%2$c    ; This is the main comment%2$c    call print_source_code%2$c    xor rax, rax%2$c    ret%2$c", 0

section .text

print_source_code:
    lea rdi, [rel source_code]
    mov rsi, 34
    mov rdx, 10
    lea rcx, [rel source_code]
    xor rax, rax
    call printf wrt ..plt
    ret

main:
    ; This is the main comment
    call print_source_code
    xor rax, rax
    ret
