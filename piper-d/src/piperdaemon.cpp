#include "../include/piperdaemon.h"

piperdaemon::piperdaemon()
{
    //ctor
}

void piperdaemon::Loop()
{
 //Want it check for an File
 //if file doesn't exist
 //sleep for 30 seconds
 //if file exists
 //fork off
 //pfork sleeps for a minute
 //cfork erases the file and tokenizes it and passes it to the video player
 //p fork goes back and loops
 //c fork dies after its played

file_exists();

}

piperdaemon::~piperdaemon()
{
    //dtor
}


bool piperdaemon::file_exists()
{
//Get env path
//WOO getenv works :3
std::string path;
path = getenv("HOME");
//std::cout<<"Path is "<<path<<std::endl;
path = path + "/.mozilla/firefox/why.kek";
 File.open(path);
 if(File.is_open())
  {
    std::cout<<"WOW it works ._."<<std::endl;
  }
  else
  {
   std::cout<<"it doesn't work :^)"<<std::endl;
  }
  File.close();
  return 1;
}
