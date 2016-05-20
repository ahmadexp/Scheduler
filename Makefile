# Makefile for simulator.

CC = g++
CFLAGS =

PROG = Command
HDRS =
SRCS = $(PROG).cpp

OBJDIR = object
OBJS = $(OBJDIR)/$(PROG).o $(OBJDIR)/CommandFunctions.o

# compiling rules
$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

$(OBJDIR)/$(PROG).o: $(SRCS) $(OBJDIR)
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJDIR)/$(PROG).o

$(OBJDIR)/CommandFunctions.o: CommandFunctions.cpp $(OBJDIR)
	$(CC) $(CFLAGS) -c CommandFunctions.cpp -o $(OBJDIR)/CommandFunctions.o

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(PROG) $(OBJS) $(OBJDIR)
