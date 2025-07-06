# ==============================
# Makefile for strutils project
# ==============================

# Targets
STATIC_LIB = ./strutils/strutils.a
SHARED_LIB = ./strutils/strutils.so
STRUTILS_OBJ = ./strutils/strutils.o
STRUTILS_SRC = ./strutils/strutils.c

all: static shared

static: $(STRUTILS_SRC)
	gcc -c $(STRUTILS_SRC) -o $(STRUTILS_OBJ)
	ar scr $(STATIC_LIB) $(STRUTILS_OBJ)
	gcc main.c -L./strutils -l:strutils.a -o main_static

shared: $(STRUTILS_SRC)
	gcc -fPIC -c $(STRUTILS_SRC) -o $(STRUTILS_OBJ)
	gcc -shared -o $(SHARED_LIB) $(STRUTILS_OBJ)
	gcc main.c -L./strutils -l:strutils.so -o main_shared

runstatic:
	./main_static

runshared:
	LD_LIBRARY_PATH=./strutils ./main_shared

clean:
	rm -f ./strutils/*.o ./strutils/*.a ./strutils/*.so main_static main_shared