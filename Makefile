dCC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBS        = 

# add directory names here if you want to separate files by directories
BINDIR = $(CURDIR)/bin/
SRCDIR = $(CURDIR)/src/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)AVLAdt.c $(SRCDIR)TreeTesting.c

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = AVLAdt.o TreeTesting.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)test


default : labLink

labLink: labCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(PROGNAME) $(OBJS) $(LIBS)

labCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)

clean:
	@ rm *.o
