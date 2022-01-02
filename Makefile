CC=gcc
RM=rm -f
CLANG-FORMAT=clang-format12

LIBS=-lm
FLAGS=-std=c99 -O2 ${LIBS}
SRC=src/aplusb.c
DEPS=

.PHONY: all
all: hello aplusb

hello: ./src/hello.c ${DEPS} 
	${CC} -o $@ ${FLAGS} ./src/hello.c

aplusb: ./src/aplusb.c ${DEPS} 
	${CC} -o $@ ${FLAGS} ./src/aplusb.c

.PHONY: format
format: ${DEPS} ${SRC}
	${CLANG-FORMAT} -i ${DEPS} ${SRC}

.PHONY: clean
clean:
	${RM} hello aplusb
