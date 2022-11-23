all: colorPalette

liballegro=-L./libraries/allegro/lib -lalleg
incallegro=-I./libraries/allegro/include
LIBRARIES=LD_LIBRARY_PATH=./libraries/allegro/lib

colorPalette:
	g++ -std=c++11 colorPalette.cpp -g -O0 $(incallegro) $(liballegro) -o colorPalette

run:
	$(LIBRARIES) ./colorPalette

clean:
	rm -rf visualizer_*
	rm -rf mainGenerator


