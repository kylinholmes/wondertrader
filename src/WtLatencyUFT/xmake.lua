add_rules("mode.debug", "mode.release")

target("WtLatencyUFT")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_deps("WtUftCore", "WTSTools", "WTSUtils", "WtShareHelper")
    add_packages("boost")