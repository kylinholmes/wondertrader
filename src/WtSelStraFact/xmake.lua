add_rules("mode.debug", "mode.release")

target("WtSelStraFact")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("linux") then
        add_links("nlopt", "boost_filesystem", "dl")
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end