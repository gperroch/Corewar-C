section .text
	global ft_isalpha

ft_isalpha :
	cmp rdi, 65
	jl nope
	jmp maybe

maybe:
	cmp rdi, 90
	jle yaisse
	cmp rdi, 97
	jge maybe2
	jmp nope

maybe2:
	cmp rdi, 122
	jle yaisse
	jmp nope

nope:
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
