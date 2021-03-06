#ifndef _NETWORK_MANAGER_H_
#define _NETWORK_MANAGER_H_

#include "NetworkConnection.h"

enum ENetState
{
	NET_STATE_IDLE = 0,
	NET_STATE_CONNECTED,
	NET_STATE_CONNECTING,
	NET_STATE_LISTENING,
};

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	bool Init();
	bool Term();
	void Update(float fTimeDelta);
	bool Connect(const char* szAddress, unsigned short port);
	bool Listen(unsigned short port);
	ENetState GetState() { return m_eState; }
	bool QueueGameMessageForConnection(unsigned long nID, t_GameMessage* pMessage, unsigned long nFlags = 0);

protected:

	bool ValidateAddress(struct sockaddr_in *pAddress);
	bool ValidatePacket(t_AddressedPacket* packet, int nSize);

	unsigned long CreateChecksum(const unsigned char* pBuffer, unsigned int nSize);
	bool ChecksumPacket(t_Packet* packet);
	bool ValidateChecksum(t_Packet* packet);

	bool IsPendingConnection(struct sockaddr_in *pAddress);
	bool IsFullyConnected(struct sockaddr_in *pAddress);
	CConnection* FindPendingConnection(struct sockaddr_in *pAddress);
	bool RemovePendingConnection(CConnection* pConnection);
	CConnection* FindConnection(struct sockaddr_in *pAddress);
	bool RemoveConnection(CConnection* pConnection);

	bool UpdateConnections(float fTimeDelta);
	bool UpdatePendingConnections(float fTimeDelta);
	bool HandleIncomingPacket();

	bool HandleOOBPacket(t_AddressedPacket* pPacket);
	bool HandlePacket(t_AddressedPacket* pPacket);

	bool HandleHeartbeat(t_AddressedPacket* pPacket);
	bool HandleGameData(t_AddressedPacket* pPacket);
	bool HandleReliableAck(t_AddressedPacket* pPacket);
	bool HandleBrowse(t_AddressedPacket* pPacket);

	bool QueuePacket(t_AddressedPacket* pPacket);
	bool UpdateReliableOutgoingPackets(float fDeltaTime);
	bool FlushOutgoingPackets();
	t_AddressedPacket*	CreatePacket();

	ENetState			m_eState;
	SOCKET				m_hSocket;
	unsigned long		m_nCurrentConnectionID; //unique ID for connections.
	ConnectionList		m_ConnectionList;

	//This is a list of connections that are currently in join arbitration
	ConnectionList		m_ConnectionPendingList;

	//
	PacketQueue			m_OutgoingPackets;

	PacketQueue			m_PacketFreeList;
};

#endif