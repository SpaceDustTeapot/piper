// This file is part of Piper.

//    Piper is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    Piper is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with Piper.  If not, see <http://www.gnu.org/licenses/>.


//File is used to write command(Video player eg mpv/vlc)  and the argument (Video URL)
//to a text file which will be excecuted by the backend daemon.
exports.writeToFile = function(inputstream,Files,netutil)
{
  console.log("trying to write to file?");
   netutil.asyncCopy(inputstream,Files);
  console.log("Should of wrote to file");


}
