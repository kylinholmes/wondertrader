add_rules("mode.debug", "mode.release")

target("TraderOES")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderOES.cpp")
    add_headerfiles("TraderOES.h")
    add_packages("boost")