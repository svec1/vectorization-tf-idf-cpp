#ifndef _DATA_ANALYSIS_ALLF__H
#define _DATA_ANALYSIS_ALLF__H

#include "vectorization.hpp"
#include "stem_str.hpp"

#include "export.h"

const size_t ANALYSIS_TEXT_LANG_RU = 0, ANALYSIS_TEXT_LANG_EN = 1;

extern "C"
__DATA_ANALYSIS_EMB_EXPORT
double *
get_vect_nums(
    const char *text,
    size_t at_lang = ANALYSIS_TEXT_LANG_RU);

extern "C"
__DATA_ANALYSIS_EMB_EXPORT
void delete_vect_nums(double *vect_num);

#endif