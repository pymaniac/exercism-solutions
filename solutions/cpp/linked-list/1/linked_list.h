#pragma once

#include <stdexcept>

namespace linked_list {

// TODO: add your solution here
template <typename T>
class List {
    private:
        struct Node {
            T val;
            Node* prev{nullptr};
            Node* next{nullptr};
            Node(T v) : val(v) {};
        };
        Node* head {nullptr};
        Node* tail {nullptr};
        int cnt{0};
    public:
        List() = default;
        void push(T val) {
            Node *nn = new Node(val);
            nn->prev = tail;
            cnt++;
            if (tail) {
                tail->next = nn;
                tail = nn;
                return;
            }
            tail = head = nn;
        }
        T pop() {
            if (!cnt) throw std::runtime_error("null list");
            T ret = tail->val;
            Node *tmp = tail->prev;
            free(tail);
            cnt--;
            tail = tmp;
            if (tmp) {
                tmp->next = nullptr;
            } else { head = nullptr; }
            return ret;
        }
        T shift() {
            if (!cnt) throw std::runtime_error("null list");
            T ret = head->val;
            Node *tmp = head->next;
            free(head);
            cnt--;
            head = tmp;
            if (tmp) {
                tmp->prev = nullptr;
            } else { tail = nullptr; }
            return ret;
        }
        void unshift(T val) {
            Node *nn = new Node(val);
            nn->next = head;
            cnt++;
            if (head) {
                head->prev = nn;
                head = nn;
            } else {
                head = tail = nn;
            }
        }
        inline int count() { return cnt; };
        bool erase(T rv) {
            for(Node *tmp = head; tmp; tmp=tmp->next) {
                if (tmp->val == rv) {
                    Node *p = tmp->prev;
                    Node *n = tmp->next;
                    if (p) p->next = n;
                    if (n) n->prev = p;
                    if (tmp == head) head = n;
                    if (tmp == tail) tail = p;
                    free(tmp);
                    cnt--;
                    return true;
                }
            }
            return false;
        }
};

}  // namespace linked_list
