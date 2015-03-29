#include <iostream>
#include "util/slice.h"

#define MAX_BUFFER_LINE 100

int main(){
    std::cout << "hello test slice" << std::endl;	

	char str_content[MAX_BUFFER_LINE] ;
	strncpy(str_content, "http://www.sohu.com/", MAX_BUFFER_LINE);
	leveldb::Slice t_slice(str_content);
	t_slice.remove_prefix(7);

	std::cout << strlen(str_content) << std::endl;
	std::cout << t_slice.data() << std::endl;
	std::cout << t_slice.size() << std::endl;


}
