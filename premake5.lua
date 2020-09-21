project "LWVL"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "On"

  -- must define a variable named output_dir in the workspace prmake5.lua
  targetdir("bin/" .. output_dir .. "/${prj.name}")
  objdir("bin/intermediates/" .. output_dir .. "/${prj.name}")

  pchheader "lwvlpch.h"
  pchsource "src/lwvlpch.cpp"

  files {
    "src/**.h",
    "src/**.cpp"
  }

  includedirs {
    "src",
    "vendor/GLEW/include"
  }

  filter "configurations:Debug"
    defines {
      "_DEBUG"
    }
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    runtime "Release"
    optimize "On"
  
  filter "configurations:Distribution"
    runtime "Release"
    optimize "On"
