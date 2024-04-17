section .text
    global main

main:
    ; Call sum(1, 2)
    mov edi, 1
    mov esi, 2
    call sum

    ; Print the result of sum(1, 2)
    mov rdi, rax        ; Move the result of sum into rdi
    call print_int      ; Call print_int function to print the result

    ; Exit the program
    mov eax, 60         ; System call number for sys_exit
    xor edi, edi        ; Exit status 0
    syscall             ; Invoke syscall

sum:
    ; Arguments x and y are in edi and esi respectively
    mov eax, edi        ; Move x to eax
    add eax, esi        ; Add y to eax
    ret

print_int:
    ; Save registers
    push rdi
    push rax

    ; Prepare parameters for syscall
    mov rsi, rsp        ; Pointer to the result on the stack
    mov rdx, 1          ; Length of the result (1 byte)
    mov rax, 1          ; System call number for sys_write
    mov rdi, 1          ; File descriptor 1 (stdout)
    
    ; Invoke syscall
    syscall

    ; Restore registers
    pop rax
    pop rdi
    ret
