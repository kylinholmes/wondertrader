add_rules("mode.debug", "mode.release")

target("TraderFemas")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderFemas.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("boost_filesystem", "dl")
    end

    if is_mode("release") then
        add_ldflags("-s")
    end