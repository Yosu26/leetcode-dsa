#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack{
    vector<vector<int>> st;
public:

    //Constructor
    MinStack(){
        //nothing here
    };

    void push(int val){
        int min_val = st.empty() ? val : min(val, st.back()[1]);
        st.push_back({val, min_val});
    }

    void pop(){
        if(!st.empty()) st.pop_back();
    }

    int top(){
        return st.empty() ? -1 : st.back()[0];
    }

    int getMin(){
        return st.empty() ? -1 : st.back()[1];
    }
};