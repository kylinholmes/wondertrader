add_rules("mode.debug", "mode.release")

target("ParserXeleSkt")
    set_kind("shared")
    set_languages("cxx17")
    add_files("ParserXeleSkt.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("boost_thread")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end