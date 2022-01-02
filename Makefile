CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12

LIBS=-lm
FLAGS=-std=c99 -O2 ${LIBS}
SRC=src/hello.c
DEPS=

.PHONY: all
all: hello

hello: ${DEPS} ${SRC}
	${CC} -o $@ ${FLAGS} ${SRC}

.PHONY: format
format: ${DEPS} ${SRC}
	${CLANG-FORMAT} -i ${DEPS} ${SRC}

.PHONY: clean
clean:
	${RM} hello
