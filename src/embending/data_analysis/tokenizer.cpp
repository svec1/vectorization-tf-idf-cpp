#include "tokenizer.hpp"

#include <algorithm>

void embending::tokenizer::set_text(std::string _text){
    text = _text;
}
const embending::word& embending::tokenizer::get_word(){
    return _words;
}

const embending::sentences& embending::tokenizer::get_sent(){
    return _sents;
}

const embending::sentences& embending::tokenizer::tokenizer_alg_sent(){
    std::string curr_sent;
    
    for(size_t i = 0; i < text.size(); ++i){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            if(i < text.size()-1 && (!isupper(text[i+1]) && !text[i+1] == ' ')) continue;
            _sents.push_back(curr_sent);
            curr_sent.clear();
            continue;
        }
        curr_sent += text[i];
    }

    return _sents;
}


const embending::word& embending::tokenizer::tokenizer_alg_word(){
    std::string curr_word;
    bool end = 0;
    
    for(size_t i = 0; i < text.size()+1; ++i){
        if(text[i] == ' '){
            while(text[i] == ' ') ++i;
            
            if(!curr_word.empty()){
                if(curr_word == "a"){
                    curr_word.clear();
                    --i;
                    continue;
                }
                _words.push_back(curr_word);
                curr_word.clear();
            }
        }
        else if((text[i] == ',' || text[i] == ':' || text[i] == ';' || i == text.size()) && !curr_word.empty()){
point_add_token:
            _words.push_back(curr_word);
            if(end){
                _words.push_back("*end*");
                end = false;
            }
next:
            curr_word.clear();
            continue;
        }
        else if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            end = true;
            goto point_add_token;
            break;
        }
        curr_word += text[i];
    }

    return _words;
}

void embending::tokenizer::set_null_tokenizer(){
    text.clear();
    _sents.clear();
    _words.clear();
}