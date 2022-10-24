all: compile link run

compile:
	g++ -c main.cpp Game.cpp Platform.cpp Player.cpp Collision.cpp -I"C:\SFML-2.5.1\include" -DSFML_STATIC
 
link:
	g++ main.o Game.o Platform.o Player.o Collision.o -o main -L"C:\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 
#add -mwindows -lsfml-main above for no "terminal", or output for cygwin
clean:
	rm -f main *.o 

run: compile
	./main
