#Standard

NAME = libprintf.a
INCLUDES = include/
SRCS_DIR = src/
OBJS_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
RM = rm -f
AR = ar rcs
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRCS_FILES = ft_printf ft_printf_utils ft_printf_utils_second ft_printf_unsigned ft_printf_ptr ft_printf_hex

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(GREEN)---Printf compiled!---\033[K\r"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@$(RM) -r $(OBJSF)

fclean:		clean
	@$(RM) -f $(NAME)

re:	fclean all

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true
.PHONY: all clean fclean re norm
