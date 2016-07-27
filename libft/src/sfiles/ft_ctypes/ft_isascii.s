section .text
	global ft_isascii

ft_isascii :
	cmp rdi, 0
	jl nope
	jmp maybe

maybe:
	cmp rdi, 127
	jle yaisse
	jmp nope

nope:
	mov rax, 0
	ret

yaisse:
	mov rax, 1
	ret
