objects_test = test.o
include = -I/usr/include/cppconn
link = -L/usr/lib -lmysqlcppconn

vpath %.c source
vpath %.h header

main : $(objects_test)
	clang++ -g -Wall -std=c++11 -fstandalone-debug $(objects_test) $(link) -o main
$(objects_test) :
	clang++ -c -g -Wall -std=c++11 -fstandalone-debug $(include) instance_1.cpp -o test.o

.PHONY : clean
clean :
	rm main $(objects_test)
