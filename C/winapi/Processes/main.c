#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int wmain(int argc, LPWSTR argv[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	LPWSTR commandLine = GetCommandLineW();
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	si.cb = sizeof(si);
	LPWSTR programArgs;
	programArgs = wcsstr(commandLine, argv[1]);

	wprintf(L"The program args are: %s\n", programArgs);
	wprintf(L"The program path is: %s\n", argv[1]);

	bool process = CreateProcessW(argv[1], programArgs, NULL, NULL, 0, 0, 0, NULL, &si, &pi);
	if (process == false) {
		printf("Someting went wrong creating process");
		exit(1);
	}

	if (WaitForSingleObject(pi.hProcess, INFINITE) == WAIT_OBJECT_0)
	{
		DWORD exitCode;
		FILETIME creation_time, exit_time, ftKernel, ftUser;
		GetExitCodeProcess(pi.hProcess, &exitCode);
		if (GetProcessTimes(pi.hProcess, &creation_time, &exit_time, &ftKernel, &ftUser)) {
			SYSTEMTIME stUser, stKernel;
			FileTimeToSystemTime(&ftKernel, &stKernel);
			FileTimeToSystemTime(&ftUser, &stUser);
			printf("error level %d\n", exitCode);
			printf("user time %d.%d\n", stUser.wSecond, stUser.wMilliseconds);
			printf("kernel time %d.%d\n", stKernel.wSecond, stKernel.wMilliseconds);
		}
		else {
			printf("Something went wrong with getting process times");
		}
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		exit(exitCode);
	}


	return 0;
}
