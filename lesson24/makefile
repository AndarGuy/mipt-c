SRC_DIR=src
MODULES_DIR=${SRC_DIR}/modules
OBJ_DIR=obj
MODULES=$(shell find ${MODULES_DIR} -name "*.c")
SRCS=$(shell find ${SRC_DIR} -d 1 -name "*.c")
EXECUTABLES=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=))

CC=cc

CFLAGS=-Wall

.PHONY: fclean clean all

.SILENT:

all: ${SRCS}
	mkdir -p ${OBJ_DIR}
	for src in ${SRCS}; do \
	obj=$${src/".c"/""}; \
	obj=$${obj/${SRC_DIR}/${OBJ_DIR}}; \
	${CC} ${CFLAGS} ${MODULES} $$src -o $$obj; \
	done;

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

run:
	$(shell find objects -d 1 -name "*.o")
