#ifndef PIPERDAEMON_H
#define PIPERDAEMON_H
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>

class piperdaemon
{
    public:
        piperdaemon();
        virtual ~piperdaemon();
        void Loop();
        bool file_exists();
    protected:
    private:
    // fork Code modified from  http://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/ to get a bare bones forking system working
    //cheers tim :3
    //fork counter
    pid_t pid;
    int counter;
    std::ifstream File;

};

#endif // PIPERDAEMON_H
