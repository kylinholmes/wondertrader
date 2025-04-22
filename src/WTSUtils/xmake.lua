add_rules("mode.debug", "mode.release")

target("WTSUtils")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp", "./zstdlib/*.c", "./yamlcpp/*.cpp", "./lmdb/*.c")
    add_headerfiles("*.h", "./zstdlib/*.h")
    add_includedirs("./yamlcpp")
