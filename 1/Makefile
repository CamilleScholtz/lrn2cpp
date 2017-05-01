CC ?= gcc

INCS = -I . -I /usr/include
LIBS = -lc `pkg-config --libs x11`

CFLAGS  += -Wall -Wextra -Werror $(INCS)
CPPLAGS += $(CFLAGS)
LDFLAGS += $(LIBS)

1: circle.hpp circle.o fill.hpp fill.o street.hpp street.o line.hpp line.o rectangle.hpp rectangle.o window.hpp window.o main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
