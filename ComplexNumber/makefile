headers = Complex.h
sources = Complex.cpp TestComplex.cpp
executable = TestComplex
$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)
.PHONY: clean
	rm $(executable)
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
