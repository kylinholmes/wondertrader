add_rules("mode.debug", "mode.release")

target("WtRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")

    add_deps("WtCore", "WTSTools", "WTSUtils")
    add_packages("boost")

    after_build(function (target)
        import("core.project.project")
        os.mkdir(path.join(target:targetdir(), "parsers"))
        os.mkdir(path.join(target:targetdir(), "traders"))
        os.mkdir(path.join(target:targetdir(), "executer"))

        local modules = {
            { "ParserUDP", "parsers" },
            { "TraderCTP", "traders" },
            { "TraderXTP", "traders" },
            { "TraderMocker", "traders" },
            { "TraderCTPMini", "traders" },
            { "TraderCTPOpt", "traders" },
            { "TraderFemas", "traders" },
            { "WtExeFact", "executer" },
            { "WtDataStorage", "" },
            { "WtDataStorageAD", "" },
            { "WtRiskMonFact", "" },
            { "WtMsgQue", "" }
        }

        for _, mod in ipairs(modules) do
            os.cp(project.target(mod[1]):targetfile() , path.join(target:targetdir(), mod[2]))
        end
    end)