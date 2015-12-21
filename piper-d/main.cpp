#include <iostream>
#include "include/piperdaemon.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

using namespace std;

void innit_log()
{
 openlog("piper-d",LOG_CONS | LOG_NDELAY | LOG_PERROR | LOG_PID, LOG_USER);

}


int main()
{
//start log
innit_log();
/*daemon backbone */
    //Process ID and session ID
   /* pid_t Pid,Sid;

    //Fork off current process
    Pid = fork();

    if(Pid < 0)
    {
     //fail forking
     exit(EXIT_FAILURE);

    }*/

    //Good pid
    /*if(Pid > 0)
    {
     exit(EXIT_SUCCESS);

    }*/
    //change file mode
  //  umask(0);

    //log supposed to go here

    // create new SID for child
    /*Sid = setsid();

    if(Sid<0)
    {
    //failure
    exit(EXIT_FAILURE);

    }


    if((chdir("/"))<0)
    {
        exit(EXIT_FAILURE);

    }
*/
    //Close standered in,out and err
    //close(STDIN_FILENO);
    //close(STDOUT_FILENO);
    //close(STDERR_FILENO);


    syslog(LOG_USER,"%s","starting piper-d");

    //infinanted daemon loop

//    while(1)
  //  {
    //std::cout<<"starting piper-d"<<std::endl;
    piperdaemon pd;
    pd.Start();
   // sleep(30);
   // }

    closelog();

     //exit(EXIT_SUCCESS);
}
