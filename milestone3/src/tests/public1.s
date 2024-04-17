.data
.text
integer_format:
		.string "%ld\n"
.global main
.str0:
		.string "Sorted Array in Ascending Order:"
.str1:
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


bubbleSort:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	%rsp, %rdx
		subq	$48, %rdx
		movq	%rdx, %rsp
		movq	$0, %r9
		movq	%r9, -16(%rbp)
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	len
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
		movq	%rax, %r10
		movq	$0, %rdx
		subq	$1, %rdx
		movq	%rdx, %r11
		movq	%r11, -16(%rbp)
		subq	$16, %rsp
		movq	%r10, -48(%rbp)
.L1:
		movq	$1, %rdx
		addq	-16(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	-16(%rbp), %rdx
		movq	-48(%rbp), %rcx
		cmpq	%rcx, %rdx
		setge	%al
		movzbl	%al, %eax
		movq	%rax, %r12
		movq	$0, %rcx
		cmpq	%r12, %rcx
		jne	.L8
		movq	$0, %r13
		movq	%r13, -24(%rbp)
		movq	$0, %r8
		movq	%r8, -32(%rbp)
		movq	$0, %r9
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	len
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
		movq	%rax, %r11
		movq	%r11, %rdx
		subq	-16(%rbp), %rdx
		movq	%rdx, %r10
		movq	$1, %r12
		movq	%r10, %rdx
		subq	%r12, %rdx
		movq	%rdx, %r13
		movq	%r9, %rdx
		subq	$1, %rdx
		movq	%rdx, -32(%rbp)
		subq	$16, %rsp
		movq	%r13, -64(%rbp)
.L3:
		movq	$1, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, -32(%rbp)
		movq	-32(%rbp), %rdx
		movq	-64(%rbp), %rcx
		cmpq	%rcx, %rdx
		setge	%al
		movzbl	%al, %eax
		movq	%rax, %r8
		movq	$0, %rcx
		cmpq	%r8, %rcx
		jne	.L6
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r11
		movq	%r11, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r10
		movq	$1, %r12
		movq	%r12, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r9
		movq	$8, %rdx
		imulq	%r9, %rdx
		movq	%rdx, %r13
		movq	%r13, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r8
		movq	%r10, %r14
		movq	%r8, %r15
		movq	(%r14), %rdx
		movq	(%r15), %rcx
		cmpq	%rcx, %rdx
		setg	%al
		movzbl	%al, %eax
		movq	%rax, %r11
		movq	$0, %rcx
		cmpq	%r11, %rcx
		je	.L5
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r12
		movq	%r12, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, %r14
		movq	%r14, %rdx
		movq	(%rdx), %rdx
		movq	%rdx, -40(%rbp)
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r13
		movq	%r13, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r10
		movq	$1, %r8
		movq	%r8, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r11
		movq	$8, %rdx
		imulq	%r11, %rdx
		movq	%rdx, %r12
		movq	%r12, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r10, %rbx
		movq	%r9, %r14
		movq	%r14, %rdx
		movq	(%rdx), %rdx
		movq	%rdx, (%rbx)
		movq	$1, %r13
		movq	%r13, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r8
		movq	$8, %rdx
		imulq	%r8, %rdx
		movq	%rdx, %r11
		movq	%r11, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r12
		movq	%r12, %rbx
		movq	-40(%rbp), %rdx
		movq	%rdx, (%rbx)
		movq	$1, %r10
		movq	%r10, -24(%rbp)
.L5:
		jmp		.L3

.L6:
		movq	-32(%rbp), %rdx
		subq	$1, %rdx
		movq	%rdx, -32(%rbp)
.L4:
		movq	$0, %rdx
		cmpq	-24(%rbp), %rdx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r9
		movq	$0, %rcx
		cmpq	%r9, %rcx
		je	.L7
		jmp		.L2

.L7:
		jmp		.L1

.L8:
		movq	-16(%rbp), %rdx
		subq	$1, %rdx
		movq	%rdx, -16(%rbp)
.L2:
		movq	%rbp, %rsp
		popq	%rbp
		ret


bubbleSort1:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	80(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	%rsp, %rdx
		subq	$48, %rdx
		movq	%rdx, %rsp
		movq	$0, %r13
		movq	%r13, -16(%rbp)
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	len
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
		movq	$0, %rdx
		subq	$1, %rdx
		movq	%rdx, %r11
		movq	%r11, -16(%rbp)
		subq	$16, %rsp
		movq	%r8, -48(%rbp)
.L9:
		movq	$1, %rdx
		addq	-16(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	-16(%rbp), %rdx
		movq	-48(%rbp), %rcx
		cmpq	%rcx, %rdx
		setge	%al
		movzbl	%al, %eax
		movq	%rax, %r12
		movq	$0, %rcx
		cmpq	%r12, %rcx
		jne	.L16
		movq	$0, %r10
		movq	%r10, -24(%rbp)
		movq	$0, %r9
		movq	%r9, -32(%rbp)
		movq	$0, %r13
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	len
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
		movq	%rax, %r11
		movq	%r11, %rdx
		subq	-16(%rbp), %rdx
		movq	%rdx, %r8
		movq	$1, %r12
		movq	%r8, %rdx
		subq	%r12, %rdx
		movq	%rdx, %r10
		movq	%r13, %rdx
		subq	$1, %rdx
		movq	%rdx, -32(%rbp)
		subq	$16, %rsp
		movq	%r10, -64(%rbp)
.L11:
		movq	$1, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, -32(%rbp)
		movq	-32(%rbp), %rdx
		movq	-64(%rbp), %rcx
		cmpq	%rcx, %rdx
		setge	%al
		movzbl	%al, %eax
		movq	%rax, %r9
		movq	$0, %rcx
		cmpq	%r9, %rcx
		jne	.L14
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r11
		movq	%r11, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r8
		movq	$1, %r12
		movq	%r12, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r13
		movq	$8, %rdx
		imulq	%r13, %rdx
		movq	%rdx, %r10
		movq	%r10, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r8, %r14
		movq	%r9, %r15
		movq	(%r14), %rdx
		movq	(%r15), %rcx
		cmpq	%rcx, %rdx
		setg	%al
		movzbl	%al, %eax
		movq	%rax, %r11
		movq	$0, %rcx
		cmpq	%r11, %rcx
		je	.L13
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r12
		movq	%r12, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r13
		movq	%r13, %r14
		movq	%r14, %rdx
		movq	(%rdx), %rdx
		movq	%rdx, -40(%rbp)
		movq	$8, %rdx
		imulq	-32(%rbp), %rdx
		movq	%rdx, %r10
		movq	%r10, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r8
		movq	$1, %r9
		movq	%r9, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r11
		movq	$8, %rdx
		imulq	%r11, %rdx
		movq	%rdx, %r12
		movq	%r12, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r13
		movq	%r8, %rbx
		movq	%r13, %r14
		movq	%r14, %rdx
		movq	(%rdx), %rdx
		movq	%rdx, (%rbx)
		movq	$1, %r10
		movq	%r10, %rdx
		addq	-32(%rbp), %rdx
		movq	%rdx, %r9
		movq	$8, %rdx
		imulq	%r9, %rdx
		movq	%rdx, %r11
		movq	%r11, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r12
		movq	%r12, %rbx
		movq	-40(%rbp), %rdx
		movq	%rdx, (%rbx)
		movq	$1, %r8
		movq	%r8, -24(%rbp)
.L13:
		jmp		.L11

.L14:
		movq	-32(%rbp), %rdx
		subq	$1, %rdx
		movq	%rdx, -32(%rbp)
.L12:
		movq	$0, %rdx
		cmpq	-24(%rbp), %rdx
		sete	%al
		movzbl	%al, %eax
		movq	%rax, %r13
		movq	$0, %rcx
		cmpq	%r13, %rcx
		je	.L15
		jmp		.L10

.L15:
		jmp		.L9

.L16:
		movq	-16(%rbp), %rdx
		subq	$1, %rdx
		movq	%rdx, -16(%rbp)
.L10:
		movq	%rbp, %rsp
		popq	%rbp
		ret


main:
		pushq	%rbp
		movq	%rsp, %rbp
		movq	%rsp, %rdx
		subq	$16, %rdx
		movq	%rdx, %rsp
		movq	$48, %rdi
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	malloc
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	%rax, %r10
		movq	%r10, %rbx
		movq	$5, (%rbx)
		subq	$16, %rsp
		movq	$8, %rdx
		addq	%rax, %rdx
		movq	%rdx, -24(%rbp)
		movq	-24(%rbp), %rdx
		movq	%rdx, -8(%rbp)
		movq	$2, %r9
		movq	$0, %rdx
		subq	%r9, %rdx
		movq	%rdx, %r11
		movq	$0, %rdx
		addq	-24(%rbp), %rdx
		movq	%rdx, %r12
		movq	%r12, %rbx
		movq	%r11, (%rbx)
		movq	$45, %r8
		movq	$8, %rdx
		addq	-24(%rbp), %rdx
		movq	%rdx, %r13
		movq	%r13, %rbx
		movq	%r8, (%rbx)
		movq	$0, %r10
		movq	$16, %rdx
		addq	-24(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, %rbx
		movq	%r10, (%rbx)
		movq	$11, %r12
		movq	$24, %rdx
		addq	-24(%rbp), %rdx
		movq	%rdx, %r11
		movq	%r11, %rbx
		movq	%r12, (%rbx)
		movq	$9, %r13
		movq	$0, %rdx
		subq	%r13, %rdx
		movq	%rdx, %r8
		movq	$32, %rdx
		addq	-24(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, %rbx
		movq	%r8, (%rbx)
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	bubbleSort
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
		leaq	.str0(%rip), %rdx
		subq	$16, %rsp
		movq	%rdx, -40(%rbp)
		movq	-40(%rbp), %rdi
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	puts@PLT
		popq	%r15
		popq	%r14
		popq	%r13
		popq	%r12
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		movq	$0, %r10
		movq	%r10, -16(%rbp)
		pushq	$0
		pushq	-8(%rbp)
		pushq	%r8
		pushq	%r9
		pushq	%r10
		pushq	%r11
		pushq	%r12
		pushq	%r13
		pushq	%r14
		pushq	%r15
		call	len
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
		movq	%rax, %r11
		movq	$0, %rdx
		subq	$1, %rdx
		movq	%rdx, %r12
		movq	%r12, -16(%rbp)
		subq	$16, %rsp
		movq	%r11, -56(%rbp)
.L17:
		movq	$1, %rdx
		addq	-16(%rbp), %rdx
		movq	%rdx, -16(%rbp)
		movq	-16(%rbp), %rdx
		movq	-56(%rbp), %rcx
		cmpq	%rcx, %rdx
		setge	%al
		movzbl	%al, %eax
		movq	%rax, %r13
		movq	$0, %rcx
		cmpq	%r13, %rcx
		jne	.L19
		movq	$8, %rdx
		imulq	-16(%rbp), %rdx
		movq	%rdx, %r9
		movq	%r9, %rdx
		addq	-8(%rbp), %rdx
		movq	%rdx, %r8
		movq	%r8, %rdx
		movq	(%rdx), %rsi
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
		jmp		.L17

.L19:
		movq	-16(%rbp), %rdx
		subq	$1, %rdx
		movq	%rdx, -16(%rbp)
.L18:
		movq	%rbp, %rsp
		popq	%rbp
		movq	$0, %rax
		ret


		leaq	.str1(%rip), %rdx
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
		movq	%rax, %r12
		movq	$0, %rcx
		cmpq	%r12, %rcx
		je	.L20
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
.L20:

