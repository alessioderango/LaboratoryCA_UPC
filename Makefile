all: colorPalette

liballegro=-L./libraries/allegro/lib -lalleg
incallegro=-I./libraries/allegro/include
LIBRARIES=LD_LIBRARY_PATH=./libraries/allegro/lib

colorPalette:
	g++ -std=c++11 colorPalette.cpp -g -O0 $(incallegro) $(liballegro) -o colorPalette

gameoflife:
	g++ -std=c++11 gameoflife.cpp -g -O0 $(incallegro) $(liballegro) -o GameOfLife


run:
	$(LIBRARIES) ./colorPalette

runGameofLife:
	$(LIBRARIES) ./GameOfLife

clean:
	rm -rf visualizer_*
	rm -rf mainGenerator


