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
        
        call kernCall ; interrupt call..
        call exit
        
        ret
    
    exit:
        
        push_: push 0x00
        
        addByte:
            ; Removing from stack..
            pop eax
            pop ecx
            pop edx
            pop ebx
            
            ; Pushing new element of 0x00 to stack after removing eax,ecx,edx and ebx
            call push_
            
            ; Assigning 4 bytes to esp(top of stack), and ebp(base of stack) registers.
            mov BYTE [esp], 32
            mov BYTE [ebp], 32
        
        ; Adding bytes to esp and ebp registers(working with the stack here..)
        call addByte
        
        ; Assigning values to each
        mov [ebp], edx
        mov [esp], ebx
        
        ; adding bytes to new stack element
        ; calling the kernel(interrupt call, 80h, 0x80..)
        call addByte
        call kernCall
        
        ; returning, and exiting program..
        ret
