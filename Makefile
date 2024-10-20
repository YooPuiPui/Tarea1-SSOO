EXEC = Tarea1

CXX = g++

CXXFLAGS = -std=c++11 -pthread

SRCS = Tarea1.cpp

all: $(EXEC)

$(EXEC): $(SRCS)
        $(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)
clean:
        rm -f $(EXEC)
