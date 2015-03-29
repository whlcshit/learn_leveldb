CXX = g++



#	all: $(TARGET)
#$(TARGET): $(OBJS)
#	$(CXX) -o $@ $^
#

#object = test1.o test.o test_random.o test_slice.o

#all: test1 test test_random test_slice

CPP_SRC = $(wildcard *.cpp)  
CPP_OBJ = $(patsubst %cpp, %o, $(CPP_SRC)) 

all:$(CPP_OBJ)  

.cpp.o:
	g++ -o $@ $< 
	


echo:
	echo ${CPP_SRC}
	echo ${CPP_OBJ}

clean:
	rm -f $(CPP_OBJ) 
