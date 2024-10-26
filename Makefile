default:
	g++ ../src/*.cpp -o Game.exe -02 -Wall -Wno-missing-braces -I ../include/ -L ../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm