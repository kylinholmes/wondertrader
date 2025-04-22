add_rules("mode.debug", "mode.release")

target("QuoteFactory")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("windows") then
        add_files("../Common/mdump.cpp")
        add_syslinks("ws2_32")
    elseif is_plat("linux") then
        add_links("dl", "boost_filesystem", "boost_thread", "pthread")
    end

    add_links("WTSTools", "WTSUtils", "WtDtCore")

    if is_mode("release") then
        add_ldflags("-s")
    end

    after_build(function (target)
        os.mkdir(path.join(target:targetdir(), "parsers"))
        local parsers = {"ParserCTP", "ParserXTP", "ParserFemas", "ParserCTPMini", "WtDataStorage"}
        for _, parser in ipairs(parsers) do
            os.cp(path.join(target:targetdir(), parser), path.join(target:targetdir(), "parsers"))
        end
    end)