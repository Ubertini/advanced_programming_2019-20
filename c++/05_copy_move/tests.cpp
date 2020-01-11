#include <memory>
#include <algorithm>  // std::copy
#include <iostream>
#include<utility>

enum class Insertion_method { push_back, push_front };

template <class value_type>
class List {
 public: 
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m){
    if(int(m)==0) push_back(v);
    else push_front(v);
  };
  // return the size of the list
  std::size_t size_list() const{return size;};

  // delete all the nodes of the list
  void reset();

  List():size{0},head{nullptr}{}
  ~List(){}
  List(const List& v);

  // copy assignment -- deep copy
  List& operator=(const List& v);

  List(List&& v) : size{std::move(v.size)}, head{std::move(v.head)} {}

  // Vector(Vector&& v) = default; // ok
  List& operator=(List&& v) {
    std::cout << "move assignment\n";
    size = std::move(v.size);
    head = std::move(v.head);
    return *this;
  }

  

 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    node(){}
    ~node(){}
  };

  

  void push_back(const value_type& v){
    std::unique_ptr<node> new_node=new node();
    new_node->value=v;
    new_node->next=nullptr;
    
    node* tmp=head.get();
    while(tmp->next){
          tmp=tmp->next.get();
    }
        tmp->next=new_node.get();
        size+=1;
  };

  void push_front(const value_type& v){
    std::unique_ptr<node> new_node=new node();
    new_node->value=v;
    new_node->next=head.release();
    head=new_node.get();
    size+=1;
  };

  std::unique_ptr<node> head;
  std::size_t size;
};
