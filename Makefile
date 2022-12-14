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
# MLXFLAGS	=	-L minilibx/minilibx-linux/libmlx_Linux.a
MLXFLAGS	=	-L minilibx/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -lz
SRCS_FILES	=	main init parse_map good_map good_map_structure render_map destroy_everything \
				movement about_score_and_exit map_dfs about_enemy about_enemy_patrol \
				animation animation2 hit_enemy print_step my_math
INCLS		=	srcs/so_long.h
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/
FSANITIZE	=	-fsanitize=address -g
RED			:= $(shell tput -Txterm setaf 1)
RESET		:= $(shell tput -Txterm sgr0)

all:			
				@mkdir -p $(OBJS_DIR)
				@make libft
				@make $(NAME)

bonus:			
				@mkdir -p $(OBJS_DIR)
				@make libft
				@make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@$(CC) -c $< -o $@

# $(NAME):		$(OBJS)
# 				$(CC) $(FSANITIZE) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MLXFLAGS) -lmlx -lXext -lX11 -o $(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(MLXFLAGS) -o $(NAME)
				@echo "$(RED)so_long READY HEHE..."

libft:
				@make -C $(LIBFT_DIR)

clean:
				@rm -rf $(OBJS_DIR)
				@make clean -C $(LIBFT_DIR)

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@rm -rf $(NAME)
				@echo "$(RED)REMOVED EVERYTHING HEHE..."

re:				fclean all

.PHONY:			all bonus libft clean fclean re

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS) $(INCLS)