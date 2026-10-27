#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 23;

// Перевірка критерію:
// елемент НЕ є непарним з індексом, кратним 3
bool IsSelected(const int s[], const int i)
{
    return !(s[i] % 2 != 0 && i % 3 == 0);
}

// Формування масиву REK
void CreateREK(int sr[], const int n, int i = 0)
{
    sr[i] = 4 + rand() % 13;

    if (i < n - 1)
        CreateREK(sr, n, i + 1);
}

// Виведення масиву REK
void PrintREK(const int sr[], const int n, int i = 0)
{
    cout << setw(4) << sr[i];

    if (i < n - 1)
        PrintREK(sr, n, i + 1);
    else
        cout << endl;
}

// Обчислення кількості елементів за критерієм REK
int CountREK(const int sr[], const int n, int i = 0)
{
    if (i >= n)
        return 0;

    return (IsSelected(sr, i) ? 1 : 0)
        + CountREK(sr, n, i + 1);
}

// Обчислення суми елементів за критерієм
int SumREK(const int sr[], const int n, int i = 0)
{
    if (i >= n)
        return 0;

    return (IsSelected(sr, i) ? sr[i] : 0)
        + SumREK(sr, n, i + 1);
}

// Заміна відібраних елементів нулями
void ReplaceREK(int sr[], const int n, int i = 0)
{
    if (i >= n)
        return;

    if (IsSelected(sr, i))
        sr[i] = 0;

    ReplaceREK(sr, n, i + 1);
}


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int sr[N];

CreateREK(sr, N);

cout << "Start array:" << endl;
PrintREK(sr, N);

cout << "Count = " << CountREK(sr, N) << endl;
cout << "Sum = " << SumREK(sr, N) << endl;

ReplaceREK(sr, N);

cout << "Modified array:" << endl;
PrintREK(sr, N);

return 0;
}