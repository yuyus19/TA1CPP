#include <iostream>
#include <vector>
#include "Loan.h"

using namespace std;

Loan addLoan(){
    double debt, interestrate;
    int years, payments, loanId;

    std :: cout << "Enter a 3 digt loan id: ";
    std::cin >> loanId;

    std :: cout << "Enter the duration of the loans in years: ";
    std :: cin >> years;

    std :: cout << "Enter the amount of the debt: ";
    std :: cin >> debt;

    std :: cout << "Enter the interrest rate: ";
    std :: cin >> interestrate;

    std :: cout << "Enter the amount of payment per annual: ";
    std :: cin >> payments;

    return Loan(debt, years, payments, interestrate, loanId);

}



void display (double a, int b, int c, double d, int e){
    Loan p (a, b, c, d, e);

    double balance, monthlyPaidInt, MonthPrincipal, MonIntRate, MonthPmt;

    MonIntRate = p.getMonthlyInterest();
    MonthPmt = p.totalPayment();
    balance = p.getDebt();

    std :: cout <<"\t Amortized Payment Schedule" << std :: endl;
    std :: cout <<setw(6)<<left<<"Month"<<setw(12)<<left<<"Paid Principal"<<setw(14)<<right<<"Paid Interest"<<setw(12)<<right<<"New Balance"
                <<setw(12)<<right<< "Total payments"
                << std :: endl;

    bool run = true;

while (run){
    for (int i=1; i <= p.getYears()*12; i++)
        {


            monthlyPaidInt = balance * MonIntRate;
            MonthPrincipal = MonthPmt + monthlyPaidInt;
            balance = balance - MonthPrincipal;

            if(balance < 0){
                run = false;
            }


            std::cout << std::setw(6)  << std::left  << i
                      << std::setw(12) << std::left  << std::setprecision(2) << std::fixed << MonthPrincipal
                      << std::setw(14) << std::right << std::setprecision(2) << std::fixed << monthlyPaidInt
                      << std::setw(14) << std::right << std::setprecision(2) << std::fixed << balance
                      << std::setw(14) << std::right << std::setprecision(2) << std::fixed << p.getDebt()-balance
                      << std::endl;


        }
    }
}

void otherTypeOfLoans(){

    Loan a;
    Loan b;

    int years, payments, loanId;
    double debt, interrestrate;

    std :: cout << "Enter a 3 digt loan id: ";
    std::cin >> loanId;

    std :: cout << "Enter the duration of the loans in years: ";
    std :: cin >> years;

    std :: cout << "Enter the amount of the debt: ";
    std :: cin >> debt;

    std :: cout << "Enter the interrest rate: ";
    std :: cin >> interrestrate;

    std :: cout << "Enter the amount of payment per annual: ";
    std :: cin >> payments;


    a.setYears(years);
    a.setDebt(debt);
    a.setInterestRate(interrestrate);
    a.setPaymentsPerYear(payments);
    a.setLoanId(loanId);

    display(debt, years, payments, interrestrate, loanId);


}

void taxDeduction(){

    Loan p (1000000.00, 30, 12, 3.0, 001);

    std :: cout << "Total interrest is : " << p.totaltInterest()
                <<std :: endl;

    std :: cout << "Your total tax dection is : " << p.totalInterestTaxDeducted(30.6)
                << std :: endl;


}

void displayChoice(){

      char a;
do{
    std :: cout << "Press 1 to see the payments of the loan." << std :: endl
                << "Press 2 to see the total i nterest tax deducted." << std :: endl
                << "Press 3 to kill yourself." << std :: endl
                << "Press q to quit." << std :: endl;



    std :: cin >> a;

    switch (a) {
    case '1': {
        std :: cout << "CASE 1";
        break;
    }
    case '2': {
        taxDeduction();
        break;
    }
    case '3': {
        otherTypeOfLoans();
        break;
    }
    default: {
        std :: cout << "DEFUALT \n";
        break;
    }
    }
    } while(a != 'q');
}

int main()
{
    //display();

   // taxDeduction();

   displayChoice();

    return 0;
}
