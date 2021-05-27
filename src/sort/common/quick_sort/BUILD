cc_library (
    name = "quick_sort",
    srcs = [
        "quick_sort.cc"
    ],
    hdrs = [
        "quick_sort.h"
    ],
    visibility = ["//visibility:public"]
)

cc_test (
    name = "test",
    srcs = [
        "quick_sort_test.cc",
    ],
    deps = [
        ":quick_sort",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)
