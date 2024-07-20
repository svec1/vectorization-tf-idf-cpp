#ifndef _TOKENIZER__H
#define _TOKENIZER__H

#include <string>
#include <vector>

namespace embending{
    
    typedef std::vector<std::string> sentences;
    typedef std::vector<std::string> word;

    //typedef std::vector<std::vector<int>> native_matrix;
    
    class tokenizer{
        public:
            tokenizer() = default;
            ~tokenizer() = default;

            tokenizer(std::string _text) : text(_text){}
        
        public:
            void set_text(std::string _text);
            
            const word& get_word();
            const sentences& get_sent();

            const sentences& tokenizer_alg_sent();
            const word& tokenizer_alg_word();

            void set_null_tokenizer();

        private:
            sentences _sents;
            word _words;

            std::string text;
    };
}

#endif