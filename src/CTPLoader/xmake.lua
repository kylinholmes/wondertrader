-- 定义目标
target("CTPLoader")
    set_kind("shared") -- 生成动态库
    set_languages("c++17") -- 设置 C++ 标准

    -- 添加源码文件
    add_files("CTPLoader.cpp", "TraderSpi.cpp")

    -- 添加头文件路径
    add_includedirs("$(projectdir)/src") -- 项目根目录的 src 文件夹
    if is_plat("windows") then
        add_includedirs("$(projectdir)/include/windows") -- Windows 特定的头文件路径
    else
        add_includedirs("$(projectdir)/include/linux") -- Linux 特定的头文件路径
    end

    -- 添加链接库路径
    add_linkdirs("$(projectdir)/lib") -- 链接库路径

    -- 添加依赖的库
    add_links("boost_filesystem", "WTSUtils", "dl")
    if is_plat("windows") then
        add_links("iconv") -- Windows 平台特定库
    end

    -- 设置编译选项
    if is_plat("windows") then
        -- Windows 平台的编译选项
        add_defines("_WINDOWS")
    else
        -- 非 Windows 平台的编译选项
        add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
        add_ldflags("-s", {force = true}) -- Release 模式下的链接选项
    end