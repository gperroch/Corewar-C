section .text
	global ft_strnew
	extern malloc
	extern ft_bzero

ft_strnew:
	cld
	xor rax, rax
	inc rdi
	push rdi
	call malloc
	cmp rax, 0
	je null
	pop rsi
	push rax
	mov rdi, rax
	call ft_bzero
	pop rax
	ret

null:
	mov rax, 0
	ret
