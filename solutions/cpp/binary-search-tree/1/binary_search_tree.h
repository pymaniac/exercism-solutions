#pragma once

#include <stack>
#include <memory>
#include <iostream>

namespace binary_search_tree {

// TODO: add your solution here
template <typename T>
class binary_tree {
    public:
    binary_tree(const T &value): _val(value), _left(nullptr), _right(nullptr) {};
    
    inline const T data() const {return _val;}
    using tree_ptr = std::unique_ptr<binary_tree>;
    inline tree_ptr& left() { return _left; }
    inline tree_ptr& right() { return _right; }
    
    inline void insert(const T &value) {
        auto node = std::make_unique<binary_tree>(value);
        if (!node) return;
        
        binary_tree<T> *curr = this;
        while(curr) {
            if (curr->_val > value && curr->_left != nullptr) {
                curr = curr->_left.get();
            } else if (curr->_val < value && curr->_right != nullptr) {
                curr = curr->_right.get();
            } else {
                break;
            }
        }

        //if (curr->_left && curr->_right) {
        //    return;
        //}
        
        if (curr->_val >= value) {
            curr->_left = std::move(node);
        } else {
            curr->_right = std::move(node);
        }
    }

    /* Iterators */
    template <typename PT, typename RT>
    class binary_tree_iterator {
    private:
        binary_tree *current;
        std::stack<binary_tree *> tree_stack;
        void push_all_left(binary_tree *current) {
            for(auto *tmp = current; tmp != nullptr; tmp = tmp->_left.get()) {
                tree_stack.push(tmp);
            }
        }
    
    public:
        binary_tree_iterator(binary_tree* ptr) : current(ptr) { push_all_left(ptr); }
        binary_tree_iterator& operator++() {
            if (tree_stack.empty()) {
                std::cout << "tree_stack empty" << std::endl;
                return *this;
            }
            
            binary_tree* curr = tree_stack.top();
            tree_stack.pop();
            if (curr->_right) {
                push_all_left(curr->_right.get());
            }
            return *this;
        }
        PT operator->() { return &(tree_stack.top()->_val); }
        RT operator*() { return tree_stack.top()->_val; }
        inline friend bool operator!=(const binary_tree_iterator &lhs, const binary_tree_iterator &rhs) {
            if (lhs.tree_stack.empty() && rhs.tree_stack.empty()) return false;
            if (lhs.tree_stack.empty() || rhs.tree_stack.empty()) return true;
            return lhs.tree_stack.top() != rhs.tree_stack.top();
        }
    };

    public:
        typedef binary_tree_iterator<T*, T&> iterator;
        typedef binary_tree_iterator<const T*, const T&> const_iterator;

        iterator begin() { return iterator(this); }
        iterator end() { return iterator(nullptr); }
        const_iterator begin() const { return const_iterator(const_cast<binary_tree*>(this)); }
        const_iterator end() const { return const_iterator(nullptr); }
    
    private:
    T _val;
    tree_ptr _left;
    tree_ptr _right;
};
}  // namespace binary_search_tree
