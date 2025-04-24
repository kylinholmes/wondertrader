add_rules("mode.debug", "mode.release")

target("TraderXTP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderXTP.cpp")
    add_headerfiles("TraderXTP.h")
    add_packages("boost")