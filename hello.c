// copyright nobody
// LINT_C_FILE
#include <assert.h>
#include <stdlib.h>
#include <node_api.h>

void finalize_cb(
    napi_env env,
    void *finalize_data,
    void *finalize_hint
) {
// this function will finalize <finalize_data>
    printf("\n\n[ free finalize_data = '%s' ]\n\n", (char *) finalize_data);
    free(finalize_data);
}

static napi_value foo(
    napi_env env,
    napi_callback_info info
) {
    napi_status status;
    napi_value result = NULL;
    const char *data = "world";
    status = napi_create_external_buffer(env,   // napi_env env
        5,                      // size_t length
        (void *) data,          // void* data
        finalize_cb,            // napi_finalize finalize_cb
        NULL,                   // void* finalize_hint
        &result);               // napi_value* result
    assert(status == napi_ok);
    printf("\n\n[ external data = '%s' ]\n\n", data);
    return result;
}


static napi_value napi_module_init(
    napi_env env,
    napi_value exports
) {
    napi_status status;
    napi_property_descriptor desc =
        { "hello", 0, foo, 0, 0, 0, napi_default, 0 };
    status = napi_define_properties(env, exports, 1, &desc);
    assert(status == napi_ok);
    return exports;
}

NAPI_MODULE(hello, napi_module_init)
