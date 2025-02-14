// Brute force 
class ProductOfNumbers {
public:
    vector <int> V;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        V.push_back(num);
    }
    
    int getProduct(int k) {
        int n = V.size();
        int ans = 1 ;
        for (int i = n - 1 ; i >= n - k ; i--)
        {
            ans *= V[i];
        }
        return ans;
    }
};
// Prefix Product
class ProductOfNumbers {
public:
    vector <int> V;
    ProductOfNumbers() {
        V.push_back(1);
    }
    
    void add(int num) {
        if (num == 0)
        {
            V.clear();
            V.push_back(1);
            return;
        }

        V.push_back(V.back()*num);
    }
    
    int getProduct(int k) {
        int n = V.size();
        if (k >= n) return 0;
        return V.back()/V[n-k-1];
    }
};
