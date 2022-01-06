CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12

LIBS=-lm
CFLAGS=-Wall -Wextra -Werror -std=c99 -O2 ${LIBS}
SRC=src/snake.c src/game.c src/utils.c
DEPS=${SRC} src/utils.h src/game.h

.PHONY: all
all: snake

snake: ${DEPS}
	${CC} -o $@ ${SRC} ${CFLAGS}

.PHONY: format
format: ${DEPS}
	${CLANG-FORMAT} -i ${DEPS}

.PHONY: isformatted
isformatted: ${DEPS}
	${CLANG-FORMAT} -dry-run -Werror ${DEPS}

.PHONY: clean
clean:
	${RM} snake
