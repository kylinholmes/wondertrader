add_rules("mode.debug", "mode.release")

target("TraderDD")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderDD.cpp")

    if is_plat("linux") then
        add_linkdirs(path.join(os.projectdir(), "src/API/FixApi/linux"))
        add_links("fixapi")
    end