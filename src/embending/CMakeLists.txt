set(export_file_name "export_shared.h")

cmake_minimum_required(VERSION 3.12)

project(data_analysis LANGUAGES CXX)

file(GLOB HEADER_FILES "data_analysis/tokenizer.hpp"
                       "stemming/stem_str.hpp"
                       "vect/vectorization.hpp"
                       "data_analysis_allf.hpp"
                       "export.h")

file(GLOB TOKENIZER "data_analysis/tokenizer.cpp")
file(GLOB VECTORIZATION "vect/vectorization.cpp")
file(GLOB WDATA_AN "data_analysis_allfd.cpp")
file(GLOB __EMB_SERV ${TOKENIZER} ${VECTORIZATION} ${WDATA_AN} ${HEADER_FILES})

include_directories("data_analysis/"
                    "vect/"
                    "stemming/")
                    
set(LIBRARY_OUTPUT_PATH ../lib)
add_library(__data_analysis_emb SHARED ${__EMB_SERV})