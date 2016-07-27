section .text
	global ft_strdup
	extern ft_strlen
	extern malloc

ft_strdup:
	cld
	push rbx
	sub rsp, 8
	mov rbx, rdi		;save pointer to string for later in rbx
	call ft_strlen		;call ft_strlen on first arg, rdi
	inc rax				;increase it for the final 0
	push rax			;push it on stack
	mov rdi, rax		;put it in rdi to call malloc
	call malloc
	cmp rax, 0			;if malloc failed go away
	je null
	pop rcx				;pop the length in counter (ou mov rcx, rdi)
	mov rsi, rbx		;put the original string in rsi
	mov rdi, rax		;put the pointer to the fresh string in first arg
	push rdi			;push the pointer to get it back later
	rep movsb			;copy it
	dec rdi
	mov al, 0			;put the final 0
	stosb
	pop rax
	add rsp, 8
	pop rbx
	ret

null:
	mov rax, 0
	ret
