#include "../include/piperdaemon.h"

piperdaemon::piperdaemon()
{
    //ctor
    firstLoad = 0;
    for(int i=0;i<255;i++)
    {
     Lastcommand[i] = "333333";
     tokens[i] = "333333";
    }
}

bool piperdaemon::Create_Settingsfolder()
{
 #if _WIN32
  std::string home = getenv("APPDATA");
  std::cout<<"HOME: "<<home<<std::endl;
  std::string setfol = home + "\\.piper-d";
 #else
std::string home = getenv("HOME");
std::cout<<"HOME: "<<home<<std::endl;
std::string setfol = home + "/.piper-d";
#endif
setting = setfol;
 mkdir(setfol.c_str(),S_IRUSR | S_IWUSR | S_IXUSR);
 return true;

}

bool piperdaemon::Find_Lastcommand()
{
 #if _WIN32
 std::string loconf = setting + "\\lastcmd.conf";
 #else
 std::string loconf = setting + "/lastcmd.conf";
 #endif

 std::ifstream file(loconf);
 if(file.is_open())
 {
  //file open;
  char c;
  std::string buf="";
  while(file.get(c))
  {
   buf = buf + c;

  }
   putoldtoke(buf);

    return true;
 }
 else
 {


  return false;
 }

}

bool piperdaemon::cmp_tokes()
{
 if(tokens[1] == Lastcommand[1])
 {
 std::cout<<"tokens are the same;"<<std::endl;
   return false;

 }
 std::cout<<"Tokens[1]: "<<tokens[2]<<" "<<"Lastcommand[1]"<<Lastcommand[1]<<std::endl;
  return true;
}

bool piperdaemon::Save_Lastcommand()
{
#if _WIN32
 std::string loconf = setting + "\\lastcmd.conf";
#else
 std::string loconf = setting + "/lastcmd.conf";
#endif
  std::ofstream file(loconf);
  file << tokens[0]<<" "<<tokens[1];
  file.close();
 return true;
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
//create Settings folder
Create_Settingsfolder();
long ProgID = getpid();
save_pid(ProgID);
std::cout<<"progID: "<<ProgID<<std::endl;
//syslog(LOG_USER,"%s","In Start()");
std::cout<<"In Start()"<<std::endl;
//syslog(LOG_USER,"%s","meems");
std::cout<<"Meemes"<<std::endl;
 find_Profile();
 Find_Lastcommand();

 //std::cout<<"in file exists"<<std::endl;
  bool file_exist = file_exists();
   load_file();
  std::cout<<"File_Exists"<<std::endl;
   bool same_cmd = cmp_tokes();
   std::cout<<"same_cmd is? "<<same_cmd<<std::endl;
   if(file_exist == 1 && same_cmd == 1)
   {
     //call real loop
     //syslog(LOG_USER,"%s","The File data.txt exists");
     std::cout<<"The File data.txt exists"<<std::endl;
     Loop();

   }
   else if(file_exist == 0 || same_cmd == 0)
   {
   //syslog(LOG_USER,"%s","Gunna sleep for 5 seconds and check for data.txt again");
   std::cout<<"Gunna Sleep for 5 seconds and check for data.txt again"<<std::endl;
   //std::cout<<"going sleep nightnight"<<std::endl;
    sleep(5);
    //syslog(LOG_USER,"%s","Arose from my slumber, I'm awake and ready to start");
    std::cout<<"Arose from my slumber, I'm awake and ready to start"<<std::endl;
    //std::cout<<"out of sleep recurively calling start again"<<std::endl;
    Start();

   }


}

void piperdaemon::Loop()
{
//Lets get it to espeak :^)
//syslog(LOG_USER,"%s","Loading file");
 std::cout<<"Loading file"<<std::endl;
// load_file();
    if(firstLoad == 0)
    {
        firstLoad = 1;
        //FORK
        //more like forkbomb.....
     //syslog(LOG_USER,"%s","Creating fork");
     std::cout<<"Creating Fork"<<std::endl;
     signal(SIGINT,sigint_handler);
        pid = fork();

        if(pid == 0)
        {
        //Child
        //syslog(LOG_USER,"%s","Child of daemon is about to execute");
            cmdExecute();
        //kill self after
            //exit(EXIT_SUCCESS);
        }
        else if(pid >0)
        {
            //adult
            //std::cout<<"adult is sleeping"<<std::endl;
  //          syslog(LOG_USER,"%s","Shhhhh! parent daemon is sleeping");
            std::cout<<"Shhhhh! parent daemon is sleeping"<<std::endl;
            //1min
            //sleep(60);
            int status;
            waitpid(pid,&status, 0);
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
#if _WIN32
mozpath = getenv("APPDATA");
//std::cout<<"Path is "<<path<<std::endl;
path = Profile_Loc + "\\data.txt";
//std::cout<<path<<std::endl;
#else
mozpath = getenv("HOME");
path = Profile_Loc + "/data.txt";
#endif
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
//syslog(LOG_USER,"%s","In find Profile()");
std::cout<<"In find profiles()"<<std::endl;
 std::string mozpath;
std::string path;
#if _WIN32
mozpath = getenv("APPDATA");
//std::cout<<"Path is "<<path<<std::endl;
path = mozpath + "\\.mozilla\\firefox\\why.kek";
#else
 mozpath = getenv("HOME");
 path=mozpath + "/.mozilla/firefox/why.kek";

#endif // _WIN32
 std::ifstream File(path);
 if(File.is_open())
  {
 //syslog(LOG_USER,"%s","Profile why.kek opened");
 std::cout<<"Profile why.kek opened"<<std::endl;
    //std::cout<<"WOW it works ._."<<std::endl;
    char c;
    std::string buf = "";
    while(File.get(c))
    {
    //syslog(LOG_USER,"%s","Actually reading from file in profile");
    std::cout<<"Actually Reading from file in profile"<<std::endl;
     buf = buf + c;

    }
    //std::cout<<"buf is: "<<std::endl;
    //std::cout<<buf<<std::endl;
    token(buf);
    #ifdef _WIN32
    Profile_Loc = mozpath + "\\Mozilla\\Firefox\\Profiles\\" + tokens[2];

    #else
    Profile_Loc = mozpath +"/.mozilla/firefox/" + tokens[2];
    #endif
    //std::cout<<"PROFILE_LOC: "<<Profile_Loc<<std::endl;
    return true;
  }
  else
  {
  // std::cout<<"it doesn't work :^)"<<std::endl;
  //syslog(LOG_USER,"%s","Didn't find why.kek, returning 1");
  std::cout<<"Didn't find why.kek, returning 1"<<std::endl;
  }
  File.close();
  return 1;

}

std::string piperdaemon::token(std::string str)
{
//syslog(LOG_USER,"%s","In Token()");
std::cout<<"In Token()"<<std::endl;
//std::cout<<"in function Token"<<std::endl;
size_t len=0;
size_t newstartpos=0;
bool ignore = false;
   len = str.length();
   //std::cout<<"before loop"<<std::endl;
   //std::cout<<"len is: "<<len<<std::endl;
   //syslog(LOG_USER,"%s","Before while loop");
   std::cout<<"Before while loop"<<std::endl;
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
//syslog(LOG_USER,"%s","Opening data.txt");
std::cout<<"Opening data.txt"<<std::endl;
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
   //syslog(LOG_USER,"%s","Can't open data.txt");
   std::cout<<"Can't open data.txt"<<std::endl;
  }
  DFile.close();
  return 1;

}


//Gotta stream line this code ._.
std::string piperdaemon::putoldtoke(std::string str)
{
  size_t len = str.length();
 std::string buff = "";
 int counta =0;
  for(size_t i=0;i<len;i++)
  {
    std::string temp = str.substr(i,1);
    if(temp == " ")
    {
            Lastcommand[counta] = buff;
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
      Lastcommand[counta] = buff;
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
// syslog(LOG_USER,"%s","starting to execute");
 std::cout<<"starting to execute"<<std::endl;
 if(tokens[0] == "mpv")
 {

  Save_Lastcommand();
  //put a ifdef here however need to find the environment varible for progfiles
    Command = "/usr/bin/" + tokens[0];
   // Command = tokens[0] +" "+ tokens[1];
    //syslog(LOG_USER,"%s",Command.c_str());
    //syslog(LOG_USER,"%s",tokens[1].c_str());
    std::cout<<Command<<std::endl;
    std::cout<<tokens[1]<<std::endl;
    //+ " " + tokens[1];
   // std::system(Command.c_str());
  //  putenv("DISPLAY=:0");
//  execl(Command.c_str(),tokens[1].c_str());
  // execle(Command.c_str(),tokens[0].c_str(),tokens[1].c_str(),NULL,getenv("DISPLAY"));
   execl(Command.c_str(),Command.c_str(),tokens[1].c_str(),NULL);
 }
}

void piperdaemon::sigint_handler(int sig)
{
 //syslog(LOG_USER,"%s","CHILDpid: "+getpid());
 //syslog(LOG_USER,"%s","ADULTPID: "+getppid());

}

void piperdaemon::save_pid(long IDpid)
{
#ifdef _WIN32
 std::string save = setting + "\\pid";
 #else
 std::string save = setting + "/pid";
 #endif
 std::ofstream file(save);
file<<IDpid;
file.close();

}
