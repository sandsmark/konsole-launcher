LDFLAGS+=-lsystemd
CFLAGS+=-Wall -Wextra -pedantic
EXECUTABLE=launch-konsole
all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
