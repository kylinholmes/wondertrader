add_rules("mode.debug", "mode.release")

target("TraderDD")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderDD.cpp")

    if is_plat("linux") then
        add_links("FixApi/libfixapi.so")
    end