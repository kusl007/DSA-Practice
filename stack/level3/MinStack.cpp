//155. Min Stack
//https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    
    
    vector<pair<int , int>>p;
    void push(int val) {
        if(p.empty()){
            pair<int ,int> peer;
            peer.first=val;
            peer.second=val; 
            p.push_back (peer);
        }
        else{
                  pair<int ,int> peer;
            peer.first=val;
            peer.second=min(val,p[p.size()-1].second); 
            p.push_back (peer);

        }
        
    }
    
    void pop() {
        p.pop_back();
        
    }
    
    int top() {
        return p[p.size()-1].first;
        
    }
    
    int getMin() {
        return p[p.size()-1].second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */