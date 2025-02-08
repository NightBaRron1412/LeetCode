class NumberContainers {
public:
    unordered_map<int, set<int>> N2I;
    unordered_map<int, int> I2N;

    NumberContainers() {}
    void change(int index, int number) {
        if (I2N.find(index) != I2N.end()) {
            int previous_number = I2N[index];
            N2I[previous_number].erase(index);
            if (N2I[previous_number].empty()) {
                N2I.erase(previous_number);
            }
        }
        I2N[index] = number;
        N2I[number].insert(index);
    }

    int find(int number) {
        if (N2I.find(number) != N2I.end()) {
            return *N2I[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */