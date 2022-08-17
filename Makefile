MANDATORY_PATH = ./mandatory_srcs
PARSE_ARGS_PATH = parse_arguments
ERRORS_HANDLERS_PATH = error_handlers
EXEC_CMD_PATH = exec_cmd
FILES_HANDLERS = files_handlers
FREE_ARGUMENTS_PATH = free_arguments

SRCS = 	$(MANDATORY_PATH)/pipex.c \
		$(addprefix $(MANDATORY_PATH)/$(PARSE_ARGS_PATH)/,parse_arguments.c parse_arguments_utils.c init_arguments.c tokenizer.c) \
		$(addprefix $(MANDATORY_PATH)/$(ERRORS_HANDLERS_PATH)/, error_handlers_utils.c error_handlers_utils_II.c close_fds.c close_fds_II.c) \
		$(addprefix $(MANDATORY_PATH)/$(EXEC_CMD_PATH)/, exec_cmd.c) \
		$(addprefix $(MANDATORY_PATH)/$(FILES_HANDLERS)/, files_handlers.c) \
		$(addprefix $(MANDATORY_PATH)/$(FREE_ARGUMENTS_PATH)/, free_arguments.c)

OBJS = $(SRCS:.c=.o)

BONUS_PATH = ./bonus_srcs
SRCS_BONUS = $(BONUS_PATH)/pipex_bonus.c \
		$(addprefix $(BONUS_PATH)/$(PARSE_ARGS_PATH)/,parse_arguments_bonus.c parse_arguments_utils_bonus.c init_arguments_bonus.c tokenizer_bonus.c here_doc_bonus.c) \
		$(addprefix $(BONUS_PATH)/$(ERRORS_HANDLERS_PATH)/, error_handlers_utils_bonus.c error_handlers_utils_II_bonus.c close_fds_bonus.c close_fds_II_bonus.c) \
		$(addprefix $(BONUS_PATH)/$(EXEC_CMD_PATH)/, exec_cmd_bonus.c) \
		$(addprefix $(BONUS_PATH)/$(FILES_HANDLERS)/, files_handlers_bonus.c) \
		$(addprefix $(BONUS_PATH)/$(FREE_ARGUMENTS_PATH)/, free_arguments_bonus.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex
NAME_BONUS = pipex_bonus

SRCS_LIBFT_PATH = ./libs/libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH), $(LIBFT))

INCLUDES = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I./includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:	$(LIBFT_FULL_PATH) $(NAME)

bonus: $(LIBFT_FULL_PATH) $(NAME_BONUS)

$(LIBFT_FULL_PATH):
	@tput setaf 4
	@echo COMPILING LIBFT
	make bonus -C $(SRCS_LIBFT_PATH)
	cp $(LIBFT_FULL_PATH) ./

$(NAME):	$(OBJS) $(LIBFT_FULL_PATH)
	@tput setaf 2
	@echo COMPILING PIPEX
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@tput setaf 7

$(NAME_BONUS):	$(OBJS_BONUS) $(LIBFT_FULL_PATH)
	@tput setaf 2
	@echo COMPILING PIPEX
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@\cp -r $(NAME_BONUS) $(NAME)
	@tput setaf 7
	
clean:
	make clean -C $(SRCS_LIBFT_PATH)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	make fclean -C $(SRCS_LIBFT_PATH)
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re bonus