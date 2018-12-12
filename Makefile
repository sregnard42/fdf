# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sregnard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:51:18 by sregnard          #+#    #+#              #
#    Updated: 2018/12/09 15:27:20 by jdugoudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

LIBFTDIR		=	libft/
LIBFT			=	$(LIBFTDIR)libft.a

HEADDIR			=	includes/
HEADERS			=	-I $(HEADDIR)
HEADERS			+=	-I $(LIBFTDIR)$(HEADDIR)

SRCDIR			=	srcs/
SRC				= 	$(SRCDIR)main.c
SRC				+= 	$(SRCDIR)errors.c

OBJDIR			=	objs/
OBJ				=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
	
CC				=	gcc	
CFLAGS			=	-Wall -Wextra -Werror
XFLAGS			=

all				: $(NAME)

$(NAME)		:	$(LIBFT) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(XFLAGS) $(HEADERS) -o $@ $(OBJ) -L $(LIBFTDIR) -lft

$(LIBFT)		:
	$(MAKE) -C libft/

$(OBJDIR)	:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $^

clean			:	
	rm -rf $(OBJDIR)
	$(MAKE) clean -C libft/

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
