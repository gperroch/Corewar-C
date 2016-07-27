section .text
	global ft_strchr
	extern ft_strlen
	extern ft_memchr

ft_strchr:
	cmp rdi, 0
	je null
	mov r9, rdi
	call ft_strlen
	inc rax
	mov rdx, rax
	mov rdi, r9
	call ft_memchr
	ret

null:
	mov rax, 0
	ret
