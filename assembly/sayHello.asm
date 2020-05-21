global _start
global exit
global kernCall

section .data
    sayHi: db "Hello World, It's aidan!!", 0xa
    length: equ $-sayHi

section .text

    kernCall:
        int 0x80
        ret

    _start:
        mov eax, 4
        mov ecx, sayHi
        mov edx, length
        mov ebx, 1
        
        call kernCall
        
        ret
    
    exit:
        
        push_: push 0x00
        
        addByte:
            mov BYTE [esp], 32
            mov BYTE [ebp], 32
        call addByte
        
        mov [ebp], edx
        
        call push_
        call addByte
        
        call kernCall
        ret
