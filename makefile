CC = cc

main: main.o keystruct.o
	${CC} -o main keystruct.o main.o 

keystruct.o: keystruct.c keystruct.h
	${CC} -c keystruct.c

clean:
	rm *.o  main
