#include "main.h"

int main() {
    Deposit deposit;
    Withdrawal withdrawal;
    Transfer transfer;
    BillPayment billPayment;

    ShortReportVisitor shortReport;
    deposit.accept(shortReport);
    withdrawal.accept(shortReport);
    transfer.accept(shortReport);
    billPayment.accept(shortReport);

    DetailedReportVisitor detailedReport;
    deposit.accept(detailedReport);
    withdrawal.accept(detailedReport);
    transfer.accept(detailedReport);
    billPayment.accept(detailedReport);

    return 0;
}
