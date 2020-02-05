# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/15 11:32:20 by kgrosjea     #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 12:15:30 by kgrosjea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

MAKEFLAGS	+= --silent

VM_FOLDER = ./vm/
ASM_FOLDER = ./asm/
LIBFT_FOLDER = ./librairies/libft

all : libft vm asm

libft:
	@make -C $(LIBFT_FOLDER)
	
vm:
	@make -C $(VM_FOLDER)

asm:
	@make -C $(ASM_FOLDER)

clean:
	@make clean -C $(VM_FOLDER)
	@make clean -C $(ASM_FOLDER)
	@make clean -C $(LIBFT_FOLDER)

fclean:
	@make fclean -C $(VM_FOLDER)
	@make fclean -C $(ASM_FOLDER)
	@make fclean -C $(LIBFT_FOLDER)

re: fclean all

norm:
	@make norm -C $(VM_FOLDER)
	@make norm -C $(ASM_FOLDER)
	@make norm -C $(LIBFT_FOLDER)

debug:
	@make debug -C $(LIBFT_FOLDER)
	@make debug -C $(VM_FOLDER)
	@make debug -C $(ASM_FOLDER)
	
.PHONY: vm asm libft clean fclean re norm debug
