var findthr = require("./data/findThreadID.js");
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

//var Payload = tabs;

//worker.port.emit("payload",Payload);

//declares button as buttons.action with the following atributes
var button = buttons.ActionButton({
id: "Mozilla-link",
label: "Visit Mozilla",
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
 findthr.WhatIsTab(tabs[0].url); 
//console.log(tabs[0].url);
 
}


function get_tabnames()
{
  //alert(tabs[0].url);

}
