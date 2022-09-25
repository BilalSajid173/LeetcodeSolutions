class MyCircularQueue {
public:
    int front, rear;
    vector<int> v;
    MyCircularQueue(int k) {
        v = vector<int>(k, -1);
        front = rear = 0;
    }
    
    bool enQueue(int value) {
        if(rear == front){
            if(v[front] == -1){
                v[rear] = value;
                if(rear == v.size()-1) rear = 0;
                else rear++;
                return true;
            }
            else return false;
        }
        else if(rear == v.size() - 1){
            v[rear] = value;
            rear = 0;
            return true;
        }
        else if(rear < v.size() - 1){
            v[rear] = value;
            rear++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(v[front] == -1){
            return false;
        } else {
            v[front] = -1;
            if(front < v.size() - 1){
                front++;
            } else {
                front = 0;
            }
        }
        return true;
    }
    
    int Front() {
        return v[front];
    }
    
    int Rear() {
        if(rear == 0) return v[v.size() - 1];
        return v[rear - 1];
    }
    
    bool isEmpty() {
        return v[front] == -1;
    }
    
    bool isFull() {
        if(rear == front && v[front] != -1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */