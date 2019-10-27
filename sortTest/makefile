project1:main.o fun1.o fun2.o quicksort.o bubbsort.o
	gcc main.o fun1.o fun2.o quicksort.o bubbsort.o -o project1
main.o:main.c
	gcc main.c -c
fun1.o:fun1.c
	gcc fun1.c -c
fun2.o:fun2.c
	gcc fun2.c -c
quicksort.o:quicksort.c
	gcc quicksort.c -c
bubbsort.o:bubbsort.c
	gcc bubbsort.c -c
clean:
	rm -f *.o
