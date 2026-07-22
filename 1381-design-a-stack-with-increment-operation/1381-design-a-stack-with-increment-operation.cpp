class CustomStack {
public:
    int *arr;
    int capacity;
    int top;
    CustomStack(int maxSize) {
        arr = new int[maxSize];
        capacity = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top < capacity-1)
        {
            arr[++top] = x;
        }
    }
    
    int pop() {
        if(top == -1) return -1;
        int t = arr[top];

        return arr[top--];
    }
    
    void increment(int k, int val) {
        int m = min(k, top+1);

        for(int i=0; i<m; i++)
        {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */