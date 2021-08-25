/*jslint beta, node*/
var addon = require("./hello.node");
console.log(addon.hello().toString()); // "world"
process.on("exit", function (exitCode) {
    console.error(`node ${__filename} exiting with exitCode=${exitCode}`);
});
