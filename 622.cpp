class MyCircularQueue {
public:
    int *A;
    int front;
    int rear;
    int size;
    int c = 0;
    MyCircularQueue(int k) {
        A = new int[k];
        size = k;
        rear = -1;
        front = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else rear = (rear + 1) % size;
        A[rear] = value;
        c++;
        return true;
    }
    
    bool deQueue() {
        if (rear == -1 && front == -1) return false;
        else if ( rear == front ) 
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        c--;
        return true;
    }
    
    int Front() {
        return front == -1 ? -1 : A[front];
    }
    
    int Rear() {
        return rear == -1 ? -1 : A[rear];
    }
    
    bool isEmpty() {
        return c == 0;
    }
    
    bool isFull() {
        return c == size;
    }
};
