def _impl(repository_ctx):
    repository_ctx.download_and_extract(
        "https://sdk.lunarg.com/sdk/download/1.2.131.2/mac/vulkansdk-macos-1.2.131.2.tar.gz?u=",
        output = "lunarg_vulkan_sdk",
        sha256 = "e28363ae0bdb3d881ebf93cdd7a721d052f6a2e5686d0fb3447e6edd585bb53f",
    )

    repository_ctx.file("WORKSPACE", content = "")
    repository_ctx.file("BUILD", content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name="main",
    hdrs=glob(["lunarg_vulkan_sdk/vulkansdk-macos-1.2.131.2/macOS/include/**"]),
    srcs=glob(["lunarg_vulkan_sdk/vulkansdk-macos-1.2.131.2/macOS/lib/libvulkan.dylib"]),
    strip_include_prefix="lunarg_vulkan_sdk/vulkansdk-macos-1.2.131.2/macOS/include",
    visibility = ["//visibility:public"],
)
    """)

vulkan_sdk = repository_rule(implementation = _impl)
