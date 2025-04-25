-- self-host repo
add_repositories("kylin git@github.com:kylinholmes/xmake-repo.git")

includes(
    "src"
)

on_install(function (target)
    import("core.base.task")
    import("core.project.project")

    -- 获取项目根目录
    local project_root = os.projectdir()
    -- 定义安装路径
    local install_dir = path.join(project_root, "install")
    -- 创建安装目录
    os.mkdir(install_dir)
    os.mkdir(path.join(install_dir, "bin"))

    print("file " .. target:name() .. " Installing to: " .. install_dir)
    local kind = target:get("kind")
    if kind == "binary" then
        -- 拷贝可执行文件
        print("Installed binary -> " .. target:targetfile())
        os.cp(target:targetfile(), path.join(install_dir, "bin"))
    end

    if kind == "shared" then
        local prefix = {
            { "Parser", "parsers" },
            { "Trader", "traders" },
            { "WtExeFact", "executer" }
            --
        }
        local function dest_dir(target_name)
            for _, mod in ipairs(prefix) do
                if target_name:find("^" .. mod[1]) then
                    return mod[2]
                end
            end
            return ""
        end
        os.mkdir(path.join(install_dir, "parsers"))
        os.mkdir(path.join(install_dir, "traders"))
        os.mkdir(path.join(install_dir, "executer"))
        local dest = path.join(install_dir, dest_dir(target:name()))
        print("Installed shared library -> " .. target:targetfile() .. " to " .. dest)
        os.cp(target:targetfile(), dest)
    end
end)