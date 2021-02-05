section .text
    global _start
    %define sys_call int 0x80
    %macro stdout_ 3
        mov ecx, %1
        mov edx, %2
        mov eax, 4
        mov ebx, 1
        sys_call
        
        mov ecx, %1
        mov [string], ecx
        mov ecx, [string]
        mov edx, %2
        mov eax, 4
        mov ebx, 1
        sys_call
        sys_call
    %endmacro
    
_start:
    stdout_ msg, len, len2
    
    mov ecx, len
    mov esi, msg
    mov edi, string
    cld
    rep movsb
    sys_call
    
    mov ecx, string
    mov edx, len
    mov eax, 4
    mov ebx, 1
    sys_call
    
    mov eax, 1
    mov ebx, 0
    sys_call

section .rodata
    msg db "Hello World",0xa
    len equ $ - msg
    len2 equ $ - len

section .bss
    string resb 20
