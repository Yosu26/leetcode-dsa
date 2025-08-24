#include <vector>
using namespace std;

class MyCalendarTwo{
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo(){

    }

    bool book(int start, int end){
        for(auto& o : overlaps){
            if(max(o.first, start) < min(o.second, end))
                return false;
        }
        for(auto& b : bookings){
            int s = max(b.first, start), e = min(b.second, end);
            if(s < e) overlaps.push_back({s, e});
        }
        bookings.push_back({start, end});
        return true;
    }
};