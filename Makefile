all: geometry.exe
geometry.exe: geometry.c
	gcc -Wall -Werror -o geometry.exe geometry.c