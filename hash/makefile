hash: hash.o linked_list.o hashtable.o file_reader.o hash.h
	gcc -Wall -ansi -pedantic hash.o linked_list.o hashtable.o file_reader.o -o hash
hash.o: hash.c hash.h
	gcc -c -Wall -ansi -pedantic hash.c -o hash.o
linked_list.o: linked_list.c hash.h
	gcc -c -Wall -ansi -pedantic linked_list.c -o linked_list.o
hashtable.o: hashtable.c linked_list.o hash.h
	gcc -c -Wall -ansi -pedantic hashtable.c -o hashtable.o
file_reader.o: file_reader.c hash.h
	gcc -c -Wall -ansi -pedantic file_reader.c -o file_reader.o