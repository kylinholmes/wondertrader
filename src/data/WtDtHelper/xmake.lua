add_rules("mode.debug", "mode.release")

target("WtDtHelper")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_deps("WTSUtils", "WTSTools")
    add_packages("boost")