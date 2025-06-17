# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 11:58:40 by mmosca            #+#    #+#              #
#    Updated: 2025/06/17 10:29:51 by mmosca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Configuration -------------------------------------------------------------

NAME = libasm.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

AR = ar
ARFLAGS = rcs

NASM = nasm
NASMFLAGS = -f elf64

RM = rm -f
MAKE = make --no-print-directory

SOURCES =																	\
	src/ft_strlen.s

OBJECTS = $(SOURCES:.s=.o)

# -- Rules ---------------------------------------------------------------------

.PHONY: all
all: ## Build the library.
	@$(MAKE) $(NAME)

.PHONY: clean
clean: ## Remove the object files generated during compilation.
	$(RM) $(OBJECTS)

.PHONY: fclean
fclean: ## Call the `clean` rule and also remove the generated library.
	@$(MAKE) clean
	$(RM) $(NAME)

.PHONY: help
help: ## Display a help menu with the description of the available rules in the Makefile.
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-10s\033[0m %s\n", $$1, $$2}'

.PHONY: norm
norm: ## Run the norminette tool to check the compliance of the source code with coding standards.
	@norminette .

.PHONY: re
re: ## Call the `fclean` and then the `all` rule to rebuild everything.
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: test
test: ## Call the `re` rule and then compiles the test file, linking it with the generated library.
	@$(MAKE) re
	$(CC) main.c $(CFLAGS) -L . -l asm

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s include/libasm.h
	$(NASM) $(NASMFLAGS) $< -o $@
