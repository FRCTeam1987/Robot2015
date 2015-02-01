/*
 * LiveCANTalon.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: LAPSTATION0
 */

#include "LiveCANTalon.h"

LiveCANTalon::LiveCANTalon(int DeviceNumber) : CANTalon(DeviceNumber) {
	// TODO Auto-generated constructor stub
	m_table = NULL;
}

LiveCANTalon::~LiveCANTalon() {
	// TODO Auto-generated destructor stub
}

void LiveCANTalon::UpdateTable()
{
	if(m_table)
		m_table->PutNumber("Value", Get());
}

void LiveCANTalon::StartLiveWindowMode()
{
	if(m_table)
		m_table->AddTableListener(this);
}

void LiveCANTalon::StopLiveWindowMode()
{
	if(m_table)
		m_table->RemoveTableListener(this);
}

void LiveCANTalon::InitTable(ITable *subtable)
{
	m_table = subtable;
	UpdateTable();
}

void LiveCANTalon::ValueChanged(ITable *source, const std::string& key, EntryValue value, bool isNew)
{
	Set(value.f);
}


