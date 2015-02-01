/*
 * LiveCANTalon.h
 *
 *  Created on: Jan 22, 2015
 *      Author: LAPSTATION0
 */

#ifndef LIVECANTALON_H_
#define LIVECANTALON_H_
#include <CANTalon.h>
#include "LiveWindow/LiveWindowSendable.h"

class LiveCANTalon : public CANTalon, public LiveWindowSendable, public ITableListener
{
public:
	LiveCANTalon(int DeviceNumber);
	virtual ~LiveCANTalon();

	virtual void UpdateTable();
	virtual void StartLiveWindowMode();
	virtual void StopLiveWindowMode();
	virtual void InitTable(ITable* subtable);
	virtual void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
	virtual std::string GetSmartDashboardType() { return "Speed Controller"; }
	ITable * GetTable() { return m_table; }

protected:
	ITable *m_table;
};

#endif /* LIVECANTALON_H_ */
