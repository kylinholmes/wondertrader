add_rules("mode.debug", "mode.release")

target("WtUftRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_packages("boost", {configs = {filesystem = true}})
    add_deps("WtUftCore", "WTSTools", "WTSUtils")

    after_build(function (target)
        import("core.project.project")
        os.mkdir(path.join(target:targetdir(), "parsers"))
        os.mkdir(path.join(target:targetdir(), "traders"))

        local modules = {
            { "TraderCTP", "traders" },
            { "ParserCTP", "parsers" }
        }

        for _, mod in ipairs(modules) do
            os.cp(project.target(mod[1]):targetfile() , path.join(target:targetdir(), mod[2]))
        end
    end)