add_rules("mode.debug", "mode.release")

target("TraderYD")
    set_kind("shared")
    set_languages("cxx17")
    add_files("TraderYD.cpp")
    add_headerfiles("TraderYD.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("linux") then
        add_links("boost_thread", "boost_filesystem", "dl")
        if is_mode("release") then
            add_ldflags("-s")
        end
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
    end