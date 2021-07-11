LDFLAGS+=-lsystemd
EXECUTABLE=konsole-launcher
all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
