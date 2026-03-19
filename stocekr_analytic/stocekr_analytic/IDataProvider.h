#ifndef DATAPROVIDER_H    
#define DATAPROVIDER_H
#include<vector>
#include <string>
#include "StockRecord.h"

struct DataResult {
	std::vector<StockRecord> records;
	std::vector<std::string> warnings;
};

class IDataProvider {
public:
	virtual ~IDataProvider() {};
	virtual DataResult get_data(const std::string& ticker) = 0;
}; 
#endif // !DATAPROVIDER_H 

