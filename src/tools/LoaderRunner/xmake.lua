-- 定义目标
target("LoaderRunner")
    set_kind("binary") -- 生成可执行文件
    set_languages("c++17") -- 设置 C++ 标准
    add_files("*.cpp") -- 添加所有 .cpp 文件
    add_deps("WtBtCore", "WTSTools", "WTSUtils")