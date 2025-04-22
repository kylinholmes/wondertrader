add_rules("mode.debug", "mode.release")

target("TraderCTPMini")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderCTPMini.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("linux") then
        add_links("pthread", "boost_filesystem", "dl")
    end

    if is_mode("release") then
        add_ldflags("-s")
    end