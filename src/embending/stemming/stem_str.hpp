#ifndef _STEM_STR__H
#define _STEM_STR__H

#include <codecvt>
#include <string>
#include <locale>
#include <vector>

#include "english_stem.h"
#include "russian_stem.h"

namespace stemmer{
    using convert_utf8 = std::codecvt_utf8<wchar_t>;
    
    void to_lower(std::string& text){
        for(size_t i = 0; i < text.size(); ++i){
            if(text[i] == ' ') continue;
            text[i] = std::tolower(text[i]);
        }
    }

    std::wstring to_wstr(const std::string& str)
    {
        std::wstring_convert<convert_utf8, wchar_t> converterX;

        return converterX.from_bytes(str);
    }

    std::string to_str(const std::wstring& wstr)
    {
        std::wstring_convert<convert_utf8, wchar_t> converterX;

        return converterX.to_bytes(wstr);
    }

    void stem_ru(std::vector<std::string> &_words){
        std::vector<std::string> st_words;
        stemming::russian_stem<> RussianStem;

        for(size_t i = 0; i < _words.size(); ++i){
            std::wstring text_w = to_wstr(_words[i]);
            RussianStem(text_w);
            st_words.push_back(to_str(text_w));
        }

        _words = st_words;
    }

    void stem_en(std::vector<std::string> &_words){
        std::vector<std::string> st_words;
        stemming::english_stem<> EnglishStem;

        for(size_t i = 0; i < _words.size(); ++i){
            std::wstring text_w = to_wstr(_words[i]);
            EnglishStem(text_w);
            st_words.push_back(to_str(text_w));
        }

        _words = st_words;
    }

}

#endif