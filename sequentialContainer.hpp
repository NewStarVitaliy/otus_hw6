#include <iostream>
#include <vector>
using std::vector;
template<typename T>
class CountainerSTL{
    public:
    T *new_value;
    size_t capacity;
    CountainerSTL() 
    {
        m_size = 0;
        capacity = 1;
        new_value = new T[capacity];
    }   
     ~CountainerSTL() { 
        delete[] new_value; 
    }

    void push_back(T value) {
        if(m_size< capacity){
            new_value[m_size] = value;
        } else {
            capacity*=2;
            m_value = new T[capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_value[i] = new_value[i]; 
            }
            m_value[m_size] = value; 
            delete [] new_value; 
            new_value = m_value; 
        }
        m_size += 1; 
    }
    void insert(int position, T value){
        m_value = new T[capacity+1];
        for (size_t i = 0; i < m_size; ++i) {
            if(i == position) {
                m_value[i] = value;
            }else if (i > position){
                m_value[i] = new_value[i-1];
            }else m_value[i] = new_value[i];

        }
        m_value[m_size] = new_value[m_size-1];
        delete [] new_value; 
        new_value = m_value; 
        m_size += 1; 
    }
    void erase(int position){
        capacity-=1
        m_value = new T[capacity];
        for (size_t i = 0; i < m_size; ++i) {             
            if (i > position){
                m_value[i-1] = new_value[i];
            }else if (i < position)m_value[i] = new_value[i];
        }
        m_value[m_size -1] = new_value[m_size];
        delete [] new_value; 
        new_value = m_value; 
        m_size -= 1; 
    }
    void erase(vector<int> vec){
        capacity-=1;
        for(int j = 0; j< vec.size(); j++){
            m_value = new T[capacity];
            for (size_t i = 0; i < m_size; ++i) {             
                if (i > vec[j]){
                    m_value[i-1] = new_value[i];
                }else if (i < vec[j])m_value[i] = new_value[i];
            }
            m_value[m_size -1] = new_value[m_size];
            delete [] new_value; 
            new_value = m_value; 
            m_size -= 1; 
        }
    }
    CountainerSTL operator [] (const int index){
        return *(new_value + index - 1);
    }
    size_t size(){
        return m_size;
    }

    private:
    T value;
    size_t m_size;
    T *m_value;
};
