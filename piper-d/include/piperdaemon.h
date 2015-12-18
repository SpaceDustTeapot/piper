#ifndef PIPERDAEMON_H
#define PIPERDAEMON_H
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>

class piperdaemon
{
    public:
        piperdaemon();
        virtual ~piperdaemon();
        void Start();
        void Loop();
        bool file_exists();
        bool load_file();
        std::string token(std::string str);
        std::string commandtoke(std::string str);
        bool find_Profile();
        void cmdExecute();

    protected:
    private:
    // fork Code modified from  http://timmurphy.org/2014/04/26/using-fork-in-cc-a-minimum-working-example/ to get a bare bones forking system working
    //cheers tim :3
    //fork counter
    pid_t pid;
    int counter;
    std::ifstream File;
    std::ifstream dFile;
   // std::ifstream DFile;
    std::string Profile_Loc;
    std::string Datafile_Loc;
    std::string tokens[255];
    int tokeptr;
    std::string has;
    bool firstLoad;
};

#endif // PIPERDAEMON_H
