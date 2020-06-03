#include "global.h"
#include "random.h"
#include "wild_encounter.h"
#include "event_data.h"
#include "fieldmap.h"
#include "roamer.h"
#include "field_player_avatar.h"
#include "battle_setup.h"
#include "overworld.h"
#include "metatile_behavior.h"
#include "event_scripts.h"
#include "region_map.h"
#include "script.h"
#include "link.h"
#include "quest_log.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/vars.h"
#include "constants/abilities.h"
#include "constants/items.h"

const u8 gFlagSecName_PalletTown[] = "PALLET TOWN";
const u8 gFlagSecName_ViridianCity[] = "VIRIDIAN CITY";
const u8 gFlagSecName_PewterCity[] = "PEWTER CITY";
const u8 gFlagSecName_CeruleanCity[] = "CERULEAN CITY";
const u8 gFlagSecName_LavenderTown[] = "LAVENDER TOWN";
const u8 gFlagSecName_VermilionCity[] = "VERMILION CITY";
const u8 gFlagSecName_CeladonCity[] = "CELADON CITY";
const u8 gFlagSecName_FuchsiaCity[] = "FUCHSIA CITY";
const u8 gFlagSecName_CinnabarIsland[] = "CINNABAR ISLAND";
const u8 gFlagSecName_IndigoPlateau[] = "INDIGO PLATEAU";
const u8 gFlagSecName_SaffronCity[] = "SAFFRON CITY";
const u8 gFlagSecName_Route4[] = "ROUTE 4";
const u8 gFlagSecName_Route10[] = "ROUTE 10";
const u8 gFlagSecName_Route1[] = "ROUTE 1";
const u8 gFlagSecName_Route2[] = "ROUTE 2";
const u8 gFlagSecName_Route3[] = "ROUTE 3";
const u8 gFlagSecName_Route4_2[] = "ROUTE 4";
const u8 gFlagSecName_Route5[] = "ROUTE 5";
const u8 gFlagSecName_Route6[] = "ROUTE 6";
const u8 gFlagSecName_Route7[] = "ROUTE 7";
const u8 gFlagSecName_Route8[] = "ROUTE 8";
const u8 gFlagSecName_Route9[] = "ROUTE 9";
const u8 gFlagSecName_Route10_2[] = "ROUTE 10";
const u8 gFlagSecName_Route11[] = "ROUTE 11";
const u8 gFlagSecName_Route12[] = "ROUTE 12";
const u8 gFlagSecName_Route13[] = "ROUTE 13";
const u8 gFlagSecName_Route14[] = "ROUTE 14";
const u8 gFlagSecName_Route15[] = "ROUTE 15";
const u8 gFlagSecName_Route16[] = "ROUTE 16";
const u8 gFlagSecName_Route17[] = "ROUTE 17";
const u8 gFlagSecName_Route18[] = "ROUTE 18";
const u8 gFlagSecName_Route19[] = "ROUTE 19";
const u8 gFlagSecName_Route20[] = "ROUTE 20";
const u8 gFlagSecName_Route21[] = "ROUTE 21";
const u8 gFlagSecName_Route22[] = "ROUTE 22";
const u8 gFlagSecName_Route23[] = "ROUTE 23";
const u8 gFlagSecName_Route24[] = "ROUTE 24";
const u8 gFlagSecName_Route25[] = "ROUTE 25";
const u8 gFlagSecName_ViridianForest[] = "VIRIDIAN FOREST";
const u8 gFlagSecName_MtMoon[] = "MT. MOON";
const u8 gFlagSecName_SSAnne[] = "S.S. ANNE";
const u8 gFlagSecName_UndergroundPath[] = "UNDERGROUND PATH";
const u8 gFlagSecName_UndergroundPath_2[] = "UNDERGROUND PATH";
const u8 gFlagSecName_DiglettsCave[] = "DIGLETT'S CAVE";
const u8 gFlagSecName_VictoryRoad[] = "VICTORY ROAD";
const u8 gFlagSecName_RocketHideout[] = "ROCKET HIDEOUT";
const u8 gFlagSecName_SilphCo[] = "SILPH CO.";
const u8 gFlagSecName_PokemonMansion[] = "POKEMON MANSION";
const u8 gFlagSecName_SafariZone[] = "SAFARI ZONE";
const u8 gFlagSecName_PokemonLeague[] = "POKEMON LEAGUE";
const u8 gFlagSecName_RockTunnel[] = "ROCK TUNNEL";
const u8 gFlagSecName_SeafoamIslands[] = "SEAFOAM ISLANDS";
const u8 gFlagSecName_PokemonTower[] = "POKEMON TOWER";
const u8 gFlagSecName_CeruleanCave[] = "CERULEAN CAVE";
const u8 gFlagSecName_PowerPlant[] = "POWER PLANT";
const u8 gFlagSecName_OneIsland[] = "ONE ISLAND";
const u8 gFlagSecName_TwoIsland[] = "TWO ISLAND";
const u8 gFlagSecName_ThreeIsland[] = "THREE ISLAND";
const u8 gFlagSecName_FourIsland[] = "FOUR ISLAND";
const u8 gFlagSecName_FiveIsland[] = "FIVE ISLAND";
const u8 gFlagSecName_SevenIsland[] = "SEVEN ISLAND";
const u8 gFlagSecName_SixIsland[] = "SIX ISLAND";
const u8 gFlagSecName_KindleRoad[] = "KINDLE ROAD";
const u8 gFlagSecName_TreasureBeach[] = "TREASURE BEACH";
const u8 gFlagSecName_CapeBrink[] = "CAPE BRINK";
const u8 gFlagSecName_BondBridge[] = "BOND BRIDGE";
const u8 gFlagSecName_ThreeIslePort[] = "THREE ISLE PORT";
const u8 gFlagSecName_SeviiIsle6[] = "SEVII ISLE 6";
const u8 gFlagSecName_SeviiIsle7[] = "SEVII ISLE 7";
const u8 gFlagSecName_SeviiIsle8[] = "SEVII ISLE 8";
const u8 gFlagSecName_SeviiIsle9[] = "SEVII ISLE 9";
const u8 gFlagSecName_ResortGorgeous[] = "RESORT GORGEOUS";
const u8 gFlagSecName_WaterLabyrinth[] = "WATER LABYRINTH";
const u8 gFlagSecName_FiveIsleMeadow[] = "FIVE ISLE MEADOW";
const u8 gFlagSecName_MemorialPillar[] = "MEMORIAL PILLAR";
const u8 gFlagSecName_OutcastIsland[] = "OUTCAST ISLAND";
const u8 gFlagSecName_GreenPath[] = "GREEN PATH";
const u8 gFlagSecName_WaterPath[] = "WATER PATH";
const u8 gFlagSecName_RuinValley[] = "RUIN VALLEY";
const u8 gFlagSecName_TrainerTower[] = "TRAINER TOWER";
const u8 gFlagSecName_CanyonEntrance[] = "CANYON ENTRANCE";
const u8 gFlagSecName_SevaultCanyon[] = "SEVAULT CANYON";
const u8 gFlagSecName_TanobyRuins[] = "TANOBY RUINS";
const u8 gFlagSecName_SeviiIsle22[] = "SEVII ISLE 22";
const u8 gFlagSecName_SeviiIsle23[] = "SEVII ISLE 23";
const u8 gFlagSecName_SeviiIsle24[] = "SEVII ISLE 24";
const u8 gFlagSecName_NavelRock[] = "NAVEL ROCK";
const u8 gFlagSecName_MtEmber[] = "MT. EMBER";
const u8 gFlagSecName_BerryForest[] = "BERRY FOREST";
const u8 gFlagSecName_IcefallCave[] = "ICEFALL CAVE";
const u8 gFlagSecName_RocketWarehouse[] = "ROCKET WAREHOUSE";
const u8 gFlagSecName_TrainerTower_2[] = "TRAINER TOWER";
const u8 gFlagSecName_DottedHole[] = "DOTTED HOLE";
const u8 gFlagSecName_LostCave[] = "LOST CAVE";
const u8 gFlagSecName_PatternBush[] = "PATTERN BUSH";
const u8 gFlagSecName_AlteringCave[] = "ALTERING CAVE";
const u8 gFlagSecName_TanobyChambers[] = "TANOBY CHAMBERS";
const u8 gFlagSecName_ThreeIslePath[] = "THREE ISLE PATH";
const u8 gFlagSecName_TanobyKey[] = "TANOBY KEY";
const u8 gFlagSecName_BirthIsland[] = "BIRTH ISLAND";
const u8 gFlagSecName_MoneanChamber[] = "MONEAN CHAMBER";
const u8 gFlagSecName_LiptooChamber[] = "LIPTOO CHAMBER";
const u8 gFlagSecName_WeepthChamber[] = "WEEPTH CHAMBER";
const u8 gFlagSecName_DilfordChamber[] = "DILFORD CHAMBER";
const u8 gFlagSecName_ScufibChamber[] = "SCUFIB CHAMBER";
const u8 gFlagSecName_RixyChamber[] = "RIXY CHAMBER";
const u8 gFlagSecName_ViapoisChamber[] = "VIAPOIS CHAMBER";
const u8 gFlagSecName_EmberSpa[] = "EMBER SPA";
const u8 gFlagSecName_CeladonDept[] = "CELADON DEPT.";

struct WildEncounterData
{
    u32 rngState;
    u16 prevMetatileBehavior;
    u16 encounterRateBuff;
    u8 stepsSinceLastEncounter;
    u8 abilityEffect;
    u16 leadMonHeldItem;
};

static EWRAM_DATA struct WildEncounterData sWildEncounterData = {};
static EWRAM_DATA bool8 sWildEncountersDisabled = FALSE;

static bool8 UnlockedTanobyOrAreNotInTanoby(void);
static u32 GenerateUnownPersonalityByLetter(u8 letter);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *rate);
static u8 GetFluteEncounterRateModType(void);
static void ApplyCleanseTagEncounterRateMod(u32 *rate);
static bool8 IsLeadMonHoldingCleanseTag(void);
static u16 WildEncounterRandom(void);
static void AddToWildEncounterRateBuff(u8 encouterRate);

#include "data/wild_encounters.h"
//#include "data/text/map_section_names.h"

static const u8 sUnownLetterSlots[][12] = {
  //  A   A   A   A   A   A   A   A   A   A   A   ?
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27},
  //  C   C   C   D   D   D   H   H   H   U   U   O
    { 2,  2,  2,  3,  3,  3,  7,  7,  7, 20, 20, 14},
  //  N   N   N   N   S   S   S   S   I   I   E   E
    {13, 13, 13, 13, 18, 18, 18, 18,  8,  8,  4,  4},
  //  P   P   L   L   J   J   R   R   R   Q   Q   Q
    {15, 15, 11, 11,  9,  9, 17, 17, 17, 16, 16, 16},
  //  Y   Y   T   T   G   G   G   F   F   F   K   K
    {24, 24, 19, 19,  6,  6,  6,  5,  5,  5, 10, 10},
  //  V   V   V   W   W   W   X   X   M   M   B   B
    {21, 21, 21, 22, 22, 22, 23, 23, 12, 12,  1,  1},
  //  Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   !
    {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26},
};

void DisableWildEncounters(bool8 state)
{
    sWildEncountersDisabled = state;
}

bool8 GetMapFlag(u8* mapName) {
	if (mapName == gFlagSecName_PalletTown)
		return FlagGet(FLAG_0x0AF);
	else if (mapName == gFlagSecName_ViridianCity)
		return FlagGet(FLAG_0x0B0);
	else if (mapName == gFlagSecName_PewterCity)
		return FlagGet(FLAG_0x0B1);
	else if (mapName == gFlagSecName_CeruleanCity)
		return FlagGet(FLAG_0x0B2);
	else if (mapName == gFlagSecName_LavenderTown)
		return FlagGet(FLAG_0x0B3);
	else if (mapName == gFlagSecName_VermilionCity)
		return FlagGet(FLAG_0x0B4);
	else if (mapName == gFlagSecName_CeladonCity)
		return FlagGet(FLAG_0x0B5);
	else if (mapName == gFlagSecName_FuchsiaCity)
		return FlagGet(FLAG_0x0B6);
	else if (mapName == gFlagSecName_CinnabarIsland)
		return FlagGet(FLAG_0x0B7);
	else if (mapName == gFlagSecName_IndigoPlateau)
		return FlagGet(FLAG_0x0B8);
	else if (mapName == gFlagSecName_SaffronCity)
		return FlagGet(FLAG_0x0B9);
	else if (mapName == gFlagSecName_Route1)
		return FlagGet(FLAG_0x0BA);
	else if (mapName == gFlagSecName_Route2)
		return FlagGet(FLAG_0x0BB);
	else if (mapName == gFlagSecName_Route3)
		return FlagGet(FLAG_0x0BC);
	else if (mapName == gFlagSecName_Route4)
		return FlagGet(FLAG_0x0BD);
	else if (mapName == gFlagSecName_Route5)
		return FlagGet(FLAG_0x0BE);
	else if (mapName == gFlagSecName_Route6)
		return FlagGet(FLAG_0x0BF);
	else if (mapName == gFlagSecName_Route7)
		return FlagGet(FLAG_0x0C0);
	else if (mapName == gFlagSecName_Route8)
		return FlagGet(FLAG_0x0C1);
	else if (mapName == gFlagSecName_Route9)
		return FlagGet(FLAG_0x0C2);
	else if (mapName == gFlagSecName_Route10)
		return FlagGet(FLAG_0x0C3);
	else if (mapName == gFlagSecName_Route11)
		return FlagGet(FLAG_0x0C4);
	else if (mapName == gFlagSecName_Route12)
		return FlagGet(FLAG_0x0C5);
	else if (mapName == gFlagSecName_Route13)
		return FlagGet(FLAG_0x0C6);
	else if (mapName == gFlagSecName_Route14)
		return FlagGet(FLAG_0x0C7);
	else if (mapName == gFlagSecName_Route15)
		return FlagGet(FLAG_0x0C8);
	else if (mapName == gFlagSecName_Route16)
		return FlagGet(FLAG_0x0C9);
	else if (mapName == gFlagSecName_Route17)
		return FlagGet(FLAG_0x0CA);
	else if (mapName == gFlagSecName_Route18)
		return FlagGet(FLAG_0x0CB);
	else if (mapName == gFlagSecName_Route19)
		return FlagGet(FLAG_0x0CC);
	else if (mapName == gFlagSecName_Route20)
		return FlagGet(FLAG_0x0CD);
	else if (mapName == gFlagSecName_Route21)
		return FlagGet(FLAG_0x0CE);
	else if (mapName == gFlagSecName_Route22)
		return FlagGet(FLAG_0x0CF);
	else if (mapName == gFlagSecName_Route23)
		return FlagGet(FLAG_0x0D0);
	else if (mapName == gFlagSecName_Route24)
		return FlagGet(FLAG_0x0D1);
	else if (mapName == gFlagSecName_Route25)
		return FlagGet(FLAG_0x0D2);
};

bool8 SetMapFlag(u8* mapName) {
	if (mapName == gFlagSecName_PalletTown)
		return FlagSet(FLAG_0x0AF);
	else if (mapName == gFlagSecName_ViridianCity)
		return FlagSet(FLAG_0x0B0);
	else if (mapName == gFlagSecName_PewterCity)
		return FlagSet(FLAG_0x0B1);
	else if (mapName == gFlagSecName_CeruleanCity)
		return FlagSet(FLAG_0x0B2);
	else if (mapName == gFlagSecName_LavenderTown)
		return FlagSet(FLAG_0x0B3);
	else if (mapName == gFlagSecName_VermilionCity)
		return FlagSet(FLAG_0x0B4);
	else if (mapName == gFlagSecName_CeladonCity)
		return FlagSet(FLAG_0x0B5);
	else if (mapName == gFlagSecName_FuchsiaCity)
		return FlagSet(FLAG_0x0B6);
	else if (mapName == gFlagSecName_CinnabarIsland)
		return FlagSet(FLAG_0x0B7);
	else if (mapName == gFlagSecName_IndigoPlateau)
		return FlagSet(FLAG_0x0B8);
	else if (mapName == gFlagSecName_SaffronCity)
		return FlagSet(FLAG_0x0B9);
	else if (mapName == gFlagSecName_Route1)
		return FlagSet(FLAG_0x0BA);
	else if (mapName == gFlagSecName_Route2)
		return FlagSet(FLAG_0x0BB);
	else if (mapName == gFlagSecName_Route3)
		return FlagSet(FLAG_0x0BC);
	else if (mapName == gFlagSecName_Route4)
		return FlagSet(FLAG_0x0BD);
	else if (mapName == gFlagSecName_Route5)
		return FlagSet(FLAG_0x0BE);
	else if (mapName == gFlagSecName_Route6)
		return FlagSet(FLAG_0x0BF);
	else if (mapName == gFlagSecName_Route7)
		return FlagSet(FLAG_0x0C0);
	else if (mapName == gFlagSecName_Route8)
		return FlagSet(FLAG_0x0C1);
	else if (mapName == gFlagSecName_Route9)
		return FlagSet(FLAG_0x0C2);
	else if (mapName == gFlagSecName_Route10)
		return FlagSet(FLAG_0x0C3);
	else if (mapName == gFlagSecName_Route11)
		return FlagSet(FLAG_0x0C4);
	else if (mapName == gFlagSecName_Route12)
		return FlagSet(FLAG_0x0C5);
	else if (mapName == gFlagSecName_Route13)
		return FlagSet(FLAG_0x0C6);
	else if (mapName == gFlagSecName_Route14)
		return FlagSet(FLAG_0x0C7);
	else if (mapName == gFlagSecName_Route15)
		return FlagSet(FLAG_0x0C8);
	else if (mapName == gFlagSecName_Route16)
		return FlagSet(FLAG_0x0C9);
	else if (mapName == gFlagSecName_Route17)
		return FlagSet(FLAG_0x0CA);
	else if (mapName == gFlagSecName_Route18)
		return FlagSet(FLAG_0x0CB);
	else if (mapName == gFlagSecName_Route19)
		return FlagSet(FLAG_0x0CC);
	else if (mapName == gFlagSecName_Route20)
		return FlagSet(FLAG_0x0CD);
	else if (mapName == gFlagSecName_Route21)
		return FlagSet(FLAG_0x0CE);
	else if (mapName == gFlagSecName_Route22)
		return FlagSet(FLAG_0x0CF);
	else if (mapName == gFlagSecName_Route23)
		return FlagSet(FLAG_0x0D0);
	else if (mapName == gFlagSecName_Route24)
		return FlagSet(FLAG_0x0D1);
	else if (mapName == gFlagSecName_Route25)
		return FlagSet(FLAG_0x0D2);
};

static u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        return 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        return 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        return 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        return 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        return 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        return 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 9;
    else if (rand == ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 10;
    else
        return 11;
}

static u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        return 3;
    else
        return 4;
}

enum
{
    OLD_ROD,
    GOOD_ROD,
    SUPER_ROD
};

static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand == ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

static u8 ChooseWildMonLevel(const struct WildPokemon * info)
{
    u8 lo;
    u8 hi;
    u8 mod;
    u8 res;
    if (info->maxLevel >= info->minLevel)
    {
        lo = info->minLevel;
        hi = info->maxLevel;
    }
    else
    {
        lo = info->maxLevel;
        hi = info->minLevel;
    }
    mod = hi - lo + 1;
    res = Random() % mod;
    return lo + res;
}

static u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader * wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == 0xFF)
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SIX_ISLAND_ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(SIX_ISLAND_ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId > 8)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            if (!UnlockedTanobyOrAreNotInTanoby())
                break;
            return i;
        }
    }

    return -1;
}

static bool8 UnlockedTanobyOrAreNotInTanoby(void)
{
    if (FlagGet(FLAG_SYS_UNLOCKED_TANOBY_RUINS))
        return TRUE;
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER))
        return TRUE;
    if (!(gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER)
    ))
        return TRUE;
    return FALSE;
}

static void GenerateWildMon(u16 species, u8 level, u8 slot)
{
    u32 personality;
    s8 chamber;
	bool8 isEgg;
	u8 mapName[25];
	u32 mapID = GetCurrentRegionMapSectionId();
	u8 *ptr = GetMapName(mapName, mapID, 0);
    ZeroEnemyPartyMons();
    if (species != SPECIES_UNOWN)
    {
        CreateMonWithNature(&gEnemyParty[0], species, level, 32, Random() % 25);
		if (!GetMapFlag(mapName)) {
			isEgg = TRUE;
			SetMonData(&gEnemyParty[0], MON_DATA_IS_EGG, &isEgg);
			//SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, mapName);
		}
    }
    else
    {
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, 32, TRUE, personality, FALSE, 0);
    }
}

static u32 GenerateUnownPersonalityByLetter(u8 letter)
{
    u32 personality;
    do
    {
        personality = (Random() << 16) | Random();
    } while (GetUnownLetterByPersonalityLoByte(personality) != letter);
    return personality;
}

u8 GetUnownLetterByPersonalityLoByte(u32 personality)
{
    return (((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 0x1C;
}

enum
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    0x1
#define WILD_CHECK_KEEN_EYE 0x2

static bool8 TryGenerateWildMon(const struct WildPokemonInfo * info, u8 area, u8 flags)
{
    u8 slot = 0;
    u8 level;
    switch (area)
    {
    case WILD_AREA_LAND:
        slot = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        slot = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        slot = ChooseWildMonIndex_WaterRock();
        break;
    }
    level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    if (flags == WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
    {
        return FALSE;
    }
    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return TRUE;
}

static u16 GenerateFishingEncounter(const struct WildPokemonInfo * info, u8 rod)
{
    u8 slot = ChooseWildMonIndex_Fishing(rod);
    u8 level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return info->wildPokemon[slot].species;
}

static bool8 DoWildEncounterRateDiceRoll(u16 a0)
{
    if (WildEncounterRandom() % 1600 < a0)
        return TRUE;
    return FALSE;
}

static bool8 DoWildEncounterRateTest(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    encounterRate += sWildEncounterData.encounterRateBuff * 16 / 200;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility)
    {
        switch (sWildEncounterData.abilityEffect)
        {
        case 1:
            encounterRate /= 2;
            break;
        case 2:
            encounterRate *= 2;
            break;
        }
    }
    if (encounterRate > 1600)
        encounterRate = 1600;
    return DoWildEncounterRateDiceRoll(encounterRate);
}

static u8 GetAbilityEncounterRateModType(void)
{
    sWildEncounterData.abilityEffect = 0;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_STENCH)
            sWildEncounterData.abilityEffect = 1;
        else if (ability == ABILITY_ILLUMINATE)
            sWildEncounterData.abilityEffect = 2;
    }
    return sWildEncounterData.abilityEffect;
}

static bool8 DoGlobalWildEncounterDiceRoll(void)
{
    if ((Random() % 100) >= 60)
        return FALSE;
    return TRUE;
}

bool8 StandardWildEncounter(u32 currMetatileBehavior, u16 previousMetatileBehavior)
{
    u16 headerId;
    struct Roamer * roamer;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId != 0xFFFF)
    {
        if (GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
        {
            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;
            else if (previousMetatileBehavior != GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR) && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            if (DoWildEncounterRateTest(gWildMonHeaders[headerId].landMonsInfo->encounterRate, FALSE) != TRUE)
            {
                AddToWildEncounterRateBuff(gWildMonHeaders[headerId].landMonsInfo->encounterRate);
                return FALSE;
            }

            else if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                {
                    return FALSE;
                }

                StartRoamerBattle();
                return TRUE;
            }
            else
            {

                // try a regular wild land encounter
                if (TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, WILD_CHECK_REPEL) == TRUE)
                {
                    StartWildBattle();
                    return TRUE;
                }
                else
                {
                    AddToWildEncounterRateBuff(gWildMonHeaders[headerId].landMonsInfo->encounterRate);
                }
            }
        }
        else if (GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER
                 || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridge(GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR)) == TRUE))
        {
            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;
            else if (previousMetatileBehavior != GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR) && !DoGlobalWildEncounterDiceRoll())
                return FALSE;
            else if (DoWildEncounterRateTest(gWildMonHeaders[headerId].waterMonsInfo->encounterRate, FALSE) != TRUE)
            {
                AddToWildEncounterRateBuff(gWildMonHeaders[headerId].waterMonsInfo->encounterRate);
                return FALSE;
            }

            if (TryStartRoamerEncounter() == TRUE)
            {
                roamer = &gSaveBlock1Ptr->roamer;
                if (!IsWildLevelAllowedByRepel(roamer->level))
                {
                    return FALSE;
                }

                StartRoamerBattle();
                return TRUE;
            }
            else // try a regular surfing encounter
            {
                if (TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, WILD_CHECK_REPEL) == TRUE)
                {
                    StartWildBattle();
                    return TRUE;
                }
                else
                {
                    AddToWildEncounterRateBuff(gWildMonHeaders[headerId].waterMonsInfo->encounterRate);
                }
            }
        }
    }

    return FALSE;
}

void RockSmashWildEncounter(void)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    if (headerIdx == 0xFFFF)
        gSpecialVar_Result = FALSE;
    else if (gWildMonHeaders[headerIdx].rockSmashMonsInfo == NULL)
        gSpecialVar_Result = FALSE;
    else if (DoWildEncounterRateTest(gWildMonHeaders[headerIdx].rockSmashMonsInfo->encounterRate, TRUE) != TRUE)
        gSpecialVar_Result = FALSE;
    else if (TryGenerateWildMon(gWildMonHeaders[headerIdx].rockSmashMonsInfo, WILD_AREA_ROCKS, WILD_CHECK_REPEL) == TRUE)
    {
        StartWildBattle();
        gSpecialVar_Result = TRUE;
    }
    else
        gSpecialVar_Result = FALSE;
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    u16 headerId;

    PlayerGetDestCoords(&x, &y);
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId != 0xFFFF)
    {
        if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
        {
            if (TryStartRoamerEncounter() == TRUE)
            {
                StartRoamerBattle();
                return TRUE;
            }

            if (gWildMonHeaders[headerId].landMonsInfo == NULL)
                return FALSE;

            TryGenerateWildMon(gWildMonHeaders[headerId].landMonsInfo, WILD_AREA_LAND, 0);

            StartWildBattle();
            return TRUE;
        }
        else if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER)
        {
            if (TryStartRoamerEncounter() == TRUE)
            {
                StartRoamerBattle();
                return TRUE;
            }

            if (gWildMonHeaders[headerId].waterMonsInfo == NULL)
                return FALSE;

            TryGenerateWildMon(gWildMonHeaders[headerId].waterMonsInfo, WILD_AREA_WATER, 0);
            StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    if (headerIdx == 0xFFFF)
        return FALSE;
    if (gWildMonHeaders[headerIdx].fishingMonsInfo == NULL)
        return FALSE;
    return TRUE;
}

void FishingWildEncounter(u8 rod)
{
    GenerateFishingEncounter(gWildMonHeaders[GetCurrentMapWildMonHeaderId()].fishingMonsInfo, rod);
    IncrementGameStat(GAME_STAT_FISHING_CAPTURES);
    StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    u16 headerId;
    const struct WildPokemonInfo * landMonsInfo;
    const struct WildPokemonInfo * waterMonsInfo;

    *isWaterMon = FALSE;
    headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == 0xFFFF)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    // Neither
    if (landMonsInfo == NULL && waterMonsInfo == NULL)
        return SPECIES_NONE;
        // Land Pokemon
    else if (landMonsInfo != NULL && waterMonsInfo == NULL)
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
        // Water Pokemon
    else if (landMonsInfo == NULL && waterMonsInfo != NULL)
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    // Either land or water Pokemon
    if ((Random() % 100) < 80)
    {
        return landMonsInfo->wildPokemon[ChooseWildMonIndex_Land()].species;
    }
    else
    {
        *isWaterMon = TRUE;
        return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
}

u16 GetLocalWaterMon(void)
{
    u16 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId != 0xFFFF)
    {
        const struct WildPokemonInfo * waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;

        if (waterMonsInfo)
            return waterMonsInfo->wildPokemon[ChooseWildMonIndex_WaterRock()].species;
    }
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 steps;

    if (InUnionRoom() == TRUE)
        return FALSE;

    if (gQuestLogState == QL_STATE_PLAYBACK)
        return FALSE;

    steps = VarGet(VAR_REPEL_STEP_COUNT);

    if (steps != 0)
    {
        steps--;
        VarSet(VAR_REPEL_STEP_COUNT, steps);
        if (steps == 0)
        {
            ScriptContext1_SetupScript(EventScript_RepelWoreOff);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!VarGet(VAR_REPEL_STEP_COUNT))
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static void ApplyFluteEncounterRateMod(u32 *encounterRate)
{
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        *encounterRate += *encounterRate / 2;
        break;
    case 2:
        *encounterRate = *encounterRate / 2;
        break;
    }
}

static u8 GetFluteEncounterRateModType(void)
{
    if (FlagGet(FLAG_SYS_WHITE_FLUTE_ACTIVE) == TRUE)
        return 1;
    else if (FlagGet(FLAG_SYS_BLACK_FLUTE_ACTIVE) == TRUE)
        return 2;
    else
        return 0;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encounterRate)
{
    if (IsLeadMonHoldingCleanseTag())
        *encounterRate = *encounterRate * 2 / 3;
}

static bool8 IsLeadMonHoldingCleanseTag(void)
{
    if (sWildEncounterData.leadMonHeldItem == ITEM_CLEANSE_TAG)
        return TRUE;
    else
        return FALSE;
}

void SeedWildEncounterRng(u16 seed)
{
    sWildEncounterData.rngState = seed;
    ResetEncounterRateModifiers();
}

static u16 WildEncounterRandom(void)
{
    sWildEncounterData.rngState *= 1103515245;
    sWildEncounterData.rngState += 12345;
    return sWildEncounterData.rngState >> 16;
}

static u8 GetMapBaseEncounterCooldown(u8 encounterType)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    if (headerIdx == 0xFFFF)
        return 0xFF;
    if (encounterType == TILE_ENCOUNTER_LAND)
    {
        if (gWildMonHeaders[headerIdx].landMonsInfo == NULL)
            return 0xFF;
        if (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate >= 80)
            return 0;
        if (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate < 10)
            return 8;
        return 8 - (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate / 10);
    }
    if (encounterType == TILE_ENCOUNTER_WATER)
    {
        if (gWildMonHeaders[headerIdx].waterMonsInfo == NULL)
            return 0xFF;
        if (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate >= 80)
            return 0;
        if (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate < 10)
            return 8;
        return 8 - (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate / 10);
    }
    return 0xFF;
}

void ResetEncounterRateModifiers(void)
{
    sWildEncounterData.encounterRateBuff = 0;
    sWildEncounterData.stepsSinceLastEncounter = 0;
}

static bool8 HandleWildEncounterCooldown(u32 currMetatileBehavior)
{
    u8 encounterType = GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_ENCOUNTER_TYPE);
    u32 minSteps;
    u32 encRate;
    if (encounterType == TILE_ENCOUNTER_NONE)
        return FALSE;
    minSteps = GetMapBaseEncounterCooldown(encounterType);
    if (minSteps == 0xFF)
        return FALSE;
    minSteps *= 256;
    encRate = 5 * 256;
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        minSteps -= minSteps / 2;
        encRate += encRate / 2;
        break;
    case 2:
        minSteps *= 2;
        encRate /= 2;
        break;
    }
    sWildEncounterData.leadMonHeldItem = GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM);
    if (IsLeadMonHoldingCleanseTag() == TRUE)
    {
        minSteps += minSteps / 3;
        encRate -= encRate / 3;
    }
    switch (GetAbilityEncounterRateModType())
    {
    case 1:
        minSteps *= 2;
        encRate /= 2;
        break;
    case 2:
        minSteps /= 2;
        encRate *= 2;
        break;
    }
    minSteps /= 256;
    encRate /= 256;
    if (sWildEncounterData.stepsSinceLastEncounter >= minSteps)
        return TRUE;
    sWildEncounterData.stepsSinceLastEncounter++;
    if ((Random() % 100) < encRate)
        return TRUE;
    return FALSE;
}

bool8 TryStandardWildEncounter(u32 currMetatileBehavior)
{
    if (!HandleWildEncounterCooldown(currMetatileBehavior))
    {
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
    else if (StandardWildEncounter(currMetatileBehavior, sWildEncounterData.prevMetatileBehavior) == TRUE)
    {
        sWildEncounterData.encounterRateBuff = 0;
        sWildEncounterData.stepsSinceLastEncounter = 0;
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR);
        return TRUE;
    }
    else
    {
        sWildEncounterData.prevMetatileBehavior = GetMetatileAttributeFromRawMetatileBehavior(currMetatileBehavior, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
}

static void AddToWildEncounterRateBuff(u8 encounterRate)
{
    if (VarGet(VAR_REPEL_STEP_COUNT) == 0)
        sWildEncounterData.encounterRateBuff += encounterRate;
    else
        sWildEncounterData.encounterRateBuff = 0;
}
