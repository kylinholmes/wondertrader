add_rules("mode.debug", "mode.release")

target("WtBtRunner")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_packages("boost")
    add_deps("WtBtCore", "WTSTools", "WTSUtils")
