add_rules("mode.debug", "mode.release")

target("WtRiskMonFact")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
