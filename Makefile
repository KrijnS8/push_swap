# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kschelvi <kschelvi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/05 14:12:02 by kschelvi      #+#    #+#                  #
#    Updated: 2023/12/07 16:00:22 by kschelvi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -g

SRC = src/main.c src/stack.c src/stack_utils.c src/operations.c src/radix.c

OBJ = $(SRC:%.c=%.o)

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@if [ ! -d "libft" ]; then \
		git clone https://github.com/KrijnS8/libft.git; \
	fi
	@cd $(LIBFT_PATH) && $(MAKE)

fclean:
	@$(RM) $(OBJ) $(NAME)
	@cd $(LIBFT_PATH) && $(MAKE) fclean

clean:
	@$(RM) $(OBJ)
	@cd $(LIBFT_PATH) && $(MAKE) clean

cleanlib:
	@$(RM) -rf $(LIBFT_PATH)

re: fclean all

relib: cleanlib $(LIBFT)

.PHONY: all fclean clean re
