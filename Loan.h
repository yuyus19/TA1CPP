#ifndef LOAN_H
#define LOAN_H

#include <iomanip>
#include <iostream>


class Loan
{
public:
    Loan();

    Loan(double debt, int years, int paymentsPerYear,
         double interestRate);

    // Returns the number of years the loan lasts
    int getYears()const;
    void setYears(int years);

    // Amount of payments per year
    int getPaymentsPerYear()const;
    void setPaymentsPerYear(int paymentsPerYear);

    //Debt
    double getDebt()const;
    void setDebt(double debt);

    //Interestrate
    double getInterestRate()const;
    void setInterestRate(double rate);

    //Calculate the total interest of a loan for all the years
    double totaltInterest()const;

    //Calculate the total repayment of a loan including the interests
    double totalPayment()const;

    //Calculate the total nete interest of a loan after tax refund
    double totalInterestTaxDeducted(double taxDeductionRate)const;

    //Output the periodical payments with unpaid balance, paid interest and
    //repayment of eacht payment to stream object ost
    void outputPeriodicalPayments(std::ostream& ost)const;

    double getQuarterlyInterest()const;


    double getMonthlyInterest()const;


    double getBalance()const;
    void setBalance(double balance);

private:

    double _debt, _interestRate, mBalance;
    int mYears, mPaymentsPerYear;

};

#endif // LOAN_H
