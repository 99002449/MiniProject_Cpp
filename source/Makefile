all: all.out 
all.out : cropparent.o cropchild.o cropdb.o croptest.o cropdbtest.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
cropdbtest.o: cropdbtest.cpp cropparent.h cropchild.h cropdb.h
	g++ $< -c
croptest.o: croptest.cpp cropparent.h cropchild.h
	g++ $< -c
cropdb.o:cropdb.cpp cropdb.h cropchild.h cropparent.h
	g++ $< -c
cropchild.o : cropchild.cpp cropchild.h cropparent.h
	g++ $< -c    
cropparent.o : cropparent.cpp cropparent.h
	g++ $< -c
clean:
	rm -rf *.o *.out
