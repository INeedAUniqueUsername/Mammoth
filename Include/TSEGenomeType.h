//	TSEGenomeType.h
//
//	Classes and functions for sovereigns.
//	Copyright (c) 2018 Kronosaur Productions, LLC. All Rights Reserved.

#pragma once

class CGenomeType : public CDesignType
	{
	public:

		CGenomeType (void);
		~CGenomeType (void);

		//	CDesignType overrides
		static CGenomeType *AsType (CDesignType *pType) { return ((pType && pType->GetType() == designGenomeType) ? (CGenomeType *)pType : NULL); }
		virtual DesignTypes GetType (void) const override { return designSovereign; }

		CString GetName (void) { return m_sName; }
		CString GetSpecies (void) { return m_sSpecies; }
		CString GetGender (void) { return m_sGender; }
		CString GetSubject (void) { return m_sSubject; }
		CString GetDeterminer (void) { return m_sDeterminer; }
		CString GetPossessive (void) { return m_sPossessive; }
		CString GetObject (void) { return m_sObject; }
		CString GetAddress (void) { return m_sAddress; }
		CString GetPerson (void) { return m_sPerson; }
		CString GetSibling (void) { return m_sSibling; }
		CString GetChild (void) { return m_sChild; }

	protected:
		//	CDesignType overrides
		virtual ALERROR OnBindDesign (SDesignLoadCtx &Ctx) override;
		virtual ALERROR OnCreateFromXML (SDesignLoadCtx &Ctx, CXMLElement *pDesc) override;
		virtual ICCItem *OnGetProperty (CCodeChainCtx &Ctx, const CString &sProperty) const override;

	private:
		CString m_sName;							//		humanMale, humanFemale, etc
		CString m_sSpecies;							//		Human, etc
		CString m_sGender;							//		male, female, etc
		CString m_sSubject;							//		%he%				he, she, etc (matching case)
		CString m_sDeterminer;						//		%his%				his, her, etc (matching case)
		CString m_sPossessive;						//		%hers%				his, her, etc (matching case)
		CString m_sObject;							//		%him%				him, her, etc (matching case)
		CString m_sAddress;							//		%sir%				sir, ma'am, etc (matching case)
		CString m_sPerson;							//		%man%				man, woman, etc (matching case)
		CString m_sSibling;							//		%brother%			brother, sister, etc (matching case)
		CString m_sChild;							//		%son%				son, daughter, etc (matching case)
	};

