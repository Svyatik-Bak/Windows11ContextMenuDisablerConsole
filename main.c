#include <stdio.h>
#include <windows.h>

int var1;
int main()
{
    HKEY hKey;
    for (int j = 0; j <= 1024; j+=1)
    {
    system("cls");
    system("title Windows11ContextMenuDisablerConsole");
    printf("1. Enable Old Context menu\n");
    printf("2. Disable Old Context menu\n");
    printf("3. Restart explorer\n");
    printf("4. Exit\n");
    scanf_s("%i", &var1);
    switch(var1)
    {
    case 1: RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL); break;
    case 2: RegDeleteKeyExW(HKEY_CURRENT_USER, L"Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32", 0, KEY_WOW64_64KEY); break;
    case 3: system("taskkill /f /im explorer.exe & start explorer.exe"); break;
    case 4: exit(0); break;
    }
    }
}
