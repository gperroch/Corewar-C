section .text
	global ft_tolower

ft_tolower:
	cmp rdi, 65
	jge maybe
	jmp cassos

maybe:
	cmp rdi, 90
	jle lower
	jmp cassos

lower:
	mov rax, rdi
	add rax, 32
	ret

cassos:
	mov rax, rdi
	ret 
