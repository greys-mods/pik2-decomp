#ifndef _GAME_ENEMYINFO_H
#define _GAME_ENEMYINFO_H

#include "types.h"

namespace Game {

extern int gEnemyInfoNum;

struct EnemyInfo {
	char* mName;        // _00
	char mId;           // _04
	char mParentID;     // _05
	char mMembers;      // _06
	u16 mFlags;         // _08
	char* mModelName;   // _0C
	char* mAnimName;    // _10
	char* mAnimMgrName; // _14
	char* mTextureName; // _18
	char* mParamName;   // _1C
	char* mCollName;    // _20
	char* mStoneName;   // _24
	int mChildID;       // _28
	int mChildNum;      // _2C
	char mBitterDrops;  // _30
};

enum EnemyInfoFlags {
	// Note: 2 is enabled anywhere EFlag_CanBeSpawned is, but doesnt seem to do anything

	// 0x100 is also used for a few (dwarf bulborbs and sheargrubs), but doesnt seem to have a purpose
	// It may have originally been another day end take off max count flag, but max 7 is just the default instead

	EFlag_UseOwnID        = 1,     // Should this enemy use its own ID instead of the parent ID
	EFlag_CanBeSpawned    = 4,     // Can be spawned at all, should be true unless youre UmiMushiBase or Pom (seems to only apply to caves)
	EFlag_CanAppearDayEnd = 0x10,  // Can this enemy appear in the day end takeoff at all
	EFlag_DayEndMax1      = 0x20,  // Max 1 of these enemies in day end takeoff
	EFlag_DayEndMax2      = 0x40,  // Max 2 of these enemies in day end takeoff (no enemy seems to use this one in particular)
	EFlag_DayEndMax4      = 0x80,  // Max 4 of these enemies (If none of the max count flags are set, 7 is the max)
	EFlag_HasNoInfo       = 0x200, // Don't track pikmin lost/creatures defeated/piklopedia entered
};

enum EBitterDropType { // ID
	BDT_Weak      = 0,
	BDT_Normal    = 1,
	BDT_Strong    = 2,
	BDT_Triple    = 3,
	BDT_Empty     = 4,
	BDT_EmptyTwo  = 5,
	BDT_MiniBoss  = 6,
	BDT_Boss      = 7,
	BDT_FinalBoss = 8,
};

// clang-format off
struct EnemyTypeID {
enum EEnemyTypeID {       // ID      Common Name
	EnemyID_NULL           = -1,  // ID not set
	EnemyID_Pelplant       = 0,	  // Pellet Posy
	EnemyID_Kochappy       = 1,	  // Dwarf Red Bulborb
	EnemyID_Chappy         = 2,	  // Red Bulborb
	EnemyID_BluePom        = 3,	  // Lapis Lazuli Candypop Bud
	EnemyID_RedPom         = 4,	  // Crimson Candypop Bud
	EnemyID_YellowPom      = 5,	  // Golden Candypop Bud
	EnemyID_BlackPom       = 6,	  // Violet Candypop Bud
	EnemyID_WhitePom       = 7,	  // Ivory Candypop Bud
	EnemyID_RandPom        = 8,	  // Queen Candypop Bud
	EnemyID_Kogane         = 9,	  // Iridescent Flint Beetle
	EnemyID_Wealthy        = 10,  // Iridescent Glint Beetle    							a
	EnemyID_Fart           = 11,  // Doodlebug   															b
	EnemyID_UjiA           = 12,  // Female Sheargrub   											c
	EnemyID_UjiB           = 13,  // Male Sheargrub   												d
	EnemyID_Tobi           = 14,  // Shearwig   															e
	EnemyID_Armor          = 15,  // Cloaking Burrow-nit   										f
	EnemyID_Qurione        = 16,  // Honeywisp   															10
	EnemyID_Frog           = 17,  // Yellow Wollywog   												11
	EnemyID_MaroFrog       = 18,  // Wollywog   															12
	EnemyID_Rock           = 19,  // Falling boulder   												13
	EnemyID_Hiba           = 20,  // Fire geyser   														14
	EnemyID_GasHiba        = 21,  // Gas pipe   															15
	EnemyID_ElecHiba       = 22,  // Electrical wire   												16
	EnemyID_Sarai          = 23,  // Swooping Snitchbug   										17
	EnemyID_Tank           = 24,  // Fiery Blowhog   													18
	EnemyID_Wtank          = 25,  // Watery Blowhog   												19
	EnemyID_Catfish        = 26,  // Water Dumple   													1a
	EnemyID_Tadpole        = 27,  // Wogpole   																1b
	EnemyID_ElecBug        = 28,  // Anode Beetle   													1c
	EnemyID_Mar            = 29,  // Puffy Blowhog   													1d
	EnemyID_Queen          = 30,  // Empress Bulblax   												1e
	EnemyID_Baby           = 31,  // Bulborb Larva   													1f
	EnemyID_Demon          = 32,  // Bumbling Snitchbug   										20
	EnemyID_FireChappy     = 33,  // Fiery Bulblax   													21
	EnemyID_SnakeCrow      = 34,  // Burrowing Snagret   											22
	EnemyID_KumaChappy     = 35,  // Spotty Bulbear  													23
	EnemyID_Bomb           = 36,  // Bomb-rock   															24
	EnemyID_Egg            = 37,  // Egg   																		25
	EnemyID_PanModoki      = 38,  // Breadbug   															26
	EnemyID_PanModokiNest  = 39,  // Breadbug Nest   													27
	EnemyID_OoPanModoki    = 40,  // Giant Breadbug   												28
	EnemyID_Fuefuki        = 41,  // Antenna Beetle   												29
	EnemyID_BlueChappy     = 42,  // Orange Bulborb   												2a
	EnemyID_YellowChappy   = 43,  // Hairy Bulborb   													2b
	EnemyID_BlueKochappy   = 44,  // Dwarf Orange Bulborb   									2c
	EnemyID_YellowKochappy = 45,  // Snow Bulborb   													2d
	EnemyID_Tanpopo        = 46,  // Dandelion   															2e
	EnemyID_Clover         = 47,  // Clover   																2f
	EnemyID_HikariKinoko   = 48,  // Common Glowcap   												30
	EnemyID_Ooinu_s        = 49,  // Figwort (red small)   										31
	EnemyID_Ooinu_l        = 50,  // Figwort (red large)   										32
	EnemyID_Wakame_s       = 51,  // Shoot (small)   													33
	EnemyID_Wakame_l       = 52,  // Shoot (large)   													34
	EnemyID_KingChappy     = 53,  // Emperor Bulblax   												35
	EnemyID_Miulin         = 54,  // Mamuta   																36
	EnemyID_Hanachirashi   = 55,  // Withering Blowhog   											37
	EnemyID_Damagumo       = 56,  // Beady Long Legs   												38
	EnemyID_Kurage         = 57,  // Lesser Spotted Jellyfloat  							39
	EnemyID_BombSarai      = 58,  // Careening Dirigibug   										3a
	EnemyID_FireOtakara    = 59,  // Fiery Dweevil   													3b
	EnemyID_WaterOtakara   = 60,  // Caustic Dweevil   												3c
	EnemyID_GasOtakara     = 61,  // Munge Dweevil   													3d
	EnemyID_ElecOtakara    = 62,  // Anode Dweevil   													3e
	EnemyID_Jigumo         = 63,  // Hermit Crawmad   												3f
	EnemyID_JigumoNest     = 64,  // Hermit Crawmad Nest   										40
	EnemyID_Imomushi       = 65,  // Ravenous Whiskerpillar   								41
	EnemyID_Houdai         = 66,  // Man-at-Legs   														42
	EnemyID_LeafChappy     = 67,  // Bulbmin   																43
	EnemyID_TamagoMushi    = 68,  // Mitite   																44
	EnemyID_BigFoot        = 69,  // Raging Long Legs   											45
	EnemyID_SnakeWhole     = 70,  // Pileated Snagret   											46
	EnemyID_UmiMushi       = 71,  // Ranging Bloyster   											47
	EnemyID_OniKurage      = 72,  // Greater Spotted Jellyfloat 							48
	EnemyID_BigTreasure    = 73,  // Titan Dweevil   													49
	EnemyID_Stone          = 74,  // Rock (projectile)   											4a
	EnemyID_Kabuto         = 75,  // Armored Cannon Beetle Larva							4b
	EnemyID_KumaKochappy   = 76,  // Dwarf Bulbear   													4c
	EnemyID_ShijimiChou    = 77,  // Unmarked Spectralids   									4d
	EnemyID_MiniHoudai     = 78,  // Gatling Groink   												4e
	EnemyID_Sokkuri        = 79,  // Skitter Leaf   													4f
	EnemyID_Tukushi        = 80,  // Horsetail   															50
	EnemyID_Watage         = 81,  // Seeding Dandelion   											51
	EnemyID_Pom            = 82,  // Candypop Bud base (crashes)   						52
	EnemyID_PanHouse       = 83,  // Breadbug Nest   													53
	EnemyID_Hana           = 84,  // Creeping Chrysanthemum   								54
	EnemyID_DaiodoRed      = 85,  // Glowstem (red)   												55
	EnemyID_DaiodoGreen    = 86,  // Glowstem (green)   											56
	EnemyID_Magaret        = 87,  // Margaret   															57
	EnemyID_Nekojarashi    = 88,  // Foxtail   																58
	EnemyID_Chiyogami      = 89,  // Chigoyami paper   												59
	EnemyID_Zenmai         = 90,  // Fiddlehead   														5a
	EnemyID_KareOoinu_s    = 91,  // Figwort (brown small)   									5b
	EnemyID_KareOoinu_l    = 92,  // Figwort (brown large)   									5c
	EnemyID_BombOtakara    = 93,  // Volatile Dweevil   											5d
	EnemyID_DangoMushi     = 94,  // Segmented Crawbster   										5e
	EnemyID_Rkabuto        = 95,  // Decorated Cannon Beetle   								5f
	EnemyID_Fkabuto        = 96,  // Armored Cannon Beetle Larva (burrowed)   60
	EnemyID_FminiHoudai    = 97,  // Gatling Groink (pedestal)   							61
	EnemyID_Tyre           = 98,  // Waterwraith rollers   										62
	EnemyID_BlackMan       = 99,  // Waterwraith   														63
	EnemyID_UmiMushiBase   = 100, // Bloyster base (crashes)   								64
	EnemyID_UmiMushiBlind  = 101, // Toady Bloyster   												65
	EnemyID_COUNT,
	EnemyID_MISC 					 = 0xbadabada,
	EnemyID_MISC2 				 = 0xbedebede
};
EEnemyTypeID mEnemyID; // _00
u8 mCount;             // _04
};
// clang-format on

extern EnemyInfo gEnemyInfo[];

struct EnemyNumInfo {
	EnemyNumInfo()
	    : mEnemyNumList(nullptr)
	{
	}

	static int getOriginalEnemyID(int enemyID);

	void init();
	void resetEnemyNum();
	void addEnemyNum(int enemyID, u8 num);
	u8 getEnemyNum(int enemyID, bool doCheckOriginal);
	u8 getEnemyNumData(int enemyID);

	u8 _00[4];                  // _00
	EnemyTypeID* mEnemyNumList; // _04
};

namespace EnemyInfoFunc {
EnemyInfo* getEnemyInfo(int enemyID, int flags);
char* getEnemyName(int enemyID, int flags);
char* getEnemyResName(int enemyID, int flags);
char getEnemyMember(int enemyID, int flags);
int getEnemyID(char* name, int flags);
} // namespace EnemyInfoFunc

inline int getEnemyMgrID(int enemyID)
{
	int idx = -1;

	for (int i = 0; i < gEnemyInfoNum; i++) {
		char id = gEnemyInfo[i].mId;

		if (id == enemyID) {
			idx = (gEnemyInfo[i].mFlags & EFlag_UseOwnID) ? enemyID : gEnemyInfo[i].mParentID;
		}
	}

	return idx;
}

#define SHIJIMICHOU_GROUP_COUNT 25
#define TAMAGOMUSHI_GROUP_COUNT 30

#define IS_ENEMY_BOSS(id)                                                                                                        \
	(id == EnemyTypeID::EnemyID_Queen || id == EnemyTypeID::EnemyID_SnakeCrow || id == EnemyTypeID::EnemyID_KingChappy           \
	 || id == EnemyTypeID::EnemyID_Damagumo || id == EnemyTypeID::EnemyID_OoPanModoki || id == EnemyTypeID::EnemyID_Houdai       \
	 || id == EnemyTypeID::EnemyID_UmiMushiBlind || id == EnemyTypeID::EnemyID_BlackMan || id == EnemyTypeID::EnemyID_DangoMushi \
	 || id == EnemyTypeID::EnemyID_BigFoot || id == EnemyTypeID::EnemyID_SnakeWhole || id == EnemyTypeID::EnemyID_UmiMushi       \
	 || id == EnemyTypeID::EnemyID_BigTreasure)

} // namespace Game
#endif
