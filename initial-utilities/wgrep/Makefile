SRCS = wgrep.c

TARG = wgrep

CC = gcc
opts = -Werror -Wall -O
LIBS = -lm

OBJS = $(SRCS:.c=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

# this is a generic rule for .o files
%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

# and finally, a clean line
clean:
	rm -f $(OBJS) $(TARG)