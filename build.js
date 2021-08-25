/*jslint beta, name, node*/
(function () {
    let fileNodeGypJs = require("path").resolve(
        require("path").dirname(process.execPath),
        "node_modules/npm/node_modules/node-gyp/bin/node-gyp.js"
    ).replace("/bin/node_modules/", "/lib/node_modules/");
    [
        "clean",
        "configure",
        "build"
    ].forEach(function (action) {
        action = [
            fileNodeGypJs,
            action
        ];
        console.error(
            "node " + action.map(function (elem) {
                return "'" + elem + "'";
            }).join(" ")
        );
        if (require("child_process").spawnSync("node", action, {
            stdio: [
                "ignore", 1, 2
            ]
        }).status !== 0) {
            process.exit(1);
        }
    });
}());
