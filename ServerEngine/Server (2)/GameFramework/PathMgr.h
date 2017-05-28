#ifndef _PATHMGR_H_
#define _PATHMGR_H_

#include <string>
#include <iostream>
#include <fstream>
#define PathMgr PathManager::GetInstance()

class PathManager{
public:
	PathManager();
	~PathManager();

	static PathManager* GetInstance();

	std::string str,projectName,savePath,test,plat;
	std::string cursor, splash;
	std::string file_n, file_c, help_n,help_c,option_n,option_c,tool_n,tool_c;
	std::string line,toolCir,toolCir_g,toolBox,toolBox_g,line_left,line_right;
	std::string task, task_green, task_pane;
	std::string filelist, file_name, logo;
};
#endif