# VARIABLES

NAME	=	bureau.exe
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJ_DIR	=	obj/

SRCS	=	main.cpp \
			Bureaucrat.cpp
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
CYAN	=	\033[0;36m
NC		=	\033[0m

# RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully.$(NC)"

$(OBJ_DIR)%.o: %.cpp
	@if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi
	@echo "$(CYAN)Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "$(RED)Removing $(OBJ_DIR)..."; \
		rm -rf $(OBJ_DIR); \
		echo "$(RED)$(OBJ_DIR) removed.$(NC)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)Removing $(NAME)..."; \
		rm -f $(NAME); \
		echo "$(RED)$(NAME) removed.$(NC)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
