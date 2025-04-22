add_rules("mode.debug", "mode.release")

target("TraderHTS")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderDD.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("linux") then
        add_links("FixApi/libfixapi.so")
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
    end

    if is_mode("release") then
        add_ldflags("-s")
    end