//leetcode 380. Insert Delete GetRandom O(1)
//https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

class RandomizedSet {
public:
vector<int>nums;
unordered_map<int,int>map;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end())return false;
        nums.push_back(val);
        map[val]=nums.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end())return false;
        int lastElement=nums.back();
        map[lastElement]=map[val];
        nums[map[lastElement]]=lastElement;
        nums.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */