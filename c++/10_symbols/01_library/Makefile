CXX = c++

SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

all: libhello.so

libhello.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -o $@ -c $< -I include/

src/hello.o: include/hello.h

format: $(SRC) include/hello.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	@rm -f *~ */*~ libgreetings.so src/*.o

.PHONY: clean all format