{
    "targets": [
        {
            "sources": [
                "hello.c"
            ],
            "target_name": "hello"
        },
        {
            "copies": [
                {
                    "destination": ".",
                    "files": [
                        "<(PRODUCT_DIR)/hello.node"
                    ]
                }
            ],
            "dependencies": [
                "hello"
            ],
            "target_name": "target_install"
        }
    ]
}
