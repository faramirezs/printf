NAME	= libftprintf.a

SRCS	= ./sources/ft_printf.c \
	./sources/ft_numbers.c \
	./sources/ft_words.c \
	./sources/ft_hexa.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	    ar rcs $(NAME) $(OBJS)

.c.o:
	    $(CC) $(CFLAGS) -c $< -o $@

clean:
	    $(RM) $(OBJS)

fclean:		clean
	    $(RM) $(NAME)

re:			fclean all


.PHONY:		all clean fclean re
