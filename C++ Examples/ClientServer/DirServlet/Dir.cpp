#include "Dir.h"
#include <dirent.h>
#include <string.h>
#include <iostream>

Dir::Dir(char* dirName){
	this->dirName = dirName;
}

char* Dir::getDir(){
	DIR *dirp;
	struct dirent *dir;
	char *dirStr = new char[1024];
	char *dc = new char[1024];
	dirp = opendir(dirName);
	while(dir = readdir(dirp)){
		if ((dir->d_type) == DT_DIR) {
			strcat(dc, dir->d_name);
			strcat(dc, ",");
		}
		else {
			strcat(dc, "X");
			strcat(dc, dir->d_name);
			strcat(dc, ",");
		}
	}
	closedir(dirp);
	return dc;
}

