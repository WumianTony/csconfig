CXX = g++
CXXFLAGS = --std=c++17
INC = -I ./include -I ./src
SRC = $(wildcard src/*.cc)
OBJ = $(patsubst %.cc, %.o, $(SRC))
EXEC = $(basename $(notdir $(wildcard exec/*.cc)))

$(OBJ): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@ $(INC)

$(EXEC): %: exec/%.cc $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(INC) $(LIB)

.PHONY: clean

clean:
	rm $(OBJ)