CC = g++
OBJ = $(OBJDIR)/main.o $(OBJDIR)/userInput.o $(OBJDIR)/loggInput.o
OBJDIR = obj
SRCDIR = src
BINDIR = bin
CFLAGS = -c -Wall -Iinclude
TARGET = alarm
INC = -I include inc/alarm.h

.PHONY: all clean

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(BINDIR)/$(TARGET)

$(OBJDIR)/main.o:
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -c -o $@ $^

$(OBJDIR)/userInput.o:
	$(CC) $(CFLAGS) $(SRCDIR)/userInput.cpp  -c -o $@ $^

$(OBJDIR)/loggInput.o:
	$(CC) $(CFLAGS) $(SRCDIR)/loggInput.cpp  -c -o $@ $^


clean:
	$(RM) $(OBJ)