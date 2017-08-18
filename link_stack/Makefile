CC:=gcc
CFLAGS:=-g
CFLAGS+=-o
TARGET:=linkstack

$(TARGET): main.c link_stack.c
	$(CC) $(CFLAGS) $@ $^

clean:
	rm -rf $(TARGET)
