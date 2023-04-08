CC = gcc
CFLAGS = -Wall -Wextra -Werror -I src
CPPFLAGS = -MMD
OBJ_GEO = obj/src/geometry
OBJ_LIB = obj/src/libgeometry

all: bin/geometry.exe run clean

bin/geometry.exe: $(OBJ_GEO)/geometry.o $(OBJ_LIB)/finder.o $(OBJ_LIB)/parser.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_GEO)/geometry.o: src/geometry/geometry.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

$(OBJ_LIB)/finder.o: src/libgeometry/finder.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

$(OBJ_LIB)/parser.o: src/libgeometry/parser.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -lm

run:
	./bin/geometry.exe

clean:
	rm bin/geometry.exe $(OBJ_GEO)/*.* $(OBJ_LIB)/*.*



-include geometry.d finder.d parser.d