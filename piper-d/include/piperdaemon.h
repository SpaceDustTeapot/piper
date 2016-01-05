/* 
   This file is part of Piper-d.

    Piper-d is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Piper-d is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

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
        bool Create_Settingsfolder();
        bool load_file();
        std::string token(std::string str);
        std::string commandtoke(std::string str);
        std::string putoldtoke(std::string str);
        bool find_Profile();
        void cmdExecute();
       static void sigint_handler(int sig);
       bool Find_Lastcommand();
       bool Save_Lastcommand();
       bool cmp_tokes();
       void save_pid(long IDpid);
       bool findmoz_ini();

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
    std::string setting;
    std::string tokens[255];
    std::string Lastcommand[255];
    int tokeptr;
    std::string has;
    bool firstLoad;
};

#endif // PIPERDAEMON_H
