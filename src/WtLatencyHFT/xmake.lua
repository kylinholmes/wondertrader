add_rules("mode.debug", "mode.release")

target("WtLatencyHFT")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_deps("WtCore", "WTSTools", "WTSUtils")
    add_packages("boost")