add_rules("mode.debug", "mode.release")

target("TraderFemas")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderFemas.cpp")
    add_packages("boost")