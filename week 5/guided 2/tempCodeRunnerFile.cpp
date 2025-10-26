void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}
