CC = gcc
CFLAGS = -Wall -Wextra -Werror -I src
CPPFLAGS = -MMD
OBJ_GEO = obj/src/geometry
OBJ_LIB = obj/src/libgeometry
LIB_PATH = obj/src/libgeometry/libgeometry.a

all: bin/geometry.exe run 

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
	rm bin/geometry.exe $(OBJ_GEO)/*.* $(OBJ_LIB)/*.*

.PHONY: all clean

-include geometry.d finder.d parser.d