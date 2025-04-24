add_rules("mode.debug", "mode.release")

target("TraderYD")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderYD.cpp")
    add_headerfiles("TraderYD.h")
    add_packages("boost")