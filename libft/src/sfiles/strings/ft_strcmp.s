section .text
	global ft_strcmp
	extern ft_strlen
	extern ft_memcmp

ft_strcmp:
	cld
	push rdi
	call ft_strlen
	inc rax
	mov rdx, rax
	pop rdi
	call ft_memcmp
	ret
