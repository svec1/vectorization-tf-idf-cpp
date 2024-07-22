#include "vectorization.hpp"
#include <iostream>

static double TF(const std::vector<std::string>& _words, const std::string& _word, size_t index){
    double count_word = 0, size_sent = 0;
    for(size_t i = index; i < _words.size(); ++i, ++size_sent){
        if(_words[i] == "*end*")
            break;
        else if(_words[i] == _word) ++count_word;
    }

    if(!count_word) ++count_word;
    if(!size_sent) return 0;

    return (double)count_word/size_sent;
}

static double IDF(const std::vector<std::string>& _sents, const std::string& _word){
    double count_word_nsent = 0;
    for(size_t i = 0; i < _sents.size(); ++i){
        if(_sents[i].find(_word) != _sents[i].npos)
            ++count_word_nsent;
    }
    if(!count_word_nsent) ++count_word_nsent;

    return std::log(_sents.size()/count_word_nsent);
}

std::vector<double> vec::vectorization(
            const embending::sentences& _sents,
            const embending::word& _words){

                std::vector<double> vec_vectorize_nums;

                size_t start_pos_sent = 0;

                for(size_t i = 0; i < _words.size(); ++i){
                    bool find = false;
                    if(_words[i] == "*end*"){
                        start_pos_sent = i+1;
                        continue;
                    }
                    for(size_t j = 0; j < i; ++j){
                        if(_words[j] == _words[i]){
                            find = true;
                            break;
                        }
                    }
                    if(find) continue;
                    
                    vec_vectorize_nums.push_back(TF(_words, _words[i], start_pos_sent)*IDF(_sents, _words[i]));
                    std::cout << "Vectorize number: " << std::to_string(vec_vectorize_nums[vec_vectorize_nums.size()-1]) << " " << _words[i] << std::endl;
                }
                return vec_vectorize_nums;
            }