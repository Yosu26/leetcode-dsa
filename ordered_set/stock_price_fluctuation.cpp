#include <unordered_map>
#include <set>
using namespace std;

class StockPrice{
    unordered_map<int, int> time_price;
    multiset<int> prices;
    int latest_time = 0;
public:
    StockPrice() {}

    void update(int timestamp, int price){
        if(time_price.count(timestamp)){
            prices.erase(prices.find(time_price[timestamp]));
        }
        time_price[timestamp] = price;
        prices.insert(price);
        if(timestamp > latest_time) latest_time = timestamp;
    }

    int current(){
        return time_price[latest_time];
    }

    int maximum(){
        return *prices.rbegin();
    }

    int minimum(){
        return *prices.begin();
    }
};