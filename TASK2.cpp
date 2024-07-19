#include <iostream>
using namespace std;

/*SIMPLE CALCULATOR*/

void simpleCalculator(float num1, float num2, char operation)
{
    switch (operation)
    {
    case '+':
        cout << num1<<operation<<num2<<"=" << num1 + num2 << endl;
        break;

    case '-':
        cout << num1<<operation<<num2<<"=" << num1 - num2 << endl;
        break;

    case '*':
        cout << num1<<operation<<num2<<"=" << num1 * num2 << endl;
        break;

    case '/':
        cout << num1<<operation<<num2<<"=" << num1 / num2 << endl;
        break;

    default:
        cout << "invalid operation entered " << endl;
    }
}

int main()
{
    char operation;
    float num1, num2;

    cout << "enter first operand " << endl;
    cin >> num1;

    cout << "enter second operand" << endl;
    cin >> num2;

    cout << "enter operation" << endl;
    cin >> operation;

    simpleCalculator(num1, num2, operation);

    return 0;
}