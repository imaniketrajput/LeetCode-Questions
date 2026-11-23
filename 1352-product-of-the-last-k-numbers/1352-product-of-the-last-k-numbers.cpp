class ProductOfNumbers {
private:
    vector<int> prefixProduct;
    int n = 0;

public:
    ProductOfNumbers() {
        prefixProduct.clear();
        n = 0;
    }

    void add(int num) {
        if (num == 0) {
            prefixProduct = {};
            n = 0;
        } else {
            if (prefixProduct.empty()) {
                prefixProduct.push_back(num);
            } else {
                prefixProduct.push_back(prefixProduct[n - 1] * num);
            }
            n++;
        }
    }

    int getProduct(int k) {
        if(k > n)
            return 0;
            
        if (k == n) {
            return prefixProduct[n - 1];
        }

        return prefixProduct[n - 1] / prefixProduct[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */