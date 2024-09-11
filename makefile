#compiler name
CXX = g++

# target executable

TARGET = main

# for deleting the target
TARGET_DEL = main.exe

# source files
SRC = main.cpp keyboard_IP.cpp gotoXY.cpp gameLogic.cpp Box.cpp gameSetup.cpp globalVariables.cpp

# object files
OBJ = $(SRC:.cpp=.o)

all : $(TARGET) run

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

.PHONY: clean
clean:
	del $(TARGET_DEL) $(OBJ)