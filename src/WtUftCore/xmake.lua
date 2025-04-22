add_rules("mode.debug", "mode.release")

target("WtUftCore")
    set_kind("static")
    set_languages("cxx17")
    add_files("*.cpp")
    add_headerfiles("*.h")
    add_includedirs("$(INCS)")
    add_linkdirs("$(LNKS)")

    if is_plat("linux") then
        add_cxflags("-fPIC")
    end