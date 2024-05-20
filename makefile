NAME = libftprintf.a
CC = cc -c
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIB	= ranlib
INCLUDE = -I includes

# SRCS = *.c
SRCS = ./sources/ft_printf.c \
	   	./sources/ft_numbers.c \
		./sources/ft_words.c \
# OBJS = *.o
OBJS = $(SRCS:.c=.o) # This is a substitution pattern, where the files ends with c it replaces with o

all: $(NAME)

$(NAME):$(OBJS)
#	 $(CC) $(FLAGS) -c
	$(AR) $(INCLUDES) $(NAME) $(OBJS)
	$(LIB) $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
#$(NAME):
#	$(CC)  $(FLAGS) $(SRCS)
#	$(AR)  $(NAME) $(OBJS)
#	$(LIB) $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
