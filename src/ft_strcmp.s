; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    Makefile                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2025/06/17 11:58:40 by mmosca            #+#    #+#              ;
;    Updated: 2025/06/17 12:15:19 by mmosca           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64

section .text

	global ft_strcmp

	ft_strcmp:
		mov rcx, 0						; Initialize the `rcx` register to zero, used as a counter.
		jmp .loop						; Jump directly to the `.loop` label to start the main loop.
	
	.loop:
		movzx rax, byte [rdi + rcx]		; Move the byte at address `rdi + rcx` into the `rax` register.
		movzx rdx, byte [rsi + rcx]		; Move the byte at address `rsi + rcx` into the `rdx` register.

		cmp rax, 0						; Compare the byte at address `rdi + rcx` with zero.
		je .end							; If the current byte in `rdi` is the null byte, jump to `.end` label.

		cmp rdx, 0						; Compare the byte at address `rsi + rcx` with zero.
		je .end							; If the current byte in `rsi` is the null byte, jump to `.end` label.

		cmp rax, rdx					; Compare the byte at address `rdi + rcx` with `rsi + rcx`.
		jne .end						; If the `rdi + rcx` byte is not the `rsi + rcx` byte, jump to `.end` label.

		inc rcx							; Increment the `rcx` register by 1 to move to the next byte.
		jmp .loop						; Jump back to the `.loop` label to repeat the process.
	
	.end:
		sub rax, rdx					; Substract `rax` to `rdi` and store the result in `rax`.
		ret								; Return from the function with the return value in `rax`.
