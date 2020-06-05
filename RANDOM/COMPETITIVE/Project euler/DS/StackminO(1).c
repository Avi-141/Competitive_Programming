typedef struct {
    long int *arr;
    int size;
    long int min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack* p = malloc(sizeof(MinStack));
    p->size = 0;
    p->min = 0;
    p->arr = malloc(sizeof(int)*maxSize);
    return p;
}

void minStackPush(MinStack* obj, long int x) {

    if(obj->size == 0){
        obj->min = x;
        obj->arr[obj->size] = x;
    } else if (x < obj->min){
        obj->arr[obj->size] = x*2 - obj->min;
        obj->min = x;
    } else
        obj->arr[obj->size] = x;
    obj->size += 1;
}

void minStackPop(MinStack* obj) {

    obj->size -= 1;
    if(obj->arr[obj->size] < obj->min){
        obj->min = 2*obj->min - obj->arr[obj->size];
    }
    if(obj->size == 0)
        obj->min = 0;

}

int minStackTop(MinStack* obj) {
    return (obj->arr[(obj->size)-1] < obj->min)? obj->min : obj->arr[(obj->size)-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/*public:
    stack stk;
    stack min;

    MinStack() { }

    void push(int x) {
        if (min.empty() || min.top() >= x) { min.push(x); }
        stk.push(x);
    }

    void pop() {
        if (stk.top() == min.top()) { min.pop(); }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min.top(); }
}; */
