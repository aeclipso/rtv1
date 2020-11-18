# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:21:26 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/18 16:44:42 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
NAME = RTv1
SRC_DIR = ./src/
SRCF = main.c\
		ft_cam.c\
		ft_con.c\
		ft_count.c\
		ft_cylinder.c\
		ft_light.c\
		ft_normal.c\
		ft_plane.c\
		ft_rot.c\
		ft_sphere.c\
		ft_trace.c\
		parser.c\
		ft_valid.c
		
OBJ_DIR = ./obj/
SRC = $(addprefix $(SRC_DIR), $(SRCF))
OBJ = $(addprefix $(OBJ_DIR), $(OBJF))
OBJF = $(SRCF:.c=.o)
LIBS = libft/libft.a veclib/veclib.a
HEADERS = -I ./includes -I ./libft/include -I ./veclib
HDR = includes/rtv1.h

ifeq ($(UNAME_S), Linux)
	FLAGS = -Wall -Wextra -Werror -lm -g
	CGFLAGS = `sdl2-config --cflags --libs` -lm
else ifeq ($(UNAME_S), Darwin)
	FLAGS = -Wall -Wextra -Werror -g
	CGFLAGS =  -framework OpenGL -framework AppKit
	INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
					-I./frameworks/SDL2_mixer.framework/Headers \
					-F./frameworks/
	FRAMEWORKS	=	-F./frameworks \
					-rpath ./frameworks \
					-framework OpenGL -framework AppKit -framework OpenCl \
					-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
					-framework SDL2_mixer
endif

ifeq ($(UNAME_S), Linux)
	CC = clang
else ifeq ($(UNAME_S), Darwin)
	CC = gcc
endif

ifeq ($(UNAME_S), Linux)
	COMP = $(CC) $(CGFLAGS) $(OBJ) $(LIBS) -o $(NAME)
else ifeq ($(UNAME_S), Darwin)
	COMP = $(CC) $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
endif

ifeq ($(UNAME_S), Linux)
	RECOMP = $(CC) $(INCLUDES) $(HEADERS) -c $< -o $@
else ifeq ($(UNAME_S), Darwin)
	RECOMP = $(CC) $(INCLUDES) $(HEADERS) -c $< -o $@
endif

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)
	
$(NAME): libft/libft.a veclib/veclib.a $(OBJ) $(HDR)
	$(COMP)
	@printf "Compailing RTv1 done\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	$(RECOMP)
	
clean:
	@make clean -C libft
	@make clean -C veclib
	@rm -Rf $(OBJ)
	@rm -Rf obj

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C veclib
	@printf "All objects and binary of RTv1 was deleted\n"

libft/libft.a:
	@make -C libft

veclib/veclib.a:
	@make -C veclib
	
re: fclean all
