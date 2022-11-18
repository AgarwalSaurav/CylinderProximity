CXX=g++
IDIR=include/cylinderproximity/
IDIR_FLAG=-Iinclude/
ODIR=obj/
SRCDIR=src/
BINDIR=bin/

CFLAGS=-std=c++14 -Wall -Wpedantic -O2 $(IDIR_FLAG) $(LDIR) -lgsl -lgslcblas -lm

_OBJ_ALL=Utils.o EE.o CL.o cc.o SS.o DD.o DS.o DL.o DC.o  EE_Cyl.o Robot.o  Cyl.o System.o main.o EE_CylHole.o EE_Rand.o poly_roots.o  eqsolver.o
OBJ_ALL=$(patsubst %,$(ODIR)%,$(_OBJ_ALL))

_DEPS=DL.h EE_CylHole.h EE_Rand.h DD.h EE.h CL.h eqsolver.h Cyl.h EE_Cyl.h cc.h DS.h SS.h Robot.h System.h DC.h Utils.h
DEPS=$(patsubst %,$(IDIR)%,$(_DEPS))

all: $(OBJ_ALL)
	$(CXX) $(CFLAGS) -o $(BINDIR)CylinderProximity $(OBJ_ALL)

$(ODIR)%.o: $(SRCDIR)%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

.PHONY : clean
clean :
	rm $(OBJ_ALL)

