#pragma once

#include <string>

namespace crypto_square {

// TODO: add your solution here
class cipher {
    private:
    std::string text;
    public:
    cipher(const std::string &str);
    inline const std::string normalized_cipher_text() { return text; }
};
}  // namespace crypto_square
