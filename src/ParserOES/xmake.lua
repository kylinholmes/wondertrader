add_rules("mode.debug", "mode.release")

target("ParserOES")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserOES.cpp")
    add_packages("boost")