CXX = g++
CXXFLAGS = -std=c++11 -pthread

TARGET = tarea1
SRCS = tarea1.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
         $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
        rm -f $(TARGET)
