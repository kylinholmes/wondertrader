add_rules("mode.debug", "mode.release")

target("WtExecMon")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    add_links("WtCore", "WTSTools", "WTSUtils")

    if is_plat("linux") then
        add_links("dl", "pthread", "boost_filesystem", "boost_thread")
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end