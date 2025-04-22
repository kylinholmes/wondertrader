add_rules("mode.debug", "mode.release")

target("WtUftRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_packages("boost", {configs = {filesystem = true}})
    add_deps("WtUftCore", "WTSTools", "WTSUtils")

    after_build(function (target)
        os.mkdir(path.join(target:targetdir(), "parsers"))
        os.mkdir(path.join(target:targetdir(), "traders"))

        os.cp(path.join(target:targetdir(), "TraderCTP"), path.join(target:targetdir(), "traders"))
        os.cp(path.join(target:targetdir(), "ParserCTP"), path.join(target:targetdir(), "parsers"))
    end)