section .text
    global _start
    %define sys_call int 0x80
    
    %macro stdout 2
        mov ecx, %2
        mov esi, %1
        mov edi, string_buffer
        cld
        rep movsb
        sys_call
        
        cmp edi, %1                        ; should have the stdout buffer
        je print_
        jmp exit
        
        print_:
            mov ecx, string_buffer         ; buffer
            mov edx, %2                    ; len
            mov eax, 4                     ; stdout
            mov ebx, 1                     ; stdout
            jmp done_
        exit:
            mov ecx, pbe
            mov edx, pbe_len
            mov eax, 4
            mov ebx, 1
            sys_call
        done_:
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
            jmp end
        End:                ; otherwise we exit
            mov ecx, error
            mov edx, error_len
            mov eax, 4
            mov ebx, 1
        end:
            sys_call
        
    %endmacro%

_start:

    stdin buffer, len, '0'
    
    mov eax, 1
    sys_call
section .rodata
    error db "Stdin was assigned NOT to print out the buffer. :'("
    error_len equ $ - error
    pbe db "There was an error printing the buffered stdout"
    pbe_len equ $ - pbe
section .bss
    string_buffer resq          15      
    buffer        resq          15
    len equ $ - buffer
