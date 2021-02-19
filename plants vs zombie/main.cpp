#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    DWORD s;
    DWORD pid;
    HWND hwnd;
    HANDLE handle;
    DWORD scoreAdress = 0x222D8940;
    hwnd = FindWindow(NULL, L"Plants vs. Zombies 1.2.0.1073 RELEASE");
    if (!hwnd) {
        cout << "NULL" << endl;
        return 0;
    }
    GetWindowThreadProcessId(hwnd, &pid);
    handle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    //scoreAdress += 0x5578;
    do {
        ReadProcessMemory(handle, (LPVOID)scoreAdress, &s, sizeof(s), NULL);
        //参数一 填许可       参数二填地址   参数三存放的位置

        printf("当前阳光:");
        cout << s << endl;
        Sleep(300);  //程序延迟300ms
        system("cls");//清空控制台
    } while (TRUE);
    return 0;
}