	.text
	.section .rodata
.LC0:
	.string "%ld\n"
	.text
	.globl sum
	.type sum@function
sum:
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movq $, -4(%rsp)
	pop	%rdi
	pop	%r8
	leave
	ret



	.globl main
	.type main@function
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	call sum
	movq returnpop, %rsi
	leaq .LC0(%rip), %rdi
	movq $0, %rax
	call printf@PLT
	leave
	ret



   .L1:
	movq $'__main__', %rdi
	call main
   end.L1:
