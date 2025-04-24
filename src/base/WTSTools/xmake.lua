add_rules("mode.debug", "mode.release")

target("WTSTools")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("base/WTSUtils/yamlcpp")
    add_packages("boost", "spdlog", "rapidjson")
