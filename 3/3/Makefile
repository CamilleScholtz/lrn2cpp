CC ?= gcc

INCS = -I . -I /usr/include
LIBS = -lc `pkg-config --libs x11`

CFLAGS  += -Wall -Wextra -lstdc++ $(INCS)
CPPLAGS += $(CFLAGS)
LDFLAGS += $(LIBS)

3: ball.* circle.* drawable.* line.* rectangle.* vector.* victim.* wall.* window.* main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
