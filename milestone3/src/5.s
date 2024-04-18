	.text
	.section .rodata
.LC0:
	.string "%ld\n"
	.text
	.globl main
	.type main@function
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movq $5, -4(%rsp)
	movq -4(%rsp), %rsi
	leaq .LC0(%rip), %rdi
	movq $0, %rax
	call printf@PLT
	leave
	ret



