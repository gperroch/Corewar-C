section .text
	global ft_isprint

ft_isprint :
	cmp rdi, 32
	jl nope
	jmp maybe

maybe:
	cmp rdi, 126
	jle yaisse
	jmp nope

nope:
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
