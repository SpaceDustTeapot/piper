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


#ifndef CHEAR_H
#define CHEAR_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

class Chear
{
    public:
        Chear();
        virtual ~Chear();
        void checkforPid();
        std::string GrabfilePID(std::string str);
    protected:
    private:
};

#endif // CHEAR_H
