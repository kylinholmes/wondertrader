/*!
 * /file WtUftRunner.h
 * /project	WonderTrader
 *
 * /author Wesley
 * /date 2020/03/30
 * 
 * /brief 
 */
#pragma once
#include <string>
#include <unordered_map>

#include "Includes/ILogHandler.h"

#include "UltraFT/WtUftCore/EventNotifier.h"
#include "UltraFT/WtUftCore/UftStrategyMgr.h"

#include "UltraFT/WtUftCore/WtUftEngine.h"
#include "UltraFT/WtUftCore/TraderAdapter.h"
#include "UltraFT/WtUftCore/ParserAdapter.h"
#include "UltraFT/WtUftCore/WtUftDtMgr.h"
#include "UltraFT/WtUftCore/ActionPolicyMgr.h"

#include "base/WTSTools/WTSHotMgr.h"
#include "base/WTSTools/WTSBaseDataMgr.h"

NS_WTP_BEGIN
class WTSVariant;
NS_WTP_END

USING_NS_WTP;

class WtUftRunner : public ILogHandler
{
public:
	WtUftRunner();
	~WtUftRunner();

public:
	void init(const std::string& filename);

	bool config(const std::string& filename);

	void run(bool bAsync = false);

private:
	bool initTraders(WTSVariant* cfgTrader);
	bool initParsers(WTSVariant* cfgParser);
	bool initDataMgr();
	bool initUftStrategies();
	bool initEvtNotifier();
	bool initEngine();

//////////////////////////////////////////////////////////////////////////
//ILogHandler
public:
	virtual void handleLogAppend(WTSLogLevel ll, const char* msg) override;

private:
	WTSVariant*			_config;
	TraderAdapterMgr	_traders;
	ParserAdapterMgr	_parsers;

	WtUftEngine			_uft_engine;

	WtUftDtMgr			_data_mgr;

	WTSBaseDataMgr		_bd_mgr;
	EventNotifier		_notifier;

	UftStrategyMgr		_uft_stra_mgr;

	ActionPolicyMgr		_act_policy;

	bool				_to_exit;
};

