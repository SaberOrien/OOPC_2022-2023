headers = Employee.h Map.h Book.h KeyDoesNotExistException.h

sources = TestMap.cpp Employee.cpp Book.cpp KeyDoesNotExistException.cpp

executable = TestMap

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
