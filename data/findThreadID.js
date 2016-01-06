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



exports.findThreadID = function (TabID)
{
  var Len = TabID.length;
  var ltemp; 
// console.log("Before for LOOP:findThreadID");
// console.log("Len" + Len);
	 for(var i=0;i<Len;i++)
	{
 		 // console.log("IN LOOP");
  		 ltemp = TabID.substr(i,3);
   		if(ltemp == "res")
  		 {
		 //  console.log("IN IF Statement");
    		 i = i + 4;
    		//should be numbers
   		//  console.log(TabID.substr(i,3));
		   	 for(var k=i;k<Len;k++)
   			 {
     			 var findDot = TabID.substr(k,1);
     				 if("." == findDot)
     		 		{
					var Diff = k - i;

				 }
   			 }
    			 //console.log("THREADID? "+ TabID.substr(i,Diff));
  		   return TabID.substr(i,Diff);
  		 }

	}

}

exports.WhatIsTab = function(TabID)
{
//console.log("INFUCKING FUNCTION");
//0-not found, 1-8ch, 2-4chan 3-youtube
 var Len = TabID.length;
 var temp;
 var check;
 //console.log("Len"+Len);
 for(var i =0;i<Len;i++)
 {
 //console.log(i);
  temp = TabID.substr(i,3);
 // console.log(temp);
  if(temp == "com")
  {//assume youtube
   for(var k =0;k<Len;k++)
   {
  	 var check = TabID.substr(k,7);
  //	 console.log(check);
  //	 console.log("in .com");
  	 if(check == "youtube")
   	{
   //	 console.log("in Youtube");
   //	 console.log("Returning 3 if watch exists");
	 	for(var count=0;count<Len;count++)
		{
		 var chock = TabID.substr(count,5);
//		console.log("Chock is " + chock);
		 if(chock == "watch")
		 {
		   return 3;
		 }
		}
   	 //return 3;
  	 }
	 else if(check == "pornhub")
	{
 		  for(var kekle=0;kekle<Len;kekle++)
		{
	 	 var dubzcheckup = TabID.substr(kekle,7);
		  if(dubzcheckup == "viewkey")
		  {
		    return 3;
		  }
		}
	}
   } 
 }
  else if(temp == "org")
  {//assume 4ch
    for(var k=0;k<Len;k++)
    {	
	 var check = TabID.substr(k,5);
  // 	 console.log("in org");
  //  	 console.log(check);
   	 if(check == "4chan")
   	 {
//		console.log("Returning 2");
		return 2;
   	 }
    } 
  } 
  else if(temp == "net")
  {//assume 8ch
    for(var k=0; k<Len;k++)
    {

   	 check = TabID.substr(k,3);
  // 	 console.log(check);
   //	 console.log("in net");
   	 if(check == "8ch")
	 {
	   for(var l=0; l<Len; l++)
	    {
		var ch = TabID.substr(l,4);
		console.log("ch is:" + ch);
	    	if(ch == "webm")
		{
			console.log("Returning 1");
			return 1;
   	   	}
	    }
	 }
    }
  }
  else if(temp == ".be")
  {
	for(var k=0;k<Len;k++)
	{
		var chk = TabID.substr(k,9);
		if(chk == "youtu.be/")
		{         
			return 3;
		}
  	}
  }
  else if(temp == ".tv")
  {
	for(var k=0;k<Len;k++)
	{
  		 var chk = TabID.substr(k,9);
		if(chk == "twitch.tv")
		{
			return 3;
		}
 	}
  }

 }
// console.log("returning nil");
 return 0;

}
