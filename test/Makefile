NAME = pipex
NAME_BONUS = pipex_bonus
PIPEX_PATH = ../
MAKE = make --no-print-directory
VALGRIND = valgrind -s --leak-check=full --show-leak-kinds=all --trace-children=yes --gen-suppressions=yes --verbose --log-fd=9 

all:	$(NAME)

CMD = ../infile "grep a" "wc -w" ../outfile 
NORMINETTES_PATH = $(shell find ../ -maxdepth 1 -type d | tr '\n' ' ')

$(NAME):
	@$(MAKE) all -C $(PIPEX_PATH)

$(NAME_BONUS):
	@$(MAKE) bonus -C $(PIPEX_PATH)

run:	$(NAME)
	@$(VALGRIND) ./$(PIPEX_PATH)$(NAME) $(CMD) 9>memcheck.log

run_bonus:	$(NAME_BONUS)
	@$(VALGRIND) ./$(PIPEX_PATH)$(NAME_BONUS) $(CMD) 9>memcheck.log

clean:
	@$(MAKE) clean -C $(PIPEX_PATH) 

fclean:	clean
	@$(MAKE) fclean -C $(PIPEX_PATH)

norm:
	norminette $(NORMINETTES_PATH) ../so_long.c

re:	fclean all

.PHONY: all clean fclean re