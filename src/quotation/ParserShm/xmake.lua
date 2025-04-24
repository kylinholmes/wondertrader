add_rules("mode.debug", "mode.release")

target("ParserShm")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserShm.cpp")
    add_packages("boost")