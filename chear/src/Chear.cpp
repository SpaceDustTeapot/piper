#include "../include/Chear.h"

Chear::Chear()
{
    //ctor
}

void Chear::checkforPid()
{
    std::string Home = getenv("HOME");
    Home = Home +"/.piper-d";
    std::cout<<"home! "<<Home<<std::endl;

   // DIR *ReaPID;
    DIR *WrittenPID = opendir(Home.c_str());

    if(WrittenPID == NULL)
    {
    //  std::system("piper-d");
    //std::cout<<"WrittenPID is null ._."<<std::endl;
    // return;
    }
    else
    {
     std::cout<<"Piper folder Exists"<<std::endl;
    }
    std::string fPID = GrabfilePID(Home);

   std::string LocPID = "/proc/" + fPID;
   std::cout<<"LOCPID is:"<<LocPID<<std::endl;
   DIR *ReaPID = opendir(LocPID.c_str());
    if(ReaPID == NULL)
    {
    std::cout<<"Not Running"<<std::endl;
    std::cout<<"So Start"<<std::endl;
     std::system("piper-d");
     //return;
    }
    else
    {
     std::cout<<"is running so Quit"<<std::endl;

    }


    //checkforPid();
}

std::string Chear::GrabfilePID(std::string str)
{
 str = str+"/pid";
 char c;
 std::string buf="";
  std::ifstream file(str);
  if(file.is_open())
  {
   while(file.get(c))
   {
    buf = buf + c;

   }

  }
   std::cout<<"Buf is:"<<buf<<std::endl;
   return buf;
}

Chear::~Chear()
{
    //dtor
}
