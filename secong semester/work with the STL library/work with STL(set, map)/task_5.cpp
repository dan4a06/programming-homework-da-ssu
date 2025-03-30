#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/*
Дана последовательность целых чисел. Найти все такие цифры, которые не
встречаются в трехзначных числах.
*/

set <int> set_n(int n){
    set <int> s;
    while(n != 0){
        s.insert(n%10);
        n /= 10;
    }
    return s;
}

int main() {
    //setlocale(LC_ALL, "RU");

    int n; cout << "Введите количество элементов: "; cin >> n; cout << "\n";
    int a;
    set <int> res, s2, s3, s;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        s = set_n(a);
        if ( a>=100 && a <= 999) s2.insert(s.begin(), s.end());
        else s3.insert(s.begin(), s.end());
    }


    // из сета цифр не трёхзначных цифр вычитается сет цифр из трёхзначных чисел и добавляется в новый сет
    set_difference(s3.begin(), s3.end(), s2.begin(), s2.end(), inserter(res, res.begin()));


    cout << "Результат: \n";
    for (auto it = res.begin(); it != res.end(); ++it) cout << *it << "\t";

    return 0;
}