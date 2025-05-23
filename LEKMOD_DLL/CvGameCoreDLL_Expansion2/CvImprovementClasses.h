/*	-------------------------------------------------------------------------------------------------------
	� 1991-2012 Take-Two Interactive Software and its subsidiaries.  Developed by Firaxis Games.  
	Sid Meier's Civilization V, Civ, Civilization, 2K Games, Firaxis Games, Take-Two Interactive Software 
	and their respective logos are all trademarks of Take-Two interactive Software, Inc.  
	All other marks and trademarks are the property of their respective owners.  
	All rights reserved. 
	------------------------------------------------------------------------------------------------------- */
#pragma once

#ifndef CIV5_IMPROVEMENT_CLASSES_H
#define CIV5_IMPROVEMENT_CLASSES_H


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  class : CvImprovementResourceInfo
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvImprovementResourceInfo
{
	friend class CvImprovementEntry;

public:
	CvImprovementResourceInfo();
	~CvImprovementResourceInfo();

	int getDiscoverRand() const;
	bool isResourceMakesValid() const;
	bool isResourceTrade() const;
	int getYieldChange(int i) const;

protected:
	int m_iDiscoverRand;
	bool m_bResourceMakesValid;
	bool m_bResourceTrade;

	// Arrays
	int* m_piYieldChange;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  CLASS:      CvImprovementEntry
//!  \brief		A single improvement available in the game
//
//!  Key Attributes:
//!  - Used to be called CvImprovementInfo
//!  - Populated from XML\Terrain\CIV5Improvements.xml
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvImprovementEntry: public CvBaseInfo
{
public:
	CvImprovementEntry(void);
	~CvImprovementEntry(void);

	virtual bool CacheResults(Database::Results& kResults, CvDatabaseUtility& kUtility);

#ifdef LEKMOD_CUSTOM_IMPROVEMENT_ICONS
	const char* GetIconString() const;
	void SetIconString(const char* szVal);
#endif

	int GetGoldMaintenance() const;
	int GetCultureBombRadius() const;
	int GetCultureBombRadiusNeutral() const;
	int GetCultureAdjacentSameType() const;

	int GetTilesPerGoody() const;
	int GetGoodyUniqueRange() const;
	int GetFeatureGrowthProbability() const;
	int GetUpgradeTime() const;
	int GetRiverSideUpgradeMod() const;
	int GetCoastalLandUpgradeMod() const;
	int GetHillsUpgradeMod() const;
	int GetFreshWaterUpgradeMod() const;
	int GetDefenseModifier() const;
	int GetDefenseModifierGlobal() const;
	int GetNearbyEnemyDamage() const;
	int GetPillageGold() const;
	int GetResourceExtractionMod() const;
	int GetLuxuryCopiesSiphonedFromMinor() const;
	int GetImprovementPillage() const;
	void SetImprovementPillage(int i);
	int GetImprovementUpgrade() const;
	void SetImprovementUpgrade(int i);
	int GetRequiresXAdjacentLand() const;

	bool IsHillsMakesValid() const;
	bool IsWaterAdjacencyMakesValid() const;
	bool IsFreshWaterMakesValid() const;
	bool IsRiverSideMakesValid() const;
	bool IsNoFreshWater() const;
	bool IsRequiresFlatlands() const;
	bool IsRequiresFlatlandsOrFreshWater() const;
	bool IsRequiresFeature() const;
	bool IsRequiresImprovement() const;
	bool IsRemovesResource() const;
	bool IsPromptWhenComplete() const;
	bool IsWater() const;
	bool IsCoastal() const;
	bool IsDestroyedWhenPillaged() const;
	bool IsDisplacePillager() const;
	bool IsBuildableOnResources() const;
	bool IsBarbarianCamp() const;
	bool IsGoody() const;
	bool IsPermanent() const;
	bool IsOutsideBorders() const;
	bool IsInAdjacentFriendly() const;
	bool IsIgnoreOwnership() const;
	bool IsOnlyCityStateTerritory() const;
	bool IsNoTwoAdjacent() const;
	bool IsAdjacentLuxury() const;
	bool IsAllowsWalkWater() const;
	bool IsAllowsSailLand() const;
	bool IsCreatedByGreatPerson() const;
	bool IsSpecificCivRequired() const;

	CivilizationTypes GetRequiredCivilization() const;

	const char* GetArtDefineTag() const;
	void SetArtDefineTag(const char* szVal);

	ImprovementUsageTypes GetImprovementUsage() const;
	void SetImprovementUsage(const ImprovementUsageTypes usageType);

	int GetWorldSoundscapeScriptId() const;

	// Arrays

	int GetResourceQuantityRequirement(int i) const;

	int GetPrereqNatureYield(int i) const;
	int* GetPrereqNatureYieldArray();
	int GetYieldChange(int i) const;
	int* GetYieldChangeArray();
	int GetYieldChangePerEra(int i) const;
	int GetRiverSideYieldChange(int i) const;
	int* GetRiverSideYieldChangeArray();
	int GetCoastalLandYieldChange(int i) const;
	int* GetCoastalLandYieldChangeArray();
	int GetHillsYieldChange(int i) const;
	int* GetHillsYieldChangeArray();
	int GetNoFreshWaterYieldChange(int i) const;
	int* GetNoFreshWaterYieldChangeArray();				// For Moose - CvWidgetData XXX
	int GetFreshWaterYieldChange(int i) const;
	int* GetFreshWaterYieldChangeArray();				// For Moose - CvWidgetData XXX
	int GetAdjacentCityYieldChange(int i) const;
	int* GetAdjacentCityYieldChangeArray();
	int GetAdjacentMountainYieldChange(int i) const;
	int* GetAdjacentMountainYieldChangeArray();

	bool GetTerrainMakesValid(int i) const;
	bool GetFeatureMakesValid(int i) const;
	bool GetImprovementMakesValid(int i) const;

	int GetTechYieldChanges(int i, int j) const;
	int* GetTechYieldChangesArray(int i);
#ifdef LEKMOD_ADJACENT_IMPROVEMENT_YIELD
	int GetImprovementAdjacentBonus(int i, int j) const;
	int GetImprovementAdjacentCivilizationAmount(int i, int j) const;
	int GetImprovementAdjacentBonusCivilizationNoAmount(int i, int j) const;
	int GetImprovementAdjacentBonusCivilization(int i, int j) const;
	int GetImprovementAdjacentAmount(int i, int j) const;
#endif
	int GetTechNoFreshWaterYieldChanges(int i, int j) const;
	int* GetTechNoFreshWaterYieldChangesArray(int i);
	int GetTechFreshWaterYieldChanges(int i, int j) const;
	int* GetTechFreshWaterYieldChangesArray(int i);
	int GetRouteYieldChanges(int i, int j) const;
	int* GetRouteYieldChangesArray(int i);				// For Moose - CvWidgetData XXX

	int  GetImprovementResourceYield(int i, int j) const;
	bool IsImprovementResourceMakesValid(int i) const;
	bool IsImprovementResourceTrade(int i) const;
	int  GetImprovementResourceDiscoverRand(int i) const;

	int  GetFlavorValue(int i) const;

	//---------------------------------------PROTECTED MEMBER VARIABLES---------------------------------
protected:
#ifndef NQM_PRUNING
	void InitImprovementResourceList(CvImprovementResourceInfo** ppImprovementResource, int iListLen);
#endif

#ifdef LEKMOD_CUSTOM_IMPROVEMENT_ICONS
	CvString m_strIconString;
#endif

	int m_iGoldMaintenance;
	int m_iCultureBombRadius;
	int m_iCultureBombRadiusNeutral;
	int m_iCultureAdjacentSameType;

	int m_iTilesPerGoody;
	int m_iGoodyUniqueRange;
	int m_iFeatureGrowthProbability;
	int m_iUpgradeTime;
	int m_iRiverSideUpgradeMod;
	int m_iCoastalLandUpgradeMod;
	int m_iHillsUpgradeMod;
	int m_iFreshWaterUpgradeMod;
	int m_iDefenseModifier;
	int m_iDefenseModifierGlobal;
	int m_iNearbyEnemyDamage;
	int m_iPillageGold;
	int m_iResourceExtractionMod;
	int m_iLuxuryCopiesSiphonedFromMinor;
	int m_iImprovementPillage;
	int m_iImprovementUpgrade;
	int m_iRequiresXAdjacentLand;

	bool m_bHillsMakesValid;
	bool m_bWaterAdjacencyMakesValid;
	bool m_bFreshWaterMakesValid;
	bool m_bRiverSideMakesValid;
	bool m_bNoFreshWater;
	bool m_bRequiresFlatlands;
	bool m_bRequiresFlatlandsOrFreshWater;
	bool m_bRequiresFeature;
	bool m_bRequiresImprovement;
	bool m_bRemovesResource;
	bool m_bPromptWhenComplete;
	bool m_bWater;
	bool m_bCoastal;
	bool m_bDestroyedWhenPillaged;
	bool m_bDisplacePillager;
	bool m_bBuildableOnResources;
	bool m_bBarbarianCamp;
	bool m_bGoody;
	bool m_bPermanent;
	bool m_bOutsideBorders;
	bool m_bInAdjacentFriendly;
	bool m_bIgnoreOwnership;
	bool m_bOnlyCityStateTerritory;
	bool m_bNoTwoAdjacent;
    bool m_bAdjacentLuxury;
	bool m_bAllowsWalkWater;
	bool m_bAllowsSailLand;
	bool m_bCreatedByGreatPerson;
	bool m_bSpecificCivRequired;

	CvString m_strArtDefineTag;
	ImprovementUsageTypes m_eImprovementUsageType;
	CivilizationTypes m_eRequiredCivilization;

	int m_iWorldSoundscapeScriptId;

	// Arrays
	int* m_piResourceQuantityRequirements;

	int* m_piPrereqNatureYield;
	int* m_piYieldChange;
	int* m_piYieldPerEra;
	int* m_piRiverSideYieldChange;
	int* m_piCoastalLandYieldChange;
	int* m_piHillsYieldChange;
	int* m_piFreshWaterChange;
	int* m_piAdjacentCityYieldChange;
	int* m_piAdjacentMountainYieldChange;
	int* m_piFlavorValue;

	bool* m_pbTerrainMakesValid;
	bool* m_pbFeatureMakesValid;
	bool* m_pbImprovementMakesValid;

#ifdef AUI_DATABASE_UTILITY_PROPER_2D_ALLOCATION_AND_DESTRUCTION
	std::pair<int**, size_t> m_ppiTechYieldChanges;
	std::pair<int**, size_t> m_ppiTechNoFreshWaterYieldChanges;
	std::pair<int**, size_t> m_ppiTechFreshWaterYieldChanges;
	std::pair<int**, size_t> m_ppiRouteYieldChanges;
#else
	int** m_ppiTechYieldChanges;
	int** m_ppiTechNoFreshWaterYieldChanges;
	int** m_ppiTechFreshWaterYieldChanges;
	int** m_ppiRouteYieldChanges;
#endif
#ifdef LEKMOD_ADJACENT_IMPROVEMENT_YIELD
	// 
	int** m_ppiImprovementAdjacentBonus;
	int** m_ppiImprovementAdjacentCivilizationAmount;
	int** m_ppiImprovementAdjacentBonusCivilizationNoAmount;
	int** m_piImprovementAdjacentBonusCivilization;
	int** m_ppiImprovementAdjacentAmount;
#endif
	CvImprovementResourceInfo* m_paImprovementResource;
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  CLASS:      CvImprovementXMLEntries
//!  \brief		Game-wide information about improvements
//
//! Key Attributes:
//! - Plan is it will be contained in CvGameRules object within CvGame class
//! - Populated from XML\Terrain\CIV5ImprovementInfo.xml
//! - Contains an array of CvImprovementEntry from the above XML file
//! - One instance for the entire game
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvImprovementXMLEntries
{
public:
	CvImprovementXMLEntries(void);
	~CvImprovementXMLEntries(void);

	// Accessor functions
	std::vector<CvImprovementEntry*>& GetImprovementEntries();
#ifdef AUI_WARNING_FIXES
	uint GetNumImprovements() const;
	_Ret_maybenull_ CvImprovementEntry* GetEntry(uint index);
#else
	int GetNumImprovements();
	_Ret_maybenull_ CvImprovementEntry* GetEntry(int index);
#endif
	CvImprovementEntry* GetImprovementForResource(int eResource);

	// Binary cache functions
	void DeleteArray();

private:
	std::vector<CvImprovementEntry*> m_paImprovementEntries;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Helper Functions to serialize arrays of variable length (based on number of improvements defined in game)
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
namespace ImprovementArrayHelpers
{
void Read(FDataStream& kStream, int* paiImprovementArray);
void Write(FDataStream& kStream, int* paiImprovementArray, int iArraySize);
void ReadYieldArray(FDataStream& kStream, int** ppaaiImprovementYieldArray, int iNumYields);
void WriteYieldArray(FDataStream& kStream, int** ppaaiImprovementYieldArray, int iArraySize);
}

#endif //CIV5_IMPROVEMENT_CLASSES_H