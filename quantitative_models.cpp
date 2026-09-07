#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void simpleInterest()
{
    double principal, rate, time;

    cout << "\nEnter principal amount: ";
    cin >> principal;

    cout << "Enter annual interest rate (%): ";
    cin >> rate;

    cout << "Enter time (years): ";
    cin >> time;

    double interest = (principal * rate * time) / 100.0;
    double amount = principal + interest;

    cout << fixed << setprecision(2);
    cout << "\nSimple Interest = " << interest << endl;
    cout << "Total Amount    = " << amount << endl;
}

void compoundInterest()
{
    double principal, rate, time;

    cout << "\nEnter principal amount: ";
    cin >> principal;

    cout << "Enter annual interest rate (%): ";
    cin >> rate;

    cout << "Enter time (years): ";
    cin >> time;

    double amount = principal * pow(1 + rate / 100.0, time);
    double interest = amount - principal;

    cout << fixed << setprecision(2);
    cout << "\nCompound Interest = " << interest << endl;
    cout << "Total Amount      = " << amount << endl;
}

void linearRegression()
{
    int n;

    cout << "\nEnter number of observations: ";
    cin >> n;

    double x[100], y[100];

    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;

    cout << "\nEnter X and Y values:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Observation " << i + 1 << " X: ";
        cin >> x[i];

        cout << "Observation " << i + 1 << " Y: ";
        cin >> y[i];

        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double denominator = n * sumX2 - sumX * sumX;

    if (denominator == 0)
    {
        cout << "\nRegression cannot be calculated because "
             << "all X values are identical." << endl;
        return;
    }

    double slope =
        (n * sumXY - sumX * sumY) / denominator;

    double intercept =
        (sumY - slope * sumX) / n;

    cout << fixed << setprecision(2);

    cout << "\nRegression Equation: Y = "
         << intercept << " + "
         << slope << "X" << endl;

    double inputX;

    cout << "Enter X value for prediction: ";
    cin >> inputX;

    double predictedY =
        intercept + slope * inputX;

    cout << "Predicted Y = "
         << predictedY << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "   BASIC QUANTITATIVE MODELS - C++\n";
        cout << "====================================\n";

        cout << "1. Simple Interest\n";
        cout << "2. Compound Interest\n";
        cout << "3. Simple Linear Regression\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                simpleInterest();
                break;

            case 2:
                compoundInterest();
                break;

            case 3:
                linearRegression();
                break;

            case 4:
                cout << "\nProgram ended successfully.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
