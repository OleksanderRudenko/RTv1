NAME = RTv1

FILES =	main \
		inites \
		events \
		error \
		draw \
		vec_operation \
		color \
		discrim \
		coords \
		light \
		spher \
		
HDRS = includes/rtv1.h

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SPEED = -O3

#add -Werror to FLAGS, in the end of the project
FLAGS = -Wall -Wextra
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework SDL2 

HEADERS = -I./includes -I./libft/

all: lib $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(SPEED) $(OBJ) $(FRAMEWORKS) libft/libft.a
	@echo "\033[1;32m 🌈  $(NAME) \033[1;0m\033[32m created.\033[0m"

libft/libft.a: lib

lib:
	@make -C ./libft/

$(OBJ): obj/%.o : src/%.c $(HDRS)
	@gcc -o $@ $(FLAG2) $(HEADERS) $(INCLUDES) -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft/
	@echo "\032[31m[ ✔ ] Objects files have been destroyed \033[91m$(OBJ_LIST)"

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft/
	@echo "\033[22;35m🔥  Objects files have been destroyed \033[91m$(OBJ_LIST)"
	@echo "\033[1;31m$(NAME) \033[22;35m destroyed."
re: fclean all
