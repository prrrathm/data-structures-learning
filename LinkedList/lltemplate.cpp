#include <iostream>
using namespace std;

template<typename T>class Node{
  private:
      T data;
      Node<T>* next;
      template<typename U>friend class LinkedList;
  public:
      Node(){
          this->next = NULL;
      }
      Node(T value){
          this->data = value;
          this->next = NULL;
      }
};
template<typename T>class LinkedList{
    private:
        Node<T>* head;
    public:
      LinkedList(){
        this->head = NULL;
      }
      void display(){
        Node<T> *temp = head;
        while(temp != NULL){
          cout << temp->data << "->";
          temp = temp->next;
        }
        cout << "NULL\n";
      }
      void insertNext(T value){
          Node<T> *temp = head;
          if(head == NULL){
            head = new Node<T>(value);
            return;
          }
          while(temp->next != NULL){
            temp = temp->next;
          }
          temp->next = new Node<T>(value);
      }
      void inserBefore(T value){
        Node<T>* temp = head;
        head = new Node<T>(value);
        head->next = temp;
      }
      int length(){
          int len = 0;
          Node<T>* temp = head;
          while(temp != NULL){
              len++;
              temp = temp->next;
          }
          return len;
      }

      void insert(int index, T value){
        if (value > head->size()){
          cout << "Index bigger than size of LinkedList" << '\n';
          return;
        }

      }
};

int main(){
  LinkedList<int> A;
  A.insertNext(1);
  A.insertNext(3);
  A.inserBefore(2);
  A.display();
  cout << A.length() << endl;
  return 0;
}
