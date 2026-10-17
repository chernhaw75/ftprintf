NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c \
		  ft_putchar_len.c \
		  ft_putstr_len.c \
		  ft_putnbr_len.c \
		  ft_putnbr_unsigned_len.c \
		  ft_puthex_len.c \
		  ft_puthex_ul_len.c \
		  ft_putptr_len.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
