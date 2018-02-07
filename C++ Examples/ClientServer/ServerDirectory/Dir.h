#ifndef DIR_H
#define DIR_H


#pragma once
class Dir {
public:
	Dir(char * dirName);
	char* getDirectory();
	~Dir();
private:
	char* dirName;
};

#endif