#ifndef _BROADCAST_H_
#define _BROADCAST_H_

#define BroadMgr BroadCast::GetInstance()
#include "Block.h"
#include <string>
#include <list>
class BroadCast{
private:
public:
	BroadCast();
	~BroadCast();

	static BroadCast* GetInstance();

	Block *m_pSelectedBlock;
	
	bool blockUp;
	bool pause=false;

	int mouseMode=1;
	std::list<Block*> UserBlock;
	std::list<string> CppFileName;
	std::list<string> HeaderFileName;

	void PleasePop(Block *m_pTmp);
};
#endif