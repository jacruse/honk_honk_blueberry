all: song_node.o music_lib.o main.o
	gcc -o lib_test song_node.o music_lib.o main.o

song_node.o: song_node.c headers.h
	gcc -c song_node.c

music_lib.o: music_lib.c headers.h
	gcc -c music_lib.c

main.o: main.c headers.h
	gcc -c main.c

run: all
	./lib_test

clean:
	rm *.o
	rm *~
