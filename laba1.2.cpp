#include <iostream>
#include <stack>

using namespace std;

struct Chtoto {
    string surname;
    double pay;
};
int main()
{
    setlocale(0, "ru");
    stack <Chtoto> estack;
    Chtoto estk;
    estk.surname = "jonhson";
    estk.pay = 30000;
    estack.push(estk);

    Chtoto estk1;
    estk1.surname = "smith";
    estk1.pay = 35000;
    estack.push(estk1);

    Chtoto estk2;
    estk2.surname = "griffin";
    estk2.pay = 20000;
    estack.push(estk2);

    int a;
    a = (estk.pay + estk1.pay + estk2.pay) / 3;
    cout << "средний оклад " << a << "\n";
    while (!estack.empty())
    {
        Chtoto emp = estack.top();

        cout << "фамилия работника " << endl << emp.surname << "\n" << "оклад " << emp.pay << endl;
        estack.pop();
    }

}
