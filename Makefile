locadora : main.o warrior.o dragon.o element.o rent.o
	gcc -o locadora main.o warrior.o dragon.o element.o rent.o

main.o : main.c 
	gcc -c main.c
warrior.o : includes/warrior.c includes/warrior.h
	gcc -c includes/warrior.c
dragon.o : includes/dragon.c includes/dragon.h
	gcc -c includes/dragon.c
element.o : includes/element.c includes/element.h
	gcc -c includes/element.c
rent.o : includes/rent.c includes/rent.h
	gcc -c includes/rent.c

clean :
	rm	main.o warrior.o dragon.o element.o rent.o