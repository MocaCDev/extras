section .text
    global _start
    global print
    global action
    extern printf
    
    %define system_call int 0x80
    
    action:
        ; setting up the "Hello World" variable
        mov ecx, msg
        mov edx, len
        mov eax, 4
        mov ebx, 1
        
        ;call printf
        system_call
        
        mov ecx, msg2
        mov edx, len2
        mov eax, 4
        mov ebx, 1
        system_call
        ret
    
    print:
        msg db "Hello World", 0xa
        len equ $ - msg
        
        msg2 db "Hello world 2", 0xa
        len2 equ $ - msg2
        ret
    
    _start:
        
        call action
        
        
        mov eax, 1
        mov ebx, 0
        system_call

segment .rodata
    call print
