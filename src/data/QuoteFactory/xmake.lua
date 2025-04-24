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

        local modules = {
            { "ParserCTP", "parsers" },
            { "ParserXTP", "parsers" },
            { "ParserFemas", "parsers" },
            { "ParserCTPMini", "parsers" },
            { "WtDataStorage", "" },
        }

        for _, parser in ipairs(parsers) do
            os.cp(project.target(mod[1]):targetfile() , path.join(target:targetdir(), mod[2]))
        end
    end)