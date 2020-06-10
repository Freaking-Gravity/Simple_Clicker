#include <iostream>
#include <Windows.h>

using namespace std;

int x = 0, y = 0, clicks;
bool clicking = false;



void Menu()
{
	cout << "How many clicks per second? (15 for best results): \n ESC to pause:" << endl;
	cin >> clicks;
}
void Clicker()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			clicking = true;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			clicking = false;
		}
		if (clicking == true)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
			Sleep(1000 / clicks);
		}

	}
}
int main()
{
	Menu();
	Clicker();
	//return 0;
}