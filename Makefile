NAME	= magic_tiles

SRCS	= ${wildcard */*.cpp}
OBJS	= ${SRCS:.cpp=.o}
ifeq ($(OS), Windows_NT)
	CC		= /c/msys64/mingw64/bin/g++
	CFLAGS	= -Wall -Wextra -Werror --target=x86_64-w64-windows-gnu
else
	CC		= g++
	CFLAGS	= -Wall -Wextra -g -lncurses
endif
RM		= rm -rf

all: ${NAME}

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all