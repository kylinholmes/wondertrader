add_rules("mode.debug", "mode.release")

target("TraderDumper")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_files("../Common/mdump.cpp")
    elseif is_plat("linux") then
        add_links("dl", "pthread", "boost_filesystem", "boost_thread")
    end

    add_links("WTSTools", "WTSUtils")

    if is_mode("release") then
        add_ldflags("-s")
    end