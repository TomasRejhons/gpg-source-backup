#ifndef _NETWORK_MANAGER_H_
#define _NETWORK_MANAGER_H_

#include "NetworkProtocol.h"

enum ENetState
{
	NET_STATE_IDLE = 0,
	NET_STATE_CONNECTED,
	NET_STATE_CONNECTING,
	NET_STATE_BROWSING,
	NET_STATE_BROWSING_COMPLETE,
};

struct ServerInfo
{
	struct sockaddr_in address;
	unsigned short nNumPlayers;
	char	szGameDesc[17];
};
typedef std::list<ServerInfo*> ServerInfoList;

class t_Connection
{
public:
	t_Connection():
	  lastJoinPacketSent(0.0f),
	  timeDeltaCounter(0.0f),
	  lastHeartbeatSent(0.0f),
	  heartbeatcount(0),
	  reliableSequenceNumber(0)
	{

		memset(&address, 0, sizeof(struct sockaddr_in));
	}

	struct sockaddr_in		address;
	float					lastJoinPacketSent;
	float					timeDeltaCounter;
	float					lastHeartbeatSent;
	int						heartbeatcount;
	unsigned long			reliableSequenceNumber;
	PacketQueue				reliableIncomingPackets;
};

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	bool				Init();
	bool				Term();
	bool				InitSocket();
	bool				CloseSocket();
	void				Update(float fTimeDelta);
	bool				Connect(const char* szAddress, unsigned short port);
	bool				Connect(const struct sockaddr_in &address);
	bool				BrowseLAN();
	bool				UpdateBrowseLAN(float fTimeDelta);
	ENetState			GetState() { return m_eState; }
	bool				QueueMessageToServer(t_GameMessage* pMessage);

protected:

	bool				HandleJoinResponse(t_AddressedPacket& packet);
	bool				HandleHeartbeat(t_AddressedPacket& packet);
	bool				HandleGameData(t_AddressedPacket& packet);
	bool				HandleBrowseResponse(t_AddressedPacket& packet);

	bool				HandleIncomingPacket();
	bool				QueuePacket(t_AddressedPacket* packet);
	bool				FlushOutgoingPackets();
	unsigned long		ChecksumPacket(const t_Packet &packet);

	bool				ValidatePacket(t_AddressedPacket& packet, int nSize);
	bool				ValidateAddress(const struct sockaddr_in &address);

	unsigned long		CreateChecksum(const unsigned char* pBuffer, unsigned int nSize);
	bool				ChecksumPacket(t_Packet* packet);
	bool				ValidateChecksum(t_Packet* packet);

	bool				UpdateConnection(float fTimeDelta);
	t_AddressedPacket*	CreatePacket();

	ENetState			m_eState;
	SOCKET				m_Socket;
	t_Connection		m_Connection;
	PacketQueue			m_OutgoingPacketQueue;
	PacketQueue			m_PacketFreeList;
	float				m_fBrowseTime;
	ServerInfoList		m_ServerInfoList;
};

#endif
