# Executable's name (Can be changed)

NAME		= wolf3d

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
LMTHDIR		= libmath/
MLXDIR		= ./minilibx_macos
INCDIR		= ./incs/ ./libft/ ./minilibx_macos/ ./libmath/

# Source files (Can be changed)

SRC			= deal_key.c image.c init.c main.c parsing.c print.c put_pixel.c read_file.c raycasting.c

LFT			= ./libft/libft.a
LMTH		= ./libmath/libmath.a

TOOLS		= OpenGL AppKit

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
SUBDIRS		= $(foreach dir, $(OBJSUBDIRS), $(OBJDIR)$(dir))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))
FRAMEWORKS	= $(foreach framework, $(TOOLS), -framework $(framework))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx -L$(LMTHDIR) -lmath
CFLAGS		= $(INCLUDES) #-Wall -Wextra -Werror -O3

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: $(SUBDIRS) $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC)  $(CFLAGS) $(LIBS) $(FRAMEWORKS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)
	# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library

$(LFT):
	@make -sC $(LFTDIR) -j
	@make -sC $(MLXDIR) -j
	@make -sC $(LMTHDIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFTDIR) clean
	@make -sC $(LMTHDIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(COBJ)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)

cleanLibrairy:
	@make -sC $(LFTDIR) fclean
	@make -sC $(MLXDIR) clean
	@make -sC $(LMTHDIR) fclean

re: fclean all

.PHONY: all clean fclean re
