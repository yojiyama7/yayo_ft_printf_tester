MAKEFLAGS		+= -rR
RM				= rm -f
MAKE			= make

TARGET_DIR			= ..
LIBFTPRINTF_NAME	= libftprintf.a
LIBFTPRINTF			= ftprintf
LIBFTPRINTF_PATH	= $(TARGET_DIR)/$(LIBFTPRINTF_NAME)

# LIBFTPRINTF_PATH	= $(TARGET_DIR)/$(LIBFTPRINTF_NAME)

CC				= cc
# CFLAGS			= -Wall -Wextra
CFLAGS			= -Wno-format-security
ifdef IS_DEBUG
	CFLAGS		+= -g
endif
LIBFLAGS		= -L$(TARGET_DIR) -l$(LIBFTPRINTF)
IFLAGS			= -I$(TARGET_DIR)

M_TESTS			= test_1
OBJS			= $(M_TESTS:=.o)

.PHONY: all
all: test_1
# test: $(LIBFTPRINTF_NAME) $(M_TESTS)

$(LIBFTPRINTF):
	@$(MAKE) IS_DEBUG=$(IS_DEBUG) -C $(TARGET_DIR) $(LIBFTPRINTF_NAME)

test_1: a.out
	@echo "=== [test_1] ==="
	@./a.out

a.out: $(LIBFTPRINTF) test_1.o
	$(CC) $(CFLAGS) test_1.o $(LIBFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(MAKE) -C $(TARGET_DIR) clean
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(MAKE) -C $(TARGET_DIR) fclean
	$(RM) a.out

.PHONY: re
re: fclean all
