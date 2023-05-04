CC		= gcc
CFLAGS		= -Wall -WExtra
LDFLAGS		= 
OBJFILES 	= lista.o main.o
TARGET		= ppp_project

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
