
exports.findThreadID = function (TabID)
{
  var Len = TabID.length;
  var ltemp; 
 console.log("Before for LOOP:findThreadID");
 console.log("Len" + Len);
 for(var i=0;i<Len;i++)
{
   console.log("IN LOOP");
   ltemp = TabID.substr(i,3);
   if(ltemp == "res")
   {
   console.log("IN IF Statement");
     i = i + 4;
    //should be numbers
     console.log(TabID.substr(i,3));
    for(var k=i;k<Len;k++)
    {
      var findDot = TabID.substr(k,1);
      if("." == findDot)
      {
	var Diff = k - i;

      }
    }
     console.log("THREADID? "+ TabID.substr(i,Diff));
     return TabID.substr(i,Diff));
   }

}

}

exports.WhatIsTab = function(TabID)
{
console.log("INFUCKING FUNCTION");
//0-not found, 1-8ch, 2-4chan 3-youtube
 var Len = TabID.length;
 var temp;
 var check;
 console.log("Len"+Len);
 for(var i =0;i<Len;i++)
 {
 console.log(i);
  temp = TabID.substr(i,3);
  console.log(temp);
  if(temp == "com")
  {//assume youtube
   for(var k =0;k<Len;k++)
   {
  	 var check = TabID.substr(k,7);
  	 console.log(check);
  	 console.log("in .com");
  	 if(check == "youtube")
   	{
   	 console.log("in Youtube");
   	 console.log("Returning 3");
   	 return 3;
  	 }
   } 
 }
  else if(temp == "org")
  {//assume 4ch
    for(var k=0;k<Len;k++)
    {	
	 var check = TabID.substr(k,5);
   	 console.log("in org");
    	 console.log(check);
   	 if(check == "4chan")
   	 {
		console.log("Returning 2");
		return 2;
   	 }
    } 
  } 
  else if(temp == "net")
  {//assume 8ch
    for(var k=0; k<Len;k++)
    {

   	 check = TabID.substr(k,3);
   	 console.log(check);
   	 console.log("in net");
   	 if(check == "8ch")
	 {
		console.log("Returning 1");
		return 1;
   	 }
    }
  }

 }
 console.log("returning nil");
 return 0;

}
