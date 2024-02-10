#include "ListTypeContainer.hpp"


template <typename T>
void List<T>::push_back(T data){
    if (head == nullptr){
        head = new Pointer<T>(data);
    }
    else{
        Pointer<T> *new_data = this->head;
        while(new_data->next !=nullptr){
            new_data = new_data->next;
        }
        new_data->next = new Pointer<T>(data);
    }
    size_++;
}

template <typename T>
T& List<T>::operator[](const int index){
    int counter = 0;
    Pointer<T> * current = this->head;
    while(current!=nullptr){

        if(counter==index){
            return current->data;
        }
        current = current->next;
        counter++;
    }
}
template <typename T>
void List<T>::erase(int index_){
    if(index_==0){
        Pointer<T> *temp = head;
	    head = head->next;
	    delete temp;
	    size_--;
    }else
    {
        Pointer<T> *previous = this->head;
		for (int i = 0; i < index_ - 1; i++)
		{
			previous = previous->next;
		}		
		Pointer<T> *toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;
		size_--;
    }
}
template <typename T>
void List<T>::erase(std::vector<int> vec){
    for(int i =0; i< vec.size();i++){
        if(vec[i]==0){
            Pointer<T> *temp = head;
            head = head->next;
            delete temp;
            size_--;
        }
        else
        {
        Pointer<T> *previous = this->head;
		for (int j = 0; j < vec[i] - 1; j++)
		{
			previous = previous->next;
		}		
		Pointer<T> *toDelete = previous->next;
		previous->next = toDelete->next;
		delete toDelete;
		size_--;
        }
    }
}
template <typename T>
void List<T>::insert(int index_, T data){
    if(index_==0){
        head = new Pointer<T>(data, head); 
        size_++;      
    }else
    {
        Pointer<T> *previous = this->head;
		for (int i = 0; i < index_ - 1; i++)
		{
			previous = previous->next;
		}		
		Pointer<T> *newPointer = new Pointer<T>(data, previous->next);
		previous->next = newPointer;
        size_++;
    }
}
template <typename T>
void List<T>::clear(){
    while(size_){
        Pointer<T> *ptr = head;
        head = head->next;
        delete head;
        size_--;
    }
}

template <typename T>
List<T>::~List(){
    clear();
}

int main(){

    List<int> lst;
    for(int i = 0; i < 10; i++){
        lst.push_back(i);
    }   
    for (int i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i]<< " ";
    }
    std::cout << std::endl;
    std::cout << lst.size() << std::endl;
    vector<int> vec{2,3,4}; 
    lst.erase(vec);
    for (int i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i]<< " ";
    }
    std::cout << std::endl;
    lst.insert(0 , 10);
    for (int i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i]<< " ";
    }  
    std::cout << std::endl;
    int length = lst.size();
    lst.insert( length/2, 20);
    for (int i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i] << " ";
    }  
    std::cout << std::endl;
    lst.push_back(30);
    for (int i = 0; i < lst.size(); i++)
    {
        std::cout << lst[i]<< " ";
    }
    std::cout << std::endl;
    return 0;
}