add_rules("mode.debug", "mode.release")

target("WtMsgQue")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_links("nanomsg", "ws2_32", "mswsock")
    elseif is_plat("linux") then
        add_links("nanomsg", "dl", "pthread")
    end

    if is_mode("release") then
        add_ldflags("-s")
    end