all: colorPalette gameoflife

liballegro=-L./libraries/allegro/lib -lalleg
incallegro=-I./libraries/allegro/include
LIBRARIES=LD_LIBRARY_PATH=./libraries/allegro/lib

colorPalette:
	g++ -std=c++11 colorPalette.cpp -g -O0 $(incallegro) $(liballegro) -o colorPalette

gameoflife:
	g++ -std=c++11 gameoflife.cpp -g -O0 $(incallegro) $(liballegro) -o gameoflife


run:
	$(LIBRARIES) ./colorPalette

rungameoflife:
	$(LIBRARIES) ./gameoflife

clean:
	rm gameoflife colorPalette


