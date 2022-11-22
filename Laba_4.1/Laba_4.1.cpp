#include <iostream>
#include <fstream>
using namespace std;

bool prost(int n)
{
    if (n == 1) return false;
    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}
int mult(int n)
{
    int k = 1;
    while (n != 0)
    {
        k *= n % 10;
        n /= 10;
    }
    return k;
}

void f1()
{
    ofstream output("output.txt");
    output << "8888" << endl;
    for (int i = 1111; i <= 9999; i++)
        if (mult(i) == 243 && prost(i))
            output << i << " ";
    cout << "Проверьте файл: ";
}

int main()
{
    setlocale(LC_ALL, "ru");
    f1();
}