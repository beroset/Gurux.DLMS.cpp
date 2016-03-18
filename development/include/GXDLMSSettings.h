//
// --------------------------------------------------------------------------
//  Gurux Ltd
//
//
//
// Filename:        $HeadURL$
//
// Version:         $Revision$,
//                  $Date$
//                  $Author$
//
// Copyright (c) Gurux Ltd
//
//---------------------------------------------------------------------------
//
//  DESCRIPTION
//
// This file is a part of Gurux Device Framework.
//
// Gurux Device Framework is Open Source software; you can redistribute it
// and/or modify it under the terms of the GNU General License
// as published by the Free Software Foundation; version 2 of the License.
// Gurux Device Framework is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General License for more details.
//
// More information of Gurux products: http://www.gurux.org
//
// This code is licensed under the GNU General License v2.
// Full text may be retrieved at http://www.gnu.org/licenses/gpl-2.0.txt
//---------------------------------------------------------------------------

#ifndef GXDLMSSETTINGS_H
#define GXDLMSSETTINGS_H

#include "enums.h"
#include "GXBytebuffer.h"
#include "GXDLMSLNSettings.h"
#include "GXDLMSSNSettings.h"
#include "GXDLMSLimits.h"
#include "GXDLMSObjectCollection.h"

// Server sender frame sequence starting number.
const unsigned char SERVER_START_SENDER_FRAME_SEQUENCE = 0x1E;

// Server receiver frame sequence starting number.
const unsigned char SERVER_START_RECEIVER_FRAME_SEQUENCE = 0xFE;

// Client sender frame sequence starting number.
const unsigned char CLIENT_START_SENDER_FRAME_SEQUENCE = 0x10;

// Client receiver frame sequence starting number.
const unsigned char CLIENT_START_RCEIVER_FRAME_SEQUENCE = 0xE;
// DLMS version number.
const unsigned char DLMS_VERSION = 6;

const unsigned short MAX_RECEIVE_PDU_SIZE = 0xFFFF;

// This class includes DLMS communication Settings.
class CGXDLMSSettings
{
    //Is connection made for the server.
    bool m_Connected;

    // Is custom challenges used. If custom challenge is used new challenge is
    // not generated if it is Set. This is for debugging purposes.
    bool m_CustomChallenges;

    // Client to server challenge.
    CGXByteBuffer m_CtoSChallenge;

    // Server to Client challenge.
    CGXByteBuffer m_StoCChallenge;

    // Invoke ID.
    int m_InvokeID;

    // Priority.
    GXDLMS_PRIORITY m_Priority;

    // Service class.
    GXDLMS_SERVICECLASS m_ServiceClass;

    // Client address.
    int m_ClientAddress;

    // Server address.
    int m_ServerAddress;

    // Is Logical Name referencing used.
    bool m_UseLogicalNameReferencing;

    // Interface type.
    GXDLMS_INTERFACETYPE m_InterfaceType;

    // User authentication.
    GXDLMS_AUTHENTICATION m_Authentication;

    // User password.
    CGXByteBuffer m_Password;

    // DLMS version number.
    unsigned char m_DlmsVersionNumber;

    // Maximum receivers PDU size.
    unsigned short m_MaxReceivePDUSize;

    // HDLC sender frame sequence number.
    unsigned char m_SenderFrame;

    // HDLC receiver block sequence number.
    unsigned char m_ReceiverFrame;

    // Is this server or client.
    bool m_Server;

    // Information from the connection size that server can handle.
    CGXDLMSLimits m_Limits;

    // Logical name Settings.
    CGXDLMSLNSettings m_LNSettings;

    // Short name Settings.
    CGXDLMSSNSettings m_SNSettings;

    // Block packet index.
    unsigned long m_BlockIndex;

    // List of server or client objects.
    CGXDLMSObjectCollection m_Objects;

public:
// Constructor.
    CGXDLMSSettings(bool isServer);

// Client to Server challenge.
    CGXByteBuffer& GetCtoSChallenge();

// Client to Server challenge.
    void SetCtoSChallenge(CGXByteBuffer value);

// Get server to Client challenge.
    CGXByteBuffer& GetStoCChallenge();

// Set server to Client challenge.
    void SetStoCChallenge(CGXByteBuffer value);

// Gets used authentication.
    GXDLMS_AUTHENTICATION GetAuthentication();

//Sets Used authentication.
    void SetAuthentication(GXDLMS_AUTHENTICATION value);

//Gets password.
    CGXByteBuffer& GetPassword();

// Sets password.
    void SetPassword(CGXByteBuffer value);

// Used DLMS version number.
    unsigned char GetDlmsVersionNumber();

// Used DLMS version number.
    void SetDlmsVersionNumber(unsigned char value);

// Reset frame sequence.
    void ResetFrameSequence();

    bool CheckFrame(unsigned char frame);

// Generates I-frame.
    unsigned char GetNextSend();

// Generates Receiver Ready S-frame.
    unsigned char GetReceiverReady();

// Generates Keep Alive S-frame.
    unsigned char GetKeepAlive();

// Gets Logical Name Settings.
    CGXDLMSLNSettings& GetLnSettings();

// Short name Settings.
    CGXDLMSSNSettings GetSnSettings();

// Gets current block index.
    unsigned long GetBlockIndex();

// Sets current block index.
    void SetBlockIndex(unsigned long value);

// Resets block index to default value.
    void ResetBlockIndex();

// Increases block index.
    void IncreaseBlockIndex();

    //Is acting as server or client.
    bool IsServer();

    // Information from the frame size that server can handle.
    CGXDLMSLimits& GetLimits();

// Used interface.
    GXDLMS_INTERFACETYPE GetInterfaceType();

// Used interface.
    void SetInterfaceType(GXDLMS_INTERFACETYPE value);

// Gets client address.
    int GetClientAddress();

// Sets client address.
    void SetClientAddress(int value);

// Server address.
    int GetServerAddress();

// Server address.
    void SetServerAddress(int value);

// DLMS version number.
    unsigned char GetDLMSVersion();

// DLMS version number.
    void SetDLMSVersion(unsigned char value);

// Maximum PDU size.
    int GetMaxReceivePDUSize();

// Maximum PDU size.
    void SetMaxReceivePDUSize(int value);

// Is Logical Name Referencing used.
    bool GetUseLogicalNameReferencing();

// Is Logical Name Referencing used.
    void SetUseLogicalNameReferencing(bool value);

// Used priority.
    GXDLMS_PRIORITY GetPriority();

// Used priority.
    void SetPriority(GXDLMS_PRIORITY value);

// Used service class.
    GXDLMS_SERVICECLASS GetServiceClass();

// Used service class.
    void SetServiceClass(GXDLMS_SERVICECLASS value);

// Invoke ID.
    int GetInvokeID();

// Invoke ID.
    void SetInvokeID(int value);

// Collection of the objects.
    CGXDLMSObjectCollection& GetObjects();

// Get Is custom challenges used.
    bool IsCustomChallenges();

// Set is custom challenges used.
    void SetCustomChallenges(bool value);

//Get is connection made for the server.
    bool IsConnected();

//Set is connection made for the server.
    void SetConnected(bool value);
};

#endif //GXDLMSSETTINGS_H
