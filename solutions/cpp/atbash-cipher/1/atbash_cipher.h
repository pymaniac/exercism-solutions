#pragma once

#include <string>

namespace atbash_cipher {

std::string decode(const std::string &cipher);
std::string encode(const std::string &str);
}  // namespace atbash_cipher
