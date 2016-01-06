 /*
    This file is part of Chear.

    Chear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Chear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Chear.  If not, see <http://www.gnu.org/licenses/>.
*/

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
