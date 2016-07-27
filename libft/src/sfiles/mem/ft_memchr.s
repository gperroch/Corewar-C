section .text
	global ft_memchr

ft_memchr:
	cmp rdi, 0
	je null
	cld
	mov rcx, rdx
	mov rax, rsi
	repne scasb
	dec rdi
	cmp byte [rdi], al
	jne null
	mov rax, rdi
	ret

null:
	mov rax, 0
	ret
