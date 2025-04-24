add_rules("mode.debug", "mode.release")

target("WTSUtils")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp", "./zstdlib/*.c", "./yamlcpp/*.cpp", "./lmdb/*.c", "./StackTracer/*.cpp")
    add_headerfiles("*.h", "./zstdlib/*.h", "./yamlcpp/*.h", "./lmdb/*.h", "./StackTracer/*.h")
    add_includedirs("./yamlcpp")
