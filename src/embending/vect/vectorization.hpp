#ifndef _VECTORIZATION__H
#define _VECTORIZATION__H

#include <vector>
#include <string>
#include <cmath>

#include <algorithm>

#include "../data_analysis/tokenizer.hpp"

namespace vec{

    extern std::vector<double> vectorization(
            const embending::sentences& _sents,
            const embending::word& _words);

}

#endif