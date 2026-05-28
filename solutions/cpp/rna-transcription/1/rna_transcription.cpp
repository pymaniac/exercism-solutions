#include "rna_transcription.h"

namespace rna_transcription {

// TODO: add your solution here
std::string to_rna(const std::string& strand) {
    std::string ret{strand};
    std::transform(strand.begin(), strand.end(), ret.begin(), 
        [](char c) { return rna_transcription::dna_rna_map.at(c); });
    return ret;
}
    
}  // namespace rna_transcription
