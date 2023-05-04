CC			= gcc
CFLAGS		=
LDFLAGS		= 
OBJFILES 	= function.o server.o
TARGET		= news_server

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~