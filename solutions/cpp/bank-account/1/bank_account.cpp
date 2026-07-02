#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {
void Bankaccount::open() {
    std::lock_guard<std::mutex> lock{account_lock};
    if (opened) {
        throw std::runtime_error("opening an already opened account");
    }
    opened = true;
    cur_balance = 0;
}
    
void Bankaccount::close() {
    std::lock_guard<std::mutex> lock{account_lock};
    if (!opened) {
        throw std::runtime_error("account not opened");
    }
    opened = false;
}
    
void Bankaccount::deposit(int amt) {
    std::lock_guard<std::mutex> lock{account_lock};
    if (!opened) {
        throw std::runtime_error("account not opened");
    }
    if (amt < 0) throw std::runtime_error("Invalid deposit");
    cur_balance += amt;
}

void Bankaccount::withdraw(int amt) {
    std::lock_guard<std::mutex> lock{account_lock};
    if (!opened) {
        throw std::runtime_error("account not opened");
    }
    if (amt < 0 || amt > cur_balance) throw std::runtime_error("not enough funds");
    cur_balance -= amt;
}
    
int Bankaccount::balance() {
    std::lock_guard<std::mutex> lock{account_lock};
    if (!opened) {
        throw std::runtime_error("account not opened");
    }
    return cur_balance;
}

}
