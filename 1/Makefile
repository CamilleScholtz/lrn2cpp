CC ?= gcc

INCS = -I . -I /usr/include
LIBS = -lc `pkg-config --libs x11`

CFLAGS  += -Wall -Wextra -lstdc++ $(INCS)
CPPLAGS += $(CFLAGS)
LDFLAGS += $(LIBS)

1: circle.* fill.* house.* line.* rectangle.* street.* window.* main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
