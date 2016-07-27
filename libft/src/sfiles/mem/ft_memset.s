section .text
	global ft_memset

ft_memset:
	push rdi
	cld
	mov	al, sil			;put the second arg into al
	mov rcx, rdx		;put the third arg in da counter
	rep stosb
	pop rax
	ret
