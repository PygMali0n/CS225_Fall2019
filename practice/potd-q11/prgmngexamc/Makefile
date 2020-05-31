EXENAME = main
OBJS = main.o
TEST = tests.o
CATCH = catchmain.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp exam.cpp
	$(CXX) $< $(CXXFLAGS)
tests.o: tests.cpp exam.cpp
	$(CXX) $< $(CXXFLAGS)
catchmain.o: catch/catchmain.cpp
	$(CXX) $< $(CXXFLAGS)
test: $(TEST) $(CATCH)
		$(LD) $^ $(LDFLAGS) -o test
clean:
	-rm -f *.o $(EXENAME)
