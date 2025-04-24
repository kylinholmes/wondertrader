add_rules("mode.debug", "mode.release")

target("ParserXeleSkt")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserXeleSkt.cpp")
    add_packages("boost")