headers = Point.h Polygon.h
sources = Point.cpp Polygon.cpp TestPolygon.cpp
executable = TestPolygon
$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
