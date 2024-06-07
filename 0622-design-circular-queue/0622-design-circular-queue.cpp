class MyCircularQueue {
public:
    vector<int> ans;
    int front;
    int rear;
    int size;  // to keep track of the current number of elements

    MyCircularQueue(int k) {
        ans.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % ans.size();
        ans[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % ans.size();
        }
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return ans[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return ans[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == ans.size();
    }
};


