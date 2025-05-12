NAME=philo
CC=cc
CFLAGS=-Wall -Werror -Wextra -g3

SRC=    main.c \
		src/parsing.c \
		src/init.c \
		src/get_time.c \
		src/create_thread.c \
		src/free.c \
		src/destroy_mutex.c \
		src/wait_thread.c \
		src/routine.c \
		src/check_simulation.c \
		src/ft_atoi.c \
		src/print_status.c \
		src/think_me.c \
		src/sleep_me.c \
		src/eat_me.c \
		src/take_and_drop.c \
		src/is_dead.c \
		src/stop_simulation.c \
		src/check_meal.c
		
OBJ_DIR=obj
OBJS=$(SRC:%.c=$(OBJ_DIR)/%.o)

# Create necessary directories for .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

all: $(NAME)

default: all

.PHONY: all re clean fclean