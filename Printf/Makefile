# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 10:57:10 by hbuisser          #+#    #+#              #
#    Updated: 2020/01/22 15:30:45 by hbuisser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_LIST = \
		printf.c \
		printf_c.c \
		printf_s.c \
		printf_d.c \
		printf_x.c \
		printf_p.c \
		printf_percent.c \
		printf_u.c \
		convert_utils_1.c \
		convert_utils_2.c \
		get.c \
		check.c
SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})
OBJS			= ${SRCS:.c=.o}
HEADER			= include
FOLDER			= srcs
LIBFT 			= libft
CC				= clang
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}
$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rcs $(NAME) $(OBJS)
bonus:			${NAME}
%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)
fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)
re:				fclean all
.PHONY: 		all fclean clean re
