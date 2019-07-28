# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:58:18 by nalexand          #+#    #+#              #
#    Updated: 2019/07/29 02:19:34 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = libftprintf.a
LIBFT = libft.a
C_FLAGS = -g -Wall -Werror -Wextra
HEADER = -I includes
PF_HEAD = ./includes/ft_printf.h
LFT_HEAD = ./includes/libft.h

SRC_DIR = src/
OBJ_DIR = obj/
PF_DIR = ft_printf/
LFT_DIR = libft/
GNL_DIR = gnl/

LFT_SRC =	ft_arraydel.c \
			ft_satoi.c \
			ft_atoi.c \
			ft_btoa.c \
			ft_bzero.c \
			ft_emalloc.c \
			ft_intlen.c \
			ft_isint.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstclear.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpushback.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memdup.c \
			ft_memjoin.c \
			ft_memmove.c \
			ft_memrev.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_puterr.c \
			ft_read_to_str.c \
			ft_reverse_bits.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclen.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strcskp.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strsskp.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strccount.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wrdcount.c \
			ft_atoi_base.c \
			ft_power.c \
			ft_check_file_format.c \
			ft_lstcount.c \

GNL_SRC =	get_next_line.c \
			clear_fd_node.c \
			write_func.c

PF_SRC =	ft_printf.c \
			pf_ltoa_base.c \
			pf_get_params.c \
			pf_parce.c \
			pf_set_params.c \
			pf_set_zero.c \
			pf_set_task.c \
			pf_set_arg_digit.c \
			pf_solve_digit.c \
			pf_solve_pcsn.c \
			pf_solve_float.c \
			pf_solve_bits.c \
			pf_get_ldbl.c \
			pf_get_float_mod.c \
			pf_get_float_div.c \
			pf_add_lnbr.c \
			pf_multi_lnbr.c \
			pf_lnbr.c \
			pf_unicode.c \
			pf_solve_unicode.c \
			pf_colors.c \
			pf_fun.c \
			pf_debug.c

LFT_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(LFT_SRC)))
PF_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PF_SRC)))
GNL_OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(GNL_SRC)))

all: $(FT_PRINTF)

$(FT_PRINTF): $(LFT_OBJ) $(PF_OBJ) $(GNL_OBJ)
	@ar rc $@ $^
	ranlib $@
$(LIBFT): $(LFT_OBJ) $(GNL_OBJ)
	@ar rc $@ $^
	ranlib $@

$(OBJ_DIR)%.o: $(SRC_DIR)$(LFT_DIR)%.c $(LFT_HEAD) $(GNL_HEAD)
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)$(PF_DIR)%.c $(PF_HEAD) $(LFT_HEAD) $(GNL_HEAD)
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)
$(OBJ_DIR)%.o: $(SRC_DIR)$(GNL_DIR)%.c $(GNL_HEAD) $(LFT_HEAD)
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(FT_PRINTF)

re: fclean all
