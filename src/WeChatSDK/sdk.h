#pragma once
typedef int(*PFNRECVTEXTMSG_CALLBACK)(int pid, wchar_t* wxid, wchar_t* msg);
typedef int(*PFNRECVMONEYMSG_CALLBACK)(int pid, wchar_t* wxid, wchar_t* tid, wchar_t* msg);

// ����΢�ţ�֧�ֶ࿪������ֵ��΢�Ž���pid���豣�����ں����ӿڵ��á�pid������࿪��ÿ��΢�Ž��̣�ָ��pid���ýӿ�ʹ�ò�����Ӧ��΢�š�** ע�⣺�ýӿ���Ҫ����ԱȨ�ޡ�**
int WXOpenWechat();
// ���΢���Ƿ������ɹ���pid��WXOpenWechat����ֵ������trueΪ�ɹ���
bool WXIsWechatAlive(DWORD pid);

// ��ʼ��WeChatSDK���ڵ��������ӿ�֮ǰ��Ҫ���ô˽ӿڣ�����SDK�޷�����������pid��WXOpenWechat����ֵ������0��ʾ�ɹ��������漰��ע�빦�ܣ�������ɱ������󱨣���ͨ����
int WXInitialize(DWORD pid);
// ����ʼ��WeChatSDK��ж��SDK��һ�㲻��Ҫ���á�pid��WXOpenWechat����ֵ������0��ʾ�ɹ���
int WXUninitialize(DWORD pid);
// ����ʼ��WeChatSDK�Ƿ�ɹ����ڼ�鵽�ɹ�֮����ܵ��������ӿڣ�����SDK�޷�����������pid��WXOpenWechat����ֵ������true��ʾ�ɹ���
bool WXIsWechatSDKOk(DWORD pid);

// ��������Ϣ�������ܡ�pid��WXOpenWechat����ֵ������0��ʾ�ɹ�����1.3.0�汾�и���ʵ�ַ�ʽ�����ӳ�����ʾ����ֹ����ĳЩ����Ԥ�������
int WXAntiRevokeMsg(DWORD pid);
// �رշ���Ϣ�������ܡ�pid��WXOpenWechat����ֵ������0��ʾ�ɹ���
int WXUnAntiRevokeMsg(DWORD pid);
// ���������������ܡ�pid��WXOpenWechat����ֵ��pathָ����������λ�õ�Ŀ¼ȫ·��������0��ʾ�ɹ���
int WXSaveVoiceMsg(DWORD pid, const wchar_t* path);
// �رձ����������ܡ�pid��WXOpenWechat����ֵ������0��ʾ�ɹ���
int WXUnSaveVoiceMsg(DWORD pid);

// ����������Ϣ�ӿڣ�֧�ֱ���[x]��pid��WXOpenWechat����ֵ��wxidָ��Ҫ���Ͷ����wxid��msgָ��Ҫ�������ݡ�����0��ʾ�ɹ����������ṩͨ��΢�������ǳƻ�ȡwxid�ӿڡ�
int WXSendTextMsg(DWORD pid, const wchar_t* wxid, const wchar_t* msg);
// ͨ��wxid�ҵ��Ѿ��򿪵�΢�ŵ�pid��ʵ�ֲ�������������ʹ�á�
int WXSendImageMsg(DWORD pid, const wchar_t* wxid, const wchar_t* path);
// ���ý���������Ϣ�Ļص��������ڻص����������д�����Ϣ��pid��WXOpenWechat����ֵ��funptr�ǻص�������PFNRECVTEXTMSG_CALLBACK�ǻص��ӿ�������
int WXRecvTextMsg(DWORD pid, PFNRECVTEXTMSG_CALLBACK funptr);

int WXGetWechat(const wchar_t* wxid);
int WXGetWechatVersion(wchar_t* version);
int WXRecvTransferMsg(DWORD pid, PFNRECVMONEYMSG_CALLBACK funptr);
// ����֧����ػص��ӿڡ�
int WXRecvPayMsg(DWORD pid, PFNRECVMONEYMSG_CALLBACK funptr);

//void WXSendGroupTextMsg(); //�ݲ�֧��
//void WXSendImageMsg(); //�ݲ�֧��
//void WXSendVoiceMsg(); //�ݲ�֧��
//void WXAddFriend(); //�ݲ�֧��
//void WXAddGroupFriends(); //�ݲ�֧��
//void WXAcceptFriend(); //�ݲ�֧��
//void WXDeleteFriend(); //�ݲ�֧��
//void WXGetUserWxid(); //�ݲ�֧��