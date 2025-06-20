; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2025/06/17 11:58:40 by mmosca            #+#    #+#              ;
;    Updated: 2025/06/17 12:15:19 by mmosca           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64

extern __errno_location

section .text

	global ft_read

	ft_read:
		mov rax, 0					; Syscall number for `read` (Linux x86-64).
		syscall						; Invoke the system call with `rdi`, `rsi` and `rdx`.
		
		cmp rax, 0					; Compare rax with 0 to check for an error.
		jl .error					; If less than 0, jump to `.error` label.
		ret							; On success, return (number of bytes written is in `rax`).
	
	.error:
		mov r8, rax					; Save error code in `r8`.
		neg r8						; Make the error code positive (to store in errno).
		call __errno_location		; Get the address of the `errno` variable.
		mov [rax], r8				; Store the error code in `errno`.
		mov rax, -1					; Store -1 to indicate failure.
		ret							; Return from the function with the return value in `rax`.
