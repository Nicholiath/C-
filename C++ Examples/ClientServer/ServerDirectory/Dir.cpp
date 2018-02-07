#include "Dir.h"
#include <sys/dir.h>
#include <string.h>

Dir::Dir(char* dirName){
	this->dirName = dirName;
}

char* Dir::getDirectory() {
	DIR * dirp;
	struct direct *d;
	char *out = new char[1024];
	dirp = opendir(dirName);
	if (dirp == NULL) {
	}
	while (d = readdir(dirp)) {
		strcat(out, d->d_name);
		strcat(out, "\n");
	}
	closedir (dirp);
	return out;
}

Dir::~Dir() {}