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


add:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	-16(%rbp), %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


subtract:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	-8(%rbp), %rdx
		subq	-16(%rbp), %rdx
		movq	%rdx, %r10
		movq	%r10, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


multiply:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	-16(%rbp), %rdx
		imulq	-8(%rbp), %rdx
		movq	%rdx, %r11
		movq	%r11, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


divide:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	$0, %r12
		movq	-16(%rbp), %rdx
		movq	%r12, %rcx
		cmpq	%rdx, %rcx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r13
		movq	$0, %rcx
		cmpq	%r13, %rcx
		je	.L1
		movq	$1, %r8
		movq	$0, %rdx
		subq	%r8, %rdx
		movq	%rdx, %r9
		movq	%r9, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret

.L1:
		movq	-8(%rbp), %rax
		cqto	
		idivq	-16(%rbp)
		movq	%rax, %r10
		movq	%r10, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


power:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	88(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	$1, %r11
		movq	-16(%rbp), %rdx
.L5:
		movq	$0, %rcx
		cmpq	%rcx, %rdx
		setg	%al
		movzbl	%al, %eax
		movq	$1, %rcx
		cmpq	%rax, %rcx
		jne		.L6
		movq	-8(%rbp), %rcx
		imulq	%r11, %rcx
		movq	%rcx, %r11
		subq	$1, %rdx
		jmp		.L5
.L6:
		movq	%r11, %rax
		movq	%rbp, %rsp
		popq	%rbp
		ret


main:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	%rsp, %rdx
		subq	$32, %rdx
		movq	%rdx, %rsp
		movq	$1, %r12
		movq	-24(%rbp), %rdx
		movq	%r12, %rcx
		cmpq	%rdx, %rcx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r13
		movq	$0, %rcx
		cmpq	%r13, %rcx
		je	.L3
		pushq	-16(%rbp)
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	add
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
		movq	%rax, %r8
		movq	%r8, %rsi
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
		jmp		.L2

.L3:
		pushq	-16(%rbp)
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	subtract
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
		movq	%rax, %r9
		movq	%r9, %rsi
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
.L2:
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
		movq	%rax, %r10
		movq	%r10, %rdx
		movq	$0, %rcx
		cmpq	%rdx, %rcx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r11
		movq	$0, %rcx
		cmpq	%r11, %rcx
		je	.L4
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
.L4:

