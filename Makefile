LDFLAGS+=-lsystemd
CFLAGS+=-Wall -Wextra -pedantic
EXECUTABLE=launch-konsole
all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

install: $(EXECUTABLE)
	install -D -m755 $(EXECUTABLE) $(DESTDIR)/usr/bin/$(EXECUTABLE)
