
#include <iostream>
using namespace std;

void recursive_Table(int m, int n)
{
    if (n == 0)
        return;

    recursive_Table(m, n - 1);
    cout <<m<<"x"<<n<<"="<<m*n<<endl;
}

int main()
{
    int m, n;
    cout << "Enter M: ";
    cin >> m;
    cout << "Enter N: ";
    cin >> n;
    recursive_Table(m, n);
    return 0;
}