#ifndef CHEAR_H
#define CHEAR_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Chear
{
    public:
        Chear();
        virtual ~Chear();
        void checkforPid();
        std::string GrabfilePID(std::string str);
    protected:
    private:
};

#endif // CHEAR_H
