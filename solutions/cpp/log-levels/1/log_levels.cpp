#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    char delim[] = "]: ";
    auto mpos = line.find(delim);
    return line.substr(mpos-1 + sizeof(delim));
}

std::string log_level(std::string line) {
    // return the log level
    // [ERROR] => 7 
    auto pos = line.find("]");
    return line.substr(1, pos-1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    auto msg = message(line);
    auto lvl = log_level(line);
    return msg + " (" + lvl + ")";
}
}  // namespace log_line
