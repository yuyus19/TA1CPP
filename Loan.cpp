#include "Loan.h"
#include <cmath>

Loan::Loan()
{

}

Loan ::Loan(double debt, int years, int paymentsPerYear,
            double interestRate, int loanId){

    _debt = debt;
    mYears = years;
    mPaymentsPerYear = paymentsPerYear;
    _interestRate = interestRate;
    mLoanId = loanId;

}


double Loan :: getBalance() const{
    return mBalance;
}

void Loan :: setBalance(double balance)
{
    mBalance = balance;
}

int Loan::getLoanId() const
{
    return mLoanId;
}

void Loan::setLoanId(int loanId)
{
    mLoanId = loanId;
}

double Loan::getInterestRate() const
{
    return (_interestRate/100);
}

void Loan::setInterestRate(double interestRate)
{
    _interestRate = interestRate;
}

double Loan::getDebt() const
{
    return _debt;
}

void Loan::setDebt(double debt)
{
    _debt = debt;
}

int Loan:: getYears() const
{
    return mYears;
}

void Loan::setYears(int years)
{
    mYears = years;
}

int Loan :: getPaymentsPerYear() const{

return mPaymentsPerYear;
}

void Loan::setPaymentsPerYear(int paymentsPerYear)
{
    mPaymentsPerYear = paymentsPerYear;
}

double Loan :: getQuarterlyInterest() const{

    return getInterestRate()/4;
}

double Loan :: getMonthlyInterest() const{

    return getInterestRate()/12;
}

double Loan :: totaltInterest() const{

    double totalInterest;
    totalInterest = _debt * getYears() * getInterestRate();
    return totalInterest;
}

double Loan :: totalPayment() const{

    double G = getDebt();
    double r = getInterestRate()/getPaymentsPerYear();
    int n = getYears() * getPaymentsPerYear();

    double y = (G * r) /((pow((1+r),n))-1);
    return y;

}

double Loan :: totalInterestTaxDeducted(double taxDeductionRate) const{

    taxDeductionRate = taxDeductionRate/100;

    return totaltInterest() * taxDeductionRate;
}

std::vector<PhoneBookPerson> PhoneBook::search(const std::string& s) const {
    std::vector<PhoneBookPerson> res;

    std::string snew(s);
    std::transform(snew.begin(), snew.end(), snew.begin(), ::toupper);

    // Search for a person with string-function find
    for (const PhoneBookPerson& p : mPersons) {
        std::string pName(p.name());
        std::transform(pName.begin(), pName.end(), pName.begin(), ::toupper);

        if (pName.find(snew) != pName.npos)
            res.push_back(p);
    }

    return res;
}




