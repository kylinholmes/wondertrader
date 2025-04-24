-- 定义目标
target("CTPLoader")
    set_kind("shared") -- 生成动态库
    set_languages("c++17") -- 设置 C++ 标准
    add_files("CTPLoader.cpp", "TraderSpi.cpp")

    add_deps("WTSUtils") -- 添加依赖的库
    add_packages("boost", "rapidjson") -- 添加 Boost 和 jsoncpp 库