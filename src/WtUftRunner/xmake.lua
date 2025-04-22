add_rules("mode.debug", "mode.release")

target("WtUftRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    add_links("WtUftCore", "WTSTools", "WTSUtils")

    if is_plat("windows") then
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("dl", "pthread", "boost_filesystem", "boost_thread")
    end

    after_build(function (target)
        os.mkdir(path.join(target:targetdir(), "parsers"))
        os.mkdir(path.join(target:targetdir(), "traders"))

        os.cp(path.join(target:targetdir(), "TraderCTP"), path.join(target:targetdir(), "traders"))
        os.cp(path.join(target:targetdir(), "ParserCTP"), path.join(target:targetdir(), "parsers"))
    end)