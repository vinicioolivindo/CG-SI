CC = gcc
TARGET = dianoite
SRC = dianoite.c

LDFLAGS_CLEAN = $(shell echo $(NIX_LDFLAGS) | sed 's/-rpath [^ ]*//g')

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(LDFLAGS_CLEAN) -lGL -lGLU -lglut -lm

clean:
	rm -f $(TARGET)

.PHONY: all clean
