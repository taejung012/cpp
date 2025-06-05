#include <iostream>
#include <stdexcept>
using namespace std;

// (1) 예외 클래스 정의
class AccountException {
protected:
    int amount;
public:
    AccountException(int amt) : amount(amt) {}
    virtual void what() const {
        cout << "계좌 예외 발생 (금액: " << amount << ")" << endl;
    }
};

class DepositException : public AccountException {
public:
    DepositException(int amt) : AccountException(amt) {}
    void what() const override {
        cout << "예외: 입금 금액이 유효하지 않음 (입금액: " << amount << ")" << endl;
    }
};

class WithdrawException : public AccountException {
public:
    WithdrawException(int amt) : AccountException(amt) {}
    void what() const override {
        cout << "예외: 출금 금액이 잔고보다 많음 (출금액: " << amount << ")" << endl;
    }
};

// (2) CustomerAccount 클래스 정의
class CustomerAccount {
    int balance;
public:
    CustomerAccount(int b = 0) : balance(b) {}

    int getBalance() const { return balance; }

    int deposit(int amount) {
        if (amount <= 0) throw DepositException(amount);
        balance += amount;
        return balance;
    }

    int withdraw(int amount) {
        if (amount > balance) throw WithdrawException(amount);
        balance -= amount;
        return balance;
    }
};

// (3) main에서 예외 처리 테스트
int main() {
    CustomerAccount acc(1000);

    try {
        cout << "입금 중... 500원" << endl;
        acc.deposit(500);
        cout << "현재 잔액: " << acc.getBalance() << endl;

        cout << "입금 중... -200원 (예외 발생)" << endl;
        acc.deposit(-200);
    } catch (const DepositException& e) {
        e.what();
    }

    try {
        cout << "출금 중... 3000원 (예외 발생)" << endl;
        acc.withdraw(3000);
    } catch (const WithdrawException& e) {
        e.what();
    }

    try {
        cout << "출금 중... 800원" << endl;
        acc.withdraw(800);
        cout << "현재 잔액: " << acc.getBalance() << endl;
    } catch (const AccountException& e) {
        e.what();
    }

    return 0;
}
