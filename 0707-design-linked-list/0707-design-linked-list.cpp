class MyLinkedList {
public:
    struct Node{
        int data;
        Node*next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
    };
    Node*head;
    int size;
    MyLinkedList() {
        head = NULL;
        size=0;
    }
    
    int get(int index) {
        if(index>=size || !head) return -1;
        int count=0;
        Node*temp = head;
        while(temp && count<index){
            temp = temp->next;
            count++;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node*newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    
    void addAtTail(int val) {
       Node*newNode = new Node(val);
       if(!head){
        head = newNode;
       } 
       else{
        Node*temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
       }
       size++;
       return;
    }
    
    void addAtIndex(int index, int val) {
        Node*newNode = new Node(val);
        if(index==0){
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }
        else if(index>size) return;
        else{
            Node*temp = head;
            int count=1;
            while(temp && count<index){
                temp = temp->next;
                count++;
            }
            if(!temp) return;
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
            size++;
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

    // delete head
    if(index == 0){
        Node* del = head;
        head = head->next;
        delete del;
        size--;
        return;
    }

    // find previous node (index-1)
    Node* temp = head;
    for(int i = 1; i < index; i++){
        temp = temp->next;
    }

    Node* del = temp->next;     // node to delete
    temp->next = del->next;     // unlink
    delete del;                 // free
    size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */