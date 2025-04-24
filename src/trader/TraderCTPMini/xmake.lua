add_rules("mode.debug", "mode.release")

target("TraderCTPMini")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderCTPMini.cpp")
    add_packages("boost")