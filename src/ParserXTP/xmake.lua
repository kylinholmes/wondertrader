add_rules("mode.debug", "mode.release")

target("ParserXTP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserXTP.cpp")
    add_packages("boost")