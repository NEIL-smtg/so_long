# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 00:35:41 by suchua            #+#    #+#              #
#    Updated: 2022/12/07 00:35:41 by suchua           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -Imlx
# MLXFLAGS	=	-L /usr/local/lib/libmlx.a
MLXFLAGS	=	-L minilibx/minilibx-linux/libmlx_Linux.a
SRCS_FILES	=	main parse_map
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/
FSANITIZE	= -fsanitize=address -g

all:			
				mkdir -p $(OBJS_DIR)
				make libft
				make $(NAME)

bonus:			
				mkdir -p $(OBJS_DIR)
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(FSANITIZE) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MLXFLAGS) -lmlx -lXext -lX11 -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all bonus libft clean fclean re

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)