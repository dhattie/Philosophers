#----------------------------		Target		----------------------------------
NAME = philo
NAME_BONUS = philo_bonus
#---------------------------------------------------------------------------------
#
CC = gcc -g
CFLAGS =
#---------------------------	Libft library	----------------------------------
LIB = libft.a
LDIR = libft

#---------------------------------------------------------------------------------
INC			=	./includes
SRCS		=	actions.c	check.c	create_push.c	main.c	utils.c
SRCS_DIR	=	src/
OBJ_DIR		= objs/
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o) $(GNL_SRS:.c=.o))
#---------------------------------------------------------------------------------
SRCS_DIR_B	=	src_bonus/
SRCS_B		=	bonus_actions.c	bonus_check.c bonus_create_push.c bonus_main.c bonus_utils.c
OBJS_B		= $(addprefix $(OBJ_DIR), $(SRCS_B:.c=.o) $(GNL_SRS:.c=.o))

#---------------------------------------------------------------------------------
all: makedir $(LIB) $(NAME)
	@echo "$(NAME) is ready"

makedir:
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LDIR) --silent
	@cp $(LDIR)/libft.h $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC) $(OBJS) $(LDIR)/$(LIB) -o $(NAME)

bonus:	makedir $(LIB) $(OBJS_B)
	$(CC) $(CFLAGS) -I$(INC) $(OBJS_B) $(LDIR)/$(LIB) -o $(NAME_BONUS)
	@echo "$(NAME_BONUS) is ready"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_DIR)%.o: $(SRCS_DIR_B)%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LDIR) clean --silent
	@rm -rf $(OBJ_DIR)
	clear
	@echo "All $(R)OBJS$(DF) deleted."

fclean: clean
	@$(MAKE) -C $(LDIR) fclean --silent
	rm -f $(NAME) $(NAME_BONUS)
	clear
	@echo "$(R)All created files deleted.$(DF)"

re: fclean all

norm:
	norminette $(SRCS_DIR)
	norminette $(SRCS_DIR_B)
	norminette $(INC)
	norminette $(LDIR)

.PHONY: clean fclean re bonus norm
