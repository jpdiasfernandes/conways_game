CC      := gcc
CCFLAGS := -O2
LDFLAGS :=

TARGETS := conways
MAINS   := main.o
OBJ     := conways_game.o main.o
DEPS    := src/conways_game.h

.PHONY: clean all

all: $(TARGETS)

clean:
	rm -f $(TARGETS) $(OBJ)

$(OBJ): %.o : src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGETS): $(OBJ)
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)
