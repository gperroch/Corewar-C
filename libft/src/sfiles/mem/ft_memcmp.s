section .text
	global ft_memcmp

ft_memcmp:
	cld
	mov rcx, rdx
	repe cmpsb
	dec rsi
	dec rdi
	xor rax, rax
	xor r8, r8
	mov al, [rdi]
	mov r8b, [rsi]
	sub al, r8b
	test al, al
	js sign
	movsx rax, ax
	ret

sign:
	movsx rax, ax
	neg rax
	add rax, 256
	neg rax
	ret
