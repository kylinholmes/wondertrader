/*!
 * /file WtRunner.h
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

#include "product/WtCore/EventNotifier.h"
#include "product/WtCore/CtaStrategyMgr.h"
#include "product/WtCore/HftStrategyMgr.h"
#include "product/WtCore/SelStrategyMgr.h"

#include "product/WtCore/WtCtaEngine.h"
#include "product/WtCore/WtHftEngine.h"
#include "product/WtCore/WtSelEngine.h"
#include "product/WtCore/WtLocalExecuter.h"
#include "product/WtCore/WtDistExecuter.h"
#include "product/WtCore/TraderAdapter.h"
#include "product/WtCore/ParserAdapter.h"
#include "product/WtCore/WtDtMgr.h"
#include "product/WtCore/ActionPolicyMgr.h"

#include "base/WTSTools/WTSHotMgr.h"
#include "base/WTSTools/WTSBaseDataMgr.h"

NS_WTP_BEGIN
class WTSVariant;
class WtDataStorage;
NS_WTP_END

USING_NS_WTP;

class WtRunner : public ILogHandler
{
public:
	WtRunner();
	~WtRunner();

public:
	void init(const std::string& filename);

	bool config(const std::string& filename);

	void run(bool bAsync = false);

private:
	bool initTraders(WTSVariant* cfgTrader);
	bool initParsers(WTSVariant* cfgParser);
	bool initExecuters(WTSVariant* cfgExecuter);
	bool initDataMgr();
	bool initEvtNotifier();
	bool initCtaStrategies();
	bool initHftStrategies();
	bool initActionPolicy();

	bool initEngine();

//////////////////////////////////////////////////////////////////////////
//ILogHandler
public:
	virtual void handleLogAppend(WTSLogLevel ll, const char* msg) override;

private:
	WTSVariant*			_config;
	TraderAdapterMgr	_traders;
	ParserAdapterMgr	_parsers;
	WtExecuterFactory	_exe_factory;

	WtCtaEngine			_cta_engine;
	WtHftEngine			_hft_engine;
	WtSelEngine			_sel_engine;
	WtEngine*			_engine;

	WtDataStorage*		_data_store;

	WtDtMgr				_data_mgr;

	WTSBaseDataMgr		_bd_mgr;
	WTSHotMgr			_hot_mgr;
	EventNotifier		_notifier;

	CtaStrategyMgr		_cta_stra_mgr;
	HftStrategyMgr		_hft_stra_mgr;
	SelStrategyMgr		_sel_stra_mgr;
	ActionPolicyMgr		_act_policy;

	bool				_is_hft;
	bool				_is_sel;

	bool				_to_exit;
};

