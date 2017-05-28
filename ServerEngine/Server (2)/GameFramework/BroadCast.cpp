
#include "BroadCast.h"
BroadCast* BroadCast::GetInstance() {
	static BroadCast Instance;
	return &Instance;
}
BroadCast::BroadCast(){
	blockUp = 0;
	m_pSelectedBlock = nullptr;
}
BroadCast::~BroadCast(){}

void BroadCast::PleasePop(Block *m_pTmp){
	pause = true;
	std::list<Block *>::iterator it = UserBlock.begin();
	for (it; it != UserBlock.end();++it){
		if (m_pTmp == *it)
			*it = nullptr;
		if (it == UserBlock.end())
			break;
	}

	it = UserBlock.begin();

	pause = false;
}
/*
std::list<Block *>TmpList;
for (std::list<Block *>::iterator it = UserBlock.begin(); it != UserBlock.end();){
printf("%d\n", *it);
++it;
}
printf("-------------------\n%d %d", TmpList.begin(), TmpList.end());

printf("-------------------\n%d %d", UserBlock.begin(),UserBlock.end());

printf("\n----------------------\n");
while (UserBlock.size()!=0){
if (m_pTmp == UserBlock.back()){
TmpList.push_back(nullptr);
UserBlock.pop_back();
}
else{
TmpList.push_back(UserBlock.back());
UserBlock.pop_back();
}
}
TmpList.reverse();
UserBlock.clear();
UserBlock.swap(TmpList);

for (std::list<Block *>::iterator it = UserBlock.begin(); it != UserBlock.end();++it){
printf("%d\n", *it);
}


*/