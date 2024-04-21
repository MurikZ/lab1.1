#include <iostream>
#include <stack>

using namespace std;

int main()
{
    deque <float> users{ 1,2.4,8 , 4.5,6 };
    stack <float> stack{ users };

    int elem1 = stack.top();
    while (!stack.empty())
    {
        int a = stack.top();
        stack.pop();
        if (a > elem1)
        {

            elem1 = a;


        }


    }
    cout << elem1;
}
