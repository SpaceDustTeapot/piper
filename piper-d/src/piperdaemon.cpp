#include "../include/piperdaemon.h"

piperdaemon::piperdaemon()
{
    //ctor
}

void piperdaemon::Start()
{
 //Want it check for an File
 //if file doesn't exist
 //sleep for 30 seconds
 //if file exists
 //hash
 //fork off
 //pfork sleeps for a minute
 //cfork erases the file and tokenizes it and passes it to the video player
 //p fork goes back and loops
 //c fork dies after its played

//file_exists();
 find_Profile();
 std::cout<<"in file exists"<<std::endl;
  bool file_exist = file_exists();
   if(file_exist == 1)
   {
     //call real loop

   }
   else if(file_exist == 0)
   {
   std::cout<<"going sleep nightnight"<<std::endl;
    sleep(5);
    std::cout<<"out of sleep recurively calling start again"<<std::endl;
    Start();

   }


}

void Piperdaemon::Loop()
{


}

piperdaemon::~piperdaemon()
{
    //dtor
}


bool piperdaemon::file_exists()
{
//Get env path
//WOO getenv works :3
std::string mozpath;
std::string path;
mozpath = getenv("HOME");
//std::cout<<"Path is "<<path<<std::endl;
path = Profile_Loc + "/data.txt";
std::cout<<path<<std::endl;
 dFile.open(path);
 if(dFile.is_open())
  {
  return true;
  /*  std::cout<<"WOW it works ._."<<std::endl;
    char c;
    std::string buf = "";
    while(File.get(c))
    {
     buf = buf + c;

    }
    std::cout<<"buf is: "<<std::endl;
    std::cout<<buf<<std::endl;*/
  }
  else
  {
   std::cout<<"it doesn't exist :^)"<<std::endl;
   std::cout<<"datapath should be: "<<path<<std::endl;
   return 0;
  }
  dFile.close();
  return 1;
}


bool piperdaemon::find_Profile()
{

//VERY HACKY
//reads to be rewrote;
 std::string mozpath;
std::string path;
mozpath = getenv("HOME");
//std::cout<<"Path is "<<path<<std::endl;
path = mozpath + "/.mozilla/firefox/why.kek";
 File.open(path);
 if(File.is_open())
  {
    std::cout<<"WOW it works ._."<<std::endl;
    char c;
    std::string buf = "";
    while(File.get(c))
    {
     buf = buf + c;

    }
    std::cout<<"buf is: "<<std::endl;
    std::cout<<buf<<std::endl;
    token(buf);
    Profile_Loc = mozpath + "/.mozilla/firefox/" + tokens[2];
    std::cout<<"PROFILE_LOC: "<<Profile_Loc<<std::endl;
    return true;
  }
  else
  {
   std::cout<<"it doesn't work :^)"<<std::endl;
  }
  File.close();
  return 1;

}

std::string piperdaemon::token(std::string str)
{
std::cout<<"in function Token"<<std::endl;
size_t len=0;
size_t newstartpos=0;
bool ignore = false;
   len = str.length();
   std::cout<<"before loop"<<std::endl;
   std::cout<<"len is: "<<len<<std::endl;
   for(size_t i=0;i<len;i++)
   {
   std::cout<<"first for loop"<<std::endl;
   //grab one letter at a time;
   std::string curr_let = str.substr(i,1);
    std::cout<<"curr_let: "<<curr_let<<std::endl;
    if(curr_let == "#" || ignore == true)
    {

        if(curr_let == "#" && ignore == true)
        {
        std::cout<<"newstartpos is "<<newstartpos<<" i is: "<<i<<std::endl;
        newstartpos = i + 1;
        ignore = false;
        }
        else if(ignore == false)
        {
            ignore = true;
        }



    }

   }
 std::cout<<"Newstartpos is "<<newstartpos<<std::endl;
 std::cout<<"outside first for loop"<<std::endl;
   int counta = 0;
   std::string buff ="";
   std::cout<<"LEN is: "<<len<<std::endl;
   for(size_t k = newstartpos; k<len;k++)
   {
     std::string stringtemp = str.substr(k,1);
     if(stringtemp == " ")
     {

     std::cout<<"In k loop"<<std::endl;
        if(counta < 255)
        {
        std::cout<<"counta is "<<counta<<std::endl;
            tokens[counta] = buff;
            counta = counta + 1;
            buff = "";
        }
     }
     else
     {
      buff = buff + stringtemp;
      std::cout<<"Buff is? "<<buff<<std::endl;
      size_t tempp = len;
      tempp = len - 2;
      std::cout<<"tempp" <<tempp<<std::endl;
      std::cout<<"k"<<k<<std::endl;
        if(k == tempp )
        {
        std::cout<<"in k if"<<std::endl;

         tokens[counta] = buff;
         counta = counta + 1;
        }
     }

   }

   for(int l=0;l<counta;l++)
   {
    std::cout<<"Token["<<l<<"] :"<<tokens[l]<<std::endl;

   }

 return "e";
}
