class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (idx_map.find(val) != idx_map.end()) {
            return false;
        }
        vec.push_back(val);
        idx_map[val] = vec.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if (idx_map.find(val) == idx_map.end()) {
            return false;
        }
        int idx = idx_map[val];
        swap(vec[idx], vec.back());
        idx_map[vec[idx]] = idx;
        vec.pop_back();
        idx_map.erase(val);

        return true;
    }
    
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }

private:
    vector<int> vec;
    unordered_map<int, int> idx_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */