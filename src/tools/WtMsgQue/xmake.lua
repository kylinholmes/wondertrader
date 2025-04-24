add_rules("mode.debug", "mode.release")

target("WtMsgQue")
    set_kind("shared")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_packages("nanomsg", "spdlog")
