CC		=	gcc

NAME		=	client

SRC_DIR		=	src
SRC		=	$(SRC_DIR)/main.c\
			$(SRC_DIR)/helper.c\
			$(SRC_DIR)/mode.c

TEST_DIR	=	tests
SRC_TEST	=	$(TEST_DIR)/tests_client.c\

OBJ_DIR		=	.obj
INCLUDE_DIR 	=	include
LIB 		=	m

CFLAGS		=	-O3 -Wall -Wextra -Wpedantic -Wundef
CFLAGS		+=	-iquote $(INCLUDE_DIR)

TEST_FLAGS = -l criterion --coverage -g2

DEBUG_FLAGS = -ggdb -g2 $(CFLAGS)

LDFLAGS =  -L $(LIB)

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

OBJ_DEBUG = $(patsubst %.c,$(OBJ_DIR)/%_debug.o,$(SRC))

OBJ_TEST = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_TEST))

$(OBJ_DIR)/%.o: %.c
	@ echo -e "$(OK_COL){+} Build $<$(NO_COL)"
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%_debug.o: %.c
	@ echo -e "$(OK_COL){+} Build $<$(NO_COL)"
	@ mkdir -p $(@D)
	@ $(CC) $(DEBUG_FLAGS) -c -o $@ $<

NO_COL=\x1b[0m
OK_COL=\x1b[32;01m
ERR_COL=\x1b[31;01m
WARN_COL=\x1b[33;01m

.PHONY: all $(NAME) debug lean fclean unit_tests tests_run run re

all: $(NAME)

$(NAME): $(OBJ)
	@ echo -e "$(OK_COL){+} Link $@$(NO_COL)"
	@ $(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LDFLAGS)

debug: $(OBJ_DEBUG)
	@ echo -e "$(OK_COL){+} Link $(NAME)_debug$(NO_COL)"
	@ $(CC) $(OBJ_DEBUG) $(CFLAGS) -o $(NAME)_debug $(LDFLAGS)

clean:
	@ echo -e "$(ERR_COL){-} Remove $(OBJ) $(OBJ_TEST)\
		$(OBJ_DEBUG)$(NO_COL)"
	@ rm -rf $(OBJ_DIR) *.gcda *.gcno vgcore*

fclean: clean
	@ echo -e "$(ERR_COL){-} Remove $(NAME) $(NAME)_debug test$(NO_COL)"
	@ rm -rf $(NAME) test $(NAME)_debug

unit_tests: fclean $(OBJ) $(OBJ_TEST)
	@ $(CC) -o test $(OBJ_TEST) $(OBJ) $(TEST_FLAGS) $(LDFLAGS)

tests_run: unit_tests
	./test

run:	$(NAME)
	./$(NAME)

re: clean all

