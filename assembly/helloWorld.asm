section .text
    global _start
    %define sys_call int 0x80
    %macro stdin 2
        mov eax, 3 ; read
        mov ebx, 0 ; stdin
        mov ecx, %1
        mov edx, %2+%2-1 ; Add the total length of the string by the length of the screen subracted by one(removing byte for the \0)
        push ecx
        sys_call
    %endmacro%
    %macro stdout 2
        mov ecx, %2
        mov esi, input
        mov edi, string
        cld
        rep movsb
        sys_call
        
        mov ecx, string
        mov ebx, %2
        mov eax, 4 ; output
        mov ebx, 1 ; stdout
        sys_call
        
        pop ecx
        push string
        sys_call
        
        push ebp
        mov ebp, esp ; re-initialize
        sys_call
    %endmacro%

_start:

    push ebp
    mov ebp, esp
    
    stdin input, len
    
    stdout input, len
    
    mov eax, 1
    mov ebx, 0
    sys_call

segment .bss
    input resq 5
    len equ $ - input
    string resq 5
