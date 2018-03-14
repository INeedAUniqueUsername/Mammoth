//	CGenomeType.cpp
//
//	CGenomeType class

#include "PreComp.h"

#define NAME_ATTRIB										CONSTLIT("name")
#define SPECIES_ATTRIB									CONSTLIT("species")
#define GENDER_ATTRIB									CONSTLIT("gender")
#define SUBJECT_ATTRIB									CONSTLIT("subject")
#define DETERMINER_ATTRIB								CONSTLIT("determiner")
#define POSSESSIVE_ATTRIB								CONSTLIT("possessive")
#define OBJECT_ATTRIB									CONSTLIT("object")
#define ADDRESS_ATTRIB									CONSTLIT("address")
#define PERSON_ATTRIB									CONSTLIT("person")
#define SIBLING_ATTRIB									CONSTLIT("sibling")
#define CHILD_ATTRIB									CONSTLIT("child")

#define PROPERTY_NAME									CONSTLIT("name")
#define PROPERTY_SPECIES								CONSTLIT("species")
#define PROPERTY_GENDER									CONSTLIT("gender")
#define PROPERTY_SUBJECT								CONSTLIT("subject")
#define PROPERTY_DETERMINER								CONSTLIT("determiner")
#define PROPERTY_POSSESSIVE								CONSTLIT("possessive")
#define PROPERTY_OBJECT									CONSTLIT("object")
#define PROPERTY_ADDRESS								CONSTLIT("address")
#define PROPERTY_PERSON									CONSTLIT("person")
#define PROPERTY_SIBLING								CONSTLIT("sibling")
#define PROPERTY_CHILD									CONSTLIT("child")

CGenomeType::CGenomeType (void)

//	CGenomeType constructor

	{
	}

CGenomeType::~CGenomeType (void)

//	CGenomeType destructor

	{
	
	}


ALERROR CGenomeType::OnBindDesign (SDesignLoadCtx &Ctx)

//	OnBindDesign
//
//	Bind design

	{
	return NOERROR;
	}

ALERROR CGenomeType::OnCreateFromXML (SDesignLoadCtx &Ctx, CXMLElement *pDesc)

//	OnCreateFromXML
//
//	Create from XML

	{
	//	Initialize

	m_sName = pDesc->GetAttribute(NAME_ATTRIB);
	m_sSpecies = pDesc->GetAttribute(SPECIES_ATTRIB);
	m_sGender = pDesc->GetAttribute(GENDER_ATTRIB);
	m_sSubject = pDesc->GetAttribute(SUBJECT_ATTRIB);
	m_sDeterminer = pDesc->GetAttribute(DETERMINER_ATTRIB);
	m_sPossessive = pDesc->GetAttribute(POSSESSIVE_ATTRIB);
	m_sObject = pDesc->GetAttribute(OBJECT_ATTRIB);
	m_sAddress = pDesc->GetAttribute(ADDRESS_ATTRIB);
	m_sPerson = pDesc->GetAttribute(PERSON_ATTRIB);
	m_sSibling = pDesc->GetAttribute(SIBLING_ATTRIB);
	m_sChild = pDesc->GetAttribute(CHILD_ATTRIB);

	//	Done

	return NOERROR;
	}

ICCItemPtr CGenomeType::OnGetProperty (CCodeChainCtx &Ctx, const CString &sProperty) const

//	OnGetProperty
//
//	Returns the given property (or NULL if not found)

	{
	CCodeChain &CC = g_pUniverse->GetCC();

	if (strEquals(sProperty, PROPERTY_NAME))
		return ICCItemPtr(CC.CreateString(m_sName));
	else if (strEquals(sProperty, PROPERTY_SPECIES))
		return ICCItemPtr(CC.CreateString(m_sSpecies));
	else if (strEquals(sProperty, PROPERTY_GENDER))
		return ICCItemPtr(CC.CreateString(m_sGender));
	else if (strEquals(sProperty, PROPERTY_SUBJECT))
		return ICCItemPtr(CC.CreateString(m_sSubject));
	else if (strEquals(sProperty, PROPERTY_DETERMINER))
		return ICCItemPtr(CC.CreateString(m_sDeterminer));
	else if (strEquals(sProperty, PROPERTY_POSSESSIVE))
		return ICCItemPtr(CC.CreateString(m_sPossessive));
	else if (strEquals(sProperty, PROPERTY_OBJECT))
		return ICCItemPtr(CC.CreateString(m_sObject));
	else if (strEquals(sProperty, PROPERTY_ADDRESS))
		return ICCItemPtr(CC.CreateString(m_sAddress));
	else if (strEquals(sProperty, PROPERTY_PERSON))
		return ICCItemPtr(CC.CreateString(m_sPerson));
	else if (strEquals(sProperty, PROPERTY_SIBLING))
		return ICCItemPtr(CC.CreateString(m_sSibling));
	else if (strEquals(sProperty, PROPERTY_CHILD))
		return ICCItemPtr(CC.CreateString(m_sChild));
	else
		return NULL;
	}