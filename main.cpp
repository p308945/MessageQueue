#include "myqueue.h"

int main()
{
	MyClass m;
	char buf[32] = { 0 };
	for (int i = 0; i < 2048; ++i)
	{
		sprintf_s(buf, sizeof(buf), "%d", i);
		m.pushMsg(strlen(buf), buf);
	}
	m.processMsg();
}