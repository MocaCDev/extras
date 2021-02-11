section .text
    global _start
    %define sys_call int 0x80
    
    %macro stdflush 0
        mov ecx, '0'
        mov eax, '0'
        mov ebx, '0'
        sys_call
        
        pop ecx ; remove value of ecx, not-final
        mov ebp, buffer ; push the buffer onto the stack, which is what ecx was holding.
                        ; only difference is that the buffer is the final value of whatever ecx had.
        sys_call
    %endmacro%
    
    %macro stdin 2
        mov eax, 3
        mov edx, %2+%2-1
        mov ecx, buffer
        mov ebx, 0 ; stdin
        sys_call
        
        push ecx ; ecx will have the buffer. Push this onto the stack, and the flush it with stdflush.
        push ebp
        mov ebp, esp
        sys_call
        
        stdflush
    %endmacro%

_start:

    stdin buffer, len
    
    mov ecx, buffer
    mov edx, len
    mov eax, 4
    mov ebx, 1
    sys_call
    
    mov eax, 1
    mov ebx, 0
    sys_call

segment .bss
    buffer resq 5
    len equ $ - buffer
