NAME = pipex
SRCS =	pipex.c\
		struct.c\
		control.c\
		cmdpaths.c\
		args.c\
		processes.c

OBJS = $(SRCS:.c=.o)
INCL = pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(LIB) $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re