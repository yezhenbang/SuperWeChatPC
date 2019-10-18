#pragma once
typedef int(*PFNRECVTEXTMSG_CALLBACK)(int pid, wchar_t* wxid, wchar_t* msg);
typedef int(*PFNRECVMONEYMSG_CALLBACK)(int pid, wchar_t* wxid, wchar_t* tid, wchar_t* msg);

// 启动微信，支持多开。返回值是微信进程pid，需保存用于后续接口调用。pid即代表多开的每个微信进程，指定pid调用接口使用操作对应的微信。** 注意：该接口需要管理员权限。**
int WXOpenWechat();
// 检查微信是否启动成功，pid是WXOpenWechat返回值。返回true为成功。
bool WXIsWechatAlive(DWORD pid);

// 初始化WeChatSDK。在调用其他接口之前需要调用此接口，否则SDK无法正常工作。pid是WXOpenWechat返回值。返回0表示成功。由于涉及到注入功能，如引起杀毒软件误报，请通过。
int WXInitialize(DWORD pid);
// 反初始化WeChatSDK，卸载SDK，一般不需要调用。pid是WXOpenWechat返回值。返回0表示成功。
int WXUninitialize(DWORD pid);
// 检查初始化WeChatSDK是否成功。在检查到成功之后才能调用其他接口，否则SDK无法正常工作。pid是WXOpenWechat返回值。返回true表示成功。
bool WXIsWechatSDKOk(DWORD pid);

// 开启防消息撤销功能。pid是WXOpenWechat返回值。返回0表示成功。在1.3.0版本中更换实现方式，增加撤销提示，防止出现某些不可预见情况。
int WXAntiRevokeMsg(DWORD pid);
// 关闭防消息撤销功能。pid是WXOpenWechat返回值。返回0表示成功。
int WXUnAntiRevokeMsg(DWORD pid);
// 开启备份语音功能。pid是WXOpenWechat返回值，path指定语音备份位置的目录全路径。返回0表示成功。
int WXSaveVoiceMsg(DWORD pid, const wchar_t* path);
// 关闭备份语音功能。pid是WXOpenWechat返回值。返回0表示成功。
int WXUnSaveVoiceMsg(DWORD pid);

// 发送文字消息接口，支持表情[x]。pid是WXOpenWechat返回值，wxid指定要发送对象的wxid，msg指定要发送内容。返回0表示成功。后续会提供通过微信名或昵称获取wxid接口。
int WXSendTextMsg(DWORD pid, const wchar_t* wxid, const wchar_t* msg);
// 通过wxid找到已经打开的微信的pid，实现不完整，不建议使用。
int WXSendImageMsg(DWORD pid, const wchar_t* wxid, const wchar_t* path);
// 设置接受文字消息的回调函数，在回调函数中自行处理消息。pid是WXOpenWechat返回值，funptr是回调函数，PFNRECVTEXTMSG_CALLBACK是回调接口声明。
int WXRecvTextMsg(DWORD pid, PFNRECVTEXTMSG_CALLBACK funptr);

int WXGetWechat(const wchar_t* wxid);
int WXGetWechatVersion(wchar_t* version);
int WXRecvTransferMsg(DWORD pid, PFNRECVMONEYMSG_CALLBACK funptr);
// 设置支付相关回调接口。
int WXRecvPayMsg(DWORD pid, PFNRECVMONEYMSG_CALLBACK funptr);

//void WXSendGroupTextMsg(); //暂不支持
//void WXSendImageMsg(); //暂不支持
//void WXSendVoiceMsg(); //暂不支持
//void WXAddFriend(); //暂不支持
//void WXAddGroupFriends(); //暂不支持
//void WXAcceptFriend(); //暂不支持
//void WXDeleteFriend(); //暂不支持
//void WXGetUserWxid(); //暂不支持