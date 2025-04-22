add_rules("mode.debug", "mode.release")

target("WtDtPorter")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    add_links("WtDtCore", "WTSTools", "WTSUtils")

    if is_plat("linux") then
        add_links("dl", "pthread", "boost_filesystem", "boost_thread")
        set_symbols("hidden")
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
        if is_mode("release") then
            add_ldflags("-s")
        end
    end

    after_build(function (target)
        os.mkdir(path.join(target:targetdir(), "parsers"))

        local modules = {
            { "ParserCTP", "parsers" },
            { "ParserXTP", "parsers" },
            { "ParserFemas", "parsers" },
            { "ParserCTPMini", "parsers" },
            { "WtDataStorage", "" },
            { "WtDataStorageAD", "" }
        }

        for _, mod in ipairs(modules) do
            os.cp(path.join(target:targetdir(), mod[1]), path.join(target:targetdir(), mod[2]))
        end
    end)