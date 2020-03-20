def _impl(repository_ctx):
    repository_ctx.download_and_extract(
        "https://sdk.lunarg.com/sdk/download/1.1.126.0/mac/vulkansdk-macos-1.1.126.0.tar.gz?u=",
        output = "lunarg_vulkan_sdk",
        sha256 = "1ae62cc33227cbb32eff50951011405b0afa7a220765df06a975d6334cc45db4",
    )

    repository_ctx.file("WORKSPACE", content = "")
    repository_ctx.file("BUILD", content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name="main",
    hdrs=glob(["lunarg_vulkan_sdk/vulkansdk-macos-1.1.126.0/macOS/include/**"]),
    srcs=glob(["lunarg_vulkan_sdk/vulkansdk-macos-1.1.126.0/macOS/lib/libvulkan.dylib"]),
    strip_include_prefix="lunarg_vulkan_sdk/vulkansdk-macos-1.1.126.0/macOS/include",
    visibility = ["//visibility:public"],
)
    """)

vulkan_sdk = repository_rule(implementation = _impl)
