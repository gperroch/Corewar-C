section .text
	global ft_toupper

ft_toupper:
	cmp rdi, 97
	jge maybe
	jmp cassos

maybe:
	cmp rdi, 122
	jle upper
	jmp cassos

upper:
	mov rax, rdi
	sub rax, 32
	ret

cassos:
	mov rax, rdi
	ret 
