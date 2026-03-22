#ifndef ANALYSISMODELS_H 
#define ANALYSISMODELS_H 
#include <string>

struct meta_data {
    std::string ticker;
    int sample_size;
    std::string last_data_point;
    std::string generated_at;
    std::string currency;
    double last_price;
};

struct PriceStats {
    double max_drawdown;
    double volatility;
};

struct TechnicalAnalysis
{
    double sma50;
    double sma200;
    double rsi;
    std::string ternd_signal;
};

struct monte_carlo {
    double median_future_price;
    double prob_of_profit;
    double conf_interval_low;
    double conf_interval_high;
};


#endif // !ANALYSISMODELS_H 
