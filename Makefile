# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:15:18 by mmaj              #+#    #+#              #
#    Updated: 2020/02/26 18:03:42 by mmaj             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_init.c ft_printf_type_c.c ft_printf_type_di.c\
		ft_printf_type_s.c ft_printf_utils.c ft_printf.c ft_printf_type_prcent.c\
		ft_printf_type_p.c ft_printf_type_u.c ft_printf_type_x.c ft_printf_type_gx.c\
		ft_printf_utils2.c ft_printf_utils3.c

OBJECTS = ft_printf_init.o ft_printf_type_c.o ft_printf_type_di.o\
		ft_printf_type_s.o ft_printf_utils.o ft_printf.o ft_printf_type_prcent.o\
		ft_printf_type_p.o ft_printf_type_u.o ft_printf_type_x.o ft_printf_type_gx.o\
		ft_printf_utils2.o ft_printf_utils3.o

SRCS_BONUS = ft_printf_init.c ft_printf_type_c.c ft_printf_type_di.c\
		ft_printf_type_s.c ft_printf_utils.c ft_printf.c ft_printf_type_prcent.c\
		ft_printf_type_p.c ft_printf_type_u.c ft_printf_type_x.c ft_printf_type_gx.c\
		ft_printf_utils2.c ft_printf_utils3.c

OBJECTS_BONUS = ft_printf_init.o ft_printf_type_c.o ft_printf_type_di.o\
		ft_printf_type_s.o ft_printf_utils.o ft_printf.o ft_printf_type_prcent.o\
		ft_printf_type_p.o ft_printf_type_u.o ft_printf_type_x.o ft_printf_type_gx.o\
		ft_printf_utils2.o ft_printf_utils3.o

INCLUDES = ./

all : $(NAME) bonus

$(NAME) :

	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus :

	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS_BONUS)
	@ar rc $(NAME) $(OBJECTS_BONUS)
	ranlib $(NAME)

clean : 
	@/bin/rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
