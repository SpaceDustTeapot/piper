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
        void Start();
        void Loop();
        bool file_exists();
        std::string token(std::string str);
        bool find_Profile();
    protected:
    private:
    // fork Code modified from  http://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/ to get a bare bones forking system working
    //cheers tim :3
    //fork counter
    pid_t pid;
    int counter;
    std::ifstream File;
    std::ifstream dFile;
    std::string Profile_Loc;
    std::string Datafile_Loc;
    std::string tokens[255];
    int tokeptr;
    std::string has

};

#endif // PIPERDAEMON_H
