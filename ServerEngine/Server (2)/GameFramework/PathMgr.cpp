#include "PathMgr.h"

#define First "Theme/"
using namespace std;
PathManager* PathManager::GetInstance(){
	static PathManager Instance;
	return &Instance;
}
PathManager::PathManager(){
	std::ifstream readSet("settings/setting.txt");
	readSet >> str>>savePath>>projectName;
	test		= First + str + "/make.png";
	cursor		= First + str + "/cursor/cursor.png";
	splash		= First + str + "/Splash/Logo3.png";
	plat		= First + str + "/PlayBroad/plat.png";
	file_n		= First + str + "/topbar/file.png";
	file_c		= First + str + "/topbar/file_a.png";
	help_n		= First + str + "/topbar/4.png";
	help_c		= First + str + "/topbar/4_a.png";
	option_n	= First + str + "/topbar/3.png";
	option_c	= First + str + "/topbar/3_a.png";
	tool_n		= First + str + "/topbar/tool.png";
	tool_c		= First + str + "/topbar/tool_a.png";
	toolCir		= First + str + "/leftbar/toolBox.png";
	toolCir_g	= First + str + "/leftbar/tool_box_a.png";
	toolBox		= First + str + "/leftbar/toolBox2.png";
	toolBox_g	= First + str + "/leftbar/tool_box2_a.png";
	line_left	= First + str + "/leftbar/line_left_a.png";
	line_right	= First + str + "/leftbar/line_right_a.png";
	line		= First + str + "/leftbar/line.png";
	task		= First + str + "/playboard/tap.png";
	task_green	= First + str + "/playboard/tab_sel.png";
	task_pane	= First + str + "/playboard/task_pane.png";
	filelist	= First + str + "/rightbar/filelist.png";
	file_name	= First + str + "/rightbar/filelist_name.png";
	logo		= First + str + "/rightbar/logo.png";
}
PathManager::~PathManager(){
}