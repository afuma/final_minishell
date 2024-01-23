
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main.c \
			transform_enum.c \
			syntax/syntax.c \
			syntax/syntax_utils_1.c \
			syntax/syntax_utils_2.c \
			syntax/syntax_utils_3.c \
			lexer/lexer.c \
			lexer/lexer_token.c \
			lexer/lexer_utils_1.c \
			lexer/lexer_utils_2.c \
			lexer/lexer_print.c \
			parser/parser.c \
			parser/parser_tab_exec.c \
			parser/parser_redir.c \
			parser/parser_redir_utils.c \
			parser/parser_utils_1.c \
			parser/parser_utils_2.c \
			parser/parser_node.c \
			parser/parser_getters.c \
			parser/parser_type_token.c \
			parser/parser_quote.c \
			parser/parser_print.c \
			expander/expander.c \
			expander/expander_utils_1.c \
			expander/expander_utils_2.c \
			trim.c \
			error.c \
			free/free.c \
			free/free_2.c \
			# off_main.c \
			# builtins/ft_echo.c \
			# builtins/ft_env.c \
			# builtins/ft_exit.c \
			# builtins/ft_pwd.c \
			# builtins/ft_unset.c \
			# builtins/ft_export.c \
			# exec/exec.c \
			# exec/file_redir.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# DEPS = $(OBJ:.o=.d)

# Modification des règles pour utiliser les nouveaux chemins d'objets
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = gcc # CC = clang
CFLAGS = -Wall -Wextra -Werror -g # -MMD -MP
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
INCLUDES = -I ./include

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = minishell
TEST_NAME = run_tests
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) bonus
	@echo $(CYAN) " - Compiling $@" $(RED)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_FLAGS) -lreadline
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	@${RM} -r $(OBJ_DIR)
	# @${RM} $(DEPS)
	@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} fclean
	
fclean: clean
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
	@${RM} $(NAME)

re: fclean all

.PHONY:		all clean fclean re

# -include $(DEPS)