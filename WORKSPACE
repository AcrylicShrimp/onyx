load("//vulkan-sdk:rule.bzl", "vulkan_sdk")

vulkan_sdk(name = "com_lunarg_vulkan_sdk")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
    name = "com_chaoticbob_spirv_reflect",
    branch = "master",
    build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "main",
    srcs = ["spirv_reflect.c"],
    hdrs = ["include/spirv/unified1/spirv.h", "spirv_reflect.h"],
    deps = ["@com_lunarg_vulkan_sdk//:main"],
    visibility = ["//visibility:public"],
)
    """,
    remote = "https://github.com/chaoticbob/SPIRV-Reflect.git",
)
