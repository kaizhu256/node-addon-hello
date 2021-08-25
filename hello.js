/*jslint beta, node*/
var addon = require("./hello.node")("hello");
console.log(addon.hello()); // "world"
