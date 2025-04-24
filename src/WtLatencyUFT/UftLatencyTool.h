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
#include "UltraFT/WtUftCore/WtUftEngine.h"
#include "UltraFT/WtUftCore/UftStrategyMgr.h"
#include "UltraFT/WtUftCore/TraderAdapter.h"
#include "UltraFT/WtUftCore/ParserAdapter.h"

#include "base/WTSTools/WTSBaseDataMgr.h"

NS_WTP_BEGIN
class WTSVariant;
NS_WTP_END

namespace uft
{
	class UftLatencyTool
	{
	public:
		UftLatencyTool();
		~UftLatencyTool();

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
		UftStrategyMgr		_stra_mgr;

		WtUftEngine			_engine;

		WTSBaseDataMgr		_bd_mgr;

		uint32_t			_times;
		uint32_t			_core;
	};
}

