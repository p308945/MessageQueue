#include "mq.h"
#include <iostream>
#include <string>

using namespace std;

class MyQueue
{
public:
	void pushMsg(int len, char *msg)
	{
		queue.pushMsg(len, msg);
	}
	void processMsg()
	{
		MsgPair *tmp = NULL;
		int i = 0;
		while (tmp = queue.getMsg())
		{
			cmdParse(tmp->first, tmp->second);
			queue.pop();
			++i;
		}
		cout << i << endl;
	}
	virtual void cmdParse(int len, char *msg) = 0;
private:
	MessageQueue<1024> queue;
};

class MyClass : public MyQueue
{
public:
	void cmdParse(int len, char *msg)
	{
		string s;
		s.assign(msg, len);
		cout << "len:" << len << "msg:" << s << endl;
	}
};