#include "stdafx.h"

// We need to provide an export to force the expected stub library to be generated
//__declspec (dllexport) void dummy(){}

extern "C"
{
	int __cdecl module_start(size_t argc, const void* args)
	{
		return 0;
	}

	int __cdecl module_stop(size_t argc, const void* args)
	{
		return 0;
	}
}