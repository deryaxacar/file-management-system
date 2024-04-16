# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = file_management_app

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(TARGET)

# Linking executable
$(TARGET): $(OBJS)
	@echo "\033[1;32mLinking executable...\033[0m"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\033[1;32mExecutable generated: $@\033[0m"

# Compiling source files
%.o: %.c
	@echo "\033[1;34mCompiling $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "\033[1;33mCleaning object files...\033[0m"
	rm -f $(OBJS)

# Clean object and binary files
fclean: clean
	@echo "\033[1;33mCleaning object and binary files...\033[0m"
	rm -f $(TARGET)

# Clean and rebuild
re: fclean all
