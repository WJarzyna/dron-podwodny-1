CC=g++
CFLAGS=-pedantic -Wall -std=c++17 -iquote inc

DEPS=vect.hh lineq.hh matrix.hh shapes.hh 

OBJ=main.o vect_s.o matrix_s.o shapes.o API/source/Dr3D_gnuplot_api.o

PROGNAME=dron.x

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

testz: $(OBJ) 
	$(CC) -o $(PROGNAME) $(OBJ) -lpthread

clean:
	rm *.o *~ $(PROGNAME)
