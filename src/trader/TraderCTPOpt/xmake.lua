add_rules("mode.debug", "mode.release")

target("TraderCTPOpt")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderCTPOpt.cpp")
    add_packages("boost")