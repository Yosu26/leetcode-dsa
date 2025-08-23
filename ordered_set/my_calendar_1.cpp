#include <set>
using namespace std;

class MyCalendar{
private:
    set<pair<int, int>> bookings;
public:
    MyCalendar() {}

    bool book(int start, int end){
        auto it = bookings.lower_bound({start, end});
        if(it != bookings.end() && it->first < end) return false;
        if(it != bookings.begin()){
            auto prevIt = prev(it);
            if(prevIt->second > start) return false;
        }
        bookings.insert({start, end});
        return true;
    }
};