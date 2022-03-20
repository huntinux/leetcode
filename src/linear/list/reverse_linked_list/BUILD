cc_library (
    name = "solution",
    srcs = [
        "solution_practise.cc"
    ],
    hdrs = [
        "solution.h"
    ],
    deps = [
        "//src/linear/list/common:list"
    ]
)

cc_test (
    name = "test",
    srcs = [
        "solution_test.cc",
    ],
    deps = [
        ":solution",
        "@gtest//:gtest",
        "@gtest//:gtest_main"
    ],
)
