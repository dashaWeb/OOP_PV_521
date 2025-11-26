#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

string text = "Nonename function";

template <typename ConType>
void print(const ConType& cont, const string& prompt = "")
{
    cout << prompt << endl;
    for (auto& i : cont)
    {
        cout << i << "\t";
    }cout << endl;
}

int main()
{
    auto func = [](int a, int b, int c) -> double {
        double sum = a + b + c;
        return sum / 3;
    };
    cout << "func(2,3,11) :: " << func(2, 3, 11) << endl;
    cout << "Typeid :: " << typeid(func).name() << endl;

    string localText = "function can ... ";

    // closure - захоплення змінної (замикання)
    // [capture-list](formal parameters) -> resulttype {body;};
    // [=] - захопили всі локальні змінні у тому ж блоці що лямбда по значенню
    // [&] - захопили всі локальні змінні у тому ж блоці що лямбда по ПОСИДАННЮ
    // 
    auto demo = [&localText] { // localText - захоплена за значенням, &localText - за посиланням
        cout << "Hello from lambda : " << text << endl;
        cout << "Hello from lambda : " << localText << endl;
    };
    cout << "\n\n";
    demo();
    localText = "Other .. ";
    cout << "\n\n";
    demo();

    deque<int> d{ 10,23,-100,45,67,-22,81 };
    int divisor = 9;

    auto it = find_if(begin(d), end(d), [&divisor](int el) {return el % divisor == 0; });
    cout << "Divisor : " << divisor << endl;
    if (it != end(d))
    {
        cout << "\n Was found divisible by  " << divisor << " :: " << *it << " in index " << distance(begin(d), it) << endl;
    }

    print(d, "\nDeque origin :: ");
    int mult = 3;
    vector<int> v(d.size());
    transform(begin(d), end(d), begin(v), [=](int el) {return el * mult; });
    print(d, "\nDeque origin :: ");
    print(v, "\n Vector after transfor :: ");


    sort(begin(d), end(d), [](int a, int b) {return abs(a) < abs(b); });
    print(d, "\nDeque sort :: ");


    deque<string> number{ "second", "one","two","hundred", "three", "second" };
    print(number, "\nDeque origin :: ");
    sort(begin(number), end(number), [](string a, string b) {return a.size() < b.size(); });
    print(number, "\nDeque origin :: ");
}
