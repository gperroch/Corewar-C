section .text
	global ft_strnequ
	extern ft_strncmp

ft_strnequ:
	call ft_strncmp
	cmp rax, 0
	je yaisse
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
