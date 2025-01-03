CC = gcc
WFLAGS = -Wall -Werror -Wextra -g -g3 -ggdb

SRCDIR = srcs
OBJDIR = objs
BONUS_OBJDIR = bonus_objs
INCDIR = .
LIBFT_DIR = lib/libft

NAME = push_swap
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(shell find $(SRCDIR) -name "*.c")
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# bonus
BONUS_SRCS = $(shell find bonus -name "*.c")
BONUS_OBJS = $(patsubst bonus/%.c, $(BONUS_OBJDIR)/%.o, $(BONUS_SRCS))
BONUS_DEPS = $(BONUS_OBJS:.o=.d)

CYAN = \033[36m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(WFLAGS) -MMD -MP -I$(INCDIR) -c $< -g3 -ggdb -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(WFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)Build completed: $(NAME)$(RESET)"

# bonus
$(BONUS_OBJDIR)/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(WFLAGS) -MMD -MP -I$(INCDIR) -c $< -g3 -ggdb -o $@

bonus: $(BONUS_OBJS)
	@$(CC) $(WFLAGS) $(BONUS_OBJS) $(LIBFT) -o checker
	@echo "$(CYAN)Bonus build completed: checker$(RESET)"

clean:
	@rm -rf $(OBJDIR) $(BONUS_OBJDIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(CYAN)Project cleaned$(RESET)"

fclean: clean
	@rm -rf $(NAME) checker
	@make -C $(LIBFT_DIR) fclean
	@echo "$(CYAN)Executable removed$(RESET)"

re: fclean all

-include $(DEPS) $(BONUS_DEPS)
