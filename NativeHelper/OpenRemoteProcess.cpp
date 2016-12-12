#include <windows.h>

#include "NativeHelper.hpp"

RC_Pointer __stdcall OpenRemoteProcess(RC_Pointer id, ProcessAccess desiredAccess)
{
	DWORD access = PROCESS_QUERY_INFORMATION | SYNCHRONIZE;
	switch (desiredAccess)
	{
		case ProcessAccess::Read:
			access |= PROCESS_VM_READ;
			break;
		case ProcessAccess::Write:
			access |= PROCESS_VM_WRITE;
			break;
		case ProcessAccess::Full:
			access |= PROCESS_VM_READ | PROCESS_VM_WRITE;
			break;
	}

	auto handle = OpenProcess(access, FALSE, (DWORD)id);

	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		return nullptr;
	}

	return handle;
}
