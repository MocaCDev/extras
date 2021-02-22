section .text
    global _start
    %define sys_call int 0x80
    
    %macro stdout 2
        mov ecx, %1
        mov edx, %2
        mov eax, 4
        mov ebx, 1
        sys_call
    %endmacro%
    
    %macro stdin 3
        mov eax, 3
        mov ebx, 0
        mov edx, %2+%2-1
        mov ecx, %1
        sys_call
        
        mov ecx, %3
        cmp ecx, '0'        ; if it is zero, then print
        je print
        jmp End             ; else, we exit the macro
        
        print:
            stdout %1, %2
            sys_call
        End:                ; otherwise we exit
            sys_call
        
    %endmacro%

_start:

    stdin buffer, len, '0'
    
    ;mov ecx, buffer
    ;mov eax, 4
    ;mov ebx, 1
    ;sys_call
    
    mov eax, 1
    sys_call

section .bss
    buffer resq 6
    len equ $ - buffer