add_rules("mode.debug", "mode.release")

target("ParserCTPMini")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserCTPMini.cpp")
    add_packages("boost")