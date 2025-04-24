add_rules("mode.debug", "mode.release")

target("WtDtCore")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h", "*.hpp")
    add_packages("boost", "spdlog")