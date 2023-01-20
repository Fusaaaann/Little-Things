#include <Winnls.h>
#include <Windows.h>
#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>

using namespace std;


int wmain(int argc, wchar_t* argv[])
{
    SetConsoleTitle(L"My Console Window - 你好");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char* a = setlocale(LC_ALL, "chinese");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo
}