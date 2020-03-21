load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    copts = [
        "-std=c++2a",
    ],
    visibility = ["//visibility:public"],
    deps = ["//onyx:main"],
)
