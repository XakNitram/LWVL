project "LWVL"
    kind "StaticLib"

    targetdir("bin/%{cfg.buildcfg}")
    objdir("bin/intermediates/%{cfg.buildcfg}")

    files {
        "**.h",
        "**.cpp"
    }

    links {
        "opengl32"
    }