section .text
	global _start
	global action
	%define system_call int 0x80

action:
	mov ecx, msg
	mov edx, len
	mov eax, 4
	mov ebx, 1
	system_call
	
	ret

_start:

	call action
	
	mov eax, 1
	mov ebx, 0
	system_call

section .data
	msg db "Hello World"
	len equ $ - msg
