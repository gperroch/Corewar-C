section .text
	global ft_strequ
	extern ft_strcmp

ft_strequ:
	call ft_strcmp
	cmp rax, 0
	je yaisse
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
