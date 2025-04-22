add_rules("mode.debug", "mode.release")


set_languages("cxx17")
-- set_warnings("all", "error")
add_requires(
    "boost[thread,filesystem,asio,system,shared,all]",
    "rapidjson",
    "nanomsg",
    "nlopt",
    "spdlog",
    "fmt"
)
add_packages("boost", "spdlog", "rapidjson", "nanomsg", "nlopt", "fmt")
add_cxflags("-Wno-deprecated-declarations")




if is_plat("windows") then
    add_links("iconv") -- Windows 平台特定库
    add_defines("_WINDOWS")
    if is_kind("msvc") then
        add_syslinks("ws2_32")
    else
        add_links("ws2_32")
    end
elseif is_plat("linux") then
    add_cxflags("-fPIC")
    set_symbols("hidden")
    add_cxflags("-fvisibility=hidden", "-fvisibility-inlines-hidden")
    add_links("dl", "pthread", "rt") -- Linux 平台特定库
    if is_mode("release") then
        add_ldflags("-s")
    end
end


includes("WTSUtils", "WTSTools", "CTPLoader", "CTPOptLoader", "LoaderRunner", 
         "ParserCTP", "ParserCTPMini", "ParserCTPOpt", "ParserFemas", "ParserXTP", 
         "ParserShm", "ParserXeleSkt", "WtDataStorage", "WtDataStorageAD", "WtDtCore", 
         "WtDtHelper", "WtDtPorter", "WtDtServo", "QuoteFactory", "WtBtCore", 
         "WtBtPorter", "WtBtRunner", "ParserUDP", "TraderCTP", "TraderCTPMini", 
         "TraderCTPOpt", "TraderFemas", "TraderMocker", "TraderXTP", "TraderYD", 
         "WtExeFact", "WtRiskMonFact", "WtMsgQue", "WtCore", "WtPorter", "WtExecMon", 
         "WtRunner", "TraderDumper", "WtShareHelper", "WtUftCore", "WtUftStraFact", 
         "WtUftRunner", "WtLatencyHFT", "WtLatencyUFT"
        --  ,"TestBtPorter", "TestDtPorter", 
        --  "TestExecPorter", "TestPorter", "TestTrader", "TestParser", "TestUnits"
        )