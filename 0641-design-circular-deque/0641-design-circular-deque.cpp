class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data){
        this->data = data;
        next = prev = NULL;
    }
};
class MyCircularDeque {
public:
    Node*front,*rear;
    int size; int curr;
    MyCircularDeque(int k) {
        front = rear = NULL;
        size = k; curr =0;
    }
    
    bool insertFront(int value) {
        Node* newNode = new Node(value);
        if(curr==size) return false;
        if(front==NULL){
            front = rear = newNode;
            curr++;
            return true;
        }
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
        curr++;
        return true;
    }
    bool insertLast(int value) {
        Node* newNode = new Node(value);
        if(curr==size) return false;
        if(rear==NULL){
            front = rear = newNode;
            curr++;
            return true;
        }
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
        curr++;
        return true;    
    }
    bool deleteFront() {
        if(front==NULL) return false;
        if(front==rear){
            curr--;
            Node*temp = front;
            front = rear = NULL;
            delete temp;
            return true;
        }
        Node*temp = front;
        front = front->next;
        curr--;
        delete temp; 
        return true;   
    }
    
    bool deleteLast() {
        if(rear==NULL) return false;
        if(front==rear){
            curr--;
            Node*temp = rear;
            front = rear = NULL;
            delete temp;
            return true;
        }
        Node*temp = rear;
        rear = rear->prev;
        curr--;
        delete temp;
        return true;    
    }
    
    int getFront() {
        if(front==NULL) return -1;
        return front->data;   
    }
    
    int getRear() {
        if(rear==NULL) return -1;
        return rear->data;    
    }
    
    bool isEmpty() {
        return front==NULL;
    }
    
    bool isFull() {
        return curr==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */