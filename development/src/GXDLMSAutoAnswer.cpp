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

#include "../include/GXDLMSVariant.h"
#include "../include/GXDLMSClient.h"
#include "../include/GXDLMSAutoAnswer.h"
#include <sstream>

void CGXDLMSAutoAnswer::Init()
{
    m_NumberOfRingsInListeningWindow = m_NumberOfRingsOutListeningWindow = 0;
    m_Mode = AUTO_CONNECT_MODE_NO_AUTO_DIALLING;
    m_Status = AUTO_ANSWER_STATUS_INACTIVE;
    m_NumberOfCalls = 0;
}

/**
 Constructor.
*/
CGXDLMSAutoAnswer::CGXDLMSAutoAnswer() : CGXDLMSObject(OBJECT_TYPE_AUTO_ANSWER, "0.0.2.2.0.255")
{
    Init();
}

/**
 Constructor.

 @param ln Logical Name of the object.
*/
CGXDLMSAutoAnswer::CGXDLMSAutoAnswer(std::string ln) : CGXDLMSObject(OBJECT_TYPE_AUTO_ANSWER, ln)
{
    Init();
}

/**
 Constructor.

 @param ln Logical Name of the object.
 @param sn Short Name of the object.
*/
CGXDLMSAutoAnswer::CGXDLMSAutoAnswer(int sn) : CGXDLMSObject(OBJECT_TYPE_AUTO_ANSWER, sn)
{
    Init();
}

AUTO_CONNECT_MODE CGXDLMSAutoAnswer::GetMode()
{
    return m_Mode;
}
void CGXDLMSAutoAnswer::SetMode(AUTO_CONNECT_MODE value)
{
    m_Mode = value;
}

std::vector<std::pair< CGXDateTime, CGXDateTime> >& CGXDLMSAutoAnswer::GetListeningWindow()
{
    return m_ListeningWindow;
}
void CGXDLMSAutoAnswer::SetListeningWindow(std::vector<std::pair< CGXDateTime, CGXDateTime> >& value)
{
    m_ListeningWindow = value;
}

AUTO_ANSWER_STATUS CGXDLMSAutoAnswer::GetStatus()
{
    return m_Status;
}
void CGXDLMSAutoAnswer::SetStatus(AUTO_ANSWER_STATUS value)
{
    m_Status = value;
}

int CGXDLMSAutoAnswer::GetNumberOfCalls()
{
    return m_NumberOfCalls;
}
void CGXDLMSAutoAnswer::SetNumberOfCalls(int value)
{
    m_NumberOfCalls = value;
}

// Number of rings within the window defined by ListeningWindow.
int CGXDLMSAutoAnswer::GetNumberOfRingsInListeningWindow()
{
    return m_NumberOfRingsInListeningWindow;
}
void CGXDLMSAutoAnswer::SetNumberOfRingsInListeningWindow(int value)
{
    m_NumberOfRingsInListeningWindow = value;
}

//Number of rings outside the window defined by ListeningWindow.
int CGXDLMSAutoAnswer::GetNumberOfRingsOutListeningWindow()
{
    return m_NumberOfRingsOutListeningWindow;
}
void CGXDLMSAutoAnswer::SetNumberOfRingsOutListeningWindow(int value)
{
    m_NumberOfRingsOutListeningWindow = value;
}

// Returns amount of attributes.
int CGXDLMSAutoAnswer::GetAttributeCount()
{
    return 6;
}

// Returns amount of methods.
int CGXDLMSAutoAnswer::GetMethodCount()
{
    return 0;
}

void CGXDLMSAutoAnswer::GetValues(std::vector<std::string>& values)
{
    values.clear();
    std::string ln;
    GetLogicalName(ln);
    values.push_back(ln);
    values.push_back(CGXDLMSVariant(m_Mode).ToString());
    std::stringstream sb;
    sb << '[';
    bool empty = true;
    for(std::vector<std::pair< CGXDateTime, CGXDateTime> >::iterator it = m_ListeningWindow.begin(); it != m_ListeningWindow.end(); ++it)
    {
        if (!empty)
        {
            sb << ", ";
        }
        empty = false;
        std::string str = it->first.ToString();
        sb.write(str.c_str(), str.size());
        sb << " ";
        str = it->second.ToString();
        sb.write(str.c_str(), str.size());
    }
    sb << ']';
    values.push_back(sb.str());
    values.push_back(CGXDLMSVariant(m_Status).ToString());
    values.push_back(CGXDLMSVariant(m_NumberOfCalls).ToString());
    //Clean
    sb.str(std::string());
    sb << m_NumberOfRingsInListeningWindow;
    sb << "/";
    sb << m_NumberOfRingsOutListeningWindow;
    values.push_back(sb.str());
}

void CGXDLMSAutoAnswer::GetAttributeIndexToRead(std::vector<int>& attributes)
{
    //LN is static and read only once.
    if (CGXDLMSObject::IsLogicalNameEmpty(m_LN))
    {
        attributes.push_back(1);
    }
    //Mode is static and read only once.
    if (!IsRead(2))
    {
        attributes.push_back(2);
    }
    //ListeningWindow is static and read only once.
    if (!IsRead(3))
    {
        attributes.push_back(3);
    }
    //Status is not static.
    if (CanRead(4))
    {
        attributes.push_back(4);
    }

    //NumberOfCalls is static and read only once.
    if (!IsRead(5))
    {
        attributes.push_back(5);
    }
    //NumberOfRingsInListeningWindow is static and read only once.
    if (!IsRead(6))
    {
        attributes.push_back(6);
    }
}

int CGXDLMSAutoAnswer::GetDataType(int index, DLMS_DATA_TYPE& type)
{
    if (index == 1)
    {
        type = DLMS_DATA_TYPE_OCTET_STRING;
        return ERROR_CODES_OK;
    }
    if (index == 2)
    {
        type = DLMS_DATA_TYPE_ENUM;
        return ERROR_CODES_OK;
    }
    if (index == 3)
    {
        type = DLMS_DATA_TYPE_ARRAY;
        return ERROR_CODES_OK;
    }
    if (index == 4)
    {
        type = DLMS_DATA_TYPE_ENUM;
        return ERROR_CODES_OK;
    }
    if (index == 5)
    {
        type = DLMS_DATA_TYPE_UINT8;
        return ERROR_CODES_OK;
    }
    if (index == 6)
    {
        type = DLMS_DATA_TYPE_ARRAY;
        return ERROR_CODES_OK;
    }
    return ERROR_CODES_INVALID_PARAMETER;
}

// Returns value of given attribute.
int CGXDLMSAutoAnswer::GetValue(int index, int selector, CGXDLMSVariant& parameters, CGXDLMSVariant& value)
{
    if (index == 1)
    {
        return GetLogicalName(this, value);
    }
    if (index == 2)
    {
        value = GetMode();
        return ERROR_CODES_OK;
    }
    if (index == 3)
    {
        int ret;
        int cnt = m_ListeningWindow.size();
        CGXByteBuffer data;
        data.SetUInt8(DLMS_DATA_TYPE_ARRAY);
        //Add count
        GXHelpers::SetObjectCount(cnt, data);
        CGXDLMSVariant f, s;
        for (std::vector<std::pair<CGXDateTime, CGXDateTime> >::iterator it =
                    m_ListeningWindow.begin(); it != m_ListeningWindow.end(); ++it)
        {
            data.SetUInt8(DLMS_DATA_TYPE_STRUCTURE);
            data.SetUInt8(2); //Count
            f = it->first;
            s = it->second;
            if ((ret = GXHelpers::SetData(data, DLMS_DATA_TYPE_OCTET_STRING, f)) != 0 || //start_time
                    (ret = GXHelpers::SetData(data, DLMS_DATA_TYPE_OCTET_STRING, s)) != 0) //end_time
            {
                return ret;
            }
        }
        value = data;
        return ERROR_CODES_OK;
    }
    if (index == 4)
    {
        value = GetStatus();
        return ERROR_CODES_OK;
    }
    if (index == 5)
    {
        value = GetNumberOfCalls();
        return ERROR_CODES_OK;
    }
    if (index == 6)
    {
        CGXByteBuffer data;
        data.SetUInt8(DLMS_DATA_TYPE_STRUCTURE);
        GXHelpers::SetObjectCount(2, data);
        CGXDLMSVariant in = m_NumberOfRingsInListeningWindow;
        CGXDLMSVariant out = m_NumberOfRingsOutListeningWindow;
        int ret;
        if ((ret = GXHelpers::SetData(data, DLMS_DATA_TYPE_UINT8, in)) != ERROR_CODES_OK ||
                (ret = GXHelpers::SetData(data, DLMS_DATA_TYPE_UINT8, out)) != ERROR_CODES_OK)
        {
            return ret;
        }
        value = data;
        return ERROR_CODES_OK;
    }
    return ERROR_CODES_INVALID_PARAMETER;
}

/*
 * Set value of given attribute.
 */
int CGXDLMSAutoAnswer::SetValue(CGXDLMSSettings* settings, int index, CGXDLMSVariant& value)
{
    if (index == 1)
    {
        return SetLogicalName(this, value);
    }
    if (index == 2)
    {
        SetMode((AUTO_CONNECT_MODE) value.lVal);
        return ERROR_CODES_OK;
    }
    if (index == 3)
    {
        m_ListeningWindow.clear();
        for (std::vector<CGXDLMSVariant>::iterator item = value.Arr.begin(); item != value.Arr.end(); ++item)
        {
            CGXDLMSVariant start, end;
            CGXDLMSClient::ChangeType((*item).Arr[0], DLMS_DATA_TYPE_DATETIME, start);
            CGXDLMSClient::ChangeType((*item).Arr[1], DLMS_DATA_TYPE_DATETIME, end);
            m_ListeningWindow.push_back(std::pair< CGXDateTime, CGXDateTime>(start.dateTime, end.dateTime));
        }
        return ERROR_CODES_OK;
    }
    if (index == 4)
    {
        SetStatus((AUTO_ANSWER_STATUS) value.lVal);
        return ERROR_CODES_OK;
    }
    if (index == 5)
    {
        SetNumberOfCalls(value.lVal);
        return ERROR_CODES_OK;
    }
    if (index == 6)
    {
        m_NumberOfRingsInListeningWindow = m_NumberOfRingsOutListeningWindow = 0;
        if (value.vt != DLMS_DATA_TYPE_NONE)
        {
            m_NumberOfRingsInListeningWindow = value.Arr[0].ToInteger();
            m_NumberOfRingsOutListeningWindow = value.Arr[1].ToInteger();
        }
        return ERROR_CODES_OK;
    }
    return ERROR_CODES_INVALID_PARAMETER;
}
