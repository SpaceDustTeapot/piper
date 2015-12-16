//File is used to write command(Video player eg mpv/vlc)  and the argument (Video URL)
//to a text file which will be excecuted by the backend daemon.
exports.writeToFile = function(inputstream,Files,netutil)
{
  console.log("trying to write to file?");
   netutil.asyncCopy(inputstream,Files);
  console.log("Should of wrote to file");


}
