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

extern __errno_location				; External function to retrieve the address of `errno`.

section .text

	global ft_write

	ft_write:
		mov rax, 1					; Syscall number for `write` (Linux x86-64).
		syscall						; Invoke the system call with `rdi`, `rsi` and `rdx`.
		jc .error					; If carry flag is set, jump to `.error` label.
		ret							; On success, return (number of bytes written is in `rax`).
	
	.error:
		mov r8, rax					; Save error code in `r8`.
		neg r8						; Make the error code positive (to store in errno).
		call __errno_location		; Get the address of the `errno` variable.
		mov [rax], r8				; Store the error code in `errno`.
		mov rax, -1					; Store -1 to indicate failure.
		ret							; Return from the function with the return value in `rax`.
