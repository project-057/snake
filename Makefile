CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12
CLANG-TIDY=clang-tidy12

LIBS=-lm -lncurses
CFLAGS=-Wall -Werror -std=c99 -O2 ${LIBS}
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

.PHONY: istidy
istidy: ${DEPS}
	${CLANG-TIDY} ${DEPS} -- ${CFLAGS}
	
.PHONY: clean
clean:
	${RM} snake
