#define UNICODE
#define _UNICODE
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>

int _tmain(int argc, LPTSTR argv[])
{
	if (argc < 3) {
		_tprintf(_T("usage: %s <arg>\n"), argv[0]);
		exit(1);
	}

	int n = 4;
	DWORD dwActualReadBytes = 0, dwActualWriteBytes = 0;
	bool rwFileResponse;
	TCHAR sourceFilePath[100];
	TCHAR destFilePath[100];
	char* buffer;

	swscanf_s(argv[1], _T("%d"), &n);
	buffer = (char*)malloc(n);
	_tcscpy_s(sourceFilePath, 100, _T("../"));
	_tcscat_s(sourceFilePath, 100, argv[2]);
	_tcscpy_s(destFilePath, 100, _T("../"));
	_tcscat_s(destFilePath, 100, argv[3]);
	HANDLE sourceFileHandle = CreateFile(sourceFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE destFileHandle = CreateFile(destFilePath, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	if (sourceFileHandle == INVALID_HANDLE_VALUE || destFileHandle == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Something went wrong"));
		exit(1);
	}

	do {
		rwFileResponse = ReadFile(sourceFileHandle, (LPVOID)buffer, sizeof(buffer), &dwActualReadBytes, NULL);
		if (rwFileResponse == false) {
			int le = GetLastError();
			_tprintf(_T("Last Error : %d\n"), le);
			exit(le);
		}
		rwFileResponse = WriteFile(destFileHandle, (LPVOID)buffer, dwActualReadBytes, &dwActualWriteBytes, NULL);
		if (rwFileResponse == false) {
			int le = GetLastError();
			_tprintf(_T("Last Error : %d\n"), le);
			exit(le);
		}

	} while (dwActualReadBytes > 0 && dwActualWriteBytes > 0);

	_tprintf(_T("Finished"));

	CloseHandle(sourceFileHandle);
	CloseHandle(destFileHandle);
	return 0;
}