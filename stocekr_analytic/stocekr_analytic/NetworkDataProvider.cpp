#include "NetworkDataProvider.h"

std::string NetworkDataProvider::build_url(const std::string& ticker) //server alphavantage
{
    std::string size = "compact";   //size = compact (last 100 records), size=full (all history)
    return "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=" + ticker + "&apikey=" + api_key + "&outputsize=" + size + "&datatype=csv";
}

NetworkDataProvider::NetworkDataProvider(std::string key) : api_key(std::move(key)) {};

DataResult NetworkDataProvider::get_data(const std::string& ticker)
{
    
}
