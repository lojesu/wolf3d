# Executable's name (Can be changed)

NAME		= wolf3d

# All the directories needed to know where files should be (Can be changed)

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
LMTHDIR		= libmath/
MLXDIR		= ./minilibx_macos
LVECDIR		= libvec/
INCDIR		= ./incs/ ./libft/ ./minilibx_macos/ ./libmath/ ./libvec/inc/

# Source files (Can be changed)

SRC			= main.c				\
			event/map.c				\
			event/move.c				\
			event/other.c				\
			event/rotation.c			\
			event/deal_key.c			\
			map/color.c				\
			map/map.c				\
			map/mini_map.c				\
			parsing/init.c				\
			parsing/parsing.c			\
			parsing/read_file.c			\
			parsing/read_bmp.c			\
			print/bresenham.c			\
			print/image.c				\
			print/print.c				\
			print/put_pixel.c			\
			raycasting/raycasting.c			\
			raycasting/raycastool.c			\
			special_bloc/speed_walk.c		\
			special_bloc/special_bloc_manager.c	\
			special_bloc/other_special_bloc.c

LFT			= ./libft/libft.a
LVEC			= ./libvec/libvec.a
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
LIBS		= -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx -L$(LMTHDIR) -lmath  -L$(LVECDIR) -lvec
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror -O3

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: $(SUBDIRS) $(NAME)

$(NAME): COMP_LIB $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC)  $(CFLAGS) $(LIBS) $(FRAMEWORKS) -o $(NAME) $(COBJ)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/event
	@mkdir -p $(OBJDIR)/map
	@mkdir -p $(OBJDIR)/parsing
	@mkdir -p $(OBJDIR)/print
	@mkdir -p $(OBJDIR)/raycasting
	@mkdir -p $(OBJDIR)/special_bloc

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)
	# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library

COMP_LIB:
	@make -sC $(LFTDIR) -j
	@make -sC $(LVECDIR) -j
	@make -sC $(MLXDIR) -j
	@make -sC $(LMTHDIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFTDIR) clean
	@make -sC $(LVECDIR) clean
	@make -sC $(LMTHDIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(COBJ)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)

cleanLibrary:
	@make -sC $(LFTDIR) fclean
	@make -sC $(LVECDIR) fclean
	@make -sC $(MLXDIR) clean
	@make -sC $(LMTHDIR) fclean

re: fclean all

.PHONY: all clean fclean re
