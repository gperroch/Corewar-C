section .text
	global ft_bzero

ft_bzero :
	cld
	cmp rsi, 0
	jne loop
	ret

loop:
	mov al, 0
	mov rcx, rsi
	rep stosb
	ret
