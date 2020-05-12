#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string test = "z";
	int a = stoi(test, nullptr, 36);
	cout << a << endl;
	return 0;
}
