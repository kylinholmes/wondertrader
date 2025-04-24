add_rules("mode.debug", "mode.release")

target("TraderXTPXAlgo")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderXTPXAlgo.cpp")
    add_packages("boost")