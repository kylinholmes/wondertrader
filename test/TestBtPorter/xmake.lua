add_rules("mode.debug", "mode.release")

target("TestBtPorter")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")

    add_deps("WtBtPorter")
