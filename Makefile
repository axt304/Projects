PROGRAM = clock
SOURCES = clock.c model.c view.c
OBJECTS = clock.o model.o view.o
DRIVERS = LEDisplay.o
LIBRARY = -lncurses
CFLAGS  = -g -Wall -Wextra
COMPILER= gcc

.SUFFIXES:
.SUFFIXES: .c .o

.c.o: ; $(COMPILER) $(CFLAGS) -c $<

$(PROGRAM) : $(OBJECTS)
	$(COMPILER) -o $(PROGRAM) $(CFLAGS) $(OBJECTS) $(DRIVERS) $(LIBRARY)

clean: ; /bin/rm -f $(PROGRAM) $(OBJECTS) depend

# handle dependencies
depend : $(SOURCES)
	gcc -M $(SOURCES) > depend

include depend
