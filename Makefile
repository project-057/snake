CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12
CLANG-TIDY=clang-tidy12

LIBS=-lm
CFLAGS=-Wall -Werror -std=c99 -O0 -g ${LIBS}
SRC=src/snake.c src/game.c src/utils.c
DEPS=${SRC} src/utils.h src/game.h
VALGRIND=valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

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
	
.PHONY: valgrind_check
valgrind_check: 
	${VALGRIND} ./$@

.PHONY: clean
clean:
	${RM} snake
