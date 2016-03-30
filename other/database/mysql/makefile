objects_mydb = MyDB.o

vpath %.c source
vpath %.h header

main : $(objects_mydb)
	g++ -g -Wall $(objects_mydb) `mysql_config --cflags --libs` -o main

$(objects_mydb) : MyDB.h
	g++ -c -g -Wall MyDB.cpp -o MyDB.o

.PHONY : clean
clean :
	rm main $(objects_mydb)
