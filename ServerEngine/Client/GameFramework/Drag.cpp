#include "Drag.h"

void DragFile::DragsFile(HDROP hDrop){
	// Index Value�� 0xFFFFFFFF�� �ָ� ����� ������ �� ������ ����.
	int nFile = DragQueryFileA(hDrop, 0xFFFFFFFF, NULL, 0);
	int i = 0;
	CHAR szFilePath[MAX_PATH] = { 0, };

	if (nFile > 0)
	{
		for (i = 0; i<nFile; i++)
		{
			// ���� �˾Ƴ���
			DragQueryFileA(hDrop, i, szFilePath, MAX_PATH);
			printf("%s", szFilePath);
		}
	}




	// ��ӵ� ���� ���ֱ�
	DragFinish(hDrop);
}