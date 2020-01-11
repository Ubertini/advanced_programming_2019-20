EXE = exe

LFLAGS = -lblass
CXX = c++
CXXFLAGS = -I include -std=c++11

SRC = src/src1.cc src/src2.cc
OBJ = $(SRC:.cc=.o)


all: $(EXE)

$(EXE): main.o $(OBJ)
	$(CXX) $^ -o $(EXE) $(CXXFLAGS)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


main.o: src/src1.o src/src2.o include/foo.h include/utility.h

src/src1.o: include/utility.h

src/src2.o: include/utility.h

format: $(SRC) include/utility.h 
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all

