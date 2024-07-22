#include "data_analysis_allf.hpp"
#include <iostream>

double* get_vect_nums(const char* text, size_t at_lang){
    std::string text_tmp(text);
        
    stemmer::to_lower(text_tmp);
    embending::tokenizer _tokenizer(text_tmp);
        
    _tokenizer.tokenizer_alg_sent();
    embending::word _words = _tokenizer.tokenizer_alg_word();

    if(at_lang == ANALYSIS_TEXT_LANG_RU) stemmer::stem_ru(_words);
    else stemmer::stem_en(_words);
    
    std::vector<double> vect_num = vec::vectorization(_tokenizer.get_sent(), _words);

    double* vect_numd = new double[vect_num.size()+1];
    for(size_t i = 0; i < vect_num.size(); ++i){
        vect_numd[i] = vect_num[i];
    }
    vect_numd[vect_num.size()] = 1.01;

    return vect_numd;
}

void delete_vect_nums(double* vect_num){
    if(!vect_num) return;
    delete[] vect_num;
}