CC:=gcc
CFLAGS:=-g
CFLAGS+=-o
TARGET:=dstring

$(TARGET): main.c dstring.c
	$(CC) $(CFLAGS) $@ $^

clean:
	rm -rf $(TARGET)
