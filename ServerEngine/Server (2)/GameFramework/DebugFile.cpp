#include "DebugFile.h"
#include "PathMgr.h"
#include "BroadCast.h"
#include <list>
DebugFile::DebugFile()
{
}


DebugFile::~DebugFile()
{

}
DebugFile* DebugFile::GetInstance(){
	static DebugFile Instance;
	return &Instance;
}

void DebugFile::Debug(){
	ofstream vcxproj(PathMgr->savePath + "/" +PathMgr->projectName+".vcxproj");
	string code,tail,tmp;
	code =
		"<Project DefaultTargets =\"Build\" ToolsVersion=\"12.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">   \n"
		"	<ItemGroup>																										            \n"
		"		<ProjectConfiguration Include=\"Debug|Win32\">																	    \n"
		"			<Configuration>Debug</Configuration>																				\n"
		"			<Platform>Win32</Platform>																						\n"
		"		</ProjectConfiguration>																							        \n\n"
		"		<ProjectConfiguration Include=\"Release|Win32\">																	\n"
		"			<Configuration>Release</Configuration>																			\n"
		"			<Platform>Win32</Platform>																						\n"
		"		</ProjectConfiguration>																							        \n"
		"	</ItemGroup>																										        \n"
		"	<Import Project=\"$(VCTargetsPath)\Microsoft.Cpp.default.props\"/>												        \n"
		"	<PropertyGroup>\n"
		"		<ConfigurationType>Application</ConfigurationType>																    \n"
		"		<PlatformToolset>v120</PlatformToolset>																			    \n"
		"	</PropertyGroup>																									        \n"
		"	<Import Project=\"$(VCTargetsPath)\Microsoft.Cpp.props\"/>														        \n"
		"	<ItemGroup>																													\n";
	vcxproj << code;
	for (std::list<string >::iterator it = BroadMgr->CppFileName.begin(); it != BroadMgr->CppFileName.end(); ++it){
		vcxproj << "		<ClCompile Include=\""<<*it<<"\"/>\n";
	}
	
	vcxproj<<"	</ItemGroup>																												\n"<<"	<ItemGroup>																													\n";

	for (std::list<string >::iterator it = BroadMgr->HeaderFileName.begin(); it != BroadMgr->HeaderFileName.end(); ++it){
		vcxproj << "		<ClCompile Include=\"" << *it << "\"/>\n";
	}
	tail =
		"	</ItemGroup>																												\n"
		"	<Import Project=\"$(VCTargetsPath)\Microsoft.Cpp.Targets\"/>															\n"
		"	<PropertyGroup>																												\n"
		"		<PreferredToolArchitecture>x64</PreferredToolArchitecture>															\n"
		"	</PropertyGroup>																											\n"
		"</Project>																														\n";
	vcxproj << tail;
	vcxproj.close();
	char *command = new char[MAX_PATH];
	string tmps = "cd " + PathMgr->savePath + "&& msbuild " + PathMgr->projectName + ".vcxproj  /p:PreferredToolArchitecture=x64";
	strcpy(command, tmps.c_str());
	system(command);
	system("cls");
	tmps = "cd " + PathMgr->savePath + "/Debug&&" + PathMgr->projectName + ".exe";
	strcpy(command, tmps.c_str());
	system(command);
}