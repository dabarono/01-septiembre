CXX = g++
CXXFLAGS = -I
LIB = ~/local/include
PROGRAM = m3030.cpp

eigen.out:
	$(CXX) $(CXXFLAGS) $(LIB) -o $@ $(PROGRAM)
