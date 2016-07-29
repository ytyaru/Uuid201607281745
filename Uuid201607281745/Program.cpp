#include <cstdio>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include "Uuid.h"
using ::std::basic_string;
using ::std::_tprintf;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ".ACP");
	
	basic_string<TCHAR> strId = ::ytyaru::Library::Uuid::Get();
	{
		using namespace ::ytyaru::Library;
		strId = Uuid::Get();
	}
	{
		namespace Uuid = ::ytyaru::Library::Uuid;
		strId = Uuid::Get();
	}
	{
		using namespace ::ytyaru::Library::Uuid;
		strId = Get();
	}

	OutputDebugString(strId.c_str());
    OutputDebugString(_T("\n"));
	_tprintf(strId.c_str());
	
	return 0;
}
