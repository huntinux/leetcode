cc_library (
    name = "heap",
    srcs = [
        "heap_sort.cc"
    ],
    hdrs = [
        "heap_sort.h"
    ],
    visibility = ["//visibility:public"]
)

cc_test (
    name = "test",
    srcs = [
        "heap_sort_test.cc",
    ],
    deps = [
        ":heap",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)
