#include "sequentialContainer.hpp"



int main(){
    CountainerSTL<int> countainer;
    for(int i = 0; i < 10; i++){
        countainer.push_back(i);
        std::cout<< countainer.new_value[i] << " ";
    }
    std::cout << std::endl;
    std::cout<< countainer.size() << " ";
    std::cout << std::endl;
    vector<int> vec{2,3,4};
    countainer.erase(vec);
    for(int i=0;i<countainer.size(); i++){
        std::cout<< countainer.new_value[i] << " ";
    }
    std::cout << std::endl;
    countainer.insert(0, 10);
    for(int i=0;i<countainer.size(); i++){
        std::cout<< countainer.new_value[i] << " ";
    }
    std::cout << std::endl;
    int length = countainer.size();
    countainer.insert(length/2, 20);
    for(int i=0;i<countainer.size(); i++){
        std::cout<< countainer.new_value[i] << " ";
    }
    std::cout << std::endl;
    countainer.push_back(30);
    for(int i=0;i<countainer.size(); i++){
        std::cout<< countainer.new_value[i] << " ";
    }
    std::cout << std::endl;
    return 0;
    /*std::cout << std::endl;
    countainer.insert(2, 99);
    countainer.erase(3);
    std::cout << "TEST" << std::endl;
    std::cout << countainer.new_value[3] << std::endl;
    for(int i = 0; i < countainer.size(); i++)std::cout << countainer.new_value[i] << std::endl;
    return 0;*/
    //std::cout << countainer.new_value[0] << std::endl;;
}