section .text
	global ft_strncmp
	extern ft_strlen
	extern ft_memcmp

ft_strncmp:			;cmpare return of strlen and rdx, choose the smallest
	cld
	push rdi
	call ft_strlen
	inc rax
	cmp rax, rdx
	jl end
	pop rdi
	call ft_memcmp
	ret

end:
	pop rdi
	mov rdx, rax
	call ft_memcmp
	ret
