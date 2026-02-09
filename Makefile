#variabili
CC = gcc 
CFLAGS = -std=c99 
FILES = MainGame.c funzioni.c lista.c 
TARGET = gioco

#compilazione ed esecuzione
$(TARGET): $(FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(FILES)
	./gioco
	
#cancellazione
clean:
	rm -f *.o $(TARGET)
