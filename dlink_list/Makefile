CC:=gcc
CFLAGS:=-g
CFLAGS+=-o
TARGET:=dlink_list

$(TARGET): main.c dlink_list.c
	$(CC) $(CFLAGS) $@ $^

clean:
	rm -rf $(TARGET)
