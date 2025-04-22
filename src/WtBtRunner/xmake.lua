add_rules("mode.debug", "mode.release")

target("WtBtRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    add_links("WtBtCore", "WTSTools", "WTSUtils")

    if is_plat("linux") then
        add_links("boost_filesystem", "pthread", "dl")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end