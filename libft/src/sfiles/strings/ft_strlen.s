section .text
	global ft_strlen

ft_strlen:
	cmp rdi, 0
	je null
	cld
	sub al, al
	sub rcx, rcx
	not rcx
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret

null:
	mov rax, 0
	ret
