class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
        nums_size++;
    }
    
    int getProduct(int k) {
        int product {1};
        int count {0};
        int i = nums_size - 1;
        while(count < k)
        {
            product *= nums [i];
            i--;
            count++;
        }
        return product;
    }
private:
vector<int> nums;
size_t nums_size {0};
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */