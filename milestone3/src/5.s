	.text
	.section .rodata
.LC0:
	.string "%ld\n"

	.text
	.globl add
	.type add@function
add:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rbp
	movq $0, -16(%rbp)
	movq $0, -8(%rbp)
	movq %r9, -16(%rbp)
	addq %r8, -16(%rbp)
   for_loop1:
	cmpq %r8, -8(%rbp)
	jg endfor_loop1
	addq %r9, -16(%rbp)
	addq $1, -8(%rbp)
	jmp for_loop1
   endfor_loop1:
	movq -16(%rbp), %rsi
	leaq .LC0(%rip), %rdi
	movq $0, %rax
	call printf@PLT
	pop	%r8
	pop	%r9
	addq $16, %rbp
	movq %rbp, %rsp
	popq %rbp
	ret



	.globl main
	.type main@function
main:
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rbp
	movq $5, -16(%rbp)
	movq $6, -8(%rbp)
	movq -16(%rbp), %r8
	pushq %r8
	movq -8(%rbp), %r9
	pushq %r9
	call add
	movq %rax, %r10
	pop	%r10
	pop	%r8
	pop	%r9
	addq $16, %rbp
	movq %rbp, %rsp
	popq %rbp
	ret



