# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 11:44:05 by aeclipso          #+#    #+#              #
#    Updated: 2020/10/24 14:38:01 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRS1=./ft_to/ft_bzero.c\
	./ft_to/ft_tolower.c\
	./ft_to/ft_itoa.c\
	./ft_to/ft_itoa_base.c\
	./ft_to/ft_toupper.c\
	./ft_to/ft_atoi.c\
	./ft_to/ft_tozero2.c\
	./ft_to/ft_tozero3.c\
	./ft_to/ft_tozero4.c\
	./ft_to/ft_tozero2_int.c\
	./ft_to/ft_tozero3_int.c\
	./ft_to/ft_tozero4_int.c\
	./ft_mem/ft_memcpy.c\
	./ft_mem/ft_memchr.c\
	./ft_mem/ft_memcmp.c\
	./ft_mem/ft_memalloc.c\
	./ft_mem/ft_memdel.c\
	./ft_mem/ft_memmove.c\
	./ft_mem/ft_memccpy.c\
	./ft_mem/ft_memset.c\
	./ft_is/ft_isalpha.c\
	./ft_is/ft_isdigit.c\
	./ft_is/ft_isascii.c\
	./ft_is/ft_isprint.c\
	./ft_is/ft_isalnum.c\
	./ft_str/ft_strlen.c\
	./ft_str/ft_strncpy.c\
	./ft_str/ft_strcat.c\
	./ft_str/ft_strdup.c\
	./ft_str/ft_strcpy.c\
	./ft_str/ft_strchr.c\
	./ft_str/ft_strnstr.c\
	./ft_str/ft_strstr.c\
	./ft_str/ft_strncat.c\
	./ft_str/ft_strlcat.c\
	./ft_str/ft_strrchr.c\
	./ft_str/ft_strcmp.c\
	./ft_str/ft_strncmp.c\
	./ft_str/ft_strnew.c\
	./ft_str/ft_strdel.c\
	./ft_str/ft_strclr.c\
	./ft_str/ft_striter.c\
	./ft_str/ft_striteri.c\
	./ft_str/ft_strmap.c\
	./ft_str/ft_strmapi.c\
	./ft_str/ft_strequ.c\
	./ft_str/ft_strnequ.c\
	./ft_str/ft_strsub.c\
	./ft_str/ft_strjoin.c\
	./ft_str/ft_strtrim.c\
	./ft_str/ft_strreverse.c\
	./ft_str/ft_strsplit.c\
	./ft_str/ft_strjoinoneletter.c\
	./ft_str/ft_strchrn.c\
	./ft_str/ft_strchrnor.c\
	./ft_str/ft_strjoin_free.c\
	./ft_str/ft_strdup_prot.c\
	./ft_str/ft_strlen_prot.c\
	./ft_put/ft_putchar_fd.c\
	./ft_put/ft_putstr_fd.c\
	./ft_put/ft_putchar.c\
	./ft_put/ft_putstr.c\
	./ft_put/ft_putendl.c\
	./ft_put/ft_putendl_fd.c\
	./ft_put/ft_putnbr_fd.c\
	./ft_put/ft_putnbr.c\
	./other/ft_longover.c\
	./other/ft_power.c\
	./other/ft_whatismyint.c\
	./other/ft_countw.c\
	./other/ft_copyword.c\
	./other/ft_lengthcounter.c\
	./other/ft_abs.c\
	get_next_line.c\
	./ft_str/ft_strtoupper.c\
	./ft_str/ft_strtolower.c\
	./ft_lst/ft_lstadd_back.c\
	./ft_lst/ft_lstadd_front.c\
	./ft_lst/ft_lstclear.c\
	./ft_lst/ft_lstdelone.c\
	./ft_lst/ft_lstiter.c\
	./ft_lst/ft_lstlast.c\
	./ft_lst/ft_lstnew.c\
	./ft_lst/ft_lstsize.c\
	./ft_lst/ft_lstmap.c\
	./src_ftprintf/ft_printf.c\
	./src_ftprintf/parser.c\
	./src_ftprintf/manage_p.c\
	./src_ftprintf/manage_d.c\
	./src_ftprintf/manage_u.c\
	./src_ftprintf/manage_o.c\
	./src_ftprintf/manage_x.c\
	./src_ftprintf/manage_csper.c\
	./src_ftprintf/manage_f.c\
	./src_ftprintf/manage_buffer.c\
	./src_ftprintf/utils.c\
	./src_ftprintf/f_bigint1.c\
	./src_ftprintf/f_bigint2.c\
	./src_ftprintf/f_counter1.c\
	./src_ftprintf/f_counter2.c\
	./src_ftprintf/f_round.c\
	./src_ftprintf/f_tochar2.c\
	./src_ftprintf/f_tochar1.c\
	./src_ftprintf/f_util.c\
	./src_ftprintf/f_util2.c


OBJ1=$(SRS1:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ1)
	@ar rc $(NAME) $(OBJ1)
	@ranlib $(NAME)

$(OBJ1): %.o: %.c
		@gcc $(FLAGS) -I ./include -o $@ -c $<

clean:
	@rm -f $(OBJ1)

fclean: clean
	@rm -f $(NAME)

re: fclean all
