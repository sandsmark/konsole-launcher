LDFLAGS+=-lsystemd
CFLAGS+=-Wall -Wextra -pedantic
EXECUTABLE=konsole-launcher
all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
