section .text
	global ft_isspace

ft_isspace:
	cmp rdi, 32
	je yaisse
	cmp rdi, 9
	jge maybe
	jmp nope

maybe:
	cmp rdi, 13
	jle yaisse
	jmp nope

yaisse:
	mov rax, 1
	ret

nope:
	mov rax, 0
	ret
