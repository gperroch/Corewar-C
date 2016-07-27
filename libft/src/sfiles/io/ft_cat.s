%define BUFSIZE				65536

section .bss
	buff resb BUFSIZE

section .text
	global ft_cat

ft_cat:
	lea rsi, [rel buff]
	mov rdx, BUFSIZE
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc exit
	cmp rax, 1
	jl exit
	lea rsi, [rel buff]
	mov rbx, rax					;val retour de read dans rbx
	mov r8, rdi						;filedes dans r8
	mov rdi, STDOUT
	mov rdx, rbx
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc exit
	mov rdi, r8
	jmp ft_cat

exit:
	ret
