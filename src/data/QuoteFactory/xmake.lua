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

    -- after_build(function (target)
    --     os.mkdir(path.join(target:targetdir(), "parsers"))
    --     local parsers_dir = path.join(target:targetdir(), "parsers")
    --     local parsers = {"ParserCTP", "ParserXTP", "ParserFemas", "ParserCTPMini", "WtDataStorage"}
    --     for _, parser in ipairs(parsers) do
    --         print(string.format("Target file for '%s' not found! %s, %s", file, os.curdir(), os.project()))
    --         local file = project.target(parser)
    --         os.cp(file, parsers_dir)
    --     end
    -- end)