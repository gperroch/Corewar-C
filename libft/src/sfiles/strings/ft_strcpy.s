section .text
	global ft_strcpy

ft_strcpy:
	push rdi		;push adress of first arg onto da staque
	sub rax, rax
	jmp loop

loop:
	lodsb			;load un byte de rsi dans al
	stosb			;copie al dans rdi
	cmp al, 0		;are we at the end, if no let's do it again
	jne loop
	jmp exit

exit:
	pop rax			;get the adress of first arg in rax
	ret
