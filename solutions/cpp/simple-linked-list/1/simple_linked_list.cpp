#include "simple_linked_list.h"

#include <stdexcept>
#include <utility>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    auto new_node = std::make_unique<Element>(entry);
    new_node->next = std::move(head);
    head = std::move(new_node);
    current_size++;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if (!current_size) throw std::runtime_error("Empty list");
    int val = head->data;
    head = std::move(head->next);
    current_size--;
    return val;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    std::unique_ptr<Element> prev{nullptr};
    while (head) {
        auto tmp = std::move(head->next);
        head->next = std::move(prev);
        prev = std::move(head);
        head = std::move(tmp);
    }
    head = std::move(prev);
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while(head) {
        head = std::move(head->next);
    }
}

}  // namespace simple_linked_list
