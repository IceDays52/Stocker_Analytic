#include "FileDataProvider.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
DataResult FileDataProvider::get_data(const std::string& ticker)
{
    DataResult to_return;
    std::vector<StockRecord> records;
    std::vector<std::string> warnings;

    std::string filename = ticker + ".csv";
    std::ifstream file(filename); 

    if (!file.is_open()) {
        throw std::runtime_error("Critical error: could not open: " + ticker);
    }

    std::string temp_line;
    std::getline(file, temp_line);

    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error("Critical error: " + filename + " is empty!");
    }

    int line_num = 1;

    while (std::getline(file, temp_line))
    {   
        ++line_num;
        if (temp_line.empty()) continue;

        std::string temp_help;
        std::stringstream ss(temp_line);

        StockRecord temp_stockrecord;
        try {
            if (!std::getline(ss, temp_stockrecord.date, ',')) throw std::runtime_error("Missing Date");

            if (!std::getline(ss, temp_help, ',')) throw std::runtime_error("Missing Open");
            temp_stockrecord.open = std::stod(temp_help);

            if (!std::getline(ss, temp_help, ',')) throw std::runtime_error("Missing High");
            temp_stockrecord.high = std::stod(temp_help);

            if (!std::getline(ss, temp_help, ',')) throw std::runtime_error("Missing Low");
            temp_stockrecord.low = std::stod(temp_help);

            if (!std::getline(ss, temp_help, ',')) throw std::runtime_error("Missing Close");
            temp_stockrecord.close = std::stod(temp_help);

            if (!std::getline(ss, temp_help, ',')) throw std::runtime_error("Missing Volume");
            temp_stockrecord.volume = std::stoll(temp_help);

            records.push_back(temp_stockrecord);

        }
        catch (const std::exception& e) {
        std::string warning = "Line " + std::to_string(line_num) + " error: " + e.what();
        warnings.push_back(warning);
        }
    }
    to_return.records = records;
    to_return.warnings = warnings;
    return to_return;
}
