
CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRCS = direction.c markup.c push_swap.c solve_a.c solve_b.c solve.c\
		../common/commands.c ../common/terminate.c\
       ../common/free.c ../common/inits.c ../common/parse.c\
	   ../common/push.c ../common/rotate.c ../common/stack.c ../common/swaps.c\
	   ../../lib/libft/src/ft_putendl.c ../../lib/libft/src/ft_putstr_fd.c\
	   ../../lib/libft/src/ft_strdup.c ../../lib/libft/src/ft_strlen.c\
	   ../../lib/libft/src/ft_stoi.c ../../lib/libft/src/ft_strchr.c\
	   ../../lib/libft/src/ft_strjoin.c ../../lib/libft/src/ft_strncmp.c\
	   ../../lib/libft/src/ft_substr.c ../../lib/libft/src/ft_isdigit.c\
       ../../lib/libft/src/ft_putendl_fd.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME) && mv $(NAME) ../../bin

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
