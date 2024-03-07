
static: main.c _build/
	gcc -o _build/app.exe \
		*.c \
		-lSDL2

run: _build/app.exe
	_build/app.exe

clean: _build/
	rm _build/*
