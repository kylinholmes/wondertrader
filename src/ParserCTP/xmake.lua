add_rules("mode.debug", "mode.release")

target("ParserCTP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserCTP.cpp")
    add_packages("boost")
