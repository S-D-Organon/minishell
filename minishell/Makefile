PROG	= minishell
SRCS	= src/main.c src/reverse_split.c src/signals.c src/sort_env.c src/utils.c src/pwd_builtin.c src/echo_builtin.c src/cd_builtin.c src/env_builtin.c src/exit_builtin.c src/export_builtin.c src/unset_builtin.c
OBJS 	= ${SRCS:.c=.o}

HEADER	= -Iinclude

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER}-I/usr/include -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@printf "\033[33m----Compiling lib----\033[K\r"
					@make re -C ./Libft
					@make re -C ./printf
					@$(CC) ${OBJS} -LLibft -lft -Lprintf -lprintf -lreadline -o ${PROG}
					@printf "\033[32mMinishell Compiled!\033[K\r"

clean:
					@make clean -C ./Libft
					@make clean -C ./printf
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./Libft
					@make fclean -C ./printf
					@rm -f ${PROG}
					@printf "\033[31mDeleting EVERYTHING!\033[K\r"

re:			fclean all

.PHONY: all clean fclean re
