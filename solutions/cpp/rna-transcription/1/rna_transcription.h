#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>

namespace rna_transcription {

        static const std::unordered_map<char, char> dna_rna_map = {
    {'C', 'G'},
    {'G', 'C'},
    {'A', 'U'},
    {'T', 'A'}};
    
// TODO: add your solution here
std::string to_rna(const std::string &strand);
    inline char to_rna(char x) { return dna_rna_map.at(x);}
    
}  // namespace rna_transcription
