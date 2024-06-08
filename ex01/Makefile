# VARIABLES

NAME	=	bureau
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp

GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
CYAN	=	\033[0;36m
NC		=	\033[0m

# RULES

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(CYAN)Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(NC) created."

clean:
	@echo "$(YELLOW)No object files to remove.$(NC)"

fclean:
	@echo "$(RED)Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re
