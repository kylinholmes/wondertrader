add_rules("mode.debug", "mode.release")

target("QuoteFactory")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_packages("boost")

    if is_plat("windows") then
        add_files("../Common/mdump.cpp")
    end

    add_deps("WTSTools", "WTSUtils", "WtDtCore")

    after_build(function (target)
        os.mkdir(path.join(target:targetdir(), "parsers"))
        local parsers = {"ParserCTP", "ParserXTP", "ParserFemas", "ParserCTPMini", "WtDataStorage"}
        for _, parser in ipairs(parsers) do
            os.cp(path.join(target:targetdir(), parser), path.join(target:targetdir(), "parsers"))
        end
    end)