.data
.text
integer_format:
		.string "%ld\n"
.global main
.str0:
		.string "__main__"
len:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	-8(%rbp), %rdx
		subq	$8, %rdx
		movq	%rdx, %r8
		movq	%r8, %r14
		movq	%r14, %rdx
		movq	(%rdx), %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


sum:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$32, %rdx
		movq	%rdx, %rsp
		movq	-16(%rbp), %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, -24(%rbp)
		movq	-24(%rbp), %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


main:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	$1, %r10
		movq	$2, %r11
		pushq	%r11
		pushq	%r10
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	sum
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	$16, %rdx
		addq	%rsp, %rdx
		movq	%rdx, %rsp
		movq	%rax, %r12
		movq	%r12, %rsi
		leaq	integer_format(%rip), %rdi
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	printf@PLT
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	%rbp, %rsp
		popq	%rbp
		movq	$0, %rax
		ret


		leaq	.str0(%rip), %rdx
		subq	$16, %rsp
		movq	%rdx, -16(%rbp)
		movq	-8(%rbp), %rdi
		movq	-16(%rbp), %rsi
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	strcmp
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	%rax, %r13
		movq	%r13, %rdx
		movq	$0, %rcx
		cmpq	%rdx, %rcx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r8
		movq	$0, %rcx
		cmpq	%r8, %rcx
		je	.L1
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	main
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	$0, %rdx
		addq	%rsp, %rdx
		movq	%rdx, %rsp
.L1:

