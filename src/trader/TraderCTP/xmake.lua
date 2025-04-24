add_rules("mode.debug", "mode.release")

target("TraderCTP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderCTP.cpp")
    add_packages("boost")