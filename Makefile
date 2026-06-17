CC = gcc
TARGET = dianoite
SRCS = main.c \
       animation/animation.c \
       draw/house.c \
       draw/person.c \
       draw/shapes.c \
       draw/sky.c \
       draw/smoke.c \
       draw/tree.c \
       input/keyboard.c \
       state/scene.c

LDFLAGS_CLEAN = $(shell echo $(NIX_LDFLAGS) | sed 's/-rpath [^ ]*//g')

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(LDFLAGS_CLEAN) -lGL -lGLU -lglut -lm

clean:
	rm -f $(TARGET)

.PHONY: all clean
