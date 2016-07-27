section .text
	global ft_isalnum
	extern ft_isdigit
	extern ft_isalpha

ft_isalnum :
	call ft_isdigit
	cmp rax, 1
	je yaisse
	call ft_isalpha
	cmp rax, 1
	je yaisse
	jmp nope

nope:
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
