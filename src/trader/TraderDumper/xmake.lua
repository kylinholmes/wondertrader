add_rules("mode.debug", "mode.release")

target("TraderDumper")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_packages("boost")

    if is_plat("windows") then
        add_files("../Common/mdump.cpp")
    end

    add_deps("WTSTools", "WTSUtils")