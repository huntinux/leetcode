cc_library (
    name = "solution",
    srcs = [
        "solution.cc"
    ],
    hdrs = [
        "solution.h"
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