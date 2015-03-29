CXX = g++

TARGET = test_random test_slice
object = test_random.o test_slice.o

.PHONY: echo clean
	
all:${TARGET}

test_random:test_random.o
	${CXX} -o test_random test_random.o
test_random.o:test_random.cpp 
	${CXX} -c test_random.cpp

test_slice:test_slice.o
	${CXX} -o test_slice test_slice.o
test_slice.o:test_slice.cpp util/slice.h
	${CXX} -c test_slice.cpp

echo:
	echo ${CPP_SRC}
	echo ${CPP_OBJ}

clean:
	rm -f $(TARGET) ${object} 
