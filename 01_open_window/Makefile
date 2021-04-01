NAME := test_input
FILENAMES := main
LIBS := mlx X11 Xext
LIBDIRS := ../mlx/
HEADERDIRS := $(LIBDIRS)

OBJ := $(addsuffix .o,$(FILENAMES))

CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
LIBFLAGS := $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS))
CFLAGS := $(CFLAGS) -Wall -Werror -Wextra $(HEADERFLAGS) $(LIBFLAGS)
OFLAGS := $(HEADERFLAGS)



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
