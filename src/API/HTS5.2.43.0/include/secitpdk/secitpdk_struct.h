#pragma once
#include "API/HTS5.2.43.0/include/itpdk/itpdk_typedef.h"
#include <string.h>
#pragma pack(push,1)
#define  HEADER_VER 5243

struct stStructMsg
{
    int16       nStructFunc;           //���ܺ�
    uint8       nStructVer;            //�����İ汾
    uint64      nStructToken;          //��ȫ����
    int16       nStructRetCode;        //����ֵ
    char        AccountId[13];         //�ͻ���
    char        FundAccount[31];       //�ʽ��˺�
    int64       OrderId;               //ί�к� 
    char        Department[5];         //Ӫҵ��
    char        Market[3];             //������
    char        SecuAccount[11];       //�ɶ��� 
    char        BPSecuAccount[11];     //�ɶ��� 
    char        StockCode[9];          //֤ȯ����
    char        StockType[9];          //֤ȯ���
    char        MarketingUnit[7];      //���׵�Ԫ
    char        TransType[3];          //ҵ�����
    char        WithdrawFlag[2];       //������־
    char        MatchSerialNo[31];     //�ɽ����
    char        MatchTime[13];         //�ɽ�ʱ��
    char        MoneyType[4];          //����
    float64     OrderPrice;            //ί�м۸�
    int64       OrderQty;              //ί������
    int64       WithdrawQty;           //��������
    float64     FrozenBalance;         //�����ʽ�
    int64       MatchQty;              //���γɽ�����
    float64     MatchPrice;            //���γɽ��۸�
    float64     MatchAmt;              //���γɽ����
    int64       TotalMatchQty;         //ί���ܳɽ�����
    float64     TotalMatchAmt;         //ί���ܳɽ����
    float64     SettleBalance;         //�����ʽ�
    uint8       EntrustType;           //�������
    int32       OrderType;             //��������
    int32       OrderStatus;           //�걨���
    char        ResultInfo[61];        //���˵��
    int64       CXOrderId;             //����ί�к�
    int64       BatchNo;               //ί�����κ�(ԭ�����Ϳͻ��˲���)
    char        OrderClerk[9];         //ί�й�Ա
    char        ETPSort[11];           //��������Ʒ����
    char        ETPOrderNo[11];        //��������Ʒ�ɽ����
    char        KFSDM[7];
    char        KFSBDBH[17];
    char        MsgCode[8];
    char        ConfirmTime[13];        //ȷ��ʱ��
    stStructMsg()
    {
        memset(this, 0, sizeof(stStructMsg));
    }
};
typedef void(*pStructMessageCallbackMethod)(const char* pTime, stStructMsg &stMsg, int nType);
//֤ȯ����
typedef struct
{
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    char     PhoneticCode[8];     //ƴ������
    char     StockType[4];        //֤ȯ���
    double   PriceTick;           //���׼�λ
    double   TradeUnit;           //���׵�λ
    int      MaxTradeAmt;         //ί������
    int      MinTradeAmt;         //ί������
    char     MoneyType[4];        //����
    double   LastPrice;           //���¼�
    double   HighLimitPrice;      //��߱���--��ͣ��
    double   LowLimitPrice;       //��ͱ���--��ͣ��
    int      NetPriceFlag;        //��ծ���۱�־
    int      QtyTick;             //������--�۹�
    double   LastClosePrice;      //������
    double   OpenPrice;           //����
    int      SuspendFlag;         //ͣ�Ʊ�־
    double   MatchQty;            //�ɽ�����
    double   MatchAmt;            //�ɽ����
    double   HighPrice;           //��߼�
    double   LowPrice;            //��ͼ�
    double   BidPrice1;           //����۸�1
    double   BidPrice2;           //����۸�2
    double   BidPrice3;           //����۸�3
    double   BidPrice4;           //����۸�4
    double   BidPrice5;           //����۸�5
    double   AskPrice1;           //�����۸�1
    double   AskPrice2;           //�����۸�2
    double   AskPrice3;           //�����۸�3
    double   AskPrice4;           //�����۸�4
    double   AskPrice5;           //�����۸�5
    int      BidQty1;             //��������1
    int      BidQty2;             //��������2
    int      BidQty3;             //��������3
    int      BidQty4;             //��������4
    int      BidQty5;             //��������5
    int      AskQty1;             //��������1
    int      AskQty2;             //��������2
    int      AskQty3;             //��������3
    int      AskQty4;             //��������4
    int      AskQty5;             //��������5
    double   InterestPrice;       //��Ϣ����
    double   FloatShareQty;       //��ͨ������
    int      ListDate;            //��������
    int      PaymentDate;         //�Ҹ�����
    double   StrikePrice;         //��Ȩ�۸�--��Ȩ
    char     StrikeCode[16];      //��Ȩ����--��Ȩ
    char     OrderTypeAvl[64];    //���ö�������
    double   UpdateTime;          //����ʱ��
} ITPDK_ZQHQ;
//�ͻ���Ϣ
typedef struct
{
    char     AccountId[16];          //�ͻ���
    char     AccountName[32];        //�ͻ�����
    char     CertificateNo[32];      //֤�����
    int      CertificateType;        //֤�����
    char     OrgCode[8];             //��������
    int      OrgAccFlag;             //�����˻���־
    int      EntrustWayAvl;          //����ί�з�ʽ
    int      ServiceAvl;             //��ͨ��Ʒ����
} ITPDK_KHH;
//�����ֵ�-�г�
typedef struct
{
    char     Market[4];           //������
    char     MarketName[16];      //���������
    char     MarketFullName[32];  //������ȫ��
} ITPDK_JYS;
//�����ֵ�-֤ȯ����
typedef struct
{
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    char     StockType[4];        //֤ȯ���
    int      TradingStatus;       //����״̬
    double   LastClosePrice;      //������
    int64    MaxTradeAmt;         //ί������
    int      MinTradeAmt;         //ί������
    int64    TradeUnit;           //���׵�λ
    double   PriceTick;           //���׼�λ
    char     MoneyType[4];        //����
    double   HighLimitPrice;      //��߱���--��ͣ��
    double   LowLimitPrice;       //��ͱ���--��ͣ��
    char     BrowIndex[16];       //��ҳ��ѯ��λ��
    char     BoardCode[4];        //����ʶ
    int64    SJMaxTradeAmt;       //�м�ί������
    int      SJMinTradeAmt;       //�м�ί������
    int64    PHMaxTradeAmt;       //�̺�ί������
    int      PHMinTradeAmt;       //�̺�ί������
} ITPDK_ZQDM;
//�����ֵ�-ͶƱ��Ϣ
typedef struct
{
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockType[4];        //֤ȯ���
    char     CompanyCode[12];     //��˾����
    char     MeetingCode[22];     //������
    char     MeetingName[100];    //�������
    char     MotionCode[12];      //�鰸���
    char     MotionName[1024];    //�鰸����
    char     MotionType[3];       //�鰸����
    int      AlloweAbstention;    //������Ȩ
    int      BeginDate;           //��ʼ����
    int      EndDate;             //��������
    int64    BrowIndex;           //��ҳ��ѯ��λ��
} ITPDK_TPXX;
//�����ֵ�-���ʲ���
typedef struct
{
    char     MoneyType1[4];       //����1
    char     MoneyType2[4];       //����2
    double   CashBuyRate;         //�ֳ������
    double   CashAskRate;         //�ֳ�������
    double   RemitBuyRate;        //�ֻ������
    double   RemitAskRate;        //�ֻ�������
    double   GSBL;                //�������
    double   JSPJJ;               //������
    int      UpdateTime;          //��������
} ITPDK_HLCS;
//�����ֵ�-ϵͳ����
typedef struct
{
    char     GroupId[32];   //�������
    char     Code[8];       //����
    char     CodeName[64];  //����˵��
} ITPDK_XTDM;
//�����ֵ�-�������
typedef struct
{
    char     EntrustType[4];         //�������
    char     EntrustTypeName[16];    //�������
} ITPDK_JYLB;
//�����ֵ�-֤ȯ��������
typedef struct
{
    char     Market[4];        //������
    char     StockType[4];     //֤ȯ���
    int      EntrustType;      //�������
    int      QtyTick;          //���׻���
    int      EntrustWay;       //ί�з�ʽ
} ITPDK_ZQJYSX;
//����
typedef struct
{
    char     MoneyType[4];        //����
    char     MoneyTypeName[16];   //��������
} ITPDK_BZ;
//�����ֵ�-��������
typedef struct
{
    char     OrgCode[8];    //��������
    char     OrgName[32];   //��������
} ITPDK_JGDM;
//�����ֵ�-���в���
typedef struct
{
    char     BankCode[8];         //���д���
    char     MoneyType[4];        //����
    char     BusinessAvl[64];     //����֤ȯ�����ҵ�����
    char     CheckFundPwd[64];    //��ҪУ���ʽ������ҵ�����
    char     CheckBankPwd[64];    //��ҪУ�����������ҵ�����
} ITPDK_YHCS;
//�����¹��깺
typedef struct
{
    int      Flag;             //��� 1.�����¹ɷ��� 2.���տ�תծ���ɽ���ծ���� ��A5�޸��ֶΣ�
    char     Market[4];        //������
    char     StockCode[12];    //֤ȯ����
    char     StockName[31];    //֤ȯ����
    char     RGCode[12];       //�Ϲ�����
    int      RGRQ;             //�Ϲ�����
    double   IssuePrice;       //���м۸�
    int64    MaxTradeAmt;      //ί������
    int      MinTradeAmt;      //ί�����ޣ�A5�޸��ֶΣ�
    char     MoneyType[4];     //���֣�A5�޸��ֶΣ�
    int      UpdateTime;       //����ʱ��
} ITPDK_XGSG;
//�����ֵ�-�۹ɽ��׼�λ
typedef struct
{
    char     Market[4];        //������
    char     StockType[4];     //֤ȯ���
    double   BeginPrice;       //��ʼ�۸�
    double   EndPrice;         //�����۸�
    double   PriceTick;        //���ü�λ
    int      UpdateTime;       //��������
} ITPDK_JYJW;
//�����ֵ�-ETF������Ϣ
typedef struct
{
    char     Market[4];              //������
    char     FundCode[8];            //�������
    char     FundName[16];           //��������
    char     SubsAndRedeCode[8];     //�깺��ش���
    int      TradingDate;            //��������
    int64    SubsAndRedeUnit;        //�깺��ص�λ
    double   CashDiff;               //Ԥ���ֽ���
    double   MaxCashRatio;           //�ֽ������������
    int64    SubsAndRedeState;       //�깺���״̬��-1=�������ʸ� 0=��ֹ���� 1=�������� 2=�����깺����ֹ��� 3=��ֹ�깺���������
    double   NetAssetValue;          //T-1����λ��ֵ
    double   NAVperCU;               //�깺��ص�λ��ֵ
    double   CashComponent;          //T��ÿ�������ֽ���
} ITPDK_ETFXX;
//�����ֵ�-ETF�ɷֹ���Ϣ
typedef struct
{
    char     FundCode[8];         //�������
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    int64    ComponentQty;        //�ɷݹ�����
    double   PremiumRatio;        //��۱���
    double   CashSubstitute;      //������
    int      SubstituteFlag;      //�����־��0=��ֹ�ֽ���� 1=�����ֽ���� 2=�����ֽ����
    char     StockType[4];        //֤ȯ���
} ITPDK_ETFMX;
//�����ֵ�-�������
typedef struct
{
    char     Market[4];                 //������
    char     StockCode[12];             //֤ȯ����
    char     FundCode[12];              //�������
    char     FundName[44];              //��������
    int      DivideAndMergeStatus;      //������״̬
    double   NetValue;                  //����ֵ
    double   TotalNAV;                  //�ۼƾ�ֵ
    int      DivideRate;                //��ֱ���
    double   MinMergeQty;               //��ͺϲ�����
    double   MinDivideQty;              //��Ͳ������
} ITPDK_JJHQ;
//�ּ�������Ϣ
typedef struct
{
    char     Market[4];                 //������
    char     FundCode_M[12];            //ĸ������
    char     FundName_M[20];            //ĸ������
    double   FundNetValue_M;            //ĸ����ֵ
    double   FundPrice_M;               //ĸ���۸�
    char     IndexCode[12];             //ָ������
    char     IndexName[12];             //ָ������
    double   IndexRate;                 //ָ���ǵ���
    char     FundManager[36];           //���������
    double   SubscribeFeeRate;          //�깺����
    double   RedeemFeeRate;             //��ط���
    char     DivideRate[20];            //AB����
    int      DivideRate_A;              //A����
    int      DivideRate_B;              //B����
    int      RegularConvertFlag;        //���۱�־
    double   UpConvertLimit;            //���۷�ֵ
    double   DownConvertLimit;          //���۷�ֵ
    char     NextConvertDate[12];       //�´ζ���
    int      ExpiryDate;                //��ֹ����
    char     FundCode_A[12];            //A������
    char     FundName_A[20];            //A������
    double   FundPrice_A;               //A���ּ�
    double   FundNetValue_A;            //A����ֵ
    char     InterestRateRule[20];      //���ʹ���
    double   CurrentInterestRate;       //��������
    double   NextInterestRate;          //��������
    double   ForwardInterestRate;       //��������
    int      TradableFlag;              //�ɽ��ױ�־
    char     TradePrompt[260];          //�����ر���ʾ
    int      NetValueDate;              //��ֵ����
    int      MinMergeQty;               //����������
    int      MinDivideQty;              //��Ͳ������
    char     FundCode_B[8];             //B������
    char     FundName_B[20];            //A������
    double   FundNetValue_B;            //A����ֵ
    double   FundProce_B;               //A���ּ�
    int      UpdateTime;                //����ʱ��
    int      PreTradeVolume_M;          //T-1ĸ��������
    int      PreTradeVolume_A;          //T-1A��������
    int      PreTradeVolume_B;          //T-1B��������
    double   FundShares;                //�ݶ�
    double   DateIncFundShares;         //�������ӷݶ�
    double   WholePremiumRate;          //T-1���������
    double   PreWholePremiumRate;       //T-2���������
    char     SubscribeStatus[68];       //�����깺״̬
    char     RedeemStatus[68];          //�������״̬
    int      Status;                    //����״̬
    double   PreNetValue;               //T-1����ֵ
} ITPDK_FJJJ;
//�ɶ���
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     Market[4];        //������
    char     SecuAccount[12];  //�ɶ���
    char     HolderName[16];   //�ɶ�����
    char     FundAccount[16];  //�ʽ��ʺ�
    char     OrgCode[8];       //��������--��������
    char     MoneyType[4];     //����
    char     TradeAccess[16];  //����Ȩ��
    int      HolderType;       //�ɶ����
    int      EquityQty;        //Ȩ������(�¹��깺)
} ITPDK_GDH;
//����Ȩ��
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     Market[4];        //������
    char     SecuAccount[12];  //�ɶ���
    int64    StarQty;          //�ƴ�������
    int64    EquityQty;        //֤ȯȨ������
    int      SettleMentDate;   //��������
} ITPDK_PSQY;
//�ʽ���Ϣ
typedef struct
{
    char     AccountId[16];             //�ͻ���
    char     FundAccount[16];           //�ʽ��˺�
    char     MoneyType[4];              //����
    char     OrgCode[8];                //��������
    int      MasterFlag;                //���ʻ���־
    int      AccountType;               //�ʻ����
    double   LastBalance;               //�������
    double   CurrentBalance;            //�˻����
    double   FrozenBalance;             //�����ʽ�
    double   UF_FrozenBalance;          //�����ʽ�δ��Ჿ��UnFinished��
    double   T2_FrozenBalance;          //T+2������
    double   FundAvl;                   //�����ʽ�
    double   T2_FundAvl;                //T+2�����ʽ�
    double   TotalAsset;                //���ʲ�
    double   MarketValue;               //������ֵ
    double   DebtAmt;                   //��ծ���
    double   CreditQuota;               //���ö��
    double   CreditQuotaAvl;            //�������ö��
    double   UncomeBalance;             //δ�����ʽ�
    double   CashBalance;               //�ֽ����
    double   CashAsset;                 //�ֽ��ʲ�
    double   OtherAsset;                //�����ʲ�
    double   FetchBalance;              //��ȡ�ʽ�
    double   DateProfit;                //����ӯ��
    double   UnclearProfit;             //����ӯ��
    double   DiluteUnclearProfit;       //̯������ӯ��
    double   UpdateTime;                //����ʱ��
    double   SettleBalance;             //ʵʱ�����ʽ�
    double   ContractPosiValue;         //��Լ�ֲ���ֵ(��Ȩ��չ��ѯ)
    double   LastPositionValue;         //���ճֲ���ֵ(��Ȩ��չ��ѯ)
} ITPDK_ZJZH;
//�ʲ�����
typedef struct
{
    char     AccountId[16];          //�ͻ���
    char     MoneyType[4];           //����
    char     CollectItem[16];        //��Ʒ��Ŀ
    char     AccountCode[16];        //�ʻ�����
    double   AssetAmt;               //�ʲ����
    double   DebtAmt;                //��ծ���
    double   NetAsset;               //���ʲ�
    double   NoNegotiableValue;      //����ͨ��ֵ
    double   UpdateTime;             //����ʱ��
} ITPDK_ZCXX;
//�����˺�
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     BankAccount[32];  //�����˺�
    char     FundAccount[16];  //�ʽ��˺�
    char     BankCode[8];      //���д���
    char     BankName[32];     //��������
    char     MoneyType[4];     //����
} ITPDK_YHZH;
//��ѯ��֤ҵ����ˮ��νṹ��
typedef struct
{
    char lpKhh[16];     //�ͻ���
    char lpZjzh[16];    //�ʽ��˺�
    char lpJymm[40];    //��������
    char lpScdm[4];     //�г�����
    char lpYyb[5];      //Ӫҵ��
    char lpBz[4];       //����
    char lpSqh[30];     //�����
    char lpYhdm[8];     //���д���
    char lpYhzh[41];    //�����˺�
    int nRowCount;      //��ѯ������<=200��
    char lpBrowindex[64];//������ˮ��
    int nExFlag;        //�Ƿ�ȡ���˻���ˮ��0:�� 1:�ǣ�Ĭ��Ϊ 0��
}ITPDK_REQ_YZYWLS;
//��ѯ��֤ҵ����ˮ���νṹ��
typedef struct
{
    char    sWTRQ[9];    //��������
    char    sWTSJ[13];   //����ʱ��
    char    sZJZH[16];   //�ʽ��˺�
    char    sBZ[4];      //����
    char    sJGDM[8];    //���д���
    char    sCLJG[30];   //�������
    char    sJGSM[128];  //���˵��
    char    sSQH[30];    //�����
    double  dZHYE;       //�˻����
    char    sYWLB[8];    //ҵ�����
    char    sYWLBMC[32]; //ҵ���������
    double  dFSJE;       //�������
    char    sYHMC[32];   //��������
}ITPDK_YZYWLS;
//��ѯ���д�����νṹ��
typedef struct
{
    char lpKhh[16];     //�ͻ���
    char lpJymm[40];    //��������
    char lpScdm[4];     //�г�����
    char lpYyb[5];      //Ӫҵ��
    int nYHLB;          //�������
    int nExFlag;        //�Ƿ�ȡ���˻���ˮ��0:�� 1:�ǣ�Ĭ��Ϊ 0��
    char lpWtfs[5];     //ί�з�ʽ
    char lpBz[4];       //����
    char lpYhdm[8];     //���д���
}ITPDK_REQ_YHDM;
//��ѯ���д�����νṹ��
typedef struct
{
    char    sYHDM[7];    //���д���
    char    sYHMC[81];   //��������
    char    sYHZH[41];   //�����˺�
    char    sYHBZ[22];   //���б�־
    char    sBZ[4];      //����
    char    sZZYMMXX[2];    //֤ת������ѡ��(0�������䣬1��ֻ���ʽ����룬2��ֻ���������룬3���������붼Ҫ��)
    char    sYZZMMXX[2];    //��ת֤����ѡ��(0�������䣬1��ֻ���ʽ����룬2��ֻ���������룬3���������붼Ҫ��)
    char    sZHH[11];    //��/���˻���
    char    sZHLB[2];       //�˻����(0-���˻���1-���˻�)
    char    sZHLBMC[31]; //�˻��������
    int     nKSQX;       //�Ƿ�֧�ֿ���ȡ��(1-֧�֣�0 ��֧��)
    char    sKHH[16];    //�ͻ���
    char    sZJZH[16];   //�ʽ��˺�
    char    sWBJGDM[8];  //�ⲿ��������
}ITPDK_YHDM;
//��ѯ���������νṹ��
typedef struct
{
    char lpKhh[16];     //�ͻ���
    char lpJymm[40];    //�ʽ��˺�
    char lpZjzh[16];    //��������
    char lpZjmm[40];    //�ʽ�����
    char lpBz[4];       //����
    char lpYhzh[41];    //�����ʺ�
    char lpYhdm[8];     //���д���
    char lpYhmm[40];    //��������
    char lpWbzhmm[40];  //�ⲿ�˺�����
}ITPDK_REQ_YHYE;
//��ѯ���������νṹ��
typedef struct
{
    char    sLSH[31];    //��ˮ��
    double  dFSJE;       //�˻����
}ITPDK_YHYE;
//��ѯ�¹���ǩ��νṹ��
typedef struct
{
    char lpYybdm[5];    //Ӫҵ������
    char lpScdm[4];     //�г�����
    char lpKhh[16];     //�ͻ���
    char lpJymm[40];    //��������
    char lpZqdm[9];     //֤ȯ���루Ϊ�վͲ�ѯ���У�
    char lpQsrq[9];     //��ʼ����
    char lpJsrq[9];     //��������
    int nRowCount;      //��ѯ������<=200��
    char lpSyrq[9];     //��������
    char lpSyYybdm[5];  //����Ӫҵ������
    char lpBrowindex[64];//������ˮ��
    char lpWtfs[5];     //ί�з�ʽ
    char sFXFS[2];      //���з�ʽ
}ITPDK_REQ_XGZQ;
//��ѯ�¹���ǩ���νṹ��
typedef struct
{
    char    sFSRQ[9];    //��������
    char    sKHYYB[5];   //����Ӫҵ��
    char    sKHH[16];    //�ͻ���
    char    sGDH[16];    //�ɶ�����
    char    sGDXM[21];   //�ɶ�����
    char    sSCDM[4];    //�г�����
    char    sSCMC[21];   //�г�����
    char    sZQDM[9];    //֤ȯ����
    char    sZQMC[41];   //֤ȯ����
    int64   nSGSL;       //�깺����
    double  dCJJG;       //�ɽ��۸�
    double  dCJJE;       //�ɽ����
    int     nZQSL;       //֤ȯ����
    char    sLSH[31];    //��ˮ��
    char    sKKRQ[9];    //�ۿ�����
    char    sZQLB[4];    //֤ȯ���
    char    sCLZT[3];    //����״̬
    char    sTQDJBZ;     //��ǰ�����־
    double  dSJZQSL;     //ʵ����ǩ����
    double  dSJZQJE;     //ʵ����ǩ���
    double  dFQSL;       //��������
    double  dFQJE;       //�������
    char    sWTRQ[9];    //ί������
    int     nPGSL;       //�������
    double  dPGJKJE;     //��ɽɿ���
    int     nJSSX;       //����˳��
    char    sFXFS[2];    //���з�ʽ
    char    sLCZT[2];    //����״̬
}ITPDK_XGZQ;
//��Ų�ѯ��νṹ��
typedef struct
{
    char lpYybdm[5];    //Ӫҵ������
    char lpScdm[4];     //�г�����
    char lpKhh[16];     //�ͻ���
    char lpJymm[40];    //��������
    char lpGddm[16];    //�ɶ�����
    char lpPhdm[9];     //��Ŵ���
    char lpQsrq[9];     //��ʼ����
    char lpJsrq[9];     //��������
    int nRowCount;      //��ѯ������<=200��
    char lpBrowindex[64];//������ˮ��
    char lpWtfs[5];     //ί�з�ʽ
    char lpZjzh[16];    //�ʽ��˺�
}ITPDK_REQ_PHCX;
//��Ų�ѯ���νṹ��
typedef struct
{
    char    sKHH[16];    //�ͻ���
    char    sSCDM[4];    //�г�����
    char    sSCMC[21];   //�г�����
    char    sGDH[16];    //�ɶ��˺�
    char    sPHDM[9];    //��Ŵ���
    char    sPHMC[41];   //�������
    char    sQSPH[13];   //��ʼ���
    int64   nPHGS;       //��Ÿ���
    char    sPHRQ[9];    //�������
    char    sLSH[31];    //��ˮ��
    char    sCLXX[81];   //������Ϣ
    char    sWTRQ[9];    //ί������
}ITPDK_PHCX;
//��֤ת����νṹ��
typedef struct
{
    char lpKhh[16];     //�ͻ���
    int nYwlb;          //ҵ�����YWLB_YHTOZQ����ת֤ȯ��YWLB_ZQTOYH֤ȯת���У�
    char lpZjzh[16];    //�ʽ��˺�
    char lpJymm[40];    //��������
    char lpZjmm[40];    //�ʽ�����
    char lpBz[4];       //����
    char lpYhzh[41];    //�����ʺ�
    double lfZzje;      //ת�˽��
    char lpYhdm[8];     //���д���
    char lpYhmm[40];    //��������
}ITPDK_REQ_YZZZ;
//֤ȯ�ֲ�
typedef struct
{
    char     AccountId[16];             //�ͻ���
    char     Market[4];                 //������
    char     StockCode[12];             //֤ȯ����
    char     SecuAccount[12];           //�ɶ���
    char     FundAccount[16];           //�ʽ��˺�
    int      AccountType;               //�˻����
    char     MoneyType[4];              //����
    char     StockName[31];             //֤ȯ����
    int64    CurrentQty;                //��ֲ���
    int64    QtyAvl;                    //����������
    double   LastPrice;                 //���¼�
    double   MarketValue;               //������ֵ
    double   DateProfit;                //����ӯ��
    double   CostPrice;                 //�ֲ־���
    double   UnclearProfit;             //����ӯ��
    double   DividendAmt;               //�������
    double   RealizeProfit;             //ʵ��ӯ��
    int64    PreQty;                    //��ֲ���
    int64    FrozenQty;                 //��������
    int64    UncomeQty;                 //δ��������
    double   CostBalance;               //�ֲֳɱ�
    double   DiluteCostPrice;           //̯���ɱ���
    double   KeepCostPrice;             //������
    double   AvgBuyPrice;               //�������
    int64    AllotmentQty;              //�������
    int64    SubscribeQty;              //�깺����
    char     OpenDate[12];              //��������
    double   InterestPrice;             //��Ϣ����
    double   Dilutekeep_CostPrice;      //̯��������
    double   DiluteUnclearProfit;       //̯������ӯ��
    int64    TradeUnit;                 //���׵�λ
    int64    SubscribableQty;           //���깺����
    int64    RedeemableQty;             //���������
    int64    RealSubsQty;               //�깺�ɽ�����
    int64    RealRedeQty;               //��سɽ�����
    int64    TotalSellQty;              //�ۼ���������
    int64    TotalBuyQty;               //�ۼ���������
    double   TotalSellAmt;              //�������
    double   TotalBuyAmt;               //������
    double   AllotmentAmt;              //��ɽ��
    int64    RealBuyQty;                //��������ɽ�����
    int64    RealSellQty;               //���������ɽ�����
    double   RealBuyBalance;            //��������ɽ����
    double   RealSellBalance;           //���������ɽ����
    int64    BrowIndex;                 //��ҳ��ѯ��λ��
    int64    OrderFrozenQty;            //ί�ж�������
} ITPDK_ZQGL;
//����ί��
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int64    OrderId;             //ί�к�
    int64    CXOrderId;           //����ί�к�
    char     SBWTH[17];           //�걨ί�к�
    int64    KFSBDBH;             //�����̱��ر��
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    char     StockType[4];        //֤ȯ���
    int      EntrustType;         //�������
    double   OrderPrice;          //ί�м۸�
    int64    OrderQty;            //ί������
    double   MatchPrice;          //�ɽ��۸�
    int64    MatchQty;            //�ɽ�����
    int64    WithdrawQty;         //��������
    char     SecuAccount[12];     //�ɶ���
    int64    BatchNo;             //ί�����κ�
    int      EntrustDate;         //ί������
    int64    SerialNo;            //��ˮ��
    int      OrderType;           //��������
    int      OrderType_HK;        //�۹ɶ�������
    double   StopPrice;           //ֹ���޼�
    int      OrderStatus;         //�걨���
    char     EntrustNode[48];     //����վ��
    char     EntrustTime[13];     //ί��ʱ��
    char     ReportTime[13];      //�걨ʱ��
    char     MatchTime[13];       //�ɽ�ʱ��
    char     WithdrawFlag[4];     //������־
    char     ResultInfo[128];     //���˵��
    double   MatchAmt;            //�ɽ����
    double   FrozenBalance;       //�����ʽ�
    double   BailBalance;         //���ᱣ֤��
    double   HandingFee;          //�����̷ּ�
    int64    BrowIndex;           //��ҳ��ѯ��λ��
} ITPDK_DRWT;
//�ֱʳɽ�
typedef struct
{
    char     AccountId[16];       //�ͻ���
    char     Market[4];           //������
    char     SecuAccount[12];     //�ɶ���
    char     MatchSerialNo[32];   //�ɽ����
    int64    OrderId;             //ί�к�
    int      EntrustType;         //�������
    char     MatchTime[13];       //�ɽ�ʱ��
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    int64    MatchQty;            //�ɽ�����
    double   MatchPrice;          //�ɽ��۸�
    double   MatchAmt;            //�ɽ����
    char     MoneyType[4];        //����
    double   ClearBalance;        //������
    int64    BatchNo;             //ί�����κ�
    int      EntrustDate;         //ί������
    int64    BrowIndex;           //��ʼ��¼����ֵ
    char     WithdrawFlag[4];     //������־
    int64    KFSBDBH;             //�����̱��ر��
} ITPDK_SSCJ;
//ת������
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     OrgCode[8];       //���д���
    char     BankAccount[32];  //�����ʺ�
    char     MoneyType[4];     //����
    char     ReportNo[16];     //������
    char     TransType[8];     //ҵ�����
    int      ResultCode;       //�������
    double   OccurAmt;         //�������
    double   FundBalance;      //�����ʽ����
    char     ResultInfo[64];   //���˵��
    char     ResultTime[13];   //����ʱ��
    char     ApplyTime[13];    //����ʱ��
} ITPDK_ZZSQ;
//������ˮ
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int      OccurDate;           //�ɽ�����
    char     browindex[64];       //��ҳ��ѯ��λ��
    char     MatchTime[13];       //�ɽ�ʱ��
    char     Market[4];           //������
    char     StockName[31];       //֤ȯ����
    char     StockCode[12];       //֤ȯ����
    int      EntrustType;         //�������
    int64    MatchQty;            //�ɽ�����
    double   MatchPrice;          //�ɽ��۸�
    double   MatchAmt;            //�ɽ����
    double   HolderQty;           //�ɷ����
    double   FundBalance;         //�ʽ����
    double   clearBalance;        //�����ʽ�
    double   HandingFee;          //Ӷ��
    double   StampTax;            //ӡ��˰
    double   TransferFee;         //������
    double   FinalValueFee;       //�ɽ���
    double   ClearingFee;         //�����
    double   RegulatoryFee;       //��ܹ��
    char     MatchSerialNo[20];   //�ɽ����
    char     SecuAccount[12];     //�ɶ���
    int64    OrderId;             //ί�к�
    char     MoneyType[4];        //����
} ITPDK_JGMX;
//��ʷί��
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int      OccurDate;           //ί������
    char     browindex[64];       //��ҳ��ѯ��λ��
    char     EntrustTime[13];     //ί��ʱ��
    int      OrderId;             //ί�к�
    char     ResultInfo[64];      //���˵��
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[31];       //֤ȯ����
    int      EntrustType;         //�������
    double   OrderPrice;          //ί�м۸�
    int      OrderQty;            //ί������
    double   MatchPrice;          //�ɽ��۸�
    int      MatchQty;            //�ɽ�����
    int      WithdrawQty;         //��������
    char     SecuAccount[12];     //�ɶ���
    char     EntrustNode[48];     //ί�е�ַ
    int      OrderType;           //��������
    int      OrderType_HK;        //�۹ɶ�������
    double   StopPrice;           //ֹ���޼�
    int      OrderStatus;         //�걨���
    char     WithdrawFlag[4];     //������־
} ITPDK_WTLS;
//�ʽ���ˮ
typedef struct
{
    int64   SerialNo;           //��ˮ��
    char    AccountId[16];      //�ͻ���
    char    FundAccount[16];    //�ʽ��˺�
    char    MoneyType[4];       //����
    int     OccurDate;          //��������
    int     FrozenType;         //�������
    double  FrozenBalance;      //������
    char    ApplyTime[13];      //����ʱ��
    char    Summary[256];       //ժҪ
    int64   BrowIndex;          //��ʼ��¼����ֵ
} ITPDK_ZJLS;
//��̨�ʽ���ˮ
typedef struct
{
    char    AccountId[16];      //�ͻ���
    char    FundAccount[16];    //�ʽ��˺�
    char    MoneyType[5];       //����
    int     OccurDate;          //��������
    char    ApplyTime[13];      //����ʱ��
    int     FrozenType;         //�������
    double  FrozenBalance;      //������
    char    Summary[128];       //ժҪ
    char    BrowIndex[25];      //��ҳ��ѯ��λ��
} ITPDK_GTZJLS;
//��ǩ�ɿ�
typedef struct
{
    char     AccountId[16];       //�ͻ���
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     SecuAccount[12];     //�ɶ���
    char     StockName[31];       //֤ȯ����
    int      LuckyQty;            //��ǩ����
    double   IssuePrice;          //���м۸�
    int      PaymentQty;          //��Ԥ�ɿ�����
    int      PaymentQtyAvl;       //�ɲ��ɿ�����
    int      T3_PaymentQty;       //T+3��Ч��������
    int      T3_CancelQty;        //T+3ȷ�Ϸ�������
} ITPDK_ZQJK;

/////////////////////////////�ӿڳ���νṹ/////////////////////////////
//�ӿ����� - �ͻ���Ϣ
struct ITPDK_CusReqInfo
{
    char     AccountId[16];       //�ͻ���
    char     SecuAccount[12];     //�ɶ���
    char     Password[40];        //��������
    int      TradeNodeID;         //���׽ڵ�
    char     EntrustWay[10];       //ί�з�ʽ
    char     NodeInfo[256];       //����վ��
    char     DevelCode[7];        //�����̴���
    int64    Token;               //��¼����

    int64    RetCode;             //����ֵ
    char     ErrMsg[256];         //������Ϣ
    char     sKZLSH[9];           //��չ��ˮ��
    ITPDK_CusReqInfo()
        :AccountId{ 0 }
        , SecuAccount{ 0 }
        , Password{ 0 }
        , TradeNodeID(-1)
        , EntrustWay{ 0 }
        , NodeInfo{ 0 }
        , DevelCode{ 0 }
        , Token(-1)
        , RetCode(0)
        , ErrMsg{ 0 }
        , sKZLSH{ 0 }
    {
    }
};
//�ͻ��ڵ���Ϣ
struct ITPDK_KHJD
{
    char     AccountId[16];       //�ͻ���
    int      SystemType;          //ϵͳ����
    char     Market[4];           //������
    int      NodeID;              //�ڵ���
};
//��ͨ��������ί��
struct BatchOrderInfo
{
    char    Jys[3];     //������
    char    Zqdm[7];    //֤ȯ����
    int     Jylb;       //�������(JYLB_BUY��JYLB_SALE)
    double  Wtjg;       //ί�м۸�
    int64   Wtsl;       //ί������
    int     Ddlx;       //��������(DDLX_XJWT,DDLX_SJWT)
    char    Gdh[11];

    //����Ϊ������������ֶ�
    int64   Wth;        //�ɹ�ʱΪί�к�>0��ʧ��ʱΪ������<=0
    char    Msg[128];   //ʧ����Ϣ
};

//ETF���ӹ�����
struct ETFBasket
{
    int64   Wth;           //�ɹ�ʱΪί�к�>0��ʧ��ʱΪ������<=0
    char    Cfgdm[10];     //�ɷֹɴ���
    char    Jys[3];        //������
    int64   Wtsl;          //ί������
    char    Msg[128];      //ʧ����Ϣ
};

//����Ȩ����Ϣ
struct ITPDK_PSQYInfo
{
    char    AccountId[16];      //�ͻ���
    char    Market[4];          //������
    char    SecuAccount[12];    //�ɶ���
    int64   BallotQty;          //�¹ɶ��
    int64   StartQty;           //�ƴ�����
};

//һ������-����������Ϣ
struct ITPDK_ZJHBCL
{
    char    AccountId[16];     //�ͻ���
    char    FundAccount[16];   //�ʽ��˺�
    char    MoneyType[4];      //����
    int64   NodeId;            //�ڵ���
    char    Market[4];         //������
    double  Rate;              //����
};

//һ������-�ڵ���ʽ𻮲���ϸ
struct ITPDK_JDJZJHBMX
{
    char    AccountId[16];      //�ͻ���
    char    FundAccount[16];    //�ʽ��˺�
    char    MoneyType[4];       //����
    int     NodeId1;            //�����ڵ�
    int     NodeId2;            //����ڵ�
    int     TradeDate;          //��������
    int     TransDate;          //��������
    char    ApplyTime[13];      //����ʱ��
    double  OccurAmt;           //�������
    char    Summary[128];       //ժҪ
    char    BrowIndex[25];      //��ҳ��ѯ��λ��
};


#pragma pack(pop)

