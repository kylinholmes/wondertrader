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
#include "product/WtCore/WtHftEngine.h"
#include "product/WtCore/HftStrategyMgr.h"
#include "product/WtCore/TraderAdapter.h"
#include "product/WtCore/ParserAdapter.h"
#include "product/WtCore/ActionPolicyMgr.h"
#include "product/WtCore/WtDtMgr.h"

#include "base/WTSTools/WTSBaseDataMgr.h"
#include "base/WTSTools/WTSHotMgr.h"


NS_WTP_BEGIN
class WTSVariant;
NS_WTP_END

namespace hft
{
	class HftLatencyTool
	{
	public:
		HftLatencyTool();
		~HftLatencyTool();

	public:
		/*
		 *	≥ı ºªØ
		 */
		bool init();

		void run();

	private:
		bool initModules();
		bool initStrategies();

		bool initEngine(WTSVariant* cfg);

	private:
		TraderAdapterMgr	_traders;
		ParserAdapterMgr	_parsers;
		HftStrategyMgr		_stra_mgr;

		WtHftEngine			_engine;

		WTSBaseDataMgr		_bd_mgr;
		WTSHotMgr			_hot_mgr;
		ActionPolicyMgr		_act_mgr;
		WtDtMgr				_dt_mgr;

		uint32_t			_times;
		uint32_t			_core;
	};
}

