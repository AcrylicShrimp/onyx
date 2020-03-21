load("@rules_cc//cc:defs.bzl", "cc_library", "objc_library")

objc_library(
    name = "window_osx",
    srcs = ["src/display/window__OSX__backend.m"],
    hdrs = ["includes/display/window__OSX__backend.h"],
)

cc_library(
    name = "main",
    srcs = [
        "src/common/manager.cpp",
        "src/common/version.cpp",
        "src/core/context.cpp",
        "src/core/contextManager.cpp",
        "src/core/deviceInfo.cpp",
        "src/core/deviceManager.cpp",
        "src/core/perContextManager.cpp",
        "src/core/renderingManager.cpp",
        "src/core/surfaceManager.cpp",
        "src/core/swapchainManager.cpp",
        "src/core/synchronizationManager.cpp",
        "src/display/displayManager.cpp",
        "src/display/window.cpp",
        "src/display/window__OSX.cpp",
        "src/display/window__WINDOWS.cpp",
        "src/onyx.cpp",
    ],
    hdrs = [
        "includes/common/manager.h",
        "includes/common/platform.h",
        "includes/common/version.h",
        "includes/core/context.h",
        "includes/core/contextManager.h",
        "includes/core/deviceInfo.h",
        "includes/core/deviceManager.h",
        "includes/core/perContextManager.h",
        "includes/core/renderingManager.h",
        "includes/core/surfaceManager.h",
        "includes/core/swapchainManager.h",
        "includes/core/synchronizationManager.h",
        "includes/core/vulkan.h",
        "includes/display/displayManager.h",
        "includes/display/window.h",
        "includes/display/window__OSX.h",
        "includes/display/window__WINDOWS.h",
        "includes/onyx.h",
    ],
    copts = [
        "-std=c++2a",
    ],
    linkopts = [
        "-framework Foundation",
        "-framework Cocoa",
        "-framework QuartzCore",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":window_osx",
        "@com_chaoticbob_spirv_reflect//:main",
        "@com_lunarg_vulkan_sdk//:main",
    ],
)
