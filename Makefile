SRCS = pipex.c
OBJS = $(SRCS:.c=.o)

MANDATORY_PATH = ./mandatory_srcs
NAME = pipex

SRCS_LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH),$(LIBFT))

INCLUDES = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I$(addprefix $(MANDATORY_PATH)/, includes)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

all:	$(LIBFT_FULL_PATH) $(NAME)

$(LIBFT_FULL_PATH):
	@tput setaf 4
	@echo COMPILING LIBFT
	make bonus -C $(SRCS_LIBFT_PATH)
	cp $(LIBFT_FULL_PATH) ./

$(NAME):	$(OBJS)
	@tput setaf 2
	@echo COMPILING PIPEX
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make clean -C $(SRCS_LIBFT_PATH)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	make fclean -C $(SRCS_LIBFT_PATH)
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re