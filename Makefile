# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 15:43:03 by sgerace           #+#    #+#              #
#    Updated: 2022/03/27 18:45:15 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c\
		ft_memchr.c ft_memcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all: $(NAME)

clean: ${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean	${RM} ${NAME}

re:	fclean ${NAME}
