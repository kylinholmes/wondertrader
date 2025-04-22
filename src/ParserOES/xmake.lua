add_rules("mode.debug", "mode.release")

target("ParserOES")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserOES.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        if is_kind("msvc") then
            add_syslinks("ws2_32")
        else
            add_links("boost_thread", "ws2_32")
        end
    elseif is_plat("linux") then
        add_links("boost_thread")
    end

    if is_plat("linux") then
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end