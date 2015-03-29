#include <assert.h>
#include <string.h>
#include <leveldb/db.h>
#include <iostream>

int main(){
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options,"./testdb", &db);
	assert(status.ok());

	//write key1,value1
    std::string key="key";
	std::string value = "value";
	std::string value_ex = "";

	status = db->Put(leveldb::WriteOptions(), key,value);
	assert(status.ok());

	status = db->Get(leveldb::ReadOptions(), key, &value);
	assert(status.ok());
	std::cout<<value<<std::endl;
	std::string key2 = "key2";
	value = "value2";
    
	//move the value under key to key2
	
	status = db->Put(leveldb::WriteOptions(),key2,value);
	assert(status.ok());

	status = db->Get(leveldb::ReadOptions(), key2, &value_ex);
	assert(status.ok());

	std::cout<<key2<<"==="<<value_ex<<std::endl;

	
	status = db->Get(leveldb::ReadOptions(),key, &value_ex);
	
	assert(status.ok());
	std::cout<<key<<"==="<<value_ex<<std::endl;
	
	status = db->Get(leveldb::ReadOptions(),key, &value);
	
	status = db->Delete(leveldb::WriteOptions(), key);
	assert(status.ok());

	status = db->Get(leveldb::ReadOptions(),key, &value);
    if(!status.ok()) std::cerr<<key<<"  "<<status.ToString()<<std::endl;
	else std::cout<<key<<"==="<<value<<std::endl;
	
    int a = 8;
	std::cout << (a>>2) << std::endl;

	delete db;
	return 0;
}
