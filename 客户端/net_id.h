//通信ID1

#define LOG_IN			0xfa	//登陆
#define REGISTER		0xfb	//注册
#define LOG_SUCCEED		0xea	//登陆成功
#define LOG_FAIL		0xeb	//登陆失败
#define LOG_TIME_OUT	0xbd	//登陆超时
#define CONNECT_BREAK	0xbe	//断开连接
#define TRANS_MESSAGE	0xcc	//传递信息
#define REGISTER_RETURN 0xfc	//注册反馈
#define COMMEND			0xfd	//命令消息
#define CHANGENUMM		0xfe	//改密码
#define CHANGESUCCEED	0xff	//改密成功
#define CHANGEFAIL		0xaa	//改密失败
#define SEARCHFRIEND	0xab	//查找好友
#define FRIENDEXIT		0xac	//好友存在
#define FRIENDNULL		0xad	//好友不存在
#define CM_AGREE		5562	//验证通过
#define CM_REFUSE		5563	//验证拒绝
//通信ID2
#define GENERALMSG		0xae	//一般消息
#define CHECKMSG		0xaf	//验证消息
#define SYSMSG			5561	//系统消息
//通信ID3
//#define PERSONALMSG		5564	//个人信息
//通信ID3
#define LOCALMSG		5564	//个人消息
#define FRDMSG			5565	//好友信息


/***通信协议***/
struct packet
{
	char commend;
	union
	{
		struct param1
		{
			int		ID;
			int		len;
			char	num_z[10];
			char	num_m[16];
			char	num_mm[16];
			char	*add;
		}info1;

		struct param2
		{
			int	 ID;
			tm	 t;
			char name[16];
			char num_z[10];			//要发送的目标
			char text[512];			//发送的信息
			char num_z1[10];		//发送者账号
		}info2;

		struct param3
		{
			int ID;
			char num_z[10];
			char name[16];
			char tel[12];
			int  sex;
			int  age;
		}info3;
	}upacket;
};




//其他ID
#define ID_NUMCTRL                      40009
#define ID_PMSG                         40010
#define ID_CHANGENUM_M                  40011
#define ID_QUIT                         40012
#define ID_40013                        40013
#define ID_40014                        40014
#define ID_40015                        40015
#define ID_CHAT                         40016
#define ID_ADD_FRD                      40017