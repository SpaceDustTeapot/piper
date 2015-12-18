#include "../include/piperdaemon.h"

piperdaemon::piperdaemon()
{
    //ctor
    firstLoad = 0;
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
syslog(LOG_USER,"%s","In Start()");

 find_Profile();

 //std::cout<<"in file exists"<<std::endl;
  bool file_exist = file_exists();
   if(file_exist == 1)
   {
     //call real loop
     syslog(LOG_USER,"%s","The File data.txt exists");
     Loop();

   }
   else if(file_exist == 0)
   {
   syslog(LOG_USER,"%s","Gunna sleep for 5 seconds and check for data.txt again");
   //std::cout<<"going sleep nightnight"<<std::endl;
    sleep(5);
    syslog(LOG_USER,"%s","Arose from my slumber, I'm awake and ready to start");
    //std::cout<<"out of sleep recurively calling start again"<<std::endl;
    Start();

   }


}

void piperdaemon::Loop()
{
//Lets get it to espeak :^)
syslog(LOG_USER,"%s","Loading file");
 load_file();
    if(firstLoad == 0)
    {
        firstLoad = 1;
        //FORK
        //more like forkbomb.....
     syslog(LOG_USER,"%s","Creating fork");
        pid = fork();

        if(pid == 0)
        {
        //Child
        syslog(LOG_USER,"%s","Child of daemon is about to execute");
            cmdExecute();
        //kill self after
            exit(EXIT_SUCCESS);
        }
        else if(pid >0)
        {
            //adult
            //std::cout<<"adult is sleeping"<<std::endl;
            syslog(LOG_USER,"%s","Shhhhh! parent daemon is sleeping");

            //1min
            //sleep(60);
            int status;
//            waitpid(pid,&status, 0);
        }
        else
        {
           // std::cout<<"Forking failed :^( "<<std::endl;

        }


 }
/* std::string cmd;
 std::cin >>cmd;
 if(cmd == "y")
 {
  Loop();
 }
*/

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
//std::cout<<path<<std::endl;
 std::ifstream dFile(path);
 if(dFile.is_open())
  {
  Datafile_Loc = path;
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
   //std::cout<<"it doesn't exist :^)"<<std::endl;
   //std::cout<<"datapath should be: "<<path<<std::endl;
   return 0;
  }
  dFile.close();
  return 1;
}


bool piperdaemon::find_Profile()
{

//VERY HACKY
//reads to be rewrote;
syslog(LOG_USER,"%s","In find Profile()");
 std::string mozpath;
std::string path;
mozpath = getenv("HOME");
//std::cout<<"Path is "<<path<<std::endl;
path = mozpath + "/.mozilla/firefox/why.kek";
 std::ifstream File(path);
 if(File.is_open())
  {
 syslog(LOG_USER,"%s","Profile why.kek opened");
    //std::cout<<"WOW it works ._."<<std::endl;
    char c;
    std::string buf = "";
    while(File.get(c))
    {
    syslog(LOG_USER,"%s","Actually reading from file in profile");
     buf = buf + c;

    }
    //std::cout<<"buf is: "<<std::endl;
    //std::cout<<buf<<std::endl;
    token(buf);
    Profile_Loc = mozpath + "/.mozilla/firefox/" + tokens[2];
    //std::cout<<"PROFILE_LOC: "<<Profile_Loc<<std::endl;
    return true;
  }
  else
  {
  // std::cout<<"it doesn't work :^)"<<std::endl;
  syslog(LOG_USER,"%s","Didn't find why.kek, returning 1");
  }
  File.close();
  return 1;

}

std::string piperdaemon::token(std::string str)
{
syslog(LOG_USER,"%s","In Token()");
//std::cout<<"in function Token"<<std::endl;
size_t len=0;
size_t newstartpos=0;
bool ignore = false;
   len = str.length();
   //std::cout<<"before loop"<<std::endl;
   //std::cout<<"len is: "<<len<<std::endl;
   syslog(LOG_USER,"%s","Before while loop");
   for(size_t i=0;i<len;i++)
   {
   //std::cout<<"first for loop"<<std::endl;
   //grab one letter at a time;
   std::string curr_let = str.substr(i,1);
    //std::cout<<"curr_let: "<<curr_let<<std::endl;

    if(curr_let == "#" || ignore == true)
    {

        if(curr_let == "#" && ignore == true)
        {
    //    std::cout<<"newstartpos is "<<newstartpos<<" i is: "<<i<<std::endl;
        newstartpos = i + 1;
        ignore = false;
        }
        else if(ignore == false)
        {
            ignore = true;
        }



    }

   }
 //std::cout<<"Newstartpos is "<<newstartpos<<std::endl;
 //std::cout<<"outside first for loop"<<std::endl;
   int counta = 0;
   std::string buff ="";
   //std::cout<<"LEN is: "<<len<<std::endl;
   for(size_t k = newstartpos; k<len;k++)
   {
     std::string stringtemp = str.substr(k,1);
     if(stringtemp == " ")
     {

     //std::cout<<"In k loop"<<std::endl;
        if(counta < 255)
        {
       // std::cout<<"counta is "<<counta<<std::endl;
            tokens[counta] = buff;
            counta = counta + 1;
            buff = "";
        }
     }
     else
     {
      buff = buff + stringtemp;
      //std::cout<<"Buff is? "<<buff<<std::endl;
      size_t tempp = len;
      tempp = len - 2;
      //std::cout<<"tempp" <<tempp<<std::endl;
      //std::cout<<"k"<<k<<std::endl;
        if(k == tempp )
        {
       // std::cout<<"in k if"<<std::endl;

         tokens[counta] = buff;
         counta = counta + 1;
        }
     }

   }

   for(int l=0;l<counta;l++)
   {
    //std::cout<<"Token["<<l<<"] :"<<tokens[l]<<std::endl;

   }

 return "e";
}


bool piperdaemon::load_file()
{

std::ifstream DFile(Datafile_Loc);
 //std::cout<<"Datafile_Loc:"<<Datafile_Loc<<std::endl;
syslog(LOG_USER,"%s","Opening data.txt");
 if(DFile.is_open())
  {
  //  std::cout<<"WOW it works ._."<<std::endl;
    char c;
    std::string buf = "";
    while(DFile.get(c))
    {
     buf = buf + c;

    }
   // std::cout<<"Buf is? "<<buf<<std::endl;
    //std::cout<<"buf is: "<<std::endl;
    //std::cout<<buf<<std::endl;
    commandtoke(buf);
//    Profile_Loc = mozpath + "/.mozilla/firefox/" + tokens[2];
    //std::cout<<"PROFILE_LOC: "<<Profile_Loc<<std::endl;
    //std::cout<<"Load file!!!"<<std::endl;
    return true;
  }
  else
  {
   //std::cout<<"it doesn't work :^)"<<std::endl;
   syslog(LOG_USER,"%s","Can't open data.txt");
  }
  DFile.close();
  return 1;

}


std::string piperdaemon::commandtoke(std::string str)
{
 size_t len = str.length();
 std::string buff = "";
 int counta =0;
  for(size_t i=0;i<len;i++)
  {
    std::string temp = str.substr(i,1);
    if(temp == " ")
    {
            tokens[counta] = buff;
            counta = counta + 1;
            buff = "";

    }
    else
    {
     buff = buff + temp;
     //std::cout<<"Buff is: "<<buff<<std::endl;
     size_t k = len - 1;
     if(i == k)
     {
      tokens[counta] = buff;
            counta = counta + 1;
            buff = "";

     }
    }

  }

  for(int l=0;l<counta;l++)
  {
  //std::cout<<"Toke["<<l<<"]: "<<tokens[l]<<std::endl;

  }
  //should be a void tbh fam
  return "pace";
}

void piperdaemon::cmdExecute()
{
 std::string Command;
 syslog(LOG_USER,"%s","starting to execute");
 if(tokens[0] == "mpv")
 {
    Command = "/usr/bin/" + tokens[0];

    syslog(LOG_USER,"%s",Command.c_str());
    syslog(LOG_USER,"%s",tokens[1].c_str());
    //+ " " + tokens[1];
    //std::system(Command.c_str());
    putenv("DISPLAY=:0");
   execl(Command.c_str(),tokens[1].c_str());
  // execle(Command.c_str(),tokens[0].c_str(),tokens[1].c_str(),NULL,getenv("DISPLAY"));
  // execl(Command.c_str(),Command.c_str(),tokens[1].c_str(),NULL);
 }
}
