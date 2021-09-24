#include <iostream>
using namespace std;

template <typename T> class Node{
    public :
        T data = 1;
        Node<T> *next;
        Node(T value){
            data = value;
            next = NULL;
        }
        Node(const Node *a){
            this->data = a->data;
            this->next = a->next;
        }
        Node operator=(const Node *a){
            return a;
        }
        void insertNext(T value){
            if (this->next == NULL){
                this->next = new Node<int>(value);
                return;
            }
            this->next->insertNext(value);
        }
        void display(){
            if(this == NULL){
                cout << "NULL\n";
                return;
            }
            cout << this->data << "->";
            this->next->display();
        }
        void insertBefore(T value){
            // Node<T> *temp = new Node<T>(this->data);
            // temp->next = this->next;
            Node<T> *temp = new Node<int>(this);
            this->data = value;
            this->next = temp;
        }
        void insertAt(int key, T value){
            if(key == 1){
                Node<T> *temp = new Node<int>(this);
                this->data = value;
                this->next = temp;
                return;
            }
            this->next->insertAt(key-1, value);
        }
        bool search(T key){
            if(key == this->data){
                return true;
            }
            if(this->next == NULL){
                return false;
            }
            return this->next->search(key);
        }
        void deleteHead(){
            Node<T> *n = this->next;
            this->data = this->next->data;
            this->next = this->next->next;
            delete n;
        }
        void deleteTail(){
            if(this->next == NULL){
                this->display();
                this = NULL;
                delete this;
                return;
            }
            this->next->deleteTail();
        }
};

int main(){
    Node<int> *head = new Node<int>(0);
    head->insertNext(1);
    head->insertNext(4);
    head->insertBefore(2);
    head->insertAt(2, 3);
    head->display();
    // cout << head->search(10);
    // head->deleteHead();
    head->deleteTail();
    head->display();
    return 0;
}