; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2025/06/17 11:58:40 by mmosca            #+#    #+#              ;
;    Updated: 2025/06/17 12:15:19 by mmosca           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64

extern ft_strcpy
extern ft_strlen

extern malloc
extern __errno_location

section .text

	global ft_strdup

	ft_strdup:
		call ft_strlen		; Save into `rax` the size of s (who is in `rdi`).
		push rdi			; Push the string s into the stack.
		inc rax				; Increment by 1 `rax` to allow null terminating.

		mov rdi, rax		; Save the size of s into rdi to allow malloc to read it.
		call malloc			; Call to malloc function.

		pop rsi				; Push back the string s to duplicate, in `rsi`.
		mov rdi, rax		; Put the newly-allocated space in `rdi`.
		call ft_strcpy		; Copy the string s into the new allocated space.
		ret					;  Return from the function with the return value in `rax`.
