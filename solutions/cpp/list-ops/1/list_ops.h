#pragma once

#include <vector>
#include <iostream>

namespace list_ops {

// TODO: add your solution here
void append(std::vector<int> &left, const std::vector<int> &right);

template <typename T>
std::vector<typename T::value_type> concat(const std::vector<T> &list) {
    std::vector<typename T::value_type> ans;
    for(const auto &l: list) {
        for(const auto &v: l) {
            ans.push_back(v);
        }
    }
    return ans;
}

template <typename F>
std::vector<int> filter(const std::vector<int> &input, F func) {
    std::vector<int> ans;
    for(const auto &i: input) {
        if(func(i)) ans.push_back(i);
    }
    return ans;
}

size_t length(const std::vector<int> &input);

template <typename F>
std::vector<int> map(const std::vector<int> &input, F func) {
    std::vector<int> ans(input.size());
    for(size_t i = 0; i < input.size(); i++) {
        ans[i] = func(input[i]);
    }
    return ans;
}

template <typename T, typename F>
T foldl(const std::vector<T> &input, int st, F func) {
    T res = st;
    for(const auto &i: input) {
        res = func(res, i);
    }
    return res;
}
    
template <typename T, typename F>
T foldr(const std::vector<T> &input, T st, F func) {
    T res = st;
    for(auto it = input.rbegin(); it != input.rend(); it++) {
       res = func(res, *it);
    }
    return res;
}

template <typename T>
std::vector<T> reverse(const std::vector<T> &input) {
    std::vector<T> ans = input;
    for(int l = 0, r = static_cast<int>(input.size()-1); l < r; l++, r--) {
        std::swap(ans[l], ans[r]);
    }
    return ans;
}
    
}  // namespace list_ops
