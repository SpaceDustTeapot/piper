var{Cu,Cc,Ci} = require("chrome");

Cu.import("resource://gre/modules/FileUtils.jsm");
Cu.import("resource://gre/modules/NetUtil.jsm");
//dataconverter
var converter = Cc["@mozilla.org/intl/scriptableunicodeconverter"].createInstance(Ci.nsIScriptableUnicodeConverter);
converter.charset = "UTF-8";
var file = FileUtils.getFile("ProfD",["data.txt"]);
//var ostream  = FileUtils.openSafeFileOutputStream(file);

//writer
var writer = require("./data/writeFile.js");

var findthr = require("./data/findThreadID.js");
var {setInterval,clearInterval} = require("sdk/timers");
//var self = require('sdk/self');

// a dummy function, to show how tests work.
// to see how to test this function, look at test/test-index.js
//function dummy(text, callback) {
 // callback(text);
//}

//exports.dummy = dummy;

//Declare buttons
var buttons = require('sdk/ui/button/action');
//declares tabs
var tabs = require("sdk/tabs");
//declare PageMod Allows us to much arround with the pagecontent
var pageMod = require("sdk/page-mod");
var ebin = require("sdk/context-menu");
var self = require("sdk/self");
//declare worker
var worker = require("sdk/content/worker");

//Create pagemod
pageMod.PageMod({
//Line under neather throws it off
//include: "youtube.com","pornhub.com","media.8ch.net",
//include: "https://media.8ch.net/",
include: "*.net",
//adds button to page so you can download stuff
//contentScriptFile: "./addButton.js"


});

ebin.Item({
	label:"Pipe to mediaplayer",
	//context: ebin.URLContext("*.mozilla.org")
	context: ebin.SelectorContext("a[href]"),
	contentScript: 'self.on("click",function(node){' +
			' var linkle = document.links;' +
			' console.log("namespacehtmllink" + node.href);' +
			' console.log(linkle[0].href);' +
			' var ebini = node.textContent;	' +
			' console.log(ebini);' +
		//	' for(var i =0;i<=linkle.length;i++) ' +
		//	' { '	+
		//	' console.log(i + ":" + linkle[i].href); ' +
		//	' } ' + 
			' self.postMessage(node.href);' +
			' return true;'+
			' });',
//	image: "./icon-64.png",
	onMessage: function(linksauce)
	{
		console.log("Linksauce is:" + linksauce);
		 var returned_val = findthr.WhatIsTab(linksauce);
 			if(returned_val == 0)
  			{
   			//console.log("Either error or not one of the acceptable sites");
			//alert("Error or Not an acceptable site");
  			}
 			else if(returned_val == 1)
  			{
				//do something
			 	var ostream  = FileUtils.openSafeFileOutputStream(file);  
 				console.log("valid youtube URL");
  			 	//TODO: CHANGE mpv if settings isn't mpv
  				var cmd_string = "mpv " + linksauce;
  				//Push cmd_string to a file
  				console.log("What is CMD_String? " + cmd_string);
 	 			var cdstring = converter.convertToInputStream(cmd_string);
				 // cdstring.available();
  				//console.log("And CD string? " + cdstring);
 			 	writer.writeToFile(cdstring,ostream,NetUtil);  
 				// cdstring.close();
			
  			}
			 else if(returned_val == 2)
 			{

 			}
	 		else if(returned_val == 3)
 			{
 			 var ostream  = FileUtils.openSafeFileOutputStream(file);  
 			console.log("valid youtube URL");
  			 //TODO: CHANGE mpv if settings isn't mpv
  			var cmd_string = "mpv " + linksauce;
  			//Push cmd_string to a file
  			console.log("What is CMD_String? " + cmd_string);
 	 		var cdstring = converter.convertToInputStream(cmd_string);
			 // cdstring.available();
  			//console.log("And CD string? " + cdstring);
 			 writer.writeToFile(cdstring,ostream,NetUtil);  
 			// cdstring.close();
 
		 	}
	}
});


//var Payload = tabs;

//worker.port.emit("payload",Payload);

//declares button as buttons.action with the following atributes
var button = buttons.ActionButton({
id: "Mozilla-link",
label: "Pipe to mediaplayer",
icon: {
 "16" : "./icon-16.png",
 "32" : "./icon-32.png",
 "64" : "./icon-64.png"
},
//Onclick do this function
 onClick: handleClick

}); 

function handleClick(state)
{
 //tabs.open("https://www.mozilla.org/");
// findthr.WhatIsTab(tabs[0].url); 
 //findthr.WhatIsTab(tabs.activeTab.url);
//console.log(tabs[0].url);
 //findthr.findThreadID(tabs.activeTab.url);
 var returned_val = findthr.WhatIsTab(tabs.activeTab.url);
 if(returned_val == 0)
  {
   //console.log("Either error or not one of the acceptable sites");
  }
 else if(returned_val == 1)
  {
	//do something
  }
 else if(returned_val == 2)
 {

 }
 else if(returned_val == 3)
 {
 var ostream  = FileUtils.openSafeFileOutputStream(file);  
 console.log("valid youtube URL");
  //TODO: CHANGE mpv if settings isn't mpv
  var cmd_string = "mpv " + tabs.activeTab.url;
  //Push cmd_string to a file
  console.log("What is CMD_String? " + cmd_string);
  var cdstring = converter.convertToInputStream(cmd_string);
 // cdstring.available();
  //console.log("And CD string? " + cdstring);
  writer.writeToFile(cdstring,ostream,NetUtil);  
 // cdstring.close();
 
 }

}


function get_tabnames()
{
  //alert(tabs[0].url);

}


var id = setInterval(function() {
//does something every five seconds
//TEMPARLY disabled
//findthr.WhatIsTab(tabs.activeTab.url);

},10000);
//5 secons = 5000
