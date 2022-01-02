CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12

LIBS=-lm
CFLAGS=-std=c99 -O2 ${LIBS}
SRC=src/snake.c
DEPS=src/utils.c

.PHONY: all
all: snake

snake: ${SRC} ${DEPS}
	${CC} -o $@ ${SRC} ${DEPS} ${CFLAGS}

.PHONY: format
format: ${DEPS} ${SRC}
	${CLANG-FORMAT} -i ${DEPS} ${SRC}

.PHONY: clean
clean:
	${RM} snake
