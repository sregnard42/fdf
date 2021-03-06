# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2019/01/10 14:37:23 by sregnard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

LIBFTDIR		=	libft/
LIBFT			=	$(LIBFTDIR)libft.a

MINILIBXDIR		=	minilibx/
MINILIBX		=	$(MINILIBXDIR)libmlx.a

HEADDIR			=	includes/
HEADERS			=	-I $(HEADDIR)
HEADERS			+=	-I $(LIBFTDIR)$(HEADDIR)
HEADERS			+=	-I $(MINILIBXDIR)

SRCDIR			=	srcs/
SRCNAME			= 	main.c \
					controller.c \
					errors.c \
					params.c \
					xpm.c \
					projection.c \
					projection_utils.c \
					projection_maths.c \
					draw_line.c
SRC				=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=	-g3
LINK			=	-lmlx -framework OpenGL -framework AppKit

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(MINILIBX) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(XFLAGS) \
		$(LINK) \
		$(HEADERS) \
		-o $@ $(OBJ) \
		-L $(LIBFTDIR) -lft \
		-L $(MINILIBXDIR) -lmlx

$(LIBFT)		:
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX)		:
	$(MAKE)	-C $(MINILIBXDIR)

$(OBJDIR)		:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJDIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILIBXDIR)

fclean			:	clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re				:	fclean all

cleanfdf		:
	rm -rf $(OBJDIR)

fcleanfdf		:	cleanfdf
	rm -rf $(NAME)

refdf			:	fcleanfdf all

.PHONY			:	all clean fclean re cleanfdf fcleanfdf refdf
