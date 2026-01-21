CC = gcc
CFLAGS = -Wall -g

OBJS = main.o lista.o pomocnicze.o

TARGET = program.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c lista.h pomocnicze.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

pomocnicze.o: pomocnicze.c pomocnicze.h
	$(CC) $(CFLAGS) -c pomocnicze.c

clean:
	del *.o program.exe
