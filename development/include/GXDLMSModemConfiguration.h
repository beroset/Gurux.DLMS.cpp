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
// and/or modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; version 2 of the License.
// Gurux Device Framework is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// More information of Gurux products: http://www.gurux.org
//
// This code is licensed under the GNU General Public License v2.
// Full text may be retrieved at http://www.gnu.org/licenses/gpl-2.0.txt
//---------------------------------------------------------------------------

#ifndef GXDLMSMODEMCONFIGURATION_H
#define GXDLMSMODEMCONFIGURATION_H

#include "GXDLMSObject.h"
#include "GXDLMSModemInitialisation.h"

class CGXDLMSModemConfiguration : public CGXDLMSObject
{
    std::vector<CGXDLMSModemInitialisation> m_InitialisationStrings;
    std::vector< std::string > m_ModemProfile;
    BAUDRATE m_CommunicationSpeed;

    void Init();
public:

    /**
     Constructor.
    */
    CGXDLMSModemConfiguration();
    /**
     Constructor.
     @param ln Logical Name of the object.
    */
    CGXDLMSModemConfiguration(std::string ln);

    /**
     Constructor.
     @param ln Logical Name of the object.
     @param sn Short Name of the object.
    */
    CGXDLMSModemConfiguration(int sn);

    BAUDRATE GetCommunicationSpeed();

    void SetCommunicationSpeed(BAUDRATE value);

    std::vector<CGXDLMSModemInitialisation>& GetInitialisationStrings();
    void SetInitialisationStrings(std::vector<CGXDLMSModemInitialisation>& value);

    std::vector< std::string > GetModemProfile();
    void SetModemProfile(std::vector< std::string >& value);

    // Returns amount of attributes.
    int GetAttributeCount();

    // Returns amount of methods.
    int GetMethodCount();

    //Get attribute values of object.
    void GetValues(std::vector<std::string>& values);

    void GetAttributeIndexToRead(std::vector<int>& attributes);

    int GetDataType(int index, DLMS_DATA_TYPE& type);

    // Returns value of given attribute.
    int GetValue(int index, int selector, CGXDLMSVariant& parameters, CGXDLMSVariant& value);

    // Set value of given attribute.
    int SetValue(CGXDLMSSettings* settings, int index, CGXDLMSVariant& value);
};
#endif //GXDLMSMODEMCONFIGURATION_H