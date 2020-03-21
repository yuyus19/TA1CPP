#include <iostream>
#include "Loan.h"

using namespace std;

void taxDeduction(){

    Loan p (1000000.00, 30, 12, 3.0);

    std :: cout << "Total interrest is : " << p.totaltInterest()
                <<std :: endl;

    std :: cout << "Your total tax dection is : " << p.totalInterestTaxDeducted(30.6)
                << std :: endl;


}

void display (){
    Loan p (1000000, 30, 12, 3.0);

    double balance, monthlyPaidInt, MonthPrincipal, MonIntRate, MonthPmt;

    MonIntRate = p.getMonthlyInterest();
    MonthPmt = p.totalPayment();
    balance = p.getDebt();

    std :: cout <<"\t Amortized Payment Schedule" << std :: endl;
    std :: cout <<setw(6)<<left<<"Month"<<setw(12)<<left<<"Paid Principal"<<setw(14)<<right<<"Paid Interest"<<setw(12)<<right<<"New Balance"
                <<std :: endl;

    bool a = true;

while (a){
    for (int i=1; i <= p.getYears()*12; i++)
        {


            monthlyPaidInt = balance * MonIntRate;
            MonthPrincipal = MonthPmt + monthlyPaidInt;
            balance = balance - MonthPrincipal;

            if(balance < 0){
                a = false;
            }


            std::cout << std::setw(6)  << std::left  << i
                      << std::setw(12) << std::left  << std::setprecision(2) << std::fixed << MonthPrincipal
                      << std::setw(14) << std::right << std::setprecision(2) << std::fixed << monthlyPaidInt
                      << std::setw(14) << std::right << std::setprecision(2) << std::fixed << balance
                      << std::endl;


        }
    }
}



void displayChoice(){

    std :: cout << "Press 1 to see the payments of the loan." << std :: endl
                << "Press 2 to see the total i nterest tax deducted." << std :: endl
                << "Press 3 to kill yourself." << std :: endl;

    char a;

    std :: cin >> a;

    switch (a) {
    case 1: {
        display();
        break;
    }
    case 2: {
        std :: cout << "Make the method for totalInterestTaxDeducted dumbass" << std :: endl;
    }

    }
}

int main()
{
    //display();

    taxDeduction();

    return 0;
}
