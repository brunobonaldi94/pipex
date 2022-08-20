SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_ptr_free.c \
		ft_get_nbr_elements.c \
		ft_strrchr_pos.c \
		ft_strnstr_pos.c

SRCS_BONUS = 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GNL_PATH = ./get_next_line
SRCS_GNL = $(addprefix $(GNL_PATH)/, get_next_line.c get_next_line_utils.c)

OBJS_GNL = $(SRCS_GNL:.c=.o)

PRINTF_PATH = ./printf
PRINTF_UTILS_PATH = $(PRINTF_PATH)/utils

SRCS_PRINTF = $(addprefix $(PRINTF_PATH)/, ft_printf.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/format_options/, \
					format_options_handler.c format_options_helpers.c format_options_invalid.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/list_handler/, \
			  		format_linked_list.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/print_args/, \
			  		print_args.c print_args_utils.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/print_args/width_handler/, \
			  		width_handler.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/print_args/print_helpers/, \
			  		ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_percent.c \
					ft_print_ptr.c ft_print_str.c ft_print_uint.c) \
			  $(addprefix $(PRINTF_UTILS_PATH)/print_args/flags_handler/, minus_zero_flag_handler.c) \
			   


OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
INCLUDES_PRINTF_GNL = ./includes
NAME = libft.a
INCLUDES = ./

NAME_BONUS = libft_bonus.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib
RM = rm -rf

%.o:	%.c
	@$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

$(PRINTF_PATH)/%.o:	$(PRINTF_PATH)/%.c
	@$(CC) $(CFLAGS) -c -I$(INCLUDES) -I$(INCLUDES_PRINTF_GNL) $< -o $(<:%.c=%.o)

$(GNL_PATH)/%.o:	$(GNL_PATH)/%.c
	@$(CC) $(CFLAGS) -c -I$(INCLUDES) -I$(INCLUDES_PRINTF_GNL) $< -o $(<:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(AR) $(NAME) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(RANLIB) $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(AR) $(NAME_BONUS) $(OBJS_BONUS) $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)
	@$(RANLIB) $(NAME_BONUS)
	@\cp -r $(NAME_BONUS) $(NAME)

bonus: $(NAME_BONUS)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS) $(OBJS_PRINTF) $(OBJS_GNL)

fclean:	clean
	@$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY:	all clean fclean re