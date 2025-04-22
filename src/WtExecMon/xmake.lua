add_rules("mode.debug", "mode.release")

target("WtExecMon")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_deps("WtCore", "WTSTools", "WTSUtils")
    add_packages("boost")