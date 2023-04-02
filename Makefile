all: geometry.exe
geometry.exe: src/geometry/geometry.c
	gcc -Wall -Werror -I src -o $@ $^