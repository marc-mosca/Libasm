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

	global ft_strcpy

	ft_strcpy:
		mov rcx, 0					; Initialize the `rcx` register to zero, used as a counter.
		jmp .loop					; Jump directly to the `.loop` label to start the main loop.
	
	.loop:
		cmp byte [rsi + rcx], 0		; Compare the byte at address `rsi + rcx` with zero.
		je .end						; If the current byte is the null byte, jump to `.end` label.

		mov al, [rsi + rcx]			; Move the byte at address `rsi + rcx` into the `al` register.
		mov [rdi + rcx], al			; Move the byte from the `al` register to the address `rdi + rcx`.
		inc rcx						; Increment the `rcx` register by 1 to move to the next byte.
		
		jmp .loop					; Jump back to the `.loop` label to repeat the process.

	.end:
		mov byte [rdi + rcx], 0		; Move the null byte to the end of the destination string.
		mov rax, rdi				; Insert the value of `rdi` into `rax`, which contains the source string.
		ret							; Return from the function with the return value in `rax`.
