NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[1;32m #green color
BLUE = \033[1;34m #blue color
RESET = \033[0m #reset to default color

PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

PART3 = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC = $(PART1) $(PART2) $(PART3)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)-Creating $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)-$(NAME) created successfully!$(RESET)"

%.o: %.c libft.h
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -f $(OBJ)
	@echo "$(GREEN)-object files removed successfully!$(RESET)"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(GREEN)-$(NAME) removed successfully!$(RESET)"


re: fclean all

teste: all
	@echo "Creating test executable..."
	@$(CC) $(CFLAGS) main.c $(NAME) -o teste

.PHONY: all clean fclean re