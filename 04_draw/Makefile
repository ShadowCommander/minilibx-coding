NAME := test_input
FILENAMES := main ft_mlx_input
LIBS := mlx Xext X11
LIBDIRS := ../mlx/
HEADERDIRS := . $(LIBDIRS)

OBJ := $(addsuffix .o,$(FILENAMES))

CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
LIBFLAGS := $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS))
OFLAGS := $(CFLAGS) $(HEADERFLAGS)
CFLAGS := $(CFLAGS) -Wall -Werror -Wextra $(HEADERFLAGS) $(LIBFLAGS)



all: $(NAME)

test: all
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.c
	$(CC) $(OFLAGS) -c $<

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
