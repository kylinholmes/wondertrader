add_rules("mode.debug", "mode.release")

target("TraderMocker")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderMocker.cpp")
    add_packages("boost")