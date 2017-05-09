CC ?= gcc

INCS = -I . -I /usr/include

CFLAGS  += -Wall -Wextra -lstdc++ $(INCS)
CPPLAGS += $(CFLAGS)

2: vector.hpp main.cpp
	$(CC) $(CFLAGS) $^ -o $@
