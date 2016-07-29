#include "Uuid.h"

namespace ytyaru
{
namespace Library
{
namespace Uuid
{
std::basic_string<TCHAR> Get()
{
	// �����Z�b�g�ɂ��^��ύX����
	#if defined(_UNICODE) || defined(UNICODE)
	RPC_WSTR p;
	#else
	RPC_CSTR p;
	#endif
			
	UUID uuid;
	RPC_STATUS res;
			
	// UUID����
	res = ::UuidCreate(&uuid);
	if (res == RPC_S_OK) {}
	else if (res == RPC_S_UUID_LOCAL_ONLY) { throw "::UuidCreate�֐����s�BRPC_S_UUID_LOCAL_ONLY�B"; }
	else if (res == RPC_S_UUID_NO_ADDRESS) { throw "::UuidCreate�֐����s�BRPC_S_UUID_NO_ADDRESS�B"; }
	else {}

	// UUID�𕶎���ɂ���
	res = ::UuidToString(&uuid, &p);
	if (res == RPC_S_OK) {}
	else if (res == RPC_S_OUT_OF_MEMORY) { throw "::UuidToString�֐����s�BRPC_S_OUT_OF_MEMORY�B"; }
	else {}
			
	// �����Z�b�g�ɂ��^���L���X�g����
	// �Ƃ���MBCS�̏ꍇ�ARPC_CSTR��unsigned char*�ł���B
	// MBCS�̏ꍇ�ATCHAR��char�ɂȂ邽�߁Achar�^�ɃL���X�g����K�v������B
	#if defined(_UNICODE) || defined(UNICODE)
	std::basic_string<TCHAR> str = reinterpret_cast<WCHAR*>(p);
	#else
	std::basic_string<TCHAR> str = reinterpret_cast<CHAR*>(p);
	#endif
			
	::RpcStringFree(&p);

	return str;
}
}
}
}
