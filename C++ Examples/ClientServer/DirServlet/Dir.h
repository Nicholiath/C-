#ifndef DIR_H
#define DIR_H

class Dir {
public:
    Dir(char* dirName);	
	char* getDir();
private:
    char* dirName;	
};

#endif 