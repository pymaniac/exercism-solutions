#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
class circular_buffer {
private:
    std::vector<T> arr;
    size_t cur_sz;
    int rd, wr;
public:
    circular_buffer(size_t sz) : cur_sz(0), rd(0), wr(0) { arr.resize(sz); }
    T read() {
        if (!cur_sz) {
            //std::cout << arr.size() << " " << arr[rd] << " " << rd << std::endl;
            throw(std::domain_error("Empty buffer, nothing to read"));
        }

        cur_sz--;
        int old_rd = rd;
        rd = (rd + 1) % arr.size();
        //std::cout << old_rd << " " << arr[old_rd] << " " << rd << std::endl;
        return arr[old_rd];
    }
    
    void write(T val) {
        if (cur_sz == arr.size()) {
            //std::cout << "Throing an error: " << cur_sz  <<  " size " << arr.size() << std::endl;
            throw std::domain_error("Buffer Full, cannot write");
        }

        arr[wr] = val;
        cur_sz++;
        wr = (wr+1) % arr.size();
    }
    
    void overwrite(T val) {
        if (cur_sz != arr.size()) {
            return write(val);
        }

        arr[wr] = val;
        wr = (wr+1) % arr.size();
        rd = wr;
    }
    
    void clear() {
        rd = wr = 0;
        cur_sz = 0;
    }
};
}  // namespace circular_buffer
