#pragma once

#include <mutex>

namespace Bankaccount {
class Bankaccount {
    public:
    Bankaccount() {};
    void open();
    void close();
    void deposit(int amt);
    void withdraw(int amt);
    int balance();
    
    private:
    int cur_balance{0};
    bool opened{false};
    std::mutex account_lock;
};  // class Bankaccount

}  // namespace Bankaccount
