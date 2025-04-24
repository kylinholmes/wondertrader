add_rules("mode.debug", "mode.release")

target("TraderATP")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderATP.cpp")
    add_packages("boost")
