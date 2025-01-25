workspace "example"
    architecture "x86_64"
    configurations { "Debug", "Release" }

project "example"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"
    
    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "deps/module-sdk/include"
    }

    filter "system:windows"
        defines { "PLATFORM_WINDOWS" }
        links { "deps/module-sdk/lib/lua.lib" }

    filter "system:linux"
        defines { "PLATFORM_LINUX" }
        links { "deps/module-sdk/lib/liblua.a" }

    filter {}