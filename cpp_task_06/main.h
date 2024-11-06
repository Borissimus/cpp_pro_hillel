#ifndef VISITORS_H
#define VISITORS_H
#include <iostream>
#include <string>
#include "logger.h"

// Forward declaration of the visitor
class TransactionVisitor;

class Transaction {
public:
    virtual void accept(TransactionVisitor &visitor) = 0; // Pure virtual method
    virtual ~Transaction() noexcept = default; // Default destructor
};

class Deposit : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override; // Override
};

class Withdrawal : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override; // Override
};

class Transfer : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override; // Override
};

class BillPayment : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override; // Override
};

class TransactionVisitor {
public:
    virtual void visit(Deposit &deposit) = 0; // Pure virtual method for Deposit
    virtual void visit(Withdrawal &withdrawal) = 0; // Pure virtual method for Withdrawal
    virtual void visit(Transfer &transfer) = 0; // Pure virtual method for Transfer
    virtual void visit(BillPayment &billPayment) = 0; // Pure virtual method for BillPayment
    virtual ~TransactionVisitor() = default; // Default destructor
};

class ShortReportVisitor : public TransactionVisitor {
public:
    void visit(Deposit &deposit) override final {
        std::string message = "Short Report: Deposit Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(Withdrawal &withdrawal) override final {
        std::string message = "Short Report: Withdrawal Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(Transfer &transfer) override final {
        std::string message = "Short Report: Transfer Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(BillPayment &billPayment) override final {
        std::string message = "Short Report: Bill Payment Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }
};

class DetailedReportVisitor : public TransactionVisitor {
public:
    void visit(Deposit &deposit) override final {
        std::string message = "Detailed Report: Detailed Deposit Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(Withdrawal &withdrawal) override final {
        std::string message = "Detailed Report: Detailed Withdrawal Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(Transfer &transfer) override final {
        std::string message = "Detailed Report: Detailed Transfer Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }

    void visit(BillPayment &billPayment) override final {
        std::string message = "Detailed Report: Detailed Bill Payment Transaction";
        std::cout << message << std::endl;
        Logger::getInstance().log(message);
    }
};

void Deposit::accept(TransactionVisitor &visitor) {
    visitor.visit(*this);
}

void Withdrawal::accept(TransactionVisitor &visitor) {
    visitor.visit(*this);
}

void Transfer::accept(TransactionVisitor &visitor) {
    visitor.visit(*this);
}

void BillPayment::accept(TransactionVisitor &visitor) {
    visitor.visit(*this);
}

#endif // VISITORS_H
