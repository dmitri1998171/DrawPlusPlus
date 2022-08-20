BIN := main
TEST := test
SRC := main.cpp
SRC_TEST := test.cpp
CC := g++
LIB_PATH := -L/System/Library/Frameworks
LDFLAGS := -framework GLUT -framework OpenGL -framework Cocoa
CFLAGS := -Wno-deprecated-declarations

all:
	clear && $(CC) $(SRC) $(LIB_PATH) $(LDFLAGS) $(CFLAGS) -o $(BIN)

test:
	clear && $(CC) $(SRC_TEST) $(LIB_PATH) $(LDFLAGS) $(CFLAGS) -o $(TEST)

clean:
	rm -rf $(BIN)