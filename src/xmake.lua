add_rules("mode.debug", "mode.release")


set_languages("cxx17")
-- set_warnings("all", "error")
add_requires(
    "boost[all]{configs={shared=false}}",
    "rapidjson",
    "nanomsg",
    "nlopt",
    "spdlog",
    "fmt"
)
add_packages("boost", "spdlog", "rapidjson", "nanomsg", "nlopt", "fmt")
add_cxflags("-Wno-deprecated-declarations")
add_includedirs("Includes","./","base/include", {public = true})




if is_plat("windows") then
    add_links("iconv") -- Windows 平台特定库
    add_defines("_WINDOWS")
    if is_kind("msvc") then
        add_syslinks("ws2_32")
    else
        add_links("ws2_32")
    end
elseif is_plat("linux") then
    add_cxflags("-fPIC","-fvisibility=hidden", "-fvisibility-inlines-hidden")
    set_symbols("hidden")
    add_links("dl", "pthread", "rt") -- Linux 平台特定库
    if is_mode("release") then
        add_ldflags("-s")
    end
end


includes(
    "base",     
    -- "WTSUtils", "WTSTools", 
    "backtest",         
    --  "WtBtCore", "WtBtPorter", "WtBtRunner", 
    "data",
    --  "WtDataStorage", "WtDataStorageAD", "WtDtCore", 
    --  "WtDtHelper", "WtDtPorter", "WtDtServo", "QuoteFactory", 
    "quotation",
    --  "ParserCTP", "ParserCTPMini", "ParserCTPOpt", "ParserFemas", "ParserXTP", 
    --  "ParserShm", "ParserXeleSkt", "ParserUDP", 
    "plugin",
    -- "WtCtaStraFact", "WtRiskMonFact", "WtExeFact", "WtHftStraFact", "WtSelStraFact",
    "product",
    --  "WtCore", "WtPorter", "WtExecMon", "WtRunner", 
    "trader",
    -- "TraderCTPOpt", "TraderFemas", "TraderMocker", "TraderXTP", "TraderYD", 
    -- "TraderDumper", "TraderCTP", "TraderCTPMini", 
    "UltraFT",
    -- "WtUftCore", "WtUftStraFact", "WtUftRunner",
    "tools",
    -- "CTPLoader", "CTPOptLoader", "LoaderRunner", "WtMsgQue", 

    -- Unkown rightnow, readme no mention
    "WtShareHelper", 
    "WtLatencyHFT", "WtLatencyUFT"
)