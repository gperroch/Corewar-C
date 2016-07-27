section .text
	global ft_strcat

ft_strcat:
	cld
	mov rcx, -1
	mov r9, rdi		;je met l'adresse de rdi dans r9
	cmp byte [rsi], 0
	je error
	mov al, 0			;al set to 0
	repne scasb
	dec rdi
	jmp loop

loop:
	movsb
	cmp [rsi], al
	jne loop
	mov byte [rdi], 0
	mov rax, r9
	ret	

error:
	mov rax, r9
	ret
