section .text
  global _start
  %define sys_call int 0x80
  %macro read_file 3
    dec eax
    cmp byte[eax + ecx] , 0xa
    je delete_newline
    jmp rest

    delete_newline:
      mov byte[eax + ecx], 0
      sys_call

      jmp rest
    
    rest:

      mov eax, 5
      mov ecx, 0
      mov ebx, %3
      sys_call

      mov eax, 3
      mov ebx, eax
      mov ecx, %1
      mov edx, %2
      sys_call

      mov ebx, '0'
      mov ecx, '0'
      sys_call

      mov ecx, buffer
      mov eax, 4
      mov ebx, 1
      sys_call
  %endmacro%

_start:

  mov eax, 4
  mov ebx, 1
  mov ecx, print
  mov edx, len
  sys_call

  mov eax, 3
  mov ebx, 0
  mov ecx, filename
  mov edx, filesize
  sys_call

  pop ebx
  pop ebx

  read_file buffer, bufsize, filename
  
  exit:
    mov eax, 1
    mov ebx, 0
    sys_call

section .rodata
  print db "File to open: "
  len equ $ - print
section .bss
  buffer   resq 1024
  filename resq 50

section .data
   file dq         1024
   bufsize dq      1024
   filesize dq     1024
