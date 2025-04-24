add_rules("mode.debug", "mode.release")

target("WtBtCore")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_packages("boost", "spdlog", "rapidjson")