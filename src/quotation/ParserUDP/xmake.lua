add_rules("mode.debug", "mode.release")

target("ParserUDP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserUDP.cpp")
    add_packages("boost")