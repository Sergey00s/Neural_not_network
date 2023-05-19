NAME=a.out
CC=gcc
SRC=main.c utils.c Network.c
OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -lm
	@echo "Done"

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "Fcleaned"

re: fclean all


.PHONY: all clean fclean re