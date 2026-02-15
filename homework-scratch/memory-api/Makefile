SRCS1 = stack-user.c
SRCS2 = heap-user.c

TARG1 = stack-user
TARG2 = heap-user

CC = gcc
opts = -Werror -Wall -O
LIBS = -lm

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all: $(TARG1) $(TARG2)

$(TARG1): $(OBJS1)
	$(CC) -o $(TARG1) $(OBJS1) $(LIBS)

$(TARG2): $(OBJS2)
	$(CC) -o $(TARG2) $(OBJS2) $(LIBS)

# this is a generic rule for .o files
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

# and finally, a clean line
clean:
	rm -f $(OBJS1) $(TARG1) $(OBJS2) $(TARG2)