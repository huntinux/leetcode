cc_library (
    name = "merge_sort",
    srcs = [
        "merge_sort.cc"
    ],
    hdrs = [
        "merge_sort.h"
    ],
    visibility = ["//visibility:public"]
)

cc_test (
    name = "test",
    srcs = [
        "merge_sort_test.cc",
    ],
    deps = [
        ":merge_sort",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)
