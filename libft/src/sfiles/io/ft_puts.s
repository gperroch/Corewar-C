section .data
bn:
	.string db 10					;the final \n
	.null db "(null)", 10			;the null string

section .text
	global ft_puts
	extern ft_strlen

ft_puts:
	cmp rdi, 0
	je null
	push rdi
	call ft_strlen					;fetch the size of arg
	mov rdx, rax					;put it in third argument for write
	pop rsi							;load adress of first arg in second arg
	mov rdi, STDOUT					;put stdout in first arg
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc error
	mov rbx, rax
	jmp append

append:
	mov rdx, 1
	lea rsi, [rel bn.string]
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc error
	add rax, rbx
	ret

null:
	mov rdx, 7
	lea rsi, [rel bn.null]
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc error
	ret

error:
	mov rax, -1
	ret
