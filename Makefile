PROJECT_NAME = game

CC = g++

RAYLIB_PATH = C:/raylib/raylib

SRC = $(wildcard src/*.cpp)

INCLUDE = -I$(RAYLIB_PATH)/src
LIBPATH = -L$(RAYLIB_PATH)/src

all:
	$(CC) $(SRC) -o $(PROJECT_NAME) \
	$(INCLUDE) $(LIBPATH) \
	-lraylib -lopengl32 -lgdi32 -lwinmm