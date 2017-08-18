CC = g++
  
CFLAGS  = -std=c++11
  
TARGET = test

all: $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	$(RM) $(TARGET)