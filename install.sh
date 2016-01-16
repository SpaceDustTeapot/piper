#!/bin/sh

# This file is part of Piper.

#    Piper is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    Piper is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with Piper.  If not, see <http://www.gnu.org/licenses/>.

 
sudo cp chear/bin/Debug/chear /usr/local/bin
sudo cp piper-d/bin/Debug/piper-d /usr/local/bin

#Crontab shit needs to go below
crontab -e < Cronbk
