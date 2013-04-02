#pragma once

class CMagicType3Set : public OdbcRecordset
{
public:
	CMagicType3Set(OdbcConnection * dbConnection, Magictype3Array * pMap) 
		: OdbcRecordset(dbConnection), m_pMap(pMap) {}

	virtual tstring GetTableName() { return _T("MAGIC_TYPE3"); }
	virtual tstring GetColumns() { return _T("iNum, DirectType, FirstDamage, EndDamage, TimeDamage, Duration, Attribute, Radius, Angle"); }

	virtual bool Fetch()
	{
		_MAGIC_TYPE3 *pData = new _MAGIC_TYPE3;

		_dbCommand->FetchUInt32(1, pData->iNum);
		_dbCommand->FetchByte(2, pData->bDirectType);
		_dbCommand->FetchUInt16(3, pData->sFirstDamage);
		_dbCommand->FetchUInt16(4, pData->sEndDamage);
		_dbCommand->FetchUInt16(5, pData->sTimeDamage);
		_dbCommand->FetchByte(6, pData->bRadius);
		_dbCommand->FetchByte(7, pData->bDuration);
		_dbCommand->FetchByte(8, pData->bAttribute);

		if (!m_pMap->PutData(pData->iNum, pData))
			delete pData;

		return true;
	}

	Magictype3Array *m_pMap;
};