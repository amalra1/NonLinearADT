CC = gcc
CFLAGS = -Wall -g
TARGET = main
SRCS = main.c bst.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

purge: clean
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean