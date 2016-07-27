section .text
	global ft_isdigit

ft_isdigit :
	cmp rdi, 48
	jl nope
	jmp maybe

maybe:
	cmp rdi, 57
	jle yaisse
	jmp nope

nope:
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
