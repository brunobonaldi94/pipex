MANDATORY_PATH = ./mandatory_srcs
PARSE_ARGS_PATH = parse_arguments
ERRORS_HANDLERS_PATH = error_handlers
EXEC_CMD_PATH = exec_cmd
FILES_HANDLERS = files_handlers

SRCS = 	$(MANDATORY_PATH)/pipex.c \
		$(addprefix $(MANDATORY_PATH)/$(PARSE_ARGS_PATH)/,parse_arguments.c parse_arguments_utils.c) \
		$(addprefix $(MANDATORY_PATH)/$(ERRORS_HANDLERS_PATH)/, error_handlers_utils.c) \
		$(addprefix $(MANDATORY_PATH)/$(EXEC_CMD_PATH)/, exec_cmd.c) \
		$(addprefix $(MANDATORY_PATH)/$(FILES_HANDLERS)/, files_handlers.c) 

OBJS = $(SRCS:.c=.o)

NAME = pipex

SRCS_LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH),$(LIBFT))

INCLUDES = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I$(addprefix $(MANDATORY_PATH)/, includes)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:	$(LIBFT_FULL_PATH) $(NAME)

$(LIBFT_FULL_PATH):
	@tput setaf 4
	@echo COMPILING LIBFT
	make bonus -C $(SRCS_LIBFT_PATH)
	cp $(LIBFT_FULL_PATH) ./

$(NAME):	$(OBJS) $(LIBFT_FULL_PATH)
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