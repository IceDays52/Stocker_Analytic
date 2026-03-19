#ifndef STOCKRECORD_H    
#define STOCKRECORD_H 
#include<vector>
#include <string>
#include "AnalysisModels.h"
#include <memory>
#include <optional>

struct StockRecord {
    std::string date;
    double open = 0.0;
    double high = 0.0;
    double low = 0.0;
    double close = 0.0;
    long long volume = 0;
};

struct FinalAnalysisResponse {
    meta_data metadata;

    bool success = false;
    std::vector<std::string> warnings;
    std::string message = "Initial message";
    std::optional<PriceStats> stats;
    std::optional<TechnicalAnalysis> technical;
    std::optional<monte_carlo> simulation;
};
#endif // !STOCKRECORD_H

