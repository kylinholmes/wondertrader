add_rules("mode.debug", "mode.release")

target("ParserYD")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserYD.cpp")
    add_packages("boost")