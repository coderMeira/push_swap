# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 18:37:53 by fmeira            #+#    #+#              #
#    Updated: 2021/07/05 21:35:55 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME_PH		= push_swap.a
NAME_CH		= checker.a

SRCS_PH		= 	markup.c\
				parse.c\
				checker.c\
				push.c\
				commands.c\
				push_swap.c\
				direction.c\
				free.c\
				ft_atoi.o\
				rotate.c\
				get_next_line.c\
				solve.c\
        		solve_a.c\
				solve_b.c\
				inits.c\
				stack.c\
            	swaps.c\
				libft\ft_isdigit.c\
				libft\ft_putendl.c\
				libft\ft_putendl_fd.c\
				libft\ft_putstr_fd.c\
				libft\ft_strdup.c\
				libft\ft_strlen.c\
				libft\ft_stoi.c\
				libft\ft_strchr.c\
				libft\ft_strjoin.c\
				libft\ft_strncmp.c\
				libft\ft_substr.c

SRCS_CH		=	get_next_line.c\
				ft_strchr.c\
				ft_substr.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlen.c\

INCLUDE_PH	= ft_push_swap.h
INCLUDE_CH	= get_next_line.h

OBJS_PH		= $(SRCS_PH:.c=.o)
OBJS_CH		= $(SRCS_CH:.c=.o)

all:		$(NAME_PH) $(NAME_CH)
$(NAME_PH):	$(OBJS_PH) $(INCLUDE_PH)
			ar -rcs $(CH) $(OBJS_PH)
$(NAME_CH):	$(OBJS_CH) $(INCLUDE_CH)
			ar -rcs $(CH) $(OBJS_CH)

push_swap: 	$(NAME_PH)
$(NAME_PH):	$(OBJS_PH) $(INCLUDE_PH)
			ar -rcs $(NAME_PH) $(OBJS_PH)

checker: 	$(NAME_CH)
$(NAME_CH):	$(OBJS_CH) $(INCLUDE_CH)
			ar -rcs $(NAME_CH) $(OBJS_CH)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME_PH) $(NAME_CH)

re:			fclean all

.PHONY:		all clean fclean re
