CC = gcc
CFLAGS = -Wall -Wextra -Werror -I src
CPPFLAGS = -MMD
OBJ_GEO = obj/src/geometry
OBJ_LIB = obj/src/libgeometry
LIB_PATH = obj/src/libgeometry/libgeometry.a
TEST_OBJ = obj/test

all: bin/geometry.exe

bin/geometry.exe: $(OBJ_GEO)/geometry.o $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(OBJ_GEO)/geometry.o: src/geometry/geometry.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

$(LIB_PATH): $(OBJ_LIB)/calculator.o $(OBJ_LIB)/parser.o
	ar rcs $@ $^

$(OBJ_LIB)/calculator.o: src/libgeometry/calculator.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

$(OBJ_LIB)/parser.o: src/libgeometry/parser.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

run:
	./bin/geometry.exe

clean:
	rm  -f bin/*.exe $(OBJ_GEO)/*.* $(OBJ_LIB)/*.* $(TEST_OBJ)/*.*

test: bin/geometry-test.exe
	./bin/geometry-test.exe

bin/geometry-test.exe: $(TEST_OBJ)/main.o $(TEST_OBJ)/ctest.o $(LIB_PATH)
	$(CC) -I src -I thirdparty $^ -o bin/geometry-test.exe -lm

$(TEST_OBJ)/main.o: test/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I thirdparty -c $< -o $@

$(TEST_OBJ)/ctest.o: test/ctest.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I thirdparty -c $< -o $@

.PHONY: all clean test

-include geometry.d finder.d parser.d main.d ctest.d