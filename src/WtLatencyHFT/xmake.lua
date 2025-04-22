add_rules("mode.debug", "mode.release")

target("WtLatencyHFT")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    add_links("WtCore", "WTSTools", "WTSUtils")

    if is_plat("windows") then
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("dl", "pthread", "boost_filesystem", "boost_thread")
    end

    if is_mode("release") then
        add_ldflags("-s")
    end