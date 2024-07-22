#include <iostream>
#include "src/embending/data_analysis_allf.hpp"

int main(){
    
    std::vector<std::string> texts = {"Hello,", "World!"};
    double* p = get_vect_nums(std::string(texts.begin(), texts.end()).c_str());
    int i = 0;
    while(p[i]!=1.01){
        std::cout << p[i] << std::endl;
        ++i;
    }
    return 0;
}