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
        //����һ �����       ���������ַ   ��������ŵ�λ��

        printf("��ǰ����:");
        cout << s << endl;
        Sleep(300);  //�����ӳ�300ms
        system("cls");//��տ���̨
    } while (TRUE);
    return 0;
}