add_rules("mode.debug", "mode.release")

target("TraderOES")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderOES.cpp")
    add_headerfiles("TraderOES.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("dl", "boost_thread", "boost_filesystem")
        if is_mode("release") then
            add_ldflags("-s")
        end
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
    end