#include <memory>
#include <algorithm>  // std::copy
#include <iostream>
#include<utility>
#include "ap_error.h"

enum class method { push_back, push_front };

template <class value_type>
class List {
 public:


  void insert(const value_type& v, const method m);
  void insert(value_type&& v, const method m);
  
  std::size_t size_list() const{return size;};

  void reset();

  List() noexcept=default;
  ~List(){};
  
  List(const List& v);
  List& operator=(const List& v);

  List(List&&) noexcept=default; //move every object and the std::move on the object of the list are fine 
  List& operator=(List&&) noexcept=default;

  template<class O>
  friend std::ostream& operator<<(std::ostream&, const List<O>&);

 private:
 
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    node(const value_type& v, node * p): value{v}, next{p} {}
    node(value_type&& v, node * p): value{std::move(v)}, next{p} {}
    node(const std::unique_ptr<node>& p): value{p->value}{
      if(p->next) next=std::make_unique<node>(p->next);
    }
    ~node(){}

  };

  // append the newly created node at the end of the list
  void push_back(const value_type& v);

  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  node* tail(){
    auto tmp = head.get();
    while(tmp->next){
      tmp=tmp->next.get();
    }
    return tmp;
  }

  std::unique_ptr<node> head;
  std::size_t size;

};


template<class value_type>
void List<value_type>::insert(value_type&& v, const method m){
  if(!head){
    //head.reset(new node{v,nullptr});    
    head= std::make_unique<node>(v,nullptr);
    return;
  }
  switch(m){
    case method::push_back:
    push_back(v);
    break;

    case method::push_front:
    push_front(v);
    break;
    default:
      AP_ERROR(false) << "Unknown insertion method"<<std::endl;
      break;
  }
}



template<class value_type>
void List<value_type>::push_back(const value_type& v){
  node* last= tail();
  last->next.reset(new node{v,nullptr});
}

template<class value_type>
void List<value_type>::push_front(const value_type& v){
  auto h = head.release();
  auto new_node= new node{v,h};
  head.reset(new_node);
}



template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
  auto tmp = l.head.get();
  while(tmp != nullptr){
    os << tmp->value << "   ";
    tmp= tmp->next.get();
  }
  return os;
};

template <class T>
List<T>::List(const List& l){
  /*auto tmp =l.head.get;
  while(tmp){
    insert(tmp->value, method::push_back);
    tmp=tmp->next.get();
  }*/
  head=std::make_unique<node>(l.head);
}

//typename List<T>::node* List<T>::tail(){}


int main(){
  try{
    List<int> lista{};
    lista.insert(4, method::push_back);
    lista.insert(5, method::push_front);
    List<int> lista1=lista;
    lista1.insert(6,method::push_back);
    std::cout<<lista<<std::endl;
    std::cout<<lista1<<std::endl;
  }catch(std::exception& e){
    std::cerr<<e.what()<< std::endl;
  }catch(...){
    std::cerr<<"Uknown exception"<<std::endl;
  }

}

