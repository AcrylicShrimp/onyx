load("//vulkan-sdk:rule.bzl", "vulkan_sdk")

vulkan_sdk(name = "com_lunarg_vulkan_sdk")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
    name = "org_khronos_spirv_cross",
    build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "main",
    hdrs = ["spirv.h"],
    include_prefix = "vulkan",
    visibility = ["//visibility:public"],
)
    """,
    remote = "https://github.com/KhronosGroup/SPIRV-Cross.git",
    tag = "2019-11-01",
)

new_git_repository(
    name = "com_chaoticbob_spirv_reflect",
    build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "main",
    srcs = ["spirv_reflect.c"],
    hdrs = ["spirv_reflect.h"],
    deps = [
        "@com_lunarg_vulkan_sdk//:main",
        "@org_khronos_spirv_cross//:main",
    ],
    visibility = ["//visibility:public"],
)
    """,
    remote = "https://github.com/chaoticbob/SPIRV-Reflect.git",
    tag = "v1.0.0",
)
