
exports.findThreadID = function (TabID)
{
  var Len = TabID.len;
 
 for(var i =0;i<Len;i++)
{
   TabID.substring(i,3);

}

}

exports.WhatIsTab = function(TabID)
{
console.log("INFUCKING FUNCTION");
//0-not found, 1-8ch, 2-4chan 3-youtube
 var Len = TabID.length;
 console.log("Len"+Len);
 for(var i =0;i<Len;i++)
 {
 console.log(i);
  var temp = TabID.substring(i,3);
  console.log(temp);
  if(temp == "com")
  {//assume youtube
   var check = TabID.substring(12,6);
  // console.log(check);
   if(check == "youtube")
   {
    console.log("Returning 3");
    return 3;
   }
  }
  else if(temp == "org")
  {//assume 4ch
    var check = TabID.substring(19,4);
  //  console.log(check);
    if(check == "4chan")
    {
	console.log("Returning 2");
	return 2;
    }
  }
  else if(temp == "net")
  {//assume 8ch
    var check = TabID.substring(9,3);
    console.log(check);
    if(check == "8ch")
    {
	console.log("Returning 1");
	return 1;
    }
  }

 }
 console.log("returning nil");
 return 0;

}
