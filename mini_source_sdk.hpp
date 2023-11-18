#pragma once

#include <cmath>
#include <cstring>
#include <cstddef>
#include <cstdint>
#include <cstdlib>

namespace mss {

// variables
inline constexpr const char* interface_version_server_plugin_callbacks = "ISERVERPLUGINCALLBACKS003";
inline constexpr const char* interface_version_engine_cvar = "VEngineCvar004";
inline constexpr const char* interface_version_engine_server = "VEngineServer023";
inline constexpr const char* interface_version_engine_sound = "IEngineSoundServer003";
inline constexpr const char* interface_version_engine_trace = "EngineTraceServer003";
inline constexpr const char* interface_version_game_movement = "GameMovement001";
inline constexpr const char* interface_version_server_game_dll = "ServerGameDLL010";
inline constexpr const char* interface_version_server_game_ents = "ServerGameEnts001";
inline constexpr const char* interface_version_server_game_clients = "ServerGameClients004";
inline constexpr const char* interface_version_player_info_manager = "PlayerInfoManager002";
inline constexpr const char* interface_version_game_event_manager = "GAMEEVENTSMANAGER002";
inline constexpr const char* interface_version_bot_manager = "BotManager001";
inline constexpr const char* interface_version_server_tools = "VSERVERTOOLS003";

inline constexpr int max_coord_integer = 16384;
inline constexpr int min_coord_integer = -max_coord_integer;
inline constexpr int max_coord_fraction = 1.0 - (1.0 / 16.0);
inline constexpr int min_coord_fraction = -1.0 + (1.0 / 16.0);
inline constexpr float max_coord_float = 16384.0f;
inline constexpr float min_coord_float = -max_coord_float;
inline constexpr int coord_extent = 2 * max_coord_integer;
inline constexpr double max_trace_length = 1.732050807569 * coord_extent;

inline constexpr int max_net_message = 6;

inline constexpr int net_msg_type_bits = 6;

inline constexpr int max_players = 65;
inline constexpr int absolute_player_limit = 255;
inline constexpr int max_edicts = 1 << 11;
inline constexpr int max_edict_bits = 11;

inline constexpr int num_ent_entry_bits = max_edict_bits + 1;
inline constexpr int num_ent_entries = 1 << num_ent_entry_bits;
inline constexpr int ent_entry_mask = num_ent_entries - 1;
inline constexpr unsigned long invalid_ehandle_index = 0xffffffff;

inline constexpr double m_pi = 3.14159265358979323846;
inline constexpr float m_pi_f = static_cast<float>(m_pi);

inline constexpr int max_player_name_length = 32;
inline constexpr int signed_guid_len = 32;
inline constexpr int max_custom_files = 4;

inline unsigned long bit_write_masks[32][33];
inline unsigned long little_bits[32];
inline unsigned long extra_masks[33];

inline constexpr int max_weapon_string = 80;
inline constexpr int max_weapon_prefix = 16;
inline constexpr int max_weapon_ammo_name = 32;
inline constexpr int num_shoot_sound_types = 16;

inline constexpr int max_weapons = 48;

inline constexpr int cs_max_weapon = 29;
inline constexpr const char* cs_weapon_names[cs_max_weapon]{
    "weapon_ak47",
    "weapon_aug",
    "weapon_awp",
    "weapon_c4",
    "weapon_deagle",
    "weapon_elite",
    "weapon_famas",
    "weapon_fiveseven",
    "weapon_flashbang",
    "weapon_g3sg1",
    "weapon_galil",
    "weapon_glock",
    "weapon_hegrenade",
    "weapon_knife",
    "weapon_m249",
    "weapon_m3",
    "weapon_m4a1",
    "weapon_mac10",
    "weapon_mp5navy",
    "weapon_p228",
    "weapon_p90",
    "weapon_scout",
    "weapon_sg550",
    "weapon_sg552",
    "weapon_smokegrenade",
    "weapon_tmp",
    "weapon_ump45",
    "weapon_usp",
    "weapon_xm1014"
};
inline constexpr const char* weapon_alias_info[]{
	"none",
	"p228",
	"glock",
	"scout",
	"hegrenade",
	"xm1014",
	"c4",
	"mac10",
	"aug",
	"smokegrenade",
	"elite",
	"fiveseven",
	"ump45",
	"sg550",
	"galil",
	"famas",
	"usp",
	"awp",
	"mp5navy",
	"m249",
	"m3",
	"m4a1",
	"tmp",
	"g3sg1",
	"flashbang",
	"deagle",
	"sg552",
	"ak47",
	"knife",
	"p90",
	"shieldgun",
	"kevlar",
	"assaultsuit",
	"nightvision"
};

// declarations
class IChangeFrameList;
class EffectData;
class SendTablePrecalc;
class IClientEntity;
class IEntityFactoryDictionary;
class CTakeDamageInfo;
class ITempEntsSystem;
class CGlobalEntityList;
class BaseTempEntity;
class IEntityFindFilter;
class SaveRestoreData;
class ServerClass;
class ClientClass;
class GlobalVars;
class Edict;
class CStandardSendProxies;
class IServerGCLobby;
class SendProp;
class DVariant;
class SendProxyRecipients;
class RecvProxyData;
class RecvTable;
class SaveRestoreData;
class IConsoleDisplayFunc;
class Color;
class ICvarQuery;
class ConVar;
class ConCommandBase;
class ConCommand;
class IConVar;
class HudTexture;
class KeyValues;
class AI_Response;
class AI_CriteriaSet;
class IRecipientFilter;
class BaseHandle;
class ICollideable;
class IServerNetworkable;
class ServerClass;
class BaseNetworkable;
class BaseEntity;
class IHandleEntity;
class Edict;
class CTimedEventMgr;
class IEventRegisterCallback;
class EventAction;
class Ray;
class Model;
class IClientUnknown;
class Edict;
class BaseHandle;
class ICollideable;
class IServerNetworkable;
class ServerClass;
class Ray_t;
class CStudioHdr;
class CEntityMapData;
class ISave;
class IRestore;
class IEntitySaveUtils;
class CBaseAnimating;
class IResponseSystem;
class ITraceFilter;
class CTakeDamageInfo;
class CDmgAccumulator;
class CBaseCombatCharacter;
class INextBot;
class CBaseCombatWeapon;
class IServerVehicle;
class EntityEvent_t;
class FireBulletsInfo_t;
class AI_CriteriaSet;
class AngularImpulse;
class CAI_BaseNPC;
class EmitSound_t;
class IPhysicsObject;
class BasePlayer;
class TimedOverlay_t;
class IHasAttributes;
class DamageModifier;
class IKContext;
class AnimationLayer;
class SceneEventInfo;
class ChoreoScene;
class ChoreoActor;
class ChoreoEvent;
class CBaseCombatWeapon;
class IServerVehicle;
class NavArea;
class SkyCamera;
class BotCmd;
class KeyValues;
class Command;
class BaseCombatWeapon;
class IPhysicsPlayerController;
class AI_Expresser;
class HintSystem;
class IMoveHelper;
class MultiplayerExpresser;
class AI_Expresser;
class ClientFrame;
class FrameSnapshot;
class INetChannel;
class NetTick;
class NetStringCmd;
class NetSetConvar;
class NetSignonState;
class NetClientInfo;
class NetBaselineAck;
class NetListenEvents;
class NetCmdKeyValues;
class NetRespondCvarValue;
class BfRead;
class BfWrite;
class NetFileCrcCheck;
class NetFileMd5Check;
class NetSaveReplay;
class NetVoiceData;
class NetMove;
class IGameEvent;
class IDemoRecorder;
class IServer;
class INetChannel;
class INetMessage;
class ClientFrame;
class EventInfo;
class NetMove;
class NetVoiceData;
class NetRespondCvarValue;
class NetFileCrcCheck;
class NetFileMd5Check;
class NetSaveReplay;
class BaseServer;
class FrameSnapshot;
class HLTVServer;
class KeyValues;
class Command;
class ICommandCompletionCallback;
class WeaponCSBase;
class HintMessageQueue;
class CSPlayerStateInfo;
class ICSPlayerAnimState;
class DamageRecord;
class IRecipientFilter;
class BfWrite;
class Edict;
class Vector;
class INetChannelInfo;
class CBitVec;
class ServerClass;
class SendTable;
class VPlane;
class ICollideable;
class ISpatialPartition;
class IScratchPad3D;
class CSharedEdictChangeInfo;
class IChangeInfoAccessor;
class IAchievementMgr;
class CGamestatsData;
class KeyValues;
class IServer;
class CTraceListData;
class ITraceFilter;
class IEntityEnumerator;
class CPhysCollide;
class INetworkStringTable;
class ISteamGameServer;
class ISteamUtils;
class ISteamNetworking;
class ISteamGameServerStats;
class ISteamHTTP;
class ISteamInventory;
class ISteamUGC;
class ISteamApps;
class NetServerInfo;
class NetworkStringTableContainer;
class ShatterSurface_t;
class RecvProp;
class HLTVEntityData;
class ReplayEntityData;

struct GameTrace;
struct CheckTransmitInfo;
struct SteamID;
struct netpacket_t;
struct PlayerInfo;
struct SoundInfo;
struct UserId;
struct trace_t;
struct variant_t;
struct notify_system_event_params_t;
struct gamevcollisionevent_t;
struct thinkfunc_t;
struct response_context_t;
struct datamap_t;
struct PVSInfo;
struct Quaternion;
struct animevent_t;
struct memhandle_t;
struct FS_LocalToGlobal;
struct impactdamagetable_t;
struct SoundParameters;
struct surfacedata_t;
struct autoim_params_t;
struct inputdata;
struct soundlevel_t;
struct con_nprint_s;
struct client_textmessage_t;
struct QueryCvarCookie_t;
struct bbox_t;
struct SndInfo;
struct CrtMemState;
struct datamap_t;
struct typedescription_t;

enum class InterfaceReturnStatus;
enum class QueryCvarValueStatus;
enum class PrepareLevelResourcesResult;
enum class CanProvideLevelResult;
enum class IAppSystemReturnValue;
enum class FieldType;
enum class SolidType;
enum class NotifySystemEvent;
enum class UseType;
enum class Class_T;
enum class Activity;
enum class ClassType;
enum class Hull;
enum class WeaponProficiency;
enum class Disposition;
enum class SoundLevel;
enum class CSPlayerState;
enum class GooseChaseAchievementStep;
enum class DefuseDefenseAchivementStep;
enum class IntervalType;
enum class MapLoadType;
enum class StepSoundTime;
enum class PlayerAnimation;
enum class PlayerConnectedState;
enum class NetAdrType;
enum class ServerType;

using CreateInterface = void* (*)(const char*, InterfaceReturnStatus*);
using ChangeCallback = void (*)(IConVar*, const char*, float);
using MemAllocFailHandler = size_t (*)(size_t);
using StringChanged = void (*)(void*, INetworkStringTable*, int, const char, const void*);
using ArrayLengthRecvProxy =  void (*)(void*, int, int);
using RecvVarProxy = void (*)(const RecvProxyData*, void*, void*);
using DataTableRecvVarProxy = void (*)(const RecvProp*, void**, void*, int);
using ArrayLengthSendProxy = int (*)(const void*, int);
using SendVarProxy = void (*)( const SendProp*, const void*, const void*, DVariant*, int, int objectID);
using SendTableProxy = void* (*)(const SendProp*, const void*, const void*, SendProxyRecipients*, int);

enum class FixAngle {
	NONE,
	ABSOLUTE,
	RELATIVE
};

enum class NetMessageType {
	NOP,
	DISCONNECT,
	FILE,
	TICK,
	STRING_CMD,
	SET_CONVAR,
	SIGNON_STATE,
	PRINT,
	SERVER_INFO,
	SEND_TABLE,
	CLASS_INFO,
	SET_PAUSE,
	CREATE_STRING_TABLE,
	UPDATE_STRING_TABLE,
	VOICE_INIT,
	VOICE_DATA,
	SOUNDS = 17,
	SET_VIEW,
	FIX_ANGLE,
	CROSSHAIR_ANGLE,
	BSP_DECAL,
	USER_MESSAGE = 23,
	ENTITY_MESSAGE,
	GAME_EVENT,
	PACKET_ENTITIES,
	TEMP_ENTITIES,
	PREFETCH,
	MENU,
	GAME_EVENT_LIST,
	GET_CVAR_VALUE,
	CMD_KEY_VALUES,
	SET_PAUSE_TIMED
};

enum class NetMessageGroup {
	GENERIC,
	LOCAL_PLAYER,
	OTHER_PLAYERS,
	ENTITIES,
	SOUNDS,
	EVENTS,
	USER_MESSAGES,
	ENT_MESSAGES,
	VOICE,
	STRING_TABLE,
	MOVE,
	STRING_CMD,
	SIGNON
};

enum class Flow {
	OUTGOING,
	INCOMING
};

enum class UpdateType {
	ENTER_PVS,
	LEAVE_PVS,
	DELTA_ENT,
	PRESERVE_ENT,
	FINISHED,
	FAILED
};

enum class ServerMode {
    INVALID,
    NO_AUTHENTICATION,
    AUTHENTICATION,
    AUTHENTICATION_AND_SECURE
};

enum class ServerState {
	DEAD,
	LOADING,
	ACTIVE,
	PAUSED
};

enum class PluginResult {
	CONTINUE,
	OVERRIDE,
	STOP
};

enum class SendPropType {
	INT,
	FLOAT,
	VECTOR_3D,
	VECTOR_2D,
	STRING,
	ARRAY,
	DATA_TABLE,
	NUM_SEND_PROP_TYPES
};

enum class ObserverMode {
	NONE,
	DEATH_CAM,
	FREEZE_CAM,
	FIXED,
	IN_EYE,
	CHASE,
	POI,
	ROAMING
};

enum class MoveType {
	NONE,
	ISOMETRIC,
	WALK,
	STEP,
	FLY,
	FLY_GRAVITY,
	VPHYSICS,
	PUSH,
	NOCLIP,
	LADDER,
	OBSERVER,
	CUSTOM
};

enum class TraceType {
	EVERYTHING,
	WORLD_ONLY,
	ENTITIES_ONLY,
	EVERYTHING_FILTER_PROPS
};

enum class FindMapResult {
	FOUND,
	NOT_FOUND,
	FUZZY_MATCH,
	NON_CANONICAL,
	POSSIBLY_AVAILABLE
};

enum class CSWeaponID {
	NONE,
	P228,
	GLOCK,
	SCOUT,
	HEGRENADE,
	XM1014,
	C4,
	MAC10,
	AUG,
	SMOKEGRENADE,
	ELITE,
	FIVESEVEN,
	UMP45,
	SG550,
	GALIL,
	FAMAS,
	USP,
	AWP,
	MP5NAVY,
	M249,
	M3,
	M4A1,
	TMP,
	G3SG1,
	FLASHBANG,
	DEAGLE,
	SG552,
	AK47,
	KNIFE,
	P90,
	SHIELDGUN,
	KEVLAR,
	ASSAULTSUIT,
	NVG
};

enum class CSWeaponMode {
	PRIMARY,
	SECONDARY
};

enum class WeaponSound {
	EMPTY,
	SINGLE,
	SINGLE_NPC,
	WPN_DOUBLE,
	DOUBLE_NPC,
	BURST,
	RELOAD,
	RELOAD_NPC,
	MELEE_MISS,
	MELEE_HIT,
	MELEE_HIT_WORLD,
	SPECIAL1,
	SPECIAL2,
	SPECIAL3,
	TAUNT,
	DEPLOY,
};

enum class SignonState {
    NONE,
    CHALLENGE,
    CONNECTED,
    NEW,
    PRESPAWN,
    FULL,
    CHANGE_LEVEL
};

enum class SolidType {
    NONE,
    BSP,
    BBOX,
    OBB,
    OBB_YAW,
    CUSTOM,
    VPHYSICS,
};

enum class SoundChannel {
    REPLACE = -1,
    AUTO = 0,
    WEAPON,
    VOICE,
    ITEM,
    BODY,
    STREAM,
    STATIC,
    VOICE2,
    VOICE_BASE,
    USER_BASE = VOICE_BASE + 128
};

enum class SoundPitch {
    NORM = 100,
    LOW = 95,
    HIGH = 120
};

enum class CSPlayerState {
    ACTIVE,
    WELCOME,
    PICKING_TEAM,
    PICKING_CLASS,
    DEATH_ANIM,
    DEATH_WAIT_FOR_KEY,
    OBSERVER_MODE
};

enum class NetChannelGroup {
	GENERIC,
	LOCALPLAYER,
	OTHERPLAYERS,
	ENTITIES,
	SOUNDS,
	EVENTS,
	USERMESSAGES,
	ENTMESSAGES,
	VOICE,
	STRINGTABLE,
	MOVE,
	STRINGCMD,
	SIGNON,
	TOTAL,
};

enum class LineOfSightCheckType {
	IGNORE_NOTHING,
	IGNORE_ACTORS
};

enum class InterfaceReturnStatus {
	OK,
	FAILED
};

enum class AccountUniverse {
	INVALID,
	PUBLIC,
	BETA,
	INTERNAL,
	DEV,
	MAX
};

enum class AccountType {
	INVALID,
	INDIVIDUAL,
	MULTISEAT,
	GAME_SERVER,
	ANON_GAME_SERVER,
	PENDING,
	CONTENT_SERVER,
	CLAN,
	CHAT,
	CONSOLE_USER,
	ANON_USER
};

enum class TakeDamage {
    NO,
    EVENTS_ONLY,
    YES,
    AIM
};

enum class HudDestination {
    NOTIFY = 1,
    CONSOLE,
    TALK,
    CENTER
};

enum class LifeState {
    ALIVE,
    DYING,
    DEAD,
    RESPAWNABLE,
    DISCARD_BODY
};

namespace SoundAttenuation {
    inline constexpr float NONE = 0.0f;
    inline constexpr float NORM = 0.8f;
    inline constexpr float IDLE = 2.0f;
    inline constexpr float STATIC = 1.25f;
    inline constexpr float RICOCHET = 1.5f; 
}

namespace SoundVolume {
    inline constexpr float NORM = 1.0f;
}

namespace PlayerFlags {
    enum {
        ON_GROUND = 1 << 0,
        DUCKING = 1 << 1,
        ANIM_DUCKING = 1 << 2,
        WATER_JUMP = 1 << 3,
        ON_TRAIN = 1 << 4,
        IN_RAIN = 1 << 5,
        FROZEN = 1 << 6,
        AT_CONTROLS = 1 << 7,
        CLIENT = 1 << 8,
        FAKE_CLIENT = 1 << 9,
        IN_WATER = 1 << 10
    };
}

namespace PlayerButtons {
    enum {
        ATTACK = 1 << 0,
        JUMP = 1 << 1,
        DUCK = 1 << 2,
        FORWARD = 1 << 3,
        BACK = 1 << 4,
        USE = 1 << 5,
        CANCEL = 1 << 6,
        LEFT = 1 << 7,
        RIGHT = 1 << 8,
        MOVE_LEFT = 1 << 9,
        MOVE_RIGHT = 1 << 10,
        ATTACK2 = 1 << 11,
        RUN = 1 << 12,
        RELOAD = 1 << 13,
        ALT1 = 1 << 14,
        ALT2 = 1 << 15,
        SCORE = 1 << 16,
        SPEED = 1 << 17,
        WALK = 1 << 18,
        ZOOM = 1 << 19,
        WEAPON1 = 1 << 20,
        WEAPON2 = 1 << 21,
        BULL_RUSH = 1 << 22,
        GRENADE1 = 1 << 23,
        GRENADE2 = 1 << 24,
        ATTACK3 = 1 << 25,
    };
};

namespace PhysicsFlags {
    enum {
        DIR_OVERRIDE = 1 << 0,
        DUCKING = 1 << 1,
        USING = 1 << 2,
        OBSERVER = 1 << 3,
        VPHYSICS_MOTION_CONTROLLER = 1 << 4,
        GAME_PHYSICS_ROTPUSH = 1 << 5
    };
}

namespace HideHud {
    enum {
        WEAPON_SELECTION = 1 << 0,
        FLASHLIGHT = 1 << 1,
        ALL = 1 << 2,
        HEALTH = 1 << 3,
        PLAYER_DEAD = 1 << 4,
        NEED_SUIT = 1 << 5,
        MISC_STATUS = 1 << 6,
        CHAT = 1 << 7,
        CROSSHAIR = 1 << 8,
        VEHICLE_CROSSHAIR = 1 << 9,
        IN_VEHICLE = 1 << 10,
        BONUS_PROGRESS = 1 << 11
    }; 
}

namespace EntityFlags {
	enum {
		KILLME = 1 << 0,
		DORMANT = 1 << 1,
		NOCLIP_ACTIVE = 1 << 2,
		SETTING_UP_BONES = 1 << 3,
		KEEP_ON_RECREATE_ENTITIES = 1 << 4,
		HAS_PLAYER_CHILD = 1 << 4,
		DIRTY_SHADOW_UPDATE = 1 << 5,
		NOTIFY = 1 << 6,
		FORCE_CHECK_TRANSMIT = 1 << 7,
		BOT_FROZEN = 1 << 8,
		SERVER_ONLY = 1 << 9,
		NO_AUTO_EDICT_ATTACk = 1 << 10,
		DIRTY_ABS_TRANSFORM = 1 << 11,
		DIRTY_ABS_VELOCITY = 1 << 12,
		DIRTY_ABS_ANG_VELOCITY = 1 << 13,
		DIRTY_SURROUNDING_COLLISION_BOUNDS = 1 << 14,
		DIRTY_SPATIAL_PARTITION = 1 << 15,
		DIRTY_IN_SKYBOX = 1 << 17,
		USE_PARITION_WHEN_NOT_SOLID = 1 << 18,
		TOUCHING_FLUID = 1 << 19,
		IS_BEING_LIFTED_BY_BARNACLE = 1 << 20,
		NO_ROTORWASH_PUSH = 1 << 21,
		NO_THINK_FUNCTION = 1 << 22,
		NO_GAME_PHYSICS_SIMULATION = 1 << 23,
		CHECK_UNTOUCH = 1 << 24,
		DONT_BLOCK_LOS = 1 << 25,
		DONT_WALK_ON = 1 << 26,
		NO_DISSOLVE = 1 << 27,
		NO_MEGA_PHYS_CANNON_RAGDOLL = 1 << 28,
		NO_WATER_VELOCITY_CHANGE = 1 << 29,
		NO_PHYS_CANNON_INTERACTION = 1 << 30,
		NO_DAMAGE_FORCES = 1 << 31
	};
}

namespace EntityEffects {
	enum {
		BONE_MERGE = 1 << 0,
		BRIGHT_LIGHT = 1 << 1,
		DIM_LIGHT = 1 << 2,
		NO_INTERP = 1 << 3,
		NO_SHADOW = 1 << 4,
		NO_DRAW = 1 << 5,
		NO_RECEIVE_SHADOW = 1 << 6,
		NO_BONE_MERGE_FAST_CULL = 1 << 7,
		ITEM_BLINK = 1 << 8,
		PARENT_ANIMATES = 1 << 9
	};
}

namespace EdictFlags {
    enum {
        CHANGED = 1 << 0,
        FREE = 1 << 1,
        FULL = 1 << 2,
        FULL_CHECK = 0 << 0,
        ALWAYS = 1 << 3,
        DONT_SEND = 1 << 4,
        PVS_CHECK = 1 << 5,
        PENDING_DORMANT_CHECK = 1 << 6,
        DIRTY_PVS_INFORMATION = 1 << 7,
        FULL_EDICT_CHANGED = 1 << 8,
    };
}

namespace ContentFlags {
	enum {
		EMPTY = 0,
		SOLID = 0x1,
		WINDOW = 0x2,
		AUX = 0x4,
		GRATE = 0x8,
		SLIME = 0x10,
		WATER = 0x20,
		BLOCKLOS = 0x40,
		OPAQUE = 0x80,
		LAST_VISIBLE = 0x80,
		ALL_VISIBLE = LAST_VISIBLE | (LAST_VISIBLE - 1),
		TEST_FOG_VOLUME = 0x100,
		UNUSED = 0x200,
		UNUSED6 = 0x400,
		TEAM1 = 0x800,
		TEAM2 = 0x1000,
		IGNORE_NODRAW_OPAQUE = 0x2000,
		MOVEABLE = 0x4000,
		AREA_PORTAL = 0x8000,
		PLAYER_CLIP = 0x10000,
		MONSTER_CLIP = 0x20000,
		CURRENT_0 = 0x40000,
		CURRENT_90 = 0x80000,
		CURRENT_180 = 0x100000,
		CURRENT_270 = 0x200000,
		CURRENT_UP = 0x400000,
		CURRENT_DOWN = 0x800000,
		ORIGIN = 0x1000000,
		MONSTER = 0x2000000,
		DEBRIS = 0x4000000,
		DETAIL = 0x8000000,
		TRANSLUCENT = 0x10000000,
		LADDER = 0x20000000,
		HITBOX = 0x40000000,
	};
}

namespace ContentsMasks {
	enum {
		ALL = 0xffffffff,
		SOLID = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::WINDOW | ContentFlags::MONSTER | ContentFlags::GRATE,
		PLAYER_SOLID = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::PLAYER_CLIP | ContentFlags::WINDOW | ContentFlags::MONSTER | ContentFlags::GRATE,
		NPC_SOLID = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::MONSTER_CLIP | ContentFlags::WINDOW | ContentFlags::MONSTER | ContentFlags::GRATE,
		WATER = ContentFlags::WATER | ContentFlags::MOVEABLE | ContentFlags::SLIME,
		OPAQUE = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::OPAQUE,
		OPAQUE_AND_NPCS = OPAQUE | ContentFlags::MONSTER,
		BLOCKLOS = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::BLOCKLOS,
		BLOCKLOS_AND_NPCS = ContentFlags::BLOCKLOS | ContentFlags::MONSTER,
		VISIBLE = OPAQUE | ContentFlags::IGNORE_NODRAW_OPAQUE,
		VISIBLE_AND_NPCS = OPAQUE_AND_NPCS | ContentFlags::IGNORE_NODRAW_OPAQUE,
		SHOT = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::MONSTER | ContentFlags::WINDOW | ContentFlags::DEBRIS | ContentFlags::HITBOX,
		SHOT_HULL = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::MONSTER | ContentFlags::WINDOW | ContentFlags::DEBRIS | ContentFlags::GRATE,
		SHOT_PORTAL = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::WINDOW | ContentFlags::MONSTER,
		SOLID_BRUSH_ONLY = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::WINDOW | ContentFlags::GRATE,
		PLAYER_SOLID_BRUSH_ONLY = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::WINDOW | ContentFlags::PLAYER_CLIP | ContentFlags::GRATE,
		NPC_SOLID_BRUSH_ONLY = ContentFlags::SOLID | ContentFlags::MOVEABLE | ContentFlags::WINDOW | ContentFlags::MONSTER_CLIP | ContentFlags::GRATE,
		NPC_WORLD_STATIC = ContentFlags::SOLID | ContentFlags::WINDOW | ContentFlags::MONSTER_CLIP | ContentFlags::GRATE,
		SPLIT_AREA_PORTAL = ContentFlags::WATER | ContentFlags::SLIME,
		CURRENT = ContentFlags::CURRENT_0 | ContentFlags::CURRENT_90 | ContentFlags::CURRENT_180 | ContentFlags::CURRENT_270 | ContentFlags::CURRENT_UP | ContentFlags::CURRENT_DOWN,
		DEAD_SOLID = ContentFlags::SOLID | ContentFlags::PLAYER_CLIP | ContentFlags::WINDOW | ContentFlags::GRATE
	};
}

namespace CollisionGroup {
    enum {
        NONE,
        DEBRIS,
        DEBRIS_TRIGGER,
        INTERACTIVE_DEBRIS,
        INTERACTIVE,
        PLAYER,
        BREAKABLE_GLASS,
        VEHICLE,
        PLAYER_MOVEMENT,
        NPC,
        IN_VEHICLE,
        WEAPON,
        VEHICLE_CLIP,
        PROJECTILE,
        DOOR_BLOCKER,
        PASSABLE_DOOR,
        DISSOLVING,
        PUSH_AWAY,
        NPC_ACTOR,
        NPC_SCRIPTED
    };
}

namespace ConvarFlags {
    enum {
        NONE = 0,
        UNREGISTERED = 1 << 0,
        DEVELOPMENT_ONLY = 1 << 1,
        GAME_DLL = 1 << 2,
        CLIENT_DLL = 1 << 3,
        HIDDEN = 1 << 4,
        PROTECTED = 1 << 5,
        SP_ONLY = 1 << 6,
        ARCHIVE = 1 << 7,
        NOTIFY = 1 << 8,
        USER_INFO = 1 << 9,
        CHEAT = 1 << 14,
        PRINTABLE_ONLY = 1 << 10,
        UNLOGGED = 1 << 11,
        NEVER_AS_STRING = 1 << 12,
        REPLICATED = 1 << 13,
        DEMO = 1 << 16,
        DONT_RECORD = 1 << 17,
        NOT_CONNECTED = 1 << 22,
        ARCHIVE_XBOX = 1 << 24,
        SERVER_CAN_EXECUTE = 1 << 28,
        SERVER_CANNOT_QUERY = 1 << 29,
        CLIENT_CMD_CAN_EXECUTE = 1 << 30
    };
};

struct netadr_t {
public:
    NetAdrType type;
    unsigned char ip[4];
    unsigned short port;
};

struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};

class AI_ExpresserSink {
public:
	virtual void on_spoke_concept(const char* c, AI_Response* response);
	virtual void on_start_speaking();
	virtual bool use_semaphore();
};

template <class B>
class AI_ExpresserHost : public B, protected AI_ExpresserSink {
public:
    virtual void note_speaking(float duration, float delay);
	virtual bool speak(const char* c, const char* modifiers=nullptr, char* out_response_chosen=nullptr, unsigned int buf_size=0, IRecipientFilter* filter=nullptr);
	virtual void post_speak_dispatch_response(const char* c, AI_Response& response);
};

class Vector {
public:
	float x;
	float y;
	float z;

	Vector();
	Vector(float x, float y, float z);
	float operator[](int i) const;
	float& operator[](int i);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator*(const Vector& v) const;
	Vector operator*(const float v) const;
	Vector operator/(const Vector& v) const;
	bool operator==(const Vector& v) const;
	bool operator!=(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector& operator*=(const Vector& v);
	Vector& operator/=(const Vector& v);
	Vector operator-();
	void zero();
	Vector min(const Vector& v) const;
	Vector max(const Vector& v) const;
	float dist_to(const Vector& v) const;
	float dot(const Vector& v) const;
	float normalize();
	float length() const;
	float length_2d() const;
	float length_sqr() const;
};

class VectorAligned : public Vector {
public:
	float w;

	using Vector::operator=;
};

class AI_MoveMonitor {
public:
	Vector mark;
	float mark_tolerance;
};

class IAppSystem {
public:
	virtual bool connect(CreateInterface factory) = 0;
	virtual void disconnect() = 0;
	virtual void query_interface(const char* name) = 0;
	virtual IAppSystemReturnValue init() = 0;
	virtual void shutdown() = 0;
};

class IHandleEntity {
public:
	virtual ~IHandleEntity();
	virtual void set_ref_e_handle(const BaseHandle& handle) = 0;
	virtual const BaseHandle& get_ref_e_handle() const = 0;
};

class IServerUnknown: public IHandleEntity {
public:
	virtual ICollideable* get_collideable() = 0;
	virtual IServerNetworkable* get_networkable() = 0;
	virtual BaseEntity* get_base_entity() = 0;
};

class IServerEntity: public IServerUnknown {
public:
	virtual ~IServerEntity();
	virtual int get_model_index() const = 0;
	virtual const char* get_model_name() const = 0;
	virtual void set_model_index(int index) = 0;
};

class IServerNetworkable {
public:
	virtual IHandleEntity* get_entity_handle() = 0;
	virtual ServerClass* get_server_class() = 0;
	virtual Edict* get_edict() const = 0;
	virtual const char* get_class_name() const = 0;
	virtual void release() = 0;
	virtual int get_area_num() const = 0;
	virtual BaseNetworkable* get_base_networkable() = 0;
	virtual BaseEntity* get_base_entity() = 0;
	virtual PVSInfo* get_pvs_info() = 0;

protected:
	virtual ~IServerNetworkable();
};

class IEventRegisterCallback {
public:
	virtual void fire_event() = 0;
};

struct PVSInfo {
	short head_node; 
	short cluster_count; 
	unsigned short* clusters; 
	short area_num;
	short area_num2;
	float center[3];

private:
	unsigned short clusters_inline[4];
};

class BaseHandle {
public:
	bool operator==(const BaseHandle& other) const;

	inline
	int get_entry_index() const {
		return this->index & ent_entry_mask;
	}

	inline
	bool is_valid() const {
		return this->index != invalid_ehandle_index;
	}

	unsigned long index;
};

class EventRegister {
public:
	CTimedEventMgr* event_mgr;
	float next_event_time;
	float update_interval;
	IEventRegisterCallback* callback;
	bool is_registered;
};

class ServerNetworkProperty: public IServerNetworkable, public IEventRegisterCallback {
public:
	virtual ~ServerNetworkProperty();
	virtual datamap_t* get_data_desc_map();
	virtual IHandleEntity* get_entity_handle();
	virtual ServerClass* get_server_class();
	virtual Edict* get_edict() const;
	virtual const char* get_class_name() const;
	virtual void release();
	virtual int get_area_num() const;
	virtual BaseNetworkable* get_base_networkable();
	virtual BaseEntity* get_base_entity();
	virtual PVSInfo* get_pvs_info();
	virtual void fire_event();

	BaseEntity* outer;
	Edict* edict;
	PVSInfo pvs_info;
	ServerClass* server_class;
	BaseHandle parent;
	EventRegister timer_event;
	bool is_pending_state_change;
};

struct Color32 {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

class Variant {
public:
	union {
		bool b;
		const char* s;
		int i;
		float f;
		float v[3];
		Color32 rgb;
	};

	BaseHandle h;
	FieldType field_type;
};

class BaseEntityOutput {
public:
	Variant value;
	EventAction* action_list;
};

struct Matrix3x4 {
	float values[3][4];
};

class QAngle {
public:
	float x;
	float y;
	float z;

    bool operator!=(const QAngle& v) const;

	void get_angle_vectors(Vector* forward) const;
	void get_angle_vectors(Vector* forward, Vector* right, Vector* up) const;
};

template <class T, class I = int>
class UtlMemory {
public:
	class Iterator {
	public:
		I index;

		bool operator==(const Iterator it) const {
			return index == it.index;
		}

		bool operator!=(const Iterator it) const {
			return index != it.index;
		}
	};

	inline
	T* base() {
		return this->memory;
	}

	inline
	int num_allocated() const {
		return this->allocation_count;
	}

	inline
	T& operator[](I i) const {
		return this->memory[static_cast<unsigned int>(i)];
	}

	inline
	bool is_externally_allocated() const {
		return this->grow_size < 0;
	}

	inline
	int calc_new_allocation_count(int new_size) {
		int new_allocation_count = this->allocation_count;

		if (this->grow_size)
			new_allocation_count = (1 + ((new_size - 1) / this->grow_size)) * this->grow_size;
		else {
			if (!new_allocation_count)
				new_allocation_count = (31 + sizeof(T)) / sizeof(T);

			while (new_allocation_count < new_size)
				new_allocation_count *= 2;
		}

		return new_allocation_count;
	}

	inline
	void grow(int num) {
		if (this->is_externally_allocated())
			return;

		int allocation_requested = this->allocation_count + num;
		int new_allocation_count = this->calc_new_allocation_count(allocation_requested);

		if (static_cast<int>(static_cast<I>(new_allocation_count)) < allocation_requested) {
			if (static_cast<int>(static_cast<I>(new_allocation_count)) == 0 && static_cast<int>(static_cast<I>(new_allocation_count - 1)) >= allocation_requested)
				--new_allocation_count;
			else {
				if (static_cast<int>(static_cast<I>(allocation_requested)) != allocation_requested)
					return;

				while (static_cast<int>(static_cast<I>(new_allocation_count)) < allocation_requested)
					new_allocation_count = (new_allocation_count + allocation_requested) / 2;
			}
		}

		this->allocation_count = new_allocation_count;

		if (this->memory)
			this->memory = static_cast<T*>(std::realloc(this->memory, this->allocation_count * sizeof(T)));
		else
			this->memory = static_cast<T*>(std::malloc(this->allocation_count * sizeof(T)));
	}

	static
	I invalid_index() {
		return (I)-1;
	}

	T* memory;
	int allocation_count;
	int grow_size;
};

template <class T> inline
T* construct(T* memory) {
	return reinterpret_cast<T*>(::new(memory) T);
}

template <class T> inline
T* copy_construct(T* memory, T const& src) {
	return reinterpret_cast<T*>(::new(memory) T{src});
}

template <typename T, typename A=UtlMemory<T>>
class UtlVector {
public:
	inline
	int count() const {
		return this->size;
	}

	inline
	const T& operator[](int i) const {
		return this->memory[i];
	}

	inline
	T& operator[](int i) {
		return this->memory[i];
	}

	inline
	const T& element(int i) const {
		return this->memory[i];
	}

	inline
	T& element(int i) {
		return this->memory[i];
	}

	inline
	T* base() {
		return this->memory.base();
	}

	inline
	void reset_dbg_info() {
		this->elements = this->base();
	}

	inline
	void grow_vector(int num) {
		if (this->size + num > this->memory.num_allocated())
			this->memory.grow(this->size + num - this->memory.num_allocated());

		this->size += num;
		this->reset_dbg_info();
	}

	inline
	void shift_elements_right(int elem, int num) {
		int num_to_move = this->size - elem - num;

		if (num_to_move > 0 && num > 0)
			std::memmove(&this->element(elem + num), &this->element(elem), num_to_move * sizeof(T));
	}

	inline
	int insert_before(int elem) {
		this->grow_vector(1);
		this->shift_elements_right(elem, 1);
		construct(&this->element(elem));

		return elem;
	}

	inline
	int insert_before(int elem, const T& src) {
		this->grow_vector(1);
		this->shift_elements_right(elem, 1);
		copy_construct(&this->element(elem), src);

		return elem;
	}

	inline
	int add_to_tail() {
		return this->insert_before(this->size);
	}

	inline
	int add_to_tail(const T& src) {
		return this->insert_before(this->size, src);
	}

	A memory;
	int size;
	T* elements;
};

template <class T, class I> 
struct UtlLinkedListElem {
	T element;
	I previous;
	I next;
};

template <class T, class S = unsigned short, bool ML = false, class I = S, class M = UtlMemory<UtlLinkedListElem<T, S>, I>> 
class UtlLinkedList {
public:
	M memory;
	I head;
	I tail;
	I first_tree;
	I element_count;
	I num_alloced;
	typename M::Iterator last_alloc;
	UtlLinkedListElem<T, S>* elements;
};

class ICollideable {
public:
	virtual IHandleEntity* get_entity_handle() = 0;
	virtual const Vector& obb_mins_pre_scaled() const = 0;
	virtual const Vector& obb_maxs_pre_scaled() const = 0;
	virtual const Vector& obb_mins() const = 0;
	virtual const Vector& obb_maxs() const = 0;
	virtual void world_space_trigger_bounds( Vector *pVecWorldMins, Vector *pVecWorldMaxs ) const = 0;
	virtual bool test_collision(const Ray& ray, unsigned int contents_mask, GameTrace& tr) = 0;
	virtual bool test_hitboxes(const Ray& ray, unsigned int contents_mask, GameTrace& tr) = 0;
	virtual int get_collision_model_index() = 0;
	virtual const Model* get_collision_model() = 0;
	virtual const Vector& get_collision_origin() const = 0;
	virtual const QAngle& get_collision_angles() const = 0;
	virtual const Matrix3x4& collision_to_world_transform() const = 0;
	virtual SolidType get_solid() const = 0;
	virtual int get_solid_flags() const = 0;
	virtual IClientUnknown*	get_client_unknown() = 0;
	virtual int get_collision_group() const = 0;
	virtual void world_space_surrounding_bounds(Vector* mins, Vector* maxs) = 0;
	virtual bool should_touch_trigger(int flags) const = 0;
	virtual const Matrix3x4* get_root_parent_to_world_transform() const = 0;
};

class CollisionProperty : public ICollideable {
public:
    virtual IHandleEntity* get_entity_handle();
	virtual const Vector& obb_mins_pre_scaled() const;
	virtual const Vector& obb_maxs_pre_scaled() const;
	virtual const Vector& obb_mins() const;
	virtual const Vector& obb_maxs() const;
	virtual void world_space_trigger_bounds(Vector* world_mins, Vector* world_maxs) const;
	virtual bool test_collision(const Ray& ray, unsigned int contents_mask, GameTrace& tr);
	virtual bool test_hitboxes(const Ray& ray, unsigned int contents_mask, GameTrace& tr);
	virtual int get_collision_model_index();
	virtual const Model* get_collision_model();
	virtual const Vector& get_collision_origin() const;
	virtual const QAngle& get_collision_angles() const;
	virtual const Matrix3x4& collision_to_world_transform() const;
	virtual SolidType get_solid() const;
	virtual int get_solid_flags() const;
	virtual IClientUnknown*	get_client_unknown();
	virtual int get_collision_group() const;
	virtual void world_space_surrounding_bounds(Vector* mins, Vector* maxs);
	virtual bool should_touch_trigger(int flags) const;
	virtual const Matrix3x4* get_root_parent_to_world_transform() const;

    virtual void network_state_changed();
    virtual void network_state_changed(void*);
    virtual datamap_t* get_data_desc_map();

	BaseEntity* outer;
    Vector mins_pre_scaled;
    Vector maxs_pre_scaled;
    Vector mins;
    Vector maxs;
    float radius;
    unsigned short solid_flags;
	unsigned short partition;
    unsigned char surround_type;
    unsigned char solid_type;
    unsigned char trigger_bloat;
    Vector specified_surrounding_mins_pre_scaled;
    Vector specified_surrounding_maxs_pre_scaled;
    Vector specified_surrounding_mins;
    Vector specified_surrounding_maxs;
	Vector surrounding_mins;
	Vector surrounding_maxs;
};

class BaseEntity: public IServerEntity {
public:
	// DECLARE_SERVERCLASS();
	virtual ServerClass* get_server_class();
	virtual int you_forgot_to_implement_or_declare_server_class();

	// DECLARE_DATADESC();
	virtual datamap_t* get_data_desc_map();

	virtual void set_model_index_override(int index, int value);
	virtual bool test_collision(const Ray_t& ray, unsigned int mask, trace_t& trace);
	virtual bool test_hitboxes(const Ray_t &ray, unsigned int mask, trace_t& trace);
	virtual void compute_world_space_surrounding_box(Vector* mins, Vector* maxs);
	virtual bool should_collide(int collision_group, int mask) const;
	virtual void set_owner_entity(BaseEntity* owner);
	virtual int should_transmit(const CheckTransmitInfo* info);
	virtual int update_transmit_state();
	virtual void set_transmit(CheckTransmitInfo* info, bool always);
	virtual const char* get_tracer_type();
	virtual void spawn();
	virtual void precache();
	virtual void set_model(const char* model_name);
	virtual CStudioHdr* on_new_model();
	virtual void post_constructor(const char* class_name);
	virtual void post_client_active();
	virtual void parse_map_data(CEntityMapData* map_data);
	virtual bool get_key_value(const char* key, const char* value);
	virtual bool get_key_value(const char* key, float value);
	virtual bool get_key_value(const char* key, const Vector& value);
	virtual bool get_key_value(const char* key, char* value, int max_len);
	virtual void activate();
	virtual void set_parent(BaseEntity* p, int attachment=-1);
	virtual int object_caps();
	virtual bool accept_input(const char* input_name, BaseEntity* activator, BaseEntity* caller, variant_t value, int output_id);
	virtual void get_input_dispatch_effect_position(const char* input, Vector& origin, QAngle& angles);
	virtual void draw_debug_geometry_overlays(); 	 	 
	virtual int draw_debug_text_overlys();
	virtual int save(ISave& save);
	virtual int restore(IRestore& restore);
	virtual bool should_save_physics();
	virtual void on_save(IEntitySaveUtils* save_utls);
	virtual void on_restore();
	virtual int required_edict_index(); 
	virtual void move_done();
	virtual void think();
	virtual void network_state_changed_next_think_tick();
	virtual void network_state_changed_next_think_tick(void*);
	virtual CBaseAnimating* get_base_animating();
	virtual IResponseSystem* get_response_system();
	virtual void dispatch_response(const char* concept_name);
	virtual Class_T classify();
	virtual void death_notice(BaseEntity* victim);
	virtual bool hould_attract_auto_aim(BaseEntity* ent);
	virtual float get_auto_aim_radius();
	virtual Vector get_auto_aim_center();
	virtual ITraceFilter* get_beam_trace_filter();
	virtual bool passes_damage_filter(const CTakeDamageInfo &info);
	virtual void trace_attack(const CTakeDamageInfo& info, const Vector& direction, trace_t* trace, CDmgAccumulator* accumulator = nullptr);
	virtual bool can_be_hit_by_melee_attack(BaseEntity* attacker);
	virtual int on_take_damage(const CTakeDamageInfo& info);
	virtual void adjust_damage_direction(const CTakeDamageInfo& info, Vector& dir, BaseEntity* entity);
	virtual int take_health(float health, int damage_type);
	virtual bool is_alive();
	virtual void event_killed(const CTakeDamageInfo& info);
	virtual void event_killed_other(BaseEntity* victim, const CTakeDamageInfo& info);
	virtual int blood_color();
	virtual bool is_triggered(BaseEntity* activator);
	virtual bool is_npc() const;
	virtual CBaseCombatCharacter* get_my_combat_character_pointer();
	virtual INextBot* my_next_bot_pointer();
	virtual float get_delay();
	virtual bool is_moving();
	virtual char const* damage_decal(int damage_type, int game_material);
	virtual void decal_trace(trace_t* trace, char const* decal_name);
	virtual void impact_trace(trace_t* trace, int damage_type, const char* custom_impact_name=nullptr);
	virtual bool on_controls(BaseEntity* controls);
	virtual bool has_target(const char* target_name);
	virtual bool is_player() const;
	virtual bool is_net_client() const;
	virtual bool is_template();
	virtual bool is_base_object() const;
	virtual bool is_base_train() const;
	virtual bool is_combat_item() const;
	virtual bool is_base_combat_weapon() const;
	virtual bool is_wearable() const;
	virtual CBaseCombatWeapon* get_my_combat_weapon_pointer();
	virtual IServerVehicle* get_server_vehicle();
	virtual bool is_viewable();
	virtual void change_team(int team);
	virtual void on_entity_event(EntityEvent_t event, void *pEventData );
	virtual bool can_stand_on(BaseEntity* surface) const;
	virtual bool can_stand_on(Edict* edict);
	virtual BaseEntity* get_enemy();
	virtual BaseEntity* get_enemy() const;
	virtual void use(BaseEntity* activator, BaseEntity* caller, UseType use_type, float value);
	virtual void start_touch(BaseEntity* other);
	virtual void touch(BaseEntity* other); 
	virtual void end_touch (BaseEntity* other);
	virtual void start_blocked(BaseEntity* other);
	virtual void blocked(BaseEntity* other);
	virtual void end_blocked();
	virtual void physics_simulate();
	virtual void update_on_remove();
	virtual void stop_looping_sound();
	virtual bool sub_is_allowed_to_fade();
	virtual void teleport(const Vector* pos, const QAngle* angles, const Vector* velocity);
	virtual void notify_system_event(BaseEntity* notify, NotifySystemEvent event_type, const notify_system_event_params_t& params);
	virtual void make_tracer(const Vector& src, const trace_t& tr, int tracer_type);
	virtual int get_tracer_attachment();
	virtual void fire_bullets(const FireBulletsInfo_t& info);
	virtual void do_impact_effect(trace_t& tr, int damage_type);
	virtual void modify_fire_bullets_damage(CTakeDamageInfo* info);
	virtual BaseEntity* respawn();
	virtual bool is_locked_by_master();
	virtual int get_max_health() const;
	virtual void modify_or_append_criteria(AI_CriteriaSet& set);
	virtual void network_state_changed_max_health();
	virtual void network_state_changed_max_health(void*);
	virtual void network_state_changed_health();
	virtual void network_state_changed_health(void*);
	virtual void network_state_changed_life_state();
	virtual void network_state_changed_life_state(void*);
	virtual void network_state_changed_take_damage();
	virtual void network_state_changed_take_damage(void*);
	virtual int get_damage_type() const;
	virtual float get_damage();
	virtual void set_damage(float damage);
	virtual Vector get_eye_position();
	virtual QAngle& eye_angles();
	virtual QAngle& local_eye_angles();
	virtual Vector get_ear_position();
	virtual Vector body_target(const Vector& src, bool noisy=true);
	virtual Vector head_target(const Vector& src);
	virtual void get_vectors(Vector* forward, Vector* right, Vector* up) const;
	virtual const Vector& get_view_offset() const;
	virtual void set_view_offset(const Vector &v);
	virtual Vector get_smoothed_velocity();
	virtual void get_velocity(Vector* v, AngularImpulse* ang_velocity=nullptr);
	virtual bool f_visible (BaseEntity* entity, int trace_mask, BaseEntity** blocker=nullptr);
	virtual bool f_visible(const Vector& target, int trace_mask, BaseEntity** blocker=nullptr);
	virtual bool can_be_seen_by(CAI_BaseNPC* npc);
	virtual float get_attack_damage_scale(BaseEntity* victim);
	virtual float get_received_damage_scale(BaseEntity* attacker);
	virtual void get_ground_velocity_to_apply(Vector& vec);
	virtual bool physics_splash(const Vector& point, const Vector& normal, float raw_speed, float scale_speed);
	virtual void splash();
	virtual const Vector& get_world_space_center() const;
	virtual Vector get_sound_emission_origin() const;
	virtual void modify_emit_sound_params(EmitSound_t& params);
	virtual bool is_deflectable();
	virtual void deflected(BaseEntity* entity, Vector& direction);
	virtual bool create_v_physics();
	virtual bool force_v_physics_collide(BaseEntity* entity);
	virtual void v_physics_destroy_object();
	virtual void v_physics_update(IPhysicsObject* physics);
	virtual int v_physics_take_damage(const CTakeDamageInfo& info);
	virtual void v_physics_shadow_collision(int index, gamevcollisionevent_t* event);
	virtual void v_physics_shadow_update(IPhysicsObject* physics);
	virtual void v_physics_collision(int index, gamevcollisionevent_t* event);
	virtual void v_physics_friction(IPhysicsObject* physics, float energy, int surface_props, int surface_props_hit);
	virtual void update_physics_shadow_to_current_position(float delta_time);
	virtual int v_physics_get_object_list(IPhysicsObject** list, int max_len);
	virtual bool v_physics_is_flesh();
	virtual BasePlayer* has_physics_attacker(float dt);
	virtual unsigned int physics_solid_mask_for_entity() const;
	virtual void resolve_fly_collision_custom(trace_t& trace, Vector& velocity);
	virtual void perform_custom_physics(Vector* pos, Vector* velocity, QAngle* angles, QAngle* ang_velocity);
	virtual Vector get_step_origin() const;
	virtual QAngle get_step_angles() const;
	virtual bool should_draw_water_impacts();
	virtual void network_state_changed_flags();
	virtual void network_state_changed_flags(void*);
	virtual void network_state_changed_water_level();
	virtual void network_state_changed_water_level(void*);
	virtual void network_state_changed_ground_entity();
	virtual void network_state_changed_ground_entity(void*);
	virtual void network_state_changed_base_velocity();
	virtual void network_state_changed_base_velocity(void*);
	virtual void network_state_changed_friction();
	virtual void network_state_changed_friction(void*);
	virtual void network_state_changed_velocity();
	virtual void network_state_changed_velocity(void*);
	virtual void network_state_changed_view_offset();
	virtual void network_state_changed_view_offset(void*);
	virtual bool should_block_nav() const;
	
	void (BaseEntity::*move_done_fn)(void);
	void (BaseEntity::*think_fn)(void);
	ServerNetworkProperty network;
	const char* class_name;
	const char* global_name;
	const char* parent_name;
	int hammer_id;
	float speed;
	unsigned char render_fx;
	unsigned char render_mode;
	short model_index;

	/*
	#ifdef TF_DLL
		CNetworkArray( int, m_nModelIndexOverrides, MAX_VISION_MODES ); // used to override the base model index on the client if necessary
	#endif
	*/

	Color32 render_color;
	float previous_anim_time;
	float anim_time;
	float simulation_time;
	int interpolation_frame;
	int last_think_tick;
	unsigned int predictable_id;
	int touch_stamp;
	UtlVector<thinkfunc_t> think_functions;
	UtlVector<response_context_t> response_contexts;
	const char* response_context;
	int next_think_tick;
	int effects;
	void (BaseEntity::*touch_fn)(BaseEntity* other);
	void (BaseEntity::*use_fn)(BaseEntity* activator, BaseEntity* caller, int use_type, float value);
	void (BaseEntity::*blocked_fn)(BaseEntity* other);
	IHasAttributes* attributes;
	BaseEntity* link;
	const char* target;
	int max_health;
	int health;
	char life_state;
	char take_damage;
	const char* damage_filter_name;
	BaseHandle damage_filter;
	int debug_overlays;
	TimedOverlay_t* timed_overlay;
	int simulation_tick;
	int spawn_flags;
	int e_flags;
	int flags;
	const char* name;
	UtlLinkedList<DamageModifier*, int> damage_modifiers;
	BaseHandle parent;
	unsigned char transmit_state_owned_counter;
	unsigned char parent_attachment;
	unsigned char move_type;
	unsigned char move_collide;
	BaseHandle move_parent;
	BaseHandle move_child;
	BaseHandle move_peer;
	CollisionProperty collision;
	BaseHandle owner_entity;
	BaseHandle effect_entity;
	int collision_group;
	IPhysicsObject* physics_object;
	float shadow_cast_distance;
	float desired_shadow_cast_distance;
	int initial_team_num;
	int team_num;
	unsigned char water_touch;
	unsigned char slime_touch;
	unsigned char water_type;
	unsigned char water_level;
	float nav_ignore_until_time;
	BaseHandle ground_entity;
	float ground_change_time;
	const char* model_name;
	Vector base_velocity;
	Vector abs_velocity;
	QAngle ang_velocity;
	Matrix3x4 coordinate_frame;
	BaseHandle blocker;
	float gravity;
	float friction;
	float elasticity;
	float local_time;
	float v_physics_update_local_time;
	float move_done_time;
	float push_enum_count;
	Vector abs_origin;
	Vector velocity;
	unsigned char texture_frame_index;
	bool is_simulated_every_tick;
	bool is_animated_every_tick;
	bool is_alternate_sorting;
	BaseEntityOutput on_user1;
	BaseEntityOutput on_user2;
	BaseEntityOutput on_user3;
	BaseEntityOutput on_user4;
	QAngle abs_rotation;
	Vector origin;
	QAngle rotation;
	BaseHandle ref_e_handle;
	Vector view_offset;
	bool is_dynamic_model_allowed;
	bool is_dynamic_model_pending;
	bool is_dynamic_model_set_bounds;
	bool is_player_simulated;
	BaseHandle player_simulation_owner;
	int data_object_types;
};

struct ThreadFastMutex {
    volatile unsigned int owner_id;
    int depth;
};

class BaseAnimating: public BaseEntity {
public:
	virtual float get_ideal_speed() const;
	virtual float get_ideal_accel() const;
	virtual void studio_frame_advance();
	virtual void set_sequence(int sequence);
	virtual bool is_activity_finished();
	virtual float get_sequence_ground_speed(CStudioHdr* studio_hr, int sequence);
	virtual void clamp_ragdoll_force(const Vector& force_in, Vector* fource_out);
	virtual bool become_ragdoll_on_client(const Vector& force);
	virtual bool is_ragdoll();
	virtual bool can_become_ragdoll();
	virtual void get_skeleton(CStudioHdr* studio_hr, Vector pos[], Quaternion q[], int bone_mask);
	virtual void get_bone_transform(int bone, Matrix3x4& bone_to_world);
	virtual void setup_bones(Matrix3x4* bone_to_world, int bone_mask);
	virtual void calculate_ik_locks(float current_time);
	virtual void dispatch_anim_events(BaseAnimating* event_handler);
	virtual void handle_anim_event(animevent_t* event);
	virtual void populate_pose_parameters();
	virtual bool get_attachment(int attachment, Matrix3x4& attachment_to_world);
	virtual void init_bone_controllers();
	virtual Vector get_ground_speed_velocity(void);
	virtual void refresh_collision_bounds();
	virtual void ignite(float flame_life_time, bool npc_only=true, float size=0.0f, bool called_by_level_designer=false);
	virtual void ignite_life_time(float flame_life_time);
	virtual void ignite_num_hitbox_fires(int num_hitbox);
	virtual void ignite_hitbox_fire_scale(float hitbox_fire_scale);
	virtual void extinguish();
	virtual void set_lighting_origin_relative(BaseEntity* origin);
	virtual void set_lighting_origin(BaseEntity* origin);

	float ground_speed;
	float last_event_check;
	int force_bone;
	Vector force;
	int skin;
	int body;
	int hitbox_set;
	float model_scale;
	float playback_rate;
	float ik_ground_contact_time;
	float ik_ground_min_height;
	float ik_ground_max_height;
	float est_ik_floor;
	float est_ik_offset;
	IKContext* ik;
	int ik_counter;
	bool is_sequence_finished;
	bool is_sequence_loops;
	bool reset_sequence_info_on_load;
	float dissolve_start_time;
	float cycle;
	int sequence;
	float pose_parameter[24];
	float encoded_controller[4];
	bool client_side_animation;
	bool client_side_frame_reset;
	int new_sequence_parity;
	int reset_events_parity;
	unsigned char muzzle_flash_parity;
	BaseHandle lighting_origin;
	BaseHandle lighting_origin_relative;
	const char* lighting_origin_relative_s;
	const char* lighting_origin_s;
	memhandle_t* bone_cache_handle;
	unsigned short bone_cache_flags;
	float fade_min_dist;
	float fade_max_dist;
	float fade_scale;
	BaseEntityOutput on_ignite;
	CStudioHdr* studio_hdr;
	ThreadFastMutex studio_hdr_init_lock;
	ThreadFastMutex bone_setup_mutex;
};

class BaseAnimatingOverlay : public BaseAnimating {
public:
    UtlVector<AnimationLayer> anim_overlay;
};

template <class I>
struct UtlRbTreeLinks {
    I left;
	I right;
	I parent;
	I tag;
};

template <class T, class I>
struct UtlRbTreeNode : public UtlRbTreeLinks<I> {
	T data;
};

template <class T, class I = unsigned short, typename L = bool (*)(const T&, const T&), class M = UtlMemory<UtlRbTreeNode<T, I>, I>>
class UtlRbTree {
public:
	inline T& element(I i) const {
		return elements[i].data; 
	}

	inline I left_child(I i) const {
		return links(i).left; 
	}

	inline I right_child(I i) const {
		return links(i).right; 
	}

	inline UtlRbTreeLinks<I>& links(I i) const {
		return *(UtlRbTreeLinks<I>*)&elements[i];
	}

	inline I invalid_index() const {
		return (I)M::invalid_index();
	}
	
	I find(const T& search) const {
		I current = root;
		while (current != invalid_index()) {
			if (less_func(search, element(current)))
				current = left_child(current);
			else if (less_func(element(current), search))
				current = right_child(current);
			else 
				break;
		}
		return current;
	}

	L less_func;
	M elements;
	I root;
	I num_elements;
	I first_tree;
	typename M::Iterator last_alloc;
	UtlRbTreeNode<T, I>* elements_p;
};

class BaseFlex : public BaseAnimatingOverlay {
public:
	virtual void set_view_target(const Vector& target);
	virtual bool start_scene_event(SceneEventInfo* info, ChoreoScene* scene, ChoreoEvent* event, ChoreoActor* actor, BaseEntity* target);
	virtual void process_scene_events();
	virtual bool process_scene_event(SceneEventInfo* info, ChoreoScene* scene, ChoreoEvent* event);
	virtual bool clear_scene_event(SceneEventInfo* info, bool fast_kill, bool canceled);
	virtual bool check_scene_event_completion(SceneEventInfo* info, float current_time, ChoreoScene* scene, ChoreoEvent* event);
	virtual float play_scene(const char* scene, float delay=0.0f, AI_Response* response=nullptr, IRecipientFilter* filter=nullptr);
	virtual float play_auto_generated_sound_scene(const char* sound_name);
	virtual int get_special_dsp();

	float flex_weight[96];
	Vector view_target;
	int blink_toggle;
	UtlVector<SceneEventInfo> scene_events;
	UtlRbTree<FS_LocalToGlobal, unsigned short> local_to_global;
	float allow_responses_end_time;
	UtlVector<ChoreoScene*> active_choreo_scenes;
	bool update_layer_priorities;
	float last_flex_animation_time;
};

struct Relationship {
	BaseHandle entity;
	ClassType class_type;
	Disposition disposition;
	int priority;
};

struct IntervalTimer {
	float time_stamp;
};

struct DamageHistory {
	int team;
	IntervalTimer interval;
};

class BaseCombatCharacter: public BaseFlex {
public:
	virtual const impactdamagetable_t& get_physics_impact_damage_table();
	virtual bool f_in_view_cone(BaseEntity* entity);
	virtual bool f_in_view_cone(const Vector& spot);
	virtual bool f_in_aim_cone(BaseEntity* entity);
	virtual bool f_in_aim_cone(const Vector& spot);
	virtual bool should_shoot_miss_target(BaseCombatCharacter* attacker);
	virtual BaseEntity* find_miss_target();
	virtual bool handle_interaction(int type, void* data, BaseCombatCharacter* ent);
	virtual QAngle body_angles();
	virtual Vector body_direction_2d();
	virtual Vector body_direction_3d();
	virtual Vector head_direction_2d();
	virtual Vector head_direction_3d();
	virtual Vector eye_direction_2d();
	virtual Vector eye_direction_3d();
	virtual bool is_hidden_by_fog(const Vector& target) const;
	virtual bool is_hidden_by_fog(BaseEntity* target) const;
	virtual bool is_hidden_by_fog(float range) const;
	virtual float get_fog_obscured_ratio(const Vector& target) const;
	virtual float get_fog_obscured_ratio(BaseEntity* target) const;
	virtual float get_fog_obscured_ratio(float range) const;
	virtual bool is_looking_towards(const BaseEntity* target, float cos_tolerance) const;
	virtual bool is_looking_towards(const Vector& target, float cos_tolerance) const;
	virtual bool is_in_field_of_view(BaseEntity* entity) const;
	virtual bool is_in_field_of_view(const Vector& pos) const;
	virtual bool is_line_of_sight_clear(BaseEntity* entity, LineOfSightCheckType check_type=LineOfSightCheckType::IGNORE_NOTHING) const;
	virtual bool is_line_of_sight_clear(const Vector& pos, LineOfSightCheckType checkType=LineOfSightCheckType::IGNORE_NOTHING, BaseEntity* ignore=nullptr) const;
	virtual int give_ammo(int count, int ammo_index, bool suppress_sound=false);
	virtual void remove_ammo(int count, int ammo_index);
	virtual void remove_ammo(int count, const char* name);
	virtual int get_ammo_count(int ammo_index) const;
	virtual Activity npc_translate_activity(Activity base_act);
	virtual Activity weapon_translate_activity(Activity base_act, bool* required=nullptr);
	virtual void weapon_frame_update();
	virtual void weapon_handle_anim_event(animevent_t* event);
	virtual bool weapon_can_use(CBaseCombatWeapon* weapon);
	virtual void weapon_equip(CBaseCombatWeapon* weapon);
	virtual bool weapon_equip_ammo_only(CBaseCombatWeapon* weapon);
	virtual void weapon_drop(CBaseCombatWeapon* weapon, const Vector* target=nullptr, const Vector* velocity=nullptr);
	virtual bool weapon_switch(CBaseCombatWeapon* weapon, int view_model_index=0);
	virtual Vector weapon_shoot_position();
	virtual bool weapon_can_switch_to(CBaseCombatWeapon* weapon);
	virtual bool weapon_slot_occupied(CBaseCombatWeapon* weapon);
	virtual CBaseCombatWeapon* weapon_get_slot(int slot) const;
	virtual bool add_player_item(CBaseCombatWeapon* item);
	virtual bool remove_player_item(CBaseCombatWeapon* item);
	virtual bool can_become_server_ragdoll();
	virtual int on_take_damage(const CTakeDamageInfo& info);
	virtual int on_take_damage_alive(const CTakeDamageInfo& info);
	virtual int on_take_damage_dying(const CTakeDamageInfo& info);
	virtual int on_take_damage_dead(const CTakeDamageInfo& info);
	virtual float get_alive_duration() const;
	virtual void on_friend_damaged(BaseCombatCharacter* teammate, BaseEntity* attacker);
	virtual void notify_friend_of_damage(BaseEntity* attacker);
	virtual bool has_ever_been_injured(int team) const;
	virtual float get_time_since_last_injury(int team) const;
	virtual void on_player_killed_other(BaseEntity* victim, const CTakeDamageInfo& info);
	virtual Activity get_death_activity();
	virtual bool corpse_gib(const CTakeDamageInfo& info);
	virtual void corpse_fade();
	virtual bool has_human_gibs();
	virtual bool has_alien_gibs();
	virtual bool should_gib(const CTakeDamageInfo& info);
	virtual void on_killed_npc(BaseCombatCharacter* victim); 
	virtual bool event_gibbed(const CTakeDamageInfo& info);
	virtual void event_dying(const CTakeDamageInfo& info);
	virtual void event_dying();
	virtual bool become_ragdoll(const CTakeDamageInfo& info, const Vector& force);
	virtual void fixup_burning_server_ragdoll(BaseEntity* ragdoll);
	virtual bool become_ragdoll_boogie(BaseEntity* killer, const Vector& force, float duration, int flags);
	virtual BaseEntity* check_trace_hull_attack(float dist, const Vector& mins, const Vector& maxs, int damage, int damage_type, float force_scale=1.0f, bool damange_npc=false);
	virtual BaseEntity* check_trace_hull_attack(const Vector& start, const Vector& end, const Vector& mins, const Vector& maxs, int damage, int damage_type, float force_scale=1.0f, bool damage_npc=false);
	virtual void push_away_touch(BaseEntity* other);
	virtual Disposition i_relation_type(BaseEntity* target);
	virtual int i_relation_priority(BaseEntity* target);
	virtual bool is_in_vehicle() const;
	virtual IServerVehicle* get_vehicle();
	virtual BaseEntity* get_vehicle_entity();
	virtual bool exit_vehicle();
	virtual void remove_all_weapons();
	WeaponProficiency get_current_weapon_proficiency();
	void set_current_weapon_proficiency(WeaponProficiency proficiency);
	virtual WeaponProficiency calc_weapon_proficiency(CBaseCombatWeapon* weapon);
	virtual Vector get_attack_spread(CBaseCombatWeapon* weapon, BaseEntity* target=nullptr);
	virtual float get_spread_bias(CBaseCombatWeapon* weapon, BaseEntity* target);
	virtual void do_muzzle_flash();
	virtual void add_entity_relationship(BaseEntity* entity, Disposition disposition, int priority);
	virtual bool remove_entity_relationship(BaseEntity* entity);
	virtual void add_class_relationship(ClassType cls, Disposition disposition, int priority);
	virtual void on_change_active_weapon(CBaseCombatWeapon* old_weapon, CBaseCombatWeapon* new_wapon);
	virtual NavArea* get_last_known_area() const;
	virtual bool is_area_traversable(const NavArea* area) const;
	virtual void clear_last_known_area();
	virtual void update_last_known_area();
	virtual void on_nav_area_changed(NavArea* entered_area, NavArea* left_area);
	virtual void on_nav_area_removed(NavArea* removed_area);
	virtual void on_pursued_by(INextBot* pursuer);
	virtual void network_state_changed_ammo();
	virtual void network_state_changed_ammo(void*);

	bool force_server_ragdoll;
	bool prevent_weapon_pickup;
	float next_attack;
	Hull hull;
	int blood_color;
	float field_of_view;
	Vector hacked_gun_pos;
	const char* relationship_string;
	float impact_energy_scale;
	int last_hit_group;
	float damage_accumulator;
	int damage_count;
	WeaponProficiency current_weapon_proficiency;
	UtlVector<Relationship> relationship;
	int ammo[32];
	BaseHandle my_weapons[48];
	BaseHandle active_weapon;
	IntervalTimer alive_timer;
	unsigned int has_been_injured;
	DamageHistory damage_history[4];
	NavArea* last_nav_area;
	AI_MoveMonitor nav_area_update_monitor;
	int registered_nav_team;
};

class BaseEdict {
public:
	bool is_free() const;

	int state_flags;
	short edict_index;
	short network_serial_number;
	IServerNetworkable* networkable;
	IServerUnknown* unknown;
};

class FogParams {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);

	Vector dir_primary;
	Color32 primary_color;
	Color32 secondary_color;
	Color32 primary_lerp_to_color;
	Color32 secondary_lerp_to_color;
	float start;
	float end;
	float farz;
	float max_density;
	float start_lerp_to;
	float end_lerp_to;
	float lerp_time;
	float duration;
	bool enable;
	bool blend;
};

class FogPlayerParams {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);

	BaseHandle controller;
	float transition_time;
	Color32 old_color;
	float old_start;
	float old_end;
	Color32 new_color;
	float new_start;
	float new_end;
};

class Sky3DParams {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);

	int scale;
	Vector origin;
	int area;
	FogParams fog;
};

class AudioParams {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);

	Vector local_sound[8];
	int sound_scape_index;
	int local_bits;
	BaseHandle ent;
};

class PlayerLocalData {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);

	unsigned char area_bits[32];
	unsigned char area_portal_bits[24];
	int hide_hud;
	float fov_rate;
	Vector over_view_point;
	bool is_ducked;
	bool is_in_duck_jump;
	float duck_time;
	float duck_jump_time;
	float jump_time;
	int step_side;
	float fall_velocity;
	int old_buttons;
	SkyCamera* old_sky_camera;
	QAngle punch_angle;
	QAngle punch_angle_vel;
	bool draw_view_model;
	bool is_wearing_suit;
	bool is_poisoned;
	float step_size;
	bool allow_auto_movement;
	Sky3DParams skybox_3d;
	FogPlayerParams player_fog;
	FogParams fog;
	AudioParams audio;
	bool slow_movement;
};

class PlayerState {
public:
	virtual void network_state_changed();
	virtual void network_state_changed(void*);
	virtual ~PlayerState();

	bool is_dead;
	QAngle v_angle; 
	const char* net_name;
	int fix_angle;
	QAngle angle_change;
	bool is_hltv;
	bool is_replay;
	int frags;
	int deaths;
};

class UserCmd {
public:
	virtual ~UserCmd();
	
	int command_number;
	int tick_count;
	QAngle view_angles;	 
	float forward_move;   
	float side_move;	  
	float up_move;		 
	int buttons; 	
	unsigned char impulse;		
	int weapon_select; 
	int weapon_sub_type;
	int random_seed;
	int server_random_seed;
	short mouse_dx;
	short mouse_dy;
	bool is_predicted;
};

class IBotController {
public:
	virtual void set_abs_origin(const Vector& v) = 0;
	virtual void set_abs_angles(const QAngle& ang) = 0;
	virtual void set_local_origin(const Vector& v) = 0;
	virtual const Vector get_local_origin() = 0;
	virtual void set_local_angles(const QAngle& ang) = 0;
	virtual const QAngle get_local_angles() = 0;
	virtual void remove_all_items(bool remove_suit) = 0;
	virtual void set_active_weapon(const char* weapon) = 0;
	virtual void post_client_messages_sent() = 0;
	virtual bool is_e_flag_set(int mask) = 0;
	virtual void run_player_move(BotCmd* cmd) = 0;
};

struct PlayerInfo {
	char name[max_player_name_length];
	int user_id;
	char guid[signed_guid_len + 1];
	unsigned int friends_id;
	char friends_name[max_player_name_length];
	bool is_fake_player;
	bool is_hltv;
	unsigned int custom_files[max_custom_files];
	unsigned char downloaded_files;
};

class IPlayerInfo {
public:
	virtual const char* get_name() = 0;
	virtual int get_user_id() = 0;
	virtual const char* get_network_id_string() = 0;
	virtual int get_team_index() = 0;
	virtual void change_team(int team) = 0;
	virtual int get_frag_count() = 0;
	virtual int get_death_count() = 0;
	virtual bool is_connected() = 0;
	virtual int get_armor_value() = 0;
	virtual bool is_hltv() = 0;
	virtual bool is_player() = 0;
	virtual bool is_fake_client() = 0;
	virtual bool is_dead() = 0;
	virtual bool is_in_vehicle() = 0;
	virtual bool is_observer() = 0;
	virtual const Vector get_abs_origin() = 0;
	virtual const QAngle get_abs_angles() = 0;
	virtual const Vector get_player_mins() = 0;
	virtual const Vector get_player_maxs() = 0;
	virtual const char* get_weapon_name() = 0;
	virtual const char* get_model_name() = 0;
	virtual int get_health() = 0;
	virtual int get_max_health() = 0;
	virtual BotCmd get_last_user_command() = 0;
	virtual bool is_replay() = 0;
};

class PlayerInfoManager : public IBotController, public IPlayerInfo {
public:
	virtual const char* get_name();
	virtual int get_user_id();
	virtual const char* get_network_id_string();
	virtual int get_team_index();
	virtual void change_team(int team);
	virtual int get_frag_count();
	virtual int get_death_count();
	virtual bool is_connected();
	virtual int get_armor_value();
	virtual bool is_hltv();
	virtual bool is_player();
	virtual bool is_fake_client();
	virtual bool is_dead();
	virtual bool is_in_vehicle();
	virtual bool is_observer();
	virtual const Vector get_abs_origin();
	virtual const QAngle get_abs_angles();
	virtual const Vector get_player_mins();
	virtual const Vector get_player_maxs();
	virtual const char* get_weapon_name();
	virtual const char* get_model_name();
	virtual int get_health();
	virtual int get_max_health();
	virtual BotCmd get_last_user_command();
	virtual bool is_replay();

	virtual void set_abs_origin(const Vector& v);
	virtual void set_abs_angles(const QAngle& ang);
	virtual void set_local_origin(const Vector& v);
	virtual const Vector get_local_origin();
	virtual void set_local_angles(const QAngle& ang);
	virtual const QAngle get_local_angles();
	virtual void remove_all_items(bool remove_suit);
	virtual void set_active_weapon(const char* weapon);
	virtual void post_client_messages_sent();
	virtual bool is_e_flag_set(int mask);
	virtual void run_player_move(BotCmd* cmd);

	BasePlayer* parent; 
};

struct SoundParameters {
	int	channel;
	float volume;
	int pitch;
	int pitch_low;
    int pitch_high;
	SoundLevel sound_level;
	bool play_to_owner_only;
	int	count;
	char sound_name[128];
	int delay_msec;
};

struct StepSoundCache {
    SoundParameters sound_parameters;
    unsigned short sound_name_index;
};

struct CommandContext {
	UtlVector<UserCmd> cmds;
	int num_cmds;
	int total_cmds;
	int dropped_packets;
	bool is_paused;
};

struct PlayerSimInfo {
	float time;
	int num_cmds;
	int ticks_corrected;
	float final_simulation_time;
	float game_simulation_time;
	float server_frame_time;  
	Vector abs_origin;
};

struct PlayerCmdInfo {
public:
	float time;
	int num_cmds;
	int dropped_packets;
};

template <class BASE_OPS>
class BitVecT : public BASE_OPS {
public:
    unsigned get(unsigned but_num) const;
    void set(int bit_num);
    void clear(int bit_num);
};

template <int NUM_BITS>
class FixedBitVecBase {
public:
    unsigned* base();
    const unsigned* base() const;

    unsigned int ints[(NUM_BITS + (32 - 1)) / 32];
};

template <int NUM_BITS>
class BitVec : public BitVecT<FixedBitVecBase<NUM_BITS>> {

};

class BasePlayer: public BaseCombatCharacter {
public:
	virtual void create_view_model(int view_model_index=0);
	virtual void setup_visibility(BaseEntity* view_entity, unsigned char* pvs, int pvs_size);
	virtual bool wants_lag_compensation_on_entity(const BasePlayer* player, const UserCmd* cmd, const BitVec<2048>* transmit_bits) const;
	virtual void shared_spawn();
	virtual void force_respawn();
	virtual void initial_spawn();
	virtual void init_hud();
	virtual void show_view_port_panel(const char* name, bool show=true, KeyValues* data=nullptr);
	virtual void player_death_think();
	virtual void jump();
	virtual void duck();
	virtual void pre_think();
	virtual void post_think();
	virtual void damage_effect(float damage, int damage_type);
	virtual void on_damage_by_explosionn(const CTakeDamageInfo& info);
	virtual bool should_fade_on_death();
	virtual bool is_fake_client() const;
	virtual const Vector get_player_mins() const;
	virtual const Vector get_player_maxs() const;
	virtual float calc_roll(const QAngle& angles, const Vector& velocity, float roll_angle, float roll_speed);
	virtual void pack_dead_player_items();
	virtual void remove_all_items(bool suit);
	virtual bool is_running() const;
	virtual void weapon_set_last(CBaseCombatWeapon* weapon);
	virtual bool weapon_should_set_last(CBaseCombatWeapon* old_weapon, CBaseCombatWeapon* new_weapon);
	virtual bool weapon_should_select_item(CBaseCombatWeapon* weapon);
	virtual void on_my_weapon_fired(CBaseCombatWeapon* weapon);
	virtual float get_time_since_weapon_fired() const;
	virtual bool is_firing_weapon() const;
	virtual void update_client_data();
	virtual void exit_ladder();
	virtual surfacedata_t* get_ladder_surface(const Vector& origin);
	virtual void set_flashlight_enabled(bool state);
	virtual int is_flashlight_on();
	virtual void flashlight_turn_on();
	virtual void flashlight_turn_off();
	virtual bool is_illiminated_by_flashlight(BaseEntity* entity, float* return_dot);
	virtual void update_step_sound(surfacedata_t* surface, const Vector& origin, const Vector& velocity);
	virtual void play_step_sound(Vector& origin, surfacedata_t* surface, float volume, bool force);
	virtual const char* get_override_step_sound(const char* base_step_sound_name);
	virtual void get_step_sound_velocities(float* vel_walk, float* vel_run);
	virtual void set_step_sound_time(StepSoundTime step_sound_time, bool is_walking);
	virtual void death_sound(const CTakeDamageInfo& info );
	virtual const char* get_scene_sound_token();
	virtual void on_emit_footstep_sound(const SoundParameters& params, const Vector& origin, float volume);
	virtual void set_animation(PlayerAnimation playerAnim);
	virtual void impulse_commands();
	virtual void cheat_impulse_commands(int impulse);
	virtual bool client_command(const Command& command);
	virtual bool start_observer_mode(int mode);
	virtual void stop_observer_mode();
	virtual bool mode_wants_spectator_gui(int mode);
	virtual bool set_observer_mode(int mode);
	virtual int get_observer_mode();
	virtual bool set_observer_target(BaseEntity* e);
	virtual void observer_use(bool is_pressed);
	virtual BaseEntity* get_observer_target();
	virtual BaseEntity* find_next_observer_target(bool reverse);
	virtual int get_next_observer_search_start_point(bool reverse);
	virtual bool is_valid_observer_target(BaseEntity* e);
	virtual void check_observer_settings();
	virtual void jump_to_position(const Vector& origin, const QAngle& ang);
	virtual void force_observer_mode(int mode);
	virtual void reset_observer_mode();
	virtual void validate_current_observer_target();
	virtual void attemp_to_exit_freeze_cam();
	virtual bool start_replay_mode(float delay, float duration, int entity);
	virtual void stop_replay_mode();
	virtual int get_delay_ticks();
	virtual int get_replay_entity();
	virtual void create_corpse();
	virtual BaseEntity* ent_select_spawn_point();
	virtual bool get_in_vehicle(IServerVehicle* vehicle, int role);
	virtual void leave_vehicle(const Vector& exit_point, const QAngle& exit_angles);
	virtual void on_vehicle_start();
	virtual void on_vehicle_end(Vector& dest_position);
	virtual void bump_weapon(BaseCombatWeapon* weapon);
	virtual void select_last_item();
	virtual void select_item(const char* s, int sub_type=0);
	virtual void item_post_frame();
	virtual BaseEntity* give_named_item(const char* s, int sub_type=0);
	virtual void check_train_update();
	virtual void set_player_under_water(bool state);
	virtual bool can_breathe_under_water();
	virtual void player_use();
	virtual void player_use_deny_sound();
	virtual BaseEntity* find_use_entity();
	virtual bool ise_useable_entity(BaseEntity* e, unsigned int required_caps);
	virtual void pickup_object(BaseEntity* object, bool limit_mass_and_size=true);
	virtual void force_drop_of_carried_phys_objects(BaseEntity* only_if_holdind_this=nullptr);
	virtual float get_held_object_mass(IPhysicsObject* object);
	virtual void update_geiger_counter();
	virtual Vector get_auto_aim_vector(float scale);
	virtual Vector get_auto_aim_vector(float scale, float max_dist);
	virtual void get_auto_aim_vector(autoim_params_t& params);
	virtual bool should_auto_aim();
	virtual void force_client_dll_update();
	virtual void process_user_cmds(UserCmd* cmds, int num, int total, int dropped_packets, bool is_paused);
	virtual void player_run_command(UserCmd* cmd, IMoveHelper* mh);
	virtual void change_team(int num) override { change_team(num, false, false); };
	virtual void change_team(int num, bool auto_team, bool silent, bool auto_balance=false);
	virtual bool can_hear_and_read_chat_from(BasePlayer* p);
	virtual bool can_speak();
	virtual void modify_or_append_player_criteria(AI_CriteriaSet& set);
	virtual void check_chat_text(char* p, int size);
	virtual void create_ragdoll_entity();
	virtual bool should_announce_achievement();
	virtual bool is_following_physics();
	virtual void init_v_collision(const Vector& abs_origin, const Vector& abs_velocity);
	virtual void update_physics_shadow_to_current_position();
	virtual HintSystem* hints();
	virtual bool is_ready_to_player();
	virtual bool is_ready_to_spawn();
	virtual bool should_gain_instant_spawn();
	virtual void reset_per_round_stats();
	virtual void reset_scores();
	virtual void equip_suit(bool play_effects=true);
	virtual void remove_suit();
	virtual float get_player_max_speed();
	virtual void commit_suicide(bool explode=false, bool force=false);
	virtual void commit_suicide(const Vector& origin, bool explode=false, bool force=false);
	virtual bool is_bot() const;
	virtual bool is_bot_of_type(int bot_type) const;
	virtual int get_bot_type();
	virtual AI_Expresser* get_expresser();
	virtual void internal_handle_map_event(inputdata& input_data);
	virtual int spawn_armor_value() const;
	virtual void network_state_changed_armor_value();
	virtual void network_state_changed_armor_value(void*);
	virtual bool has_haptics();
	virtual void set_haptics(bool has);
	virtual unsigned int player_solid_mask(bool brush_only=false) const;

	float movement_time_for_user_cmd_processing_remaining;
	int stuck_last;
	PlayerLocalData local_data;
	UtlVector<BaseHandle> trigger_sound_scape_list;
	PlayerState player_state;
	int buttons;
	int button_pressed;
	int button_released;
	int button_last;
	int button_disabled;
	int button_forced;
	bool is_on_target;
	char anim_extension[32];
	int update_rate;
	float lerp_time;
	bool lag_compensation;
	bool predict_weapons;
	Activity activity;
	float last_objective_time;
	Vector additional_pvs_origin;
	Vector camera_pvs_origin;
	BaseHandle use_entity;
	int train;
	float respawn_frames;
	unsigned int physics_flags;
	BaseHandle vehicle;
	int vehicle_analog_bias;
	bool pause_bonus_progress;
	int bonus_progress;
	int bonus_challenge;
	int last_damage_amount;
	Vector dmg_origin;
	float dmg_take;
	float dmg_save;
	int damage_type_bits;
	int hud_damage_bits;
	float death_time;
	float death_anim_time;
	int observer_mode;
	int fov;
	int default_fov;
	int fov_start;
	float fov_time;
	int last_observer_mode;
	BaseHandle observer_target;
	bool forced_observer_mode;
	BaseHandle zoom_owner;
	float tbd_prev;
	int drown_dmg;
	int drown_restored;
	int poison_dmg;
	int poison_restored;
	unsigned char time_based_damage[8];
	int vphysics_collision_state;
	float next_suicide_time;
	int suicide_custom_kill_flags;
	float delay;
	float replay_end;
	int replay_entity;
	UtlVector<CommandContext> command_context;
	IPhysicsPlayerController* physics_controller;
	IPhysicsObject* shadow_stand;
	IPhysicsObject* shadow_crouch;
	Vector old_origin;
	Vector smoothed_velocity;
	bool is_touched_phys_object;
	bool is_physics_was_frozen;
	int player_sound;
	int target_volume;
	int rg_items[5];
	float swim_time;
	float duck_time;
	float duck_jump_time;
	float suit_update;
	int rg_suit_player_list[4];
	int suit_play_next;
	int suit_no_repeat[32];
	float suit_no_repeat_time[32];
	float geiger_range;
	float geiger_delay;
	int geiger_range_prev;
	bool hud_init;
	bool is_game_hud_initialized;
	bool weapon;
	int update_time;
	int client_battery;
	QAngle auto_aim;
	int auto_aim_last_x;
	int auto_aim_last_y;
	int frags;
	int deaths;
	float next_decal_time;
	PlayerConnectedState connected_state;
	int armor_value;
	float air_finished;
	float pain_finished;
	int player_locked;
	BaseHandle view_model[2];
	UserCmd last_cmd;
	UserCmd* current_command;
	int lock_view_angles_tick_number;
	QAngle lock_view_angles;
	float step_sound_time;
	bool allow_instant_spawn;
	float max_speed;
	float water_jump_time;
	Vector water_jump_vel;
	int impulse;
	float swim_sound_time;
	Vector ladder_normal;
	float flash_time;
	int drown_dmg_rate;
	int num_croushes;
	bool is_duck_toggled;
	float forward_move;
	float side_move;
	int num_crate_hud_hints;
	Vector forced_origin;
	bool force_origin;
	int tick_base;
	bool is_game_paused;
	float last_player_talk_time;
	BaseHandle last_weapon;
	UtlVector<BaseHandle> simulated_by_this_player;
	float old_player_z;
	float old_player_view_offset_z;
	bool is_player_under_water;
	BaseHandle view_entity;
	BaseHandle constraint_entity;
	Vector constraint_center;
	float constraint_radius;
	float constraint_width;
	float constraint_speed_factor;
	char net_name[max_player_name_length];
	float lagged_movement_value;
	Vector new_vphysics_position;
	Vector new_vphysics_velocity;
	Vector vehicle_view_origin;
	QAngle vehicle_view_angles;
	float vehicle_view_fov;
	int vehicle_view_saved_frame;
	Vector previously_predicted_origin;
	int body_pitch_pose_param;
	char last_place_name[18];
	char network_id_string[64];
	PlayerInfoManager player_info;
	int surface_props;
	surfacedata_t* surface_data;
	float surface_friction;
	char texture_type;
	char previous_texture_type;
	bool is_single_player_game_ending;
	bool is_has_haptics;
	bool is_auto_kick_disabled;
	StepSoundCache step_sound_cache[2];
	UtlLinkedList<PlayerSimInfo> player_sim_info;
	UtlLinkedList<PlayerCmdInfo> player_cmd_info;
	IntervalTimer weapon_fired_timer;
	float last_user_command_time;
	UtlVector<float> achievement_times;
};

template <typename K, typename T, typename I = unsigned short> 
class UtlMap {
public:
	using LessFunc = bool (*)(const K&, const K&);

	struct Node {
		K key;
		T elem;
	};

	class KeyLess {
	public:
		bool operator!() const {
			return !less_func;
		}

		bool operator()(const Node& left, const Node& right) const {
			return less_func(left.key, right.key);
		}

		LessFunc less_func;
	};

	I find(const K& key) const {
		Node dummy_node;
		dummy_node.key = key;
		return tree.find(dummy_node);
	}

	inline
	T& operator[](I i) const {
		return tree.element(i).elem;
	}

protected:
	UtlRbTree<Node, I, KeyLess> tree;
};

template <class T, class I = int> 
class UtlDict {
public:
	inline
	I find(const char* name) const {
		return elements.find(name);
	}

	inline
	T& element(I i) const {
		return elements[i]; 
	}

	inline
	T& operator[](I i) {
		return element(i); 
	}

	UtlMap<const char*, T, I> elements;
};

class UtlString {
public:
	char* value;
};

class BaseMultiplayerPlayer : public AI_ExpresserHost<BasePlayer> {
public:
    virtual bool speak_if_allowed(const char* s, const char* modifiers=nullptr, char* out_response_chosen=nullptr, size_t buf_size=0, IRecipientFilter* filter=nullptr);
    virtual bool speak_concept_if_allowed(int c, const char* modifiers=nullptr, char*  out_response_chosen=nullptr, size_t buf_size=0, IRecipientFilter* filter=nullptr);
    virtual bool can_be_auto_balanced();
    virtual bool can_speak_voice_command();
    virtual bool should_show_voice_subtitle_to_enemy();
	virtual void note_spoke_voice_command(const char* scene);
    virtual void on_achievement_earned(int i);
    virtual MultiplayerExpresser* get_multiplayer_expresser();
    virtual int calculate_team_balance_score();
    virtual AI_Expresser* create_expresser();

    int ignore_global_chat;
    float area_capture_score_accumulator;
    float cap_point_score_rate;
    int current_concept;
    MultiplayerExpresser* expresser;
    float connection_time;
    float last_forced_change_team_time;
    int balance_score;
    KeyValues* achievement_kv;
    UtlDict<float, int> rate_limit_last_command_times;
};

struct CPlane {
	Vector normal;
	float dist;
	unsigned char type;
	unsigned char sign_bits;
	unsigned char pad[2];
};

struct BaseTrace {
    Vector start_pos;
    Vector end_pos;
    CPlane plane;
    float fraction;
    int contents;
    unsigned short disp_flags;
    bool all_solid;
    bool start_solid;
};

class IHasOwner {
public:
    virtual BaseEntity* get_owner_via_interface() = 0;
};

class BaseViewModel : public BaseAnimating, public IHasOwner {
public:
    virtual void send_view_model_matching_sequence(int sequence);
    virtual void set_weapon_model(const char* model_name, BaseCombatWeapon* weapon);
    virtual void calc_view_model_lag(Vector& origin, QAngle& angles, QAngle& original_angles);
    virtual void calc_view_model_view(BasePlayer* owner, const Vector& eye_position, const QAngle& eye_angles);
    virtual void add_view_model_bob(BasePlayer* owner, Vector& eye_position, QAngle& eye_angles);
    virtual BaseEntity* get_owner();
    virtual void add_effects(int efffects);
    virtual void remove_effects(int effects);
    virtual BaseCombatWeapon* get_owning_weapon();
    virtual bool is_self_animating();

    Vector last_facing;
    int view_model_index;
    BaseHandle owner;
    float time_weapon_idle;
    Activity activity;
    int animation_parity;
    const char* vm_name;
    const char* animation_prefix;
    BaseHandle weapon;
    UtlVector<BaseHandle> screens;
};

class PredictedViewModel : public BaseViewModel {
    virtual ~PredictedViewModel();
    virtual void CalcViewModeLag(Vector& origin, QAngle& angles, QAngle& original_angles);
};

class BitWriteMasksInit {
public:
    BitWriteMasksInit();
} inline const bit_write_masks_init;

template <typename T> inline
T dword_swap(T dw) {
   unsigned temp;

   temp = *(static_cast<unsigned*>(&dw)) >> 24;
   temp |= ((*(static_cast<unsigned*>(&dw)) & 0x00ff0000) >> 8);
   temp |= ((*(static_cast<unsigned*>(&dw)) & 0x0000ff00) << 8);
   temp |= ((*(static_cast<unsigned*>(&dw)) & 0x000000ff) << 24);

   return *(static_cast<T*>(&temp));
}

inline
unsigned little_dword(unsigned val) {
	int test = 1;
	return *reinterpret_cast<char*>(&test) == 1 ? val : dword_swap(val);
}

inline
unsigned long load_little_dword(const unsigned long* base, unsigned dword_index) {
	return little_dword(base[dword_index]);
}

class BfRead {
public:
	BfRead(const void* data, int bytes, int start_bit=0) {
		this->assert_on_overflow = true;
		this->start_reading(data, bytes, start_bit);
	}

	void start_reading(const void* data, int bytes, int start_bit=0, int bits=-1) {
		this->data = reinterpret_cast<const unsigned char*>(data);
		this->data_bytes = bytes;

		if (bits == -1)
			this->data_bits = this->data_bytes << 3;
		else
			this->data_bits = bits;
		
		this->cur_bit = start_bit;
		this->overflow = false;
	}

	inline
	unsigned int read_u_bit_long(int num_bits) {
		unsigned start_bit = this->cur_bit & 31u;
		int last_bit = this->cur_bit + num_bits - 1;

		unsigned word_offset1 = this->cur_bit >> 5;
		unsigned word_offset2 = last_bit >> 5;

		this->cur_bit += num_bits;

		unsigned dw1 = reinterpret_cast<const unsigned long*>(data)[word_offset1] >> start_bit;
		unsigned dw2 = reinterpret_cast<const unsigned long*>(data)[word_offset2] << (32 - start_bit);

		unsigned int bit_mask = extra_masks[num_bits];

		return (dw1 | dw2) & bit_mask;
	}

	void read_bits(void* out_data, int bits) {
		unsigned char* out = reinterpret_cast<unsigned char*>(out_data);
		int bits_left = bits;

		while ((reinterpret_cast<std::size_t>(out) & 3) != 0 && bits_left >= 8) {
			*out = static_cast<unsigned char>(this->read_u_bit_long(8));
			++out;
			bits_left -= 8;
		}
		
		while (bits_left >= 32) {
			*reinterpret_cast<unsigned long*>(out) = this->read_u_bit_long(32);
			out += sizeof(unsigned long);
			bits_left -= 32;
		}

		while (bits_left >= 8) {
			*out = this->read_u_bit_long(8);
			++out;
			bits_left -= 8;
		}

		if (bits_left)
			*out = this->read_u_bit_long(bits_left);
	}

	float read_float() {
		float r;
		this->read_bits(&r, 32);
		return r;
	}

	inline
	int read_byte() {
		return this->read_u_bit_long(8);
	}

	const unsigned char* data;
	int data_bytes;
	int data_bits;
	int cur_bit;

private:
	bool overflow;
	bool assert_on_overflow;
	const char* debug_name;
};

class BfWrite {
public:
    BfWrite(void* data, int bytes, int max_bits=-1);
    void start_writing(void* data, int bytes, int start_bit=0, int max_bits=-1);
    void write_u_bit_long(unsigned int data, int num_bits) __restrict;
    void write_s_bit_long(int data, int num_bits);
    void write_bits(const void* in, int bits);
    void write_char(int value);
    void write_byte(int value);
    void write_one_bit(int value);
    void write_short(int value);
    void write_word(int value);
    void write_long(long value);
    void write_long_long(long long value);
    void write_float(float value);
    void write_bytes(const void* buf, int bytes);
    void write_string(const char* str);

    unsigned long* __restrict data;
    int data_bytes;
    int data_bits;
    int cur_bit;

private:
    bool overflow;
    bool assert_on_overflow;
    const char* debug_name;
};

class IBotManager {
public:
	virtual IBotController* get_bot_controller(Edict* e) = 0;
	virtual Edict* create_bot(const char* name) = 0;
};

struct CSurface {
    const char* name;
    short surface_props;
    unsigned short flags;
};

struct CheckTransmitInfo {
    Edict* client_ent;
    unsigned char pvs[8192];
    int pvs_size;
    BitVec<2048>* transmit_edict;
    BitVec<2048>* transmit_always;
    int areas_networked;
    int areas[8];
    unsigned char area_flood_nums[256];
    int map_areas;
};

class UtlMemoryPool {
public:
	class Blob {
	public:
		Blob* prev;
        Blob* next;
		int num_bytes;
		char data[1];
		char padding[3];
	};

	int block_size;
	int blocks_per_blob;
	int grow_mode;
	int blocks_allocated;
	void* head_of_free_list;
	int peak_alloc;
	unsigned short alignment;
	unsigned short num_blobs;
	const char*	alloc_owner;
	Blob blob_head;
};

template <typename T>
class ClassMemoryPool : public UtlMemoryPool {

};

class ClientFrameManager {
public:
	virtual ~ClientFrameManager();

	ClientFrame* frames;
	ClientFrame* last_frame;
	int num_frames;
	ClassMemoryPool<ClientFrame> client_frame_pool;
};

class FrameSnapshotEntry {
public:
	ServerClass* cls;
	int serial_number;
	std::intptr_t packed_data;
};

class FrameSnapshot {
public:
	volatile int list_index;
	int tick_count;
	FrameSnapshotEntry* entities;
	int num_entities;
	unsigned short* valid_entities;
	int num_valid_entities;
	HLTVEntityData* hltv_entity_data;
	ReplayEntityData* replay_entity_data;
	EventInfo** temp_entities;
	int num_temp_entities;
	UtlVector<int> explicit_delete_slots;

private:
	volatile int references;
};

class ClientFrame {
public:
    virtual ~ClientFrame();
    virtual bool is_mem_pool_allocated();

    int last_entity;
    int tick_count;

    BitVec<max_edicts> transmit_entity;
    BitVec<max_edicts>* from_baseline;
    BitVec<max_edicts>* transmit_always;
    ClientFrame* next;
    FrameSnapshot* snapshot;
};

struct SteamIDComponent {
	unsigned int account_id : 32;
	unsigned int account_instance: 20;
	unsigned int account_type : 4;
	AccountUniverse universe : 8;
};

#pragma pack(push, 1)

struct SteamID {
	union {
		SteamIDComponent component;
		unsigned long long all_bits;
	};
};

#pragma pack(pop)

class INetMessageHandler {
public:
	virtual ~INetMessageHandler();
	virtual bool process_tick(NetTick* msg) = 0;
	virtual bool process_string_cmd(NetStringCmd* msg) = 0;
    virtual bool process_set_convar(NetSetConvar* msg) = 0;
    virtual bool process_signon_state(NetSignonState* msg) = 0;
};

class IClientMessageHandler : public INetMessageHandler {
public:
    virtual ~IClientMessageHandler();
    virtual bool process_client_info(NetClientInfo* msg) = 0;
	virtual bool process_move(NetMove* msg) = 0;
	virtual bool process_voice_data(NetVoiceData* msg) = 0;
    virtual bool process_baseline_ack(NetBaselineAck* msg) = 0;
    virtual bool process_listen_events(NetListenEvents* msg) = 0;
	virtual bool process_respond_cvar_value(NetRespondCvarValue* msg) = 0;
	virtual bool process_file_crc_check(NetFileCrcCheck* msg) = 0;
	virtual bool process_file_md5_check(NetFileMd5Check* msg) = 0;
	virtual bool process_save_replay(NetSaveReplay* msg) = 0;
    virtual bool process_cmd_key_values(NetCmdKeyValues* msg) = 0;
};

class INetMessage {
public:
	virtual	~INetMessage();
	virtual void set_net_channel(INetChannel*) = 0;
	virtual void set_reliable(bool) = 0;
	virtual bool process() = 0;
	virtual	bool read_from_buffer(BfRead&) = 0;
	virtual	bool write_to_buffer(BfWrite&) = 0;
	virtual bool is_reliable() const = 0;
	virtual int get_type() const = 0;
	virtual int get_group() const = 0;
	virtual const char* get_name() const = 0;
	virtual INetChannel* get_net_channel() const = 0;
	virtual const char* to_string() const = 0;
};

class NetMessage : public INetMessage {
	virtual ~NetMessage();

	bool reliable;
	INetChannel* net_channel;
};

class SVC_UserMessage: public NetMessage {
public:
	virtual ~SVC_UserMessage();
	
	int __pad;
	int msg_type;
	int length;
	BfRead data_in;
	BfWrite data_out;
};

class IGameEventListener2 {
public:
	virtual ~IGameEventListener2();
	virtual void fire_game_event(IGameEvent* event) = 0;
};

class INetChannelHandler {
public:
	virtual	~INetChannelHandler();
	virtual void connection_start(INetChannel* ch) = 0;
	virtual void connection_closing(const char* reason) = 0;
	virtual void connection_crashed(const char* reason) = 0;
	virtual void packet_start(int incoming_sequence, int outgoing_acknowledged) = 0;
	virtual void packet_end() = 0;
	virtual void file_requested(const char* name, unsigned int transfer_id) = 0;
	virtual void file_received(const char* name, unsigned int tranfser_iid) = 0;
	virtual void file_dened(const char* name, unsigned int transfer_id) = 0;
	virtual void file_sent(const char* name, unsigned int transfer_id) = 0;
};

class INetChannelInfo {
public:
    virtual const char* get_name() const = 0;
	virtual const char* get_address() const = 0;
	virtual float get_time() const = 0;
	virtual float get_time_connected() const = 0;
	virtual int	get_buffer_siize() const = 0;
	virtual int get_data_rate() const = 0;
	virtual bool is_loop_back() const = 0;
	virtual bool is_timing_out() const = 0;
	virtual bool is_playback() const = 0;
	virtual float get_latency(int flow) const = 0;
	virtual float get_avg_latency(int flow) const = 0;
	virtual float get_avg_loss(int flow) const = 0;
	virtual float get_avg_choke(int flow) const = 0;
	virtual float get_avg_data(int flow) const = 0;
	virtual float get_avg_packets(int flow) const = 0;
	virtual int get_total_data(int flow) const = 0;
	virtual int get_sequence_nr(int flow) const = 0;
	virtual bool is_valid_packet(int flow, int frame_number) const = 0;
	virtual float get_packet_time(int flow, int frame_number) const = 0;
	virtual int get_packet_bytes(int flow, int frame_number, int group) const = 0;
	virtual bool get_stream_progress(int flow, int* received, int *total) const = 0;
	virtual float get_time_since_last_received() const = 0;
	virtual	float get_command_interpolaton_amount(int flow, int frame_number) const = 0;
	virtual void get_packet_response_latency(int flow, int frame_number, int* latency, int* choke) const = 0;
	virtual void get_remote_framerate(float* frame_time, float* frame_time_std_deviation) const = 0;
	virtual float get_timeout_seconds() const = 0;
};

class INetChannel : public INetChannelInfo {
public:
	virtual	~INetChannel();
	virtual void set_data_rate(float rate) = 0;
	virtual bool register_message(INetMessage* msg) = 0;
	virtual bool start_streaming(unsigned int challenge) = 0;
	virtual void reset_streaming() = 0;
	virtual void set_timeout(float seconds) = 0;
	virtual void set_demo_recorder(IDemoRecorder* recorder) = 0;
	virtual void set_challenge_nr(unsigned int chnr) = 0;
	virtual void reset() = 0;
	virtual void clear() = 0;
	virtual void shutdown(const char* reason) = 0;
	virtual void process_playback() = 0;
	virtual bool process_stream() = 0;
	virtual void process_packet(struct netpacket_s* packet, bool is_has_header) = 0;
	virtual bool set_net_msg(INetMessage& msg, bool force_reliable=false, bool voice=false) = 0;
	virtual bool send_data(BfWrite& msg, bool reliable=true) = 0;
	virtual bool send_file(const char* name, unsigned int transfer_id) = 0;
	virtual void deny_file(const char* name, unsigned int transfer_id) = 0;
	virtual void request_file_old(const char* name, unsigned int transfer_id) = 0;
	virtual void set_choked() = 0;
	virtual int send_datagram(BfWrite* data) = 0;		
	virtual bool transmit(bool reliable=false) = 0;
	virtual const netadr_t& get_remote_address() const = 0;
	virtual INetChannelHandler* get_msg_handler() const = 0;
	virtual int	get_drop_number() const = 0;
	virtual int get_socket() const = 0;
	virtual unsigned int get_challenge_nr() const = 0;
	virtual void get_sequence_data(int& out_sequence_nr, int& in_sequence_nr, int& out_sequence_nr_ack) = 0;
	virtual void set_sequence_data(int out_sequence_nr, int in_sequence_nr, int out_sequence_nr_ack) = 0;
	virtual void update_message_stats(int msg_group, int bits) = 0;
	virtual bool can_packet() const = 0;
	virtual bool is_overflowed() const = 0;
	virtual bool is_timed_out() const  = 0;
	virtual bool is_has_pending_reliable_data() = 0;
	virtual void set_file_transmission_mode(bool mode) = 0;
	virtual void set_compression_mode(bool use) = 0;
	virtual unsigned int request_file(const char* name) = 0;
	virtual float get_time_siince_last_received() const = 0;
	virtual void set_max_buffer_size(bool reliiable, int n_bytes, bool voice=false) = 0;
	virtual bool is_null() const = 0;
	virtual int get_num_biits_written(bool reliable) = 0;
	virtual void set_interpolation_amount(float amount) = 0;
	virtual void set_remote_framerate(float frame_time, float frame_time_std_deviation) = 0;
	virtual void set_max_routable_payload_size(int split_size) = 0;
	virtual int get_max_routable_payload_size() = 0;
	virtual int get_protocol_version() = 0;
};

struct Spike {
	char desc[64];
	int bits;
};

struct NetworkStatTrace {
	int min_warning_bytes;
	int start_bit;
	int cur_bit;
	UtlVector<Spike> records;
	double start_send_time;
};

struct CustomFile {
	unsigned int crc;
	unsigned int request_id;
};

class IClient : public INetChannelHandler {
public:
	virtual	~IClient();
	virtual void connect(const char* name, int user_id, INetChannel* ch, bool is_fake_player, int challenge) = 0;
	virtual void inactivate() = 0;
	virtual	void reconnect() = 0;
	virtual void disconnect(const char* reason, ...) = 0;
	virtual int	get_player_slot() const = 0;
	virtual int get_user_id() const = 0;
	virtual const UserId get_network_id() const = 0;
	virtual const char* get_client_name() const = 0;
	virtual INetChannel* get_net_channel() = 0;
	virtual IServer* get_server() = 0;
	virtual const char* get_user_setting(const char* cvar) const = 0;
	virtual const char* get_network_id_string() const = 0;
	virtual void set_rate(int rate, bool force) = 0;
	virtual int get_rate() const = 0;
	virtual void set_update_rate(int rate, bool force) = 0;
	virtual int get_update_rate() const = 0;	
	virtual void clear() = 0;
	virtual int get_max_ack_tick_count() const = 0;
	virtual bool execute_string_command(const char* s) = 0;
	virtual bool send_net_msg(INetMessage& msg, bool force_reliable=false) = 0;
	virtual void client_printf (const char* fmt, ...) = 0;
	virtual bool is_connected() const = 0;
	virtual bool is_spawned() const = 0;
	virtual bool is_active() const = 0;
	virtual bool is_fake_client() const = 0;
	virtual bool is_hltv() const = 0;
	virtual bool is_replay() const = 0;
	virtual bool is_hearing_client(int index) const = 0;
	virtual bool is_proximity_hearing_client(int index) const = 0;
	virtual void set_max_routable_payload_size(int size) = 0;
};

class BaseClient : public IGameEventListener2, public IClient, public IClientMessageHandler {
public:
	virtual ~BaseClient();
	
	int	get_player_slot() const;
	int get_user_id() const;
	const UserId get_network_id() const;
	const char* get_client_name() const;
	INetChannel* get_net_channel();
	IServer* get_server();
	const char* get_user_setting(const char* cvar) const;
	const char* get_network_id_string() const;

	virtual void connect(const char* name, int user_id, INetChannel* ch, bool is_fake_player, int challenge);
	virtual void inactivate();
	virtual	void reconnect();
	virtual void disconnect(const char* reason, ...);
	virtual	void set_rate(int rate, bool force);
	virtual	int get_rate() const;
	virtual void set_update_rate(int update_rate, bool force);
	virtual int get_update_rate() const;
	virtual void clear();
	virtual void demo_restart();
	virtual	int get_max_ack_tick_count() const;
	virtual bool execute_string_command(const char* s);
	virtual bool send_net_msg(INetMessage& msg, bool force_reliable=false);
	virtual void client_printf(const char* fmt, ...);
	virtual	bool is_connected() const;
	virtual	bool is_spawned() const;
	virtual	bool is_active() const;
	virtual	bool is_fake_client() const;
	virtual	bool is_hltv() const;
	virtual bool is_replay() const;
	virtual	bool is_hearing_client(int index) const;
	virtual	bool is_proximity_hearing_client(int index) const;
	virtual void set_max_routable_payload_size(int value);
	virtual bool is_split_screen_user() const;
	virtual bool process_tick(NetTick* msg);
	virtual bool process_string_cmd(NetStringCmd* msg);
    virtual bool process_set_convar(NetSetConvar* msg);
    virtual bool process_signon_state(NetSignonState* msg);
	virtual bool process_client_info(NetClientInfo* msg);
	virtual bool process_baseline_ack(NetBaselineAck* msg);
	virtual bool process_listen_events(NetListenEvents* msg);
	virtual bool process_cmd_key_values(NetCmdKeyValues* msg);
	virtual void connection_start(INetChannel* ch);
	virtual void fire_game_event(IGameEvent*);
	virtual	bool update_acknowledged_frame_count(int tick);
	virtual bool should_send_messages();
	virtual void update_send_state();
	virtual bool fill_user_info(PlayerInfo*);
	virtual void update_user_settings();
	virtual bool set_signon_state(int state, int spawn_count);
	virtual void write_game_sounds(BfWrite&);
	virtual ClientFrame* get_delta_frame(int tick);
	virtual void send_snapshot(ClientFrame*);
	virtual bool send_server_info();
	virtual bool send_signon_data();
	virtual void spawn_player();
	virtual void activate_player();
	virtual void set_name(const char*);
	virtual void set_user_cvar(const char* cvar, const char* value);
	virtual void free_baselines();
	virtual bool ignore_temp_entity(EventInfo*);
	
	int client_slot;
	int entity_index;
	int user_id;
	char name[32];
	char guid[33];
	SteamID steam_id;
	unsigned int friends_id;
	char friends_name[32];
	KeyValues* convars;
	bool convars_changed;
	bool initial_convars_set;
	bool should_send_server_info;
	BaseServer* server;
	bool hltv;
	bool replay;
	int client_challenge;
	unsigned int send_table_crc;
	CustomFile custom_files[4];
	int files_downloaded;
	INetChannel* net_channel;
	int signon_state;
	int delta_tick;
	int string_table_ack_tick;
	int signon_tick;
	// CSmartPtr
	void* last_snapshot;
	FrameSnapshot* baseline;
	int base_line_update_tick;
	// CBitVec
	unsigned int baselines_sent[(2048 + (32 - 1)) / 32];
	int baseline_used;
	int force_wait_for_tick;
	bool is_fake_player;
	bool report_fake_client;
	bool received_packet;
	bool fully_authenticated;
	double time_last_name_change;
	bool player_name_locked;
	char pending_name_change[32];
	double next_message_time;
	float snapshot_interval;
	unsigned int snapshot_scratch_buffer[160'000 / 4];
	int tracing;
	NetworkStatTrace trace;
};

class GameClient : public BaseClient, public ClientFrameManager {
public:
	virtual void connection_closing(const char* reason);
	virtual void connection_crashed(const char* reason);
	virtual void packet_start(int incoming_sequence, int outgoing_acknowledged);
	virtual void packet_end();
	virtual void file_received(const char* name, unsigned int tranfser_iid);
	virtual void file_requested(const char* name, unsigned int transfer_id);
	virtual void file_dened(const char* name, unsigned int transfer_id);
	virtual void file_sent(const char* name, unsigned int transfer_id);
	virtual bool process_move(NetMove* msg);
	virtual bool process_voice_data(NetVoiceData* msg);
	virtual bool process_respond_cvar_value(NetRespondCvarValue* msg);
	virtual bool process_fle_crc_check(NetFileCrcCheck* msg);
	virtual bool process_file_md5_check(NetFileMd5Check* msg);
	virtual bool process_save_replay(NetSaveReplay* msg);

	bool voice_loopback;
	// CBitVec
	unsigned int voice_streams[(255 + (32 - 1)) / 32];
	unsigned int voice_proximity[(255 + (32 - 1)) / 32];
	int last_movement_tick;
	int sound_sequence;
	Edict* edict;
	UtlVector<SoundInfo> sounds;
	const Edict* view_entity;
	ClientFrame* current_frame;
	CheckTransmitInfo pack_info;
	bool is_in_replay_mode;
	CheckTransmitInfo prev_pack_info;
	// CBitVec
	unsigned int prev_transmit_edict[(2048 + (32 - 1)) / 32];
	float last_save_replay_time;
};

class Command {
public:
	const char* operator[](int index) const;
	int count() const;

	int args_count;
	int args_size;
	char arg_s_buffer[512];
	char arg_v_buffer[512];
	const char* args[664];
};

class ConCommandBase {
public:
	virtual ~ConCommandBase();
	virtual bool is_command() const;
	virtual bool is_flag_set(int f) const;
	virtual void add_flags(int f);
	virtual const char* get_name() const;
	virtual const char* get_help_text() const;
	virtual bool is_registered() const;
	virtual int get_dll_identifier() const;

protected:
	virtual void create_base(const char* n, const char* hs=0, int f=0);
	virtual void init();

public:
	ConCommandBase* next;
	bool registered;
	const char* name;
	const char* help_string;
	int flags;
};

class ConCommand : public ConCommandBase {
public:
	virtual ~ConCommand();
	virtual int suggest_auto_complete(const char* partial, UtlVector<UtlString>& commands);
	virtual bool can_auto_complete();
	virtual void dispatch(const Command& c);

	void (*command_callback)(const Command& c);
	
	union {
		int (*completion_callback)(const char* partial, char commands[64][64]);
		ICommandCompletionCallback* command_completion_callback;
	};

	bool has_completion_callback;
	bool is_using_new_command_callback;
	bool is_using_command_callback_interface;
};

class IConVar {
public:
	virtual void set_value(const char* value) = 0;
	virtual void set_value(float value) = 0;
	virtual void set_value(int value) = 0;
	virtual const char* get_name() const = 0;
	virtual bool is_flag_set(int flag) const = 0;
};

class ConVar: public ConCommandBase, public IConVar {
public:
	virtual ~ConVar();
	virtual bool is_flag_set(int flag) const;
	virtual const char* get_help_text() const;
	virtual bool is_registered() const;
	virtual const char* get_name() const;
	virtual void add_flags(int flags);
	virtual bool is_command() const;
	virtual void set_value(const char* value);
	virtual void set_value(float value);
	virtual void set_value(int value);

	float get_float() const;
	int get_int() const;

private:
	virtual void set_internal_value(const char* value);
	virtual void set_internal_value(float value);
	virtual void set_internal_value(int value);
	virtual bool clamp_value(float& value);
	virtual void change_string_value(const char* value, float old_value);
	virtual void create(const char* name, const char* default_value, int flags=0, const char* help_string=0, bool is_has_min=false, float min=0.0, bool is_has_max=false, float max=0.0, ChangeCallback callback=0);
	virtual void init();

public:
	ConVar* parent;
	const char* default_value;
	char* string;
	int string_length;
	float float_value;
	int int_value;
	bool is_has_min;
	float min_value;
	bool is_has_max;
	float max_value;
	ChangeCallback change_callback;
};

class CountdownTimer {
public:
    virtual float now() const;

	float duration;
	float timestamp;
};

struct RebuyStruct {
	char primary_weapon[64];
	char secondary_weapon[64];
	int primary_ammo;
	int secondary_ammo;
	int grenade;
	int flashbang;
	int smoke_grenade;
	int armor;
	bool defuser;
	bool night_vision;
};

class ICSPlayerAnimStateHelpers {
public:
	virtual WeaponCSBase* cs_anim_get_active_weapon() = 0;
	virtual bool cs_anim_can_move() = 0;
};

class CSPlayer : public BaseMultiplayerPlayer, public ICSPlayerAnimStateHelpers {
public:
    virtual bool is_being_given_item() const;
    virtual WeaponCSBase* cs_anim_get_active_weapon();
	virtual bool cs_anim_can_move();
    virtual void blind(float hold_time, float fade_time, float starting_alpha=255);

    HintMessageQueue* hint_message_queue;
    unsigned int display_history_bits;
    bool show_hints;
    float last_attacked_teammate;
    float next_mouse_over_update;
    float blind_until_time;
    float blind_start_time;
    float allow_auto_follow_time;
    float radio_time;
    int radio_messages;
    int radio_menu;
    bool ignore_radio;
    CSPlayerState cs_player_state;
    CSPlayerStateInfo* cur_state_info;
    bool receives_money_next_round;
    int death_pose;
    int death_frame;
    bool abort_freeze_cam;
    bool resume_zoom;
    int last_zoom;
    bool is_defusing;
    int last_hit_group;
    int last_hit_box;
    Vector last_hit_location_object_space;
    BaseHandle dropped_equipment[4];
    bool has_helmet;
    bool is_escaped;
    bool is_vip;
    int num_spawns;
    int old_team;
    bool team_changed;
    int account;
    int should_have_cash;
    bool just_killed_teammate;
    bool punished_for_tk;
    int team_kills;
    float last_movement;
    int next_timeleft_check;
    float name_change_history[5];
    bool has_defuser;
    bool has_night_vision;
    bool nigth_vision_on;
    float last_radar_update_time;
    NavArea* last_nav_area;
    char menu_string_buffer[1024];
    BaseHandle into_camera;
    float intro_cam_time;
    bool is_in_bomb_zone;
    bool is_in_buy_zone;
    int bomb_site_index;
    bool is_in_hostage_rescue_zone;
    float stamina;
    int direction;
    int shots_fired;
    float velocity_modifier;
    int hostages_killed;
    char new_name[max_player_name_length];
    char clan_tag[16];
    Vector total_bullet_force;
    float flash_duration;
    float flash_max_alpha;
    float progess_bar_start_time;
    int progress_bar_duration;
    int throw_grenade_counter;
    BaseHandle ragdoll;
    bool duck_until_on_ground;
    Vector last_standing_pos;
    bool is_detected;
    CountdownTimer ladder_surpression_timer;
    Vector last_ladder_normal;
    Vector last_ladder_pos;
    int cs_class;
    ICSPlayerAnimState* player_anim_state;
    float idle_time;
    float move_time;
    float last_damage_time;
    float target_find_time;
    int last_damage_health;
    int last_damage_armor;
    bool picked_up_defuser;
    bool defused_with_picked_up_kit;
    int last_weapon_fire_user_cmd;
    QAngle eye_angles;
    bool v_collision_initted;
    bool is_in_auto_buy;
    bool auto_reload;
    bool is_in_rebuy;
    RebuyStruct rebuy_struct;
    bool using_default_pistol;
    bool being_given_item;
    int addon_bits;
    int primary_addon;
    int secondary_addon;
    UtlLinkedList<DamageRecord*, int> damage_given_list;
    UtlLinkedList<DamageRecord*, int> damage_taken_list;
    float apply_deafness_time;
    int current_deafness_filter;
    bool is_vip_;
    UtlDict<float, int> rate_limit_last_command_times;
    int cycle_latch;
    CountdownTimer cycle_latch_timer;
    UtlVector<float> kill_times;
    UtlVector<BaseHandle> enemy_players_killed_this_round;
    UtlVector<int> kill_weapons;
    int num_enemies_killed_this_round;
    int num_enemies_at_round_start;
    int killing_spree_start_time;
    float first_kill_blind_start_time;
    int kills_while_blind;
    bool is_rescuing;
    bool injured_a_hostage;
    int num_followers;
    bool survived_headshot_due_to_helmet;
    GooseChaseAchievementStep goose_chase_step;
    DefuseDefenseAchivementStep defuse_defense_step;
    BaseHandle goose_chase_distracting_player;
    int last_round_result;
    bool made_footstep_noise;
    float bomb_pickup_time;
    bool made_purchase_this_round;
    int rounds_won_without_purchase;
    bool killed_defuser;
    bool killed_rescuer;
    int max_grenade_kills;
    int grenade_damage_taken_this_round;
    BaseHandle last_flashbang_attacker;
    bool was_not_killed_naturally;
    bool player_dominated[66];
    bool player_dominating_me[66];
    int mvps;
    bool wielding_knife_and_killed_by_gun;
    UtlVector<CSWeaponID> weapon_type_used;
    int death_flags;
};

class FileWeaponInfo {
public:
	virtual void parse(KeyValues* kv, const char* weapon_name);

	bool is_parsed_script;
	bool is_loaded_hud_elements;
	char class_name[max_weapon_string];
	char print_name[max_weapon_string];
	char view_model[max_weapon_string];
	char world_model[max_weapon_string];
	char animation_prefix[max_weapon_prefix];
	int slot;
	int position;
	int max_clip_primary;
	int max_clip_secondary;
	int default_clip_primary;
	int default_clip_secondary;
	int weight;
	int rumble_effect;
	bool auto_switch_to;
	bool auto_switch_from;
	int flags;
	char ammo_primary[max_weapon_ammo_name];
	char ammo_secondary[max_weapon_ammo_name];
	char shoot_sounds[num_shoot_sound_types][max_weapon_string];	
	int ammo_type_primary;
	int ammo_type_secondary;
	bool is_melee_weapon;
	bool is_build_right_handed;
	bool allow_flipping;
	int sprite_count;
	HudTexture* active_icon;
	HudTexture* inactive_icon;
	HudTexture* primary_ammo_icon;
	HudTexture* secondary_ammo_icon;
	HudTexture* crosshair_icon;
	HudTexture* auto_aim_icon;
	HudTexture* zoomed_crosshair_icon;
	HudTexture* zoomed_auto_aim_icon;
	HudTexture* small_icon;
	bool show_usage_hint;
};

class Edict: public BaseEdict {
public:
	float free_time; 
};

class ICvar: public IAppSystem {
public:
	virtual int allocate_dll_identifier() = 0;
	virtual void register_console_command(ConCommandBase* command) = 0;
	virtual void unregister_console_command(ConCommandBase* command) = 0;
	virtual void unregister_console_commands(int dll_identifier) = 0;
	virtual const char* get_command_line_value(const char* name) = 0;
	virtual ConCommandBase* find_command_base(const char* name) = 0;
	virtual const ConCommandBase* find_command_base(const char* name) const = 0;
	virtual ConVar* find_var(const char* name) = 0;
	virtual const ConVar* find_var(const char* name) const = 0;
	virtual ConCommand* find_command(const char* name) = 0;
	virtual const ConCommand* find_command(const char* name) const = 0;
	virtual ConCommandBase* get_commands() = 0;
	virtual const ConCommandBase* get_commands() const = 0;
	virtual void install_global_change_callback(ChangeCallback callback) = 0;
	virtual void remove_global_change_callback(ChangeCallback callback) = 0;
	virtual void call_global_change_callbacks(ConVar* var, const char* old_string, float old_value) = 0;
	virtual void install_console_display_func(IConsoleDisplayFunc* func) = 0;
	virtual void remove_console_display_func(IConsoleDisplayFunc* func) = 0;
	virtual void console_color_printf(const Color& color, const char* format, ...) const = 0;
	virtual void console_printf(const char* format, ...) const = 0;
	virtual void console_dprintf(const char* format, ...) const = 0;
	virtual void revert_flagged_convars(int flag) = 0;
	virtual void install_cvar_query(ICvarQuery query) = 0;
	virtual bool is_material_thread_set_allowed() const = 0;
	virtual void queue_material_thread_set_value(ConVar cvar, const char* value) = 0;
	virtual void queue_material_thread_set_value(ConVar cvar, int value) = 0;
	virtual void queue_material_thread_set_value(ConVar cvar, float value) = 0;
	virtual bool has_queued_material_thread_convar_sets() const = 0;
	virtual int process_queued_material_thread_convar_sets() = 0;
};

class IVEngineServer {
public:
	virtual void change_level(const char* s1, const char* s2) = 0;
	virtual int is_map_valid(const char* file_name) = 0;
	virtual bool is_dedicated_server() = 0;
	virtual int is_in_edit_mode() = 0;
	virtual int precache_model(const char* s, bool preload=false) = 0;
	virtual int precache_sentence_file(const char* s, bool preload=false) = 0;
	virtual int precache_decal(const char* name, bool preload=false) = 0;
	virtual int precache_generic(const char* s, bool preload=false) = 0;
	virtual bool is_model_precached(const char* s) const = 0;
	virtual bool is_decal_precached(const char* s ) const = 0;
	virtual bool is_generic_precached(const char* s) const = 0;
	virtual int get_cluster_for_origin(const Vector& origin) = 0;
	virtual int get_pvs_for_cluster(int cluster, int output_pvs_length, unsigned char* output_pvs) = 0;
	virtual bool check_origin_in_pvs(const Vector& origin, const unsigned char* check_pvs, int check_pvs_size) = 0;
	virtual bool check_box_in_pvs(const Vector& mins, const Vector& maxs, const unsigned char* check_pvs, int check_pvs_size) = 0;
	virtual int get_player_user_id(const Edict* e) = 0; 
	virtual const char* get_player_network_id_string(const Edict* e) = 0;
	virtual int get_entity_count() = 0;
	virtual int get_index_from_edict(const Edict* e) = 0;
	virtual Edict* get_edict_from_index(int index) = 0;
	virtual INetChannelInfo* get_player_net_info(int index) = 0;
	virtual Edict* create_edict(int force_index = -1) = 0;
	virtual void remove_edict(Edict* e) = 0;
	virtual void* pv_alloc_ent_private_data(long cb) = 0;
	virtual void free_ent_private_data(void* entity) = 0;
	virtual void* save_alloc_memory(size_t num, size_t size) = 0;
	virtual void save_free_memory( void* m) = 0;
	virtual void emit_ambient_sound(int ent_index, const Vector& pos, const char* samp, float vol, soundlevel_t sound_level, int flags, int pitch, float delay = 0.0f) = 0;
	virtual void fade_client_volume(const Edict* e, float fade_percent, float fade_out_seconds, float hold_time, float fade_seconds) = 0;
	virtual int sentence_group_pick(int group_index, char* name, int name_len) = 0;
	virtual int sentence_group_pick_sequential(int group_index, char* name, int name_len, int sentence_index, int reset) = 0;
	virtual int sentence_index_from_name(const char* name) = 0;
	virtual const char* sentence_name_from_index(int index) = 0;
	virtual int sentence_group_index_from_name(const char* name) = 0;
	virtual const char* sentence_group_name_from_index(int index) = 0;
	virtual float sentence_length(int index) = 0;
	virtual void execute_server_command(const char* s) = 0;
	virtual void execute_server_commands_immediately() = 0;
	virtual void execute_client_command(Edict edict, const char* fmt, ...) = 0;
	virtual void set_light_style(int style, const char* value) = 0;
	virtual void project_static_decal(const Vector& origin_in_entity_space, int decal_index, int entity_index, int model_index, bool is_low_priority) = 0;
	virtual void determine_multicast_recipients_for_message(bool use_pas, const Vector& origin, BitVec<absolute_player_limit>& player_bits) = 0;
	virtual BfWrite* begin_entity_message(int index, ServerClass* ent_class, bool is_reliable) = 0;
	virtual BfWrite* begin_user_message(const IRecipientFilter* filter, int type) = 0;
	virtual void end_user_message() = 0;
	virtual void client_printf(Edict* e, const char* msg) = 0;
	virtual void con_n_printf(int pos, const char* fmt, ...) = 0;
	virtual void con_nx_printf(const struct con_nprint_s* info, const char *fmt, ...) = 0;
	virtual void set_view(const Edict* client, const Edict* view_ent) = 0;
	virtual float get_time() = 0;
	virtual void set_crosshair_angle(const Edict* e, float pitch, float yaw) = 0;
	virtual void get_game_directory(char *s, int max_length) = 0;
	virtual int compare_file_time(const char* first, const char* second, int* compare) = 0;
	virtual bool lock_network_string_table(bool lock) = 0;
	virtual Edict* create_fake_client(const char* name) = 0;
	virtual const char* get_client_convar_value(int index, const char* name) = 0;
	virtual const char* parse_file(const char* data, char* token, int max_len) = 0;
	virtual bool copy_file(const char* source, const char* destination) = 0;
	virtual void reset_pvs(unsigned char* pvs, int pvs_size) = 0;
	virtual void add_origin_to_pvs(const Vector& origin) = 0;
	virtual void set_area_portal_state(int portal_number, int is_open) = 0;
	virtual void playback_temp_entity(IRecipientFilter& filter, float delay, const void* sender, const SendTable* table, int class_id) = 0;
	virtual int check_head_node_visible(int node, const unsigned char* pvs, int pvs_size) = 0;
	virtual int check_areas_connected(int first, int second) = 0;
	virtual int get_area(const Vector& origin ) = 0;
	virtual void get_area_bits(int area, unsigned char* bits, int buf_len) = 0;
	virtual bool get_are_portal_plane(Vector const& origin, int portal_key, VPlane* plane) = 0;
	virtual bool load_game_state(char const* map_name, bool create_players) = 0;
	virtual void load_adjacent_entities(const char* old_level, const char* landmark_name) = 0;
	virtual void clear_save_dir() = 0;
	virtual const char* get_map_entities_string() = 0;
	virtual client_textmessage_t* get_text_message( const char* name) = 0;
	virtual void log_print(const char* msg) = 0;
	virtual void build_entity_clust_list(Edict* e, PVSInfo* info) = 0;
	virtual void solid_moved(Edict* e, ICollideable* collide, const Vector* prev_abs_origin, bool test_surrounding_bounds_only) = 0;
	virtual void trigger_moved(Edict* e, bool test_surrounding_bounds_only) = 0;
	virtual ISpatialPartition* create_spatial_partition(const Vector& world_min, const Vector& world_max) = 0;
	virtual void destroy_spatial_partition(ISpatialPartition* partition) = 0;
	virtual void draw_map_to_scratch_pad(IScratchPad3D* pad, unsigned long flags) = 0;
	virtual const CBitVec* get_entity_transmit_bits_for_client(int index) = 0;
	virtual bool is_paused() = 0;
	virtual void force_exact_file(const char* s) = 0;
	virtual void force_model_bounds(const char* s, const Vector& mins, const Vector& maxs) = 0;
	virtual void clear_save_dir_after_client_load() = 0;
	virtual void set_fake_client_convar_value(Edict* e, const char* cvar, const char* value) = 0;
	virtual void force_simple_material(const char* s) = 0;
	virtual int is_in_commentary_mode() = 0;
	virtual void set_are_portal_states(const int* portal_numbers, const int* is_open, int portals) = 0;
	virtual void notify_edict_flags_change(int index) = 0;
	virtual const CheckTransmitInfo* get_prev_check_transmit_info(Edict* e) = 0;
	virtual CSharedEdictChangeInfo* get_shared_edict_change_info() = 0;
	virtual void allow_immedite_edict_reuse() = 0;
	virtual bool is_internal_build() = 0;
	virtual IChangeInfoAccessor* get_change_accessor(const Edict* e) = 0; 
	virtual char const* get_most_recently_loaded_file_name() = 0;
	virtual char const* get_save_file_name() = 0;
	virtual void multiplayer_end_game() = 0;
	virtual void change_team(const char* name) = 0;
	virtual void clean_entity_cluster_list(PVSInfo* info) = 0;
	virtual void SetAchievementMgr(IAchievementMgr* mgr) = 0;
	virtual IAchievementMgr* get_achievement_manager() = 0;
	virtual int get_app_id() = 0;
	virtual bool is_low_violence() = 0;
	virtual QueryCvarCookie_t start_query_cvar_value(Edict* e, const char* name) = 0;
	virtual void insert_server_command(const char* s) = 0;
	virtual bool get_player_info(int index, PlayerInfo* info) = 0;
	virtual bool is_client_fully_authenticated(Edict* e) = 0;
	virtual void set_dedicated_server_benchmark_mode(bool mode) = 0;
	virtual void set_game_stats_data(CGamestatsData* data) = 0;
	virtual CGamestatsData* get_game_stats_data() = 0;
	virtual const SteamID* get_client_steam_id(Edict* e) = 0;
	virtual const SteamID* get_game_server_steam_id() = 0;
	virtual void send_client_command(Edict* e, KeyValues* command) = 0;
	virtual const SteamID* get_client_steam_id_from_index(int index) = 0;
	virtual int get_cluster_count() = 0;
	virtual int get_all_cluster_bounds(bbox_t* list, int max_box) = 0;
	virtual Edict* create_fake_client_Ex(const char* name, bool report_fake_client = true) = 0;
	virtual int get_server_version() const = 0;
	virtual float get_server_time() const = 0;
	virtual IServer* get_i_server() = 0;
	virtual bool is_player_name_locked(const Edict* e) = 0;
	virtual bool can_player_change_name(const Edict* e) = 0;
	virtual FindMapResult find_map(char* name, int max_len) = 0;
};

class IEngineSound {
public:
	virtual bool precache_sound(const char* sample, bool bPreload=false, bool is_ui_sound=false) = 0;
	virtual bool is_sound_precached(const char* sample) = 0;
	virtual void prefetch_sound(const char* sample) = 0;
	virtual float get_sound_duration(const char* sample) = 0;  
	virtual void emit_sound(const IRecipientFilter& filter, int ent_index, int channel, const char* sample, float volume, float attenuation, int flags=0, int pitch=100, int special_dsp=0, const Vector* origin=nullptr, const Vector* direction=nullptr, UtlVector<Vector>* vec_origins=nullptr, bool update_positions=true, float sound_time=0.0f, int speaker_entity=-1) = 0;
    virtual void emit_sound(const IRecipientFilter& filter, int ent_index, int channel, const char* sample, float volume, SoundLevel sound_level, int flags=0, int pitch=100, int special_dsp=0, const Vector* origin=nullptr, const Vector* direction=nullptr, UtlVector<Vector>* vec_origins=nullptr, bool update_positions=true, float sound_time=0.0f, int speaker_entity=-1) = 0;
    virtual void emit_soundconst (IRecipientFilter& filter, int ent_index, int channel, int sentence_index, float volume, SoundLevel sound_level, int flags=0, int pitch=100, int special_dsp=0, const Vector* origin=nullptr, const Vector* direction=nullptr, UtlVector<Vector>* vec_origins=nullptr, bool update_positions=true, float sound_time=0.0f, int speaker_entity=-1) = 0;
    virtual void stop_sound(int ent_index, int channel, const char* sample) = 0;
	virtual void stop_all_sound(bool clear_buffers) = 0;
	virtual void set_room_type(const IRecipientFilter& filter, int room_type) = 0;
	virtual void set_player_dsp(const IRecipientFilter& filter, int dsp_type, bool fast_reset) = 0;
	virtual void emit_ambient_sound(const char* sample, float volume, int iPitch=100, int flags=0, float sound_time=0.0f) = 0;
	virtual float get_dist_gain_from_sound_level(SoundLevel sound_level, float dist) = 0;
	virtual int get_guid_for_last_sound_emitted() = 0;
	virtual bool is_sound_still_playing(int guid) = 0;
	virtual void top_sound_by_guid(int guid) = 0;
	virtual void set_volume_by_guid(int guid, float vol) = 0;
	virtual void get_active_sound(UtlVector<SndInfo>& snd_list) = 0;
	virtual void precache_sentence_group(const char* name) = 0;
	virtual void notify_begin_movie_playback() = 0;
	virtual void notify_end_movie_playback() = 0;
};

class IEngineTrace {
public:
	virtual int get_point_contents(const Vector& abs_position, IHandleEntity** entity=nullptr) = 0;
	virtual int get_point_contents_collideable(ICollideable* collide, const Vector& abs_position) = 0;
	virtual void clip_ray_to_entity(const Ray& ray, unsigned int mask, IHandleEntity* entity, GameTrace* trace) = 0;
	virtual void clip_ray_to_collideable(const Ray& ray, unsigned int fMask, ICollideable* collide, GameTrace* trace) = 0;
	virtual void trace_ray(const Ray& ray, unsigned int mask, ITraceFilter* trace_filter, GameTrace* trace) = 0;
	virtual void setup_leaf_and_entity_list_ray(const Ray& ray, CTraceListData& trace_data) = 0;
	virtual void setup_leaf_and_entity_list_box(const Vector& mins, const Vector& maxs, CTraceListData& trace_data) = 0;
	virtual void trace_ray_against_leaf_and_entity_list(const Ray& ray, CTraceListData& trace_data, unsigned int mask, ITraceFilter* trace_filter, GameTrace* trace) = 0;
	virtual void sweap_collideable(ICollideable* collide, const Vector& start, const Vector& end, const QAngle& angles, unsigned int mask, ITraceFilter* trace_filter, GameTrace* trace) = 0;
	virtual void enumerate_entities(const Ray& ray, bool triggers, IEntityEnumerator* enumerator) = 0;
	virtual void enumerate_entities(const Vector& mins, const Vector& maxs, IEntityEnumerator* enumerator) = 0;
	virtual ICollideable* get_collideable(IHandleEntity* entity) = 0;
	virtual int get_stat_by_index(int index, bool clear) = 0;
	virtual void get_brushes_in_aabb(const Vector& mins, const Vector& maxs, void* output, int mask=0xFFFFFFFF) = 0;
	virtual CPhysCollide* get_collideable_from_displacements_in_aabb(const Vector& mins, const Vector& maxs) = 0;
	virtual bool get_brush_info(int brush, void* planes_out, int* contents_out) = 0;
	virtual bool point_outside_world(const Vector& test) = 0;
	virtual int get_leaf_containing_point(const Vector& test) = 0;
};

class IBaseInterface {
public:
	virtual ~IBaseInterface();
};

class IServerTools : public IBaseInterface {
public:
	virtual IServerEntity* get_i_server_entity(IClientEntity* client_entity) = 0;
	virtual bool snap_player_to_position(const Vector& org, const QAngle& ang, IClientEntity* client_entity=nullptr) = 0;
	virtual bool get_player_position(Vector& org, QAngle& ang, IClientEntity* client_entity=nullptr) = 0;
	virtual bool set_player_fov(int fov, IClientEntity* client_entity=nullptr) = 0;
	virtual int get_player_fov(IClientEntity* client_entity=nullptr) = 0;
	virtual bool is_in_noclip_mode(IClientEntity* client_entity=nullptr) = 0;
	virtual BaseEntity* first_entity() = 0;
	virtual BaseEntity* next_entity(BaseEntity* entity) = 0;
	virtual BaseEntity* find_entity_by_hammer_id(int hammer_id) = 0;
	virtual bool get_key_value(BaseEntity* entity, const char* field, char* value, int max_len) = 0;
	virtual bool set_key_value(BaseEntity* entity, const char* field, const char* value) = 0;
	virtual bool set_key_value(BaseEntity* entity, const char* field, float value) = 0;
	virtual bool SetKeyValue(BaseEntity* entity, const char* field, const Vector& value) = 0;
	virtual BaseEntity* create_entity_by_name(const char* szClassName) = 0;
	virtual void dispatch_spawn(BaseEntity* entity) = 0;
	virtual void reload_particle_defintions(const char* file_name, const void* buf_data, int len) = 0;
	virtual void add_origin_to_vps(const Vector& org) = 0;
	virtual void move_engine_view_to(const Vector& Pos, const QAngle& angles) = 0;
	virtual bool destroy_entity_by_hammer_id(int hammer_id) = 0;
	virtual BaseEntity* get_base_entity_by_index(int index) = 0;
	virtual void remove_entity(BaseEntity* entity) = 0;
	virtual void remove_entity_immediate(BaseEntity* entity) = 0;
	virtual IEntityFactoryDictionary* get_entity_factory_dictionary() = 0;
	virtual void set_move_type(BaseEntity* entity, int value) = 0;
	virtual void set_move_type(BaseEntity* entity, int value, int move_collide) = 0;
	virtual void reset_sequence(BaseAnimating* entity, int nSequence) = 0;
	virtual void reset_sequence_info(BaseAnimating* entity) = 0;
	virtual void clear_multi_damage() = 0;
	virtual void apply_multi_damage() = 0;
	virtual void add_multi_damage(const CTakeDamageInfo& info, BaseEntity* entity) = 0;
	virtual void radius_damage(const CTakeDamageInfo& info, const Vector& src, float radius, int ignore_class, BaseEntity* ignore_entity) = 0;
	virtual ITempEntsSystem* get_temp_ents_system() = 0;
	virtual BaseTempEntity* get_temp_ent_list() = 0;
	virtual CGlobalEntityList* get_entity_list() = 0;
	virtual bool is_entity_ptr(void* test) = 0;
	virtual BaseEntity* find_entity_by_classname(BaseEntity* start, const char* name) = 0;
	virtual BaseEntity* find_entity_by_name(BaseEntity* start, const char* name, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr, IEntityFindFilter* filter=nullptr) = 0;
	virtual BaseEntity* find_entity_in_sphere(BaseEntity* start, const Vector& center, float radius) = 0;
	virtual BaseEntity* find_entity_by_target(BaseEntity* start, const char* name) = 0;
	virtual BaseEntity* find_entity_by_model(BaseEntity* start, const char* model_name) = 0;
	virtual BaseEntity* find_entity_by_name_nearest(const char* name, const Vector& src, float radius, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
	virtual BaseEntity* find_entity_by_name_within(BaseEntity* start, const char* name, const Vector& src, float radius, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
	virtual BaseEntity* find_entity_by_class_name_nearest(const char* name, const Vector& src, float radius) = 0;
	virtual BaseEntity* find_entity_by_class_name_within(BaseEntity* start, const char* name, const Vector& src, float radius) = 0;
	virtual BaseEntity* find_entity_by_class_name_within(BaseEntity* start, const char* name, const Vector& mins, const Vector& maxs) = 0;
	virtual BaseEntity* find_entity_generic(BaseEntity* start, const char* name, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
	virtual BaseEntity* find_entity_generic_within(BaseEntity* start, const char* name, const Vector& src, float radius, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
	virtual BaseEntity* find_entity_generic_nearest(const char* name, const Vector& src, float radius, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
	virtual BaseEntity* find_entity_nearest_facing(const Vector& origin, const Vector& facing, float threshold) = 0;
	virtual BaseEntity* find_entity_class_nearest_facing(const Vector& origin, const Vector& facing, float threshold, char* classname) = 0;
	virtual BaseEntity* find_entity_procedural(const char* name, BaseEntity* search=nullptr, BaseEntity* activator=nullptr, BaseEntity* caller=nullptr) = 0;
};

class IGameEventManager2 : public IBaseInterface {
public:
	virtual ~IGameEventManager2();
	virtual int load_events_from_file(const char* file_name) = 0;
	virtual void reset() = 0; 
	virtual bool add_listener(IGameEventListener2* listener, const char* name, bool is_server_side) = 0;
	virtual bool find_listener(IGameEventListener2* listener, const char* name) = 0;
	virtual void remove_listener(IGameEventListener2* listener) = 0;
	virtual IGameEvent* create_event(const char* name, bool force=false) = 0;
	virtual bool fire_event(IGameEvent* event, bool dont_broadcast=false) = 0;
	virtual bool fire_event_client_side(IGameEvent* event) = 0;
	virtual IGameEvent* duplicate_event(IGameEvent* event) = 0;
	virtual void free_event(IGameEvent* event) = 0;
	virtual bool serialize_event(IGameEvent* event, BfWrite* bf) = 0;
	virtual IGameEvent* unserialize_event(BfWrite* buf) = 0;
};

struct MoveData {
    bool first_run_of_functions : 1;
    bool is_game_code_moved_player : 1;
    BaseHandle player_handle;
    int impulse_command;
    QAngle view_angles;
    QAngle abs_view_angles;
    int buttons;
    int old_buttons;
    float forward_move;
    float side_move;
    float up_move;
    float max_speed;
    float max_client_speed;
    Vector velocity;
    QAngle angles;
    QAngle old_angles;
    float out_step_height;
    Vector out_wish_vel;
    Vector out_jump_vel;
    Vector constraint_center;
    float constraint_radius;
    float constraint_width;
    float constraint_speed_factor;
    Vector abs_origin;
};

class IGameMovement {
public:
    virtual ~IGameMovement();
	virtual void process_movement(BasePlayer* p, MoveData* md) = 0;		
	virtual void start_track_prediction_errors(BasePlayer* p) = 0;
	virtual void finish_track_prediction_errors(BasePlayer* p) = 0;
	virtual void print_diff(const char* fmt, ...) = 0;
	virtual Vector get_player_mins(bool is_ducked) const = 0;
	virtual Vector get_player_maxs(bool is_ducked) const = 0;
	virtual Vector get_player_view_offset(bool is_ducked) const = 0;
};

class GameMovement : public IGameMovement {
public:
    virtual void trace_player_bbox(const Vector& start, const Vector& end, unsigned int mask, int collision_group, GameTrace& pm);
    virtual void try_touch_ground(const Vector& start, const Vector& end, const Vector& mins, const Vector& maxs, unsigned int mask, int collision_group, GameTrace& pm);
    virtual unsigned int player_solid_mask(bool brush_only=true);
    virtual void player_move();
    virtual float calc_roll(const QAngle& angles, const Vector& velocity, float roll_angle, float roll_speed);
    virtual void decay_punch_angle();
    virtual void check_water_jump();
    virtual void water_move();
    virtual void air_accelerate(Vector& wish_dir, float wish_speed, float accel);
    virtual void air_move();
    virtual float get_air_speed_cap();
    virtual bool can_accelerate();
    virtual void accelerate(Vector& wish_dir, float wish_speed, float accel);
    virtual void walk_move();
    virtual void full_walk_move();
    virtual void on_jump(float impulse);
    virtual void on_land(float velocity);
    virtual void on_try_player_move_collision(GameTrace& tr);
    virtual Vector get_player_mins() const;
    virtual Vector get_player_maxs() const;
    virtual int get_check_interval(IntervalType type);
    virtual bool check_jump_button();
    virtual void full_toss_move();
    virtual void full_ladder_move();
    virtual int try_player_move(Vector* first_dest=nullptr, GameTrace* first_trace=nullptr);
    virtual bool ladder_move();
    virtual bool on_ladder(GameTrace& tr);
    virtual float ladder_distance() const;
    virtual unsigned int ladder_mask() const;
    virtual float climb_speed() const;
    virtual float ladder_lateral_multiplier() const;
    virtual int check_stuck();
    virtual bool check_water();
    virtual void categorize_position();
    virtual void check_parameters();
    virtual void reduce_timers();
    virtual void check_falling();
    virtual void player_rough_landing_effects(float vol);
    virtual void duck();
    virtual void handle_ducking_speed_crop();
    virtual void finish_unduck();
    virtual void finish_duck();
    virtual bool can_unduck();
    virtual BaseHandle test_player_position(const Vector& pos, int collision_group, GameTrace& tr);
    virtual void set_ground_entity(GameTrace* pm);
    virtual void step_move(Vector& dest, GameTrace& tr);
    virtual bool game_has_ladders() const;

    BasePlayer* player;
    MoveData* move_data;
    int old_water_level;
    float water_entry_time;
    int is_on_ladder;
    Vector forward;
    Vector right;
    Vector up;
};

struct GameTrace : public BaseTrace {
    float fraction_left_solid;
    CSurface surface;
    int hitgroup;
    short physics_bone;
    BaseEntity* ent;
    int hitbox;
};

class GlobalVarsBase {
public:
	float real_time;
	int frame_count;
	float absolute_frame_time;
	float current_time;
	float frame_time;
	int max_clients;
	int tick_count;
	float interval_per_tick;
	float interpolation_amount;
	int sim_ticks_this_frames;
	int network_protocol;
	SaveRestoreData* save_data;
	bool is_client;
	int time_stamp_networking_base;   
	int time_stamp_randomize_window;
};

class GlobalVars : public GlobalVarsBase {
public:
	const char* map_name;
	int map_version;
	const char* start_spot;
	MapLoadType map_load_type;
	bool is_map_load_failed;
	bool is_deathmatch;
	bool is_coop;
	bool is_team_play;
	int max_entities;
	int server_count;
};

class IConnectionlessPacketHandler {
public:
	virtual ~IConnectionlessPacketHandler();
	virtual bool process_connectionless_packet(netpacket_t* packet) = 0;
};

class IGameEvent {
public:
	virtual ~IGameEvent() = 0;
	virtual const char* get_name() const = 0;
	virtual bool is_reliable() const = 0;
	virtual bool is_local() const = 0;
	virtual bool is_empty(const char* key_name=nullptr) = 0;
	virtual bool get_bool(const char* key_name=nullptr, bool default_value=false) = 0;
	virtual int get_int( const char* key_name=nullptr, int default_value=0) = 0;
	virtual float get_float(const char* key_name=nullptr, float default_value=0.0f) = 0;
	virtual const char* get_string(const char* key_name=nullptr, const char* default_value="") = 0;
	virtual void set_bool(const char* key_name, bool value) = 0;
	virtual void set_int(const char* key_name, int value) = 0;
	virtual void set_float(const char* key_name, float value) = 0;
	virtual void set_string(const char* key_name, const char* value) = 0;
};

class IMemAlloc {
public:
	virtual void alloc(size_t size) = 0;
	virtual void* realloc(void* mem, size_t size) = 0;
	virtual void free(void* mem) = 0;
	virtual void* expand_no_longer_supported(void* mem, size_t size) = 0;
	virtual void* alloc(size_t size, const char* file_name, int line) = 0;
	virtual void* realloc(void* mem, size_t size, const char* file_name, int line) = 0;
	virtual void free(void* mem, const char* file_name, int line) = 0;
	virtual void* expand_no_longer_supported(void* mem, size_t size, const char* file_name, int line) = 0;
	virtual size_t get_size(void* mem) = 0;
	virtual void push_alloc_db_info( const char* file_name, int line) = 0;
	virtual void pop_alloc_db_info() = 0;
	virtual long crt_set_break_alloc(long new_break_alloc) = 0;
	virtual int crt_set_report_mode(int report_type, int report_mode) = 0;
	virtual int crt_is_valid_heap_pointer(const void* mem) = 0;
	virtual int crt_is_valid_pointer(const void* mem, unsigned int size, int access) = 0;
	virtual int crt_check_memory() = 0;
	virtual int crt_set_db_flag(int new_flag) = 0;
	virtual void CrtMemCheckpoint(CrtMemState *pState ) = 0;
	virtual void dump_stats() = 0;
	virtual void dump_stats_file_base(const char* file_base) = 0;
	virtual void* crt_set_report_file(int report_type, void* file) = 0;
	virtual void* crt_set_report_hook(void* new_hook) = 0;
	virtual int crt_db_report(int report_type, const char* file_name, int line, const char* m, const char* msg) = 0;
	virtual int heap_chk() = 0;
	virtual bool is_debug_heap() = 0;
	virtual void get_actual_db_info(const char*& file_name, int& line) = 0;
	virtual void register_allocation(const char* file_name, int line, int logical_size, int actual_size, unsigned time) = 0;
	virtual void RegisterDeallocation(const char* file_name, int line, int logical_size, int actual_size, unsigned time) = 0;
	virtual int get_version() = 0;
	virtual void compact_heap() = 0;
	virtual MemAllocFailHandler set_alloc_fail_handler(MemAllocFailHandler handler) = 0;
	virtual void dump_block_stats(void*) = 0;
	virtual size_t memory_alloc_failed() = 0;
	virtual unsigned int get_debug_info_size() = 0;
	virtual void save_debug_info(void* info) = 0;
	virtual void restore_debug_info(const void* info) = 0; 
	virtual void init_debug_info(void* info, const char* file_name, int line) = 0;
	virtual void get_global_memory_status(size_t* used_memory, size_t* free_memory) = 0;
};

class INetworkStringTableContainer {
public:
	virtual ~INetworkStringTableContainer() {};
	virtual INetworkStringTable* create_string_table(const char* table_name, int max_entries, int user_data_fixed_size=0, int user_data_network_bits=0) = 0;
	virtual void remove_all_tables() = 0;
	virtual INetworkStringTable* find_table(const char* table_name) const = 0;
	virtual INetworkStringTable* get_table(int table_id) const = 0;
	virtual int get_num_tables() const = 0;
	virtual INetworkStringTable* create_string_table_ex(const char* table_name, int max_entries, int user_data_fixed_size=0, int user_data_network_bits=0, bool is_file_names=false) = 0;
	virtual void set_allow_client_side_add_string(INetworkStringTable* table, bool is_allow_client_side_add_string) = 0;
};

class INetworkStringTable {
public:
	virtual ~INetworkStringTable() {};
	virtual const char* get_table_name() const = 0;
	virtual int get_table_id() const = 0;
	virtual int get_num_strings() const = 0;
	virtual int get_max_strings() const = 0;
	virtual int get_entry_bits() const = 0;
	virtual void set_tick(int tick) = 0;
	virtual bool change_since_tick(int tick) const = 0;
	virtual int add_string(bool is_server, const char* value, int length=-1, const void* user_data=0) = 0; 
	virtual const char* get_string(int num) = 0;
	virtual void set_string_user_data(int num, int length, const void* user_data) = 0;
	virtual const void* get_string_user_data(int num, int* length) = 0;
	virtual int find_string_index(const char* s) = 0;
	virtual void set_string_changed_callback(void* object, StringChanged change_func) = 0;
};

class IPredictionSystem {
public:
	virtual ~IPredictionSystem();

	IPredictionSystem* next;
	bool suppress_event;
	BaseEntity* suppress_host;
	int status_pushed;
};

class IPlayerInfoManager {
public:
	virtual IPlayerInfo* get_player_info(Edict* e) = 0;
	virtual GlobalVars* get_global_vars() = 0;
};

class PlayerMove {
public:
    virtual ~PlayerMove();
    virtual void setup_move(BasePlayer* p, UserCmd* cmd, IMoveHelper* mh, MoveData* move);
    virtual void finish_move(BasePlayer* p, UserCmd* cmd, MoveData* move);
    virtual void start_command(BasePlayer* p, UserCmd* cmd);
};

class Ray {
public:
	VectorAligned start;
	VectorAligned delta;
	VectorAligned start_offset;
	VectorAligned extents;
	bool is_ray;
	bool is_swept;

	void init(const Vector& start);
	void init(const Vector& start, const Vector& delta);
};

class IRecipientFilter {
public:
	virtual ~IRecipientFilter();
	virtual bool is_reliable() const = 0;
	virtual bool is_init_message() const = 0;
	virtual int get_recipient_count() const = 0;
	virtual int get_recipient_index(int slot) const = 0;
};

class SRecipientFilter : public IRecipientFilter {
public:
	SRecipientFilter(int i, bool reliable=false);
	virtual bool is_reliable() const;
	virtual bool is_init_message() const;
	virtual int get_recipient_count() const;
	virtual int get_recipient_index(int slot) const;

private:
	int recipient;
	bool reliable;
};

class MRecipientFilter : public IRecipientFilter {
public:
	MRecipientFilter();
	virtual bool is_reliable() const;
	virtual bool is_init_message() const;
	virtual int get_recipient_count() const;
	virtual int get_recipient_index(int slot) const;
	void add_recipient(int i);

	int recipients[64];
	int count;
	bool reliable;
	bool init_message;
};

class RecvProp {
public:
	const char* var_name;
	SendPropType type;
	int flags;
	int string_buffer_size;

private:
	bool is_inside_array;
	const void* extra_data;
	RecvProp* array_prop;
	ArrayLengthRecvProxy array_legth_proxy_fn;
	RecvVarProxy proxy_fn;
	DataTableRecvVarProxy data_table_proxy_fn;
	RecvTable* data_table;
	int offset;
	int element_stride;
	int elements;
	const char* arent_array_prop_name;
};

class SendProp {
public:
	virtual ~SendProp();

	RecvProp* matching_recv_prop;
	SendPropType type;
	int bits;
	float low_value;
	float high_value;
	SendProp* array_prop;
	ArrayLengthSendProxy array_length_proxy_fn;
	int elements;
	int element_stride;
	const char* exclude_dt_name;
	const char* parent_array_prop_name;
	const char* var_name;
	float high_low_mul;
	int flags;
	SendVarProxy proxy_fn;
	SendTableProxy data_table_proxy_fn;
	SendTable* data_table;
	int offset;
	const void* extra_data;
};

class SendTable {
public:
	SendProp* props;
	int props_count;
	const char* net_table_name;
	SendTablePrecalc* precalc;

protected: 	
	bool is_initialized;
	bool is_written;
	bool is_props_encoded_against_current_tick_count;
};

class ServerClass {
public:
	const char* network_name;
	SendTable* table;
	ServerClass* next;
	int class_id;
	int instance_base_line_index;
};

class IServerGameDLL {
public:
	virtual bool dll_init(CreateInterface engine_factory, CreateInterface physics_factory, CreateInterface file_system_factory, GlobalVars* global_vars) = 0;
	virtual bool replay_init(CreateInterface replay_factory) = 0;
	virtual bool game_init() = 0;
	virtual bool level_init(const char* map_name, const char* entities, const char* old_level, const char* landmark_name, bool load_game, bool background) = 0;
	virtual void server_activate(Edict* edict_list, int edict_count, int max_clients) = 0;
	virtual void game_frame(bool is_simulating) = 0;
	virtual void pre_client_update(bool is_simulating) = 0;
	virtual void level_shutdown() = 0;
	virtual void game_shutdown() = 0;
	virtual void dll_shutdown() = 0;
	virtual float get_tick_interval() const = 0;
	virtual ServerClass* get_all_server_classes() = 0;
	virtual const char* get_game_description() = 0;
	virtual void create_network_string_tables() = 0;
	virtual SaveRestoreData* save_init(int size) = 0;
	virtual void save_write_field(SaveRestoreData*, const char*, void*, datamap_t*, typedescription_t*, int) = 0;
	virtual void save_read_fields(SaveRestoreData*, const char*, void*, datamap_t *, typedescription_t *, int) = 0;
	virtual void save_global_state(SaveRestoreData*) = 0;
	virtual void restore_global_state(SaveRestoreData*) = 0;
	virtual void pre_save(SaveRestoreData*) = 0;
	virtual void save(SaveRestoreData*) = 0;
	virtual void get_save_comment(char* comment, int max_length, float minutes, float seconds, bool no_time=false);
	virtual void write_save_headers(SaveRestoreData*) = 0;
	virtual void read_restore_headers(SaveRestoreData*) = 0;
	virtual void restore(SaveRestoreData*, bool) = 0;
	virtual void is_restoring() = 0;
	virtual int create_entity_transition_list(SaveRestoreData*, int) = 0;
	virtual void build_adjacent_map_list() = 0;
	virtual bool get_user_message_info(int msg_type, char* name, int max_name_length, int& size) = 0;
	virtual CStandardSendProxies* get_standard_send_proxies() = 0;
	virtual void post_init() = 0;
	virtual void think(bool is_final_tick) = 0;
	virtual void pre_save_game_loaded(const char* save_name, bool is_currently_in_game) = 0;
	virtual bool should_hide_server() = 0;
	virtual void invalidate_mdl_cache() = 0;
	virtual void on_query_cvar_value_finished(int cookie, Edict* edict, int status, const char* cvar_name, const char* cvar_value) = 0;
	virtual void game_server_steam_api_activated() = 0;
	virtual void game_server_steam_api_shutdown() = 0;
	virtual void set_server_hibernation(bool hibernating) = 0;
	virtual IServerGCLobby* get_server_gc_lobby() = 0;
	virtual const char* get_server_browser_map_override() = 0;
	virtual const char* get_server_browser_game_data() = 0;
	virtual void get_status(void (*print) (const char *fmt, ...)) = 0;
	virtual void prepare_level_resources(char* map_name, size_t map_name_size, char* map_file, size_t map_file_size) = 0;
	virtual PrepareLevelResourcesResult async_prepare_level_resources(char* map_name, size_t map_name_size, char* map_file, size_t map_file_size, float* progress=nullptr) = 0;
	virtual CanProvideLevelResult can_provide_level(char* map_name, int max_map_name) = 0;
	virtual bool is_manual_map_change_okay(const char** reason) = 0;
};

class IServerGameClients {
public:
	virtual void get_player_limits(int& min_players, int& maxplayers, int& default_max_players) const = 0;
	virtual bool client_connect(Edict* e, const char* name, const char* address, char* reject, int max_reject_len) = 0;
	virtual void client_active(Edict* e, bool load_game) = 0;
	virtual void client_disconnect(Edict* e) = 0;
	virtual void client_put_in_server(Edict* e, char const* player_name) = 0;
	virtual void client_command(Edict* e, const Command& c) = 0;
	virtual void set_command_client(int index) = 0;
	virtual void client_settings_changed(Edict* e) = 0;
	virtual void client_setup_visibility(Edict* view_entity, Edict* client, unsigned char* pvs, int pvs_size) = 0;
	virtual float process_user_cmds(Edict* player, BfRead* buf, int num_cmds, int total_cmds, int dropped_packets, bool ignore, bool paused) = 0;
	virtual void post_client_messages_sent_depreciated() = 0;
	virtual PlayerState* get_player_state(Edict* e) = 0;
	virtual void client_ear_position(Edict* e, Vector* origin) = 0;
	virtual int get_replay_delay(Edict* e, int& entity) = 0;
	virtual void get_bug_report_info(char* buf, int buf_len) = 0;
	virtual void network_id_validates(const char* user_name, const char* network_id) = 0;
	virtual void client_command_key_values(Edict* entity, KeyValues* key_values) = 0;
	virtual void client_spawned(Edict* e) = 0;
};

class IServerGameEnts {
public:
	virtual ~IServerGameEnts();
	virtual void set_debug_edict_base(Edict*) = 0;
	virtual void mark_entities_as_touching(Edict* e1, Edict* e2) = 0;
	virtual void free_containing_entity(Edict*) = 0;
	virtual Edict* base_entity_to_edict(BaseEntity*) = 0;
	virtual BaseEntity* edict_to_base_entity(Edict*) = 0;
	virtual void check_transmit(CheckTransmitInfo* info, const unsigned short* edict_indices, int edicts = 0);
};

class IServerPluginCallbacks {
public:
	virtual bool load(CreateInterface ef, CreateInterface sf) = 0;
	virtual void unload() = 0;
	virtual void pause() = 0;
	virtual void unpause() = 0;
	virtual const char* get_plugin_description() = 0;
	virtual void level_init(const char* map_name) = 0;
	virtual void server_activate(Edict* edict_list, int edict_count, int max_clients) = 0;
	virtual void game_frame(bool is_simulating) = 0;
	virtual void level_shutdown() = 0;
	virtual void client_active(Edict* e) = 0;
	virtual void client_disconnect(Edict* e) = 0;
	virtual void client_put_in_server(Edict* e, const char* player_name) = 0;
	virtual void set_command_client(int index) = 0;
	virtual void client_settings_changed(Edict* e) = 0;
	virtual PluginResult client_connect(bool* is_allowed_to_connect, Edict* e, const char* name, const char* address, char* reject, int max_reject_len) = 0;
	virtual PluginResult client_command(Edict* e, const Command& c) = 0;
	virtual PluginResult network_id_validated(const char* user_name, const char* network_id) = 0;
	virtual void on_query_cvar_value_finished(int cookie, Edict* e, QueryCvarValueStatus status, const char* cvar_name, const char* cvar_value) = 0;
	virtual void on_edict_allocated(Edict* e) = 0;
	virtual void on_edict_freed(const Edict* e) = 0;
};

class IServer: public IConnectionlessPacketHandler {
public:
	virtual ~IServer();
	virtual int get_num_clients() const = 0;
	virtual int get_num_proxies() const = 0;
	virtual int get_num_fake_clients() const = 0;
	virtual int get_max_clients( void ) const = 0;
	virtual IClient* get_client(int index) = 0;
	virtual int get_client_count() const = 0;
	virtual int get_udp_port() const = 0;
	virtual float get_time() const = 0;
	virtual int get_tick() const = 0;
	virtual float get_tick_interval() const = 0;
	virtual const char* get_name() const = 0;
	virtual const char* get_map_name() const = 0;
	virtual int get_spawn_count() const = 0; 
	virtual int get_num_classes() const = 0;
	virtual int get_class_bits() const = 0;
	virtual void get_net_stats(float& avg_in, float& avg_out) = 0;
	virtual int get_num_players() = 0;
	virtual bool get_player_info(int index, PlayerInfo* info) = 0;
	virtual bool is_active() const = 0; 
	virtual bool is_loading() const = 0;
	virtual bool is_dedicated() const = 0;
	virtual bool is_paused() const = 0;
	virtual bool is_multiplayer() const = 0;
	virtual bool is_pausable() const = 0;
	virtual bool is_hltv() const = 0;
	virtual bool is_replay() const = 0;
	virtual const char* get_password() const = 0;
	virtual void set_paused(bool paused) = 0;
	virtual void set_password(const char* p) = 0;
	virtual void broadcast_message(INetMessage& msg, bool only_active=false, bool is_reliable=false) = 0;
	virtual void broadcast_message(INetMessage& msg, IRecipientFilter& filter) = 0;
	virtual void disconnect_client(IClient* client, const char* reason) = 0;
};

class BaseServer : public IServer {
public:
	virtual float get_cpu_usage();
	virtual void broadcast_printf(const char* fmt, ...);
	virtual void set_max_clients(int n);
	virtual void write_delta_entities(BaseClient* cl, ClientFrame* to, ClientFrame* from, BfWrite& bf);
	virtual void write_temp_entities(BaseClient* cl, FrameSnapshot* to, FrameSnapshot* from, BfWrite& bf, int max_ents);
	virtual void init(bool is_dedicated);
	virtual void clear();
	virtual void shutdown();
	virtual BaseClient* create_fake_client(const char* name);
	virtual void remove_client_from_game(BaseClient* client);
	virtual void send_client_messages(bool send_shapshots);
	virtual void fill_server_info(NetServerInfo& info);
	virtual void user_info_changed(int index);
	virtual void reject_connection(const netadr_t& adr, int client_challenge, const char* s);
	virtual bool check_ip_restrictions(const netadr_t& adr, int auth_protocol);
	virtual IClient* connect_client(netadr_t& adr, int protocol, int challenge, int auth_protocol, const char* name, const char* password, const char* cd_key, int cd_key_len);
	virtual BaseClient* get_free_client(netadr_t& adr);
	virtual BaseClient* create_new_client(int slot);
	virtual bool finish_certificate_check(netadr_t& adr, int auth_protocol, const char* raw_certificate);
	virtual int get_challenge_nr(netadr_t& adr);
	virtual int get_challenge_type(netadr_t& adr);
	virtual bool check_protocol(netadr_t& adr, int protocol);
	virtual bool check_challenge_nr(netadr_t& adr, int value);
	virtual bool check_challenge_type(BaseClient* client, int new_user_id, netadr_t& adr, int auth_protocool, const char* logon_cookie, int cookie);
	virtual bool check_password(netadr_t& adr, const char* password, const char* name);
	virtual bool check_ip_connection_reuse(netadr_t& adr);
	virtual void reply_challenge(netadr_t& adr);
	virtual void reply_server_challenge(netadr_t& adr);
	virtual void calculate_cpu_usage();
	virtual bool should_update_master_server();
	virtual void update_master_server_players();

	ServerState state;
	int socket;
	int tick_count;
	bool is_simulating_ticks;
	char map_name[64];
	char map_file_name[64];
	char sky_name[64];
	char password[32];
	unsigned char world_map_md5[16];
	NetworkStringTableContainer* string_tables;
	INetworkStringTable* instance_base_line_table;
	INetworkStringTable* light_style_table;
	INetworkStringTable* user_info_table;
	INetworkStringTable* server_startup_table;
	INetworkStringTable* downloadable_file_table;
	BfWrite signon;
	UtlMemory<unsigned char> signon_buffer;
	int server_classes;
	int server_class_bits;
	int user_id;
	int max_clients;
	int spawn_count;
	float tick_interval;
	UtlVector<GameClient*> clients;
	bool is_dedicated;
	unsigned int current_random_nonce;
	unsigned int last_random_nonce;
	float last_random_number_generation_time;
	float cpu_percent;
	float start_time;
	float last_cpu_check_time;
	bool restart_on_level_change;
	bool master_server_rules_dirty;
	double last_master_server_update_time;
	int num_connections;
	bool report_new_fake_clients;
	float paused_time_end;
};

struct SteamGameServerAPIContext {
	ISteamGameServer* game_server;
	ISteamUtils* utils;
	ISteamNetworking* networking;
	ISteamGameServerStats* game_server_stats;
	ISteamHTTP* http;
	ISteamInventory* inventory;
	ISteamUGC* ugc;
	ISteamApps* apps;
};

class SteamServer : public SteamGameServerAPIContext {
public:
    bool lan_only() const;

private:
    // callbacks
    char __pad[148];

public:
    ServerMode mode;
    ServerType type;
    bool master_server_updater_sharing_game_socket;
    bool log_on_finished;
    bool logged_on;
    bool log_on_result;
    bool has_active_players;
    SteamID steam_id_gs;
    SteamID steam_id_lan_only;
    bool active;
    bool wants_secure;
    bool initialized;
    bool wants_persistent_account_logon;
    unsigned int ip;
    unsigned short port;
    unsigned short query_port;
    const char* account_token;
    SteamID steam_id_group_for_blocking;
};

struct TakeDamageInfo {
    Vector damage_force;
    Vector damage_position;
    Vector reported_position;
    BaseHandle inflictor;
    BaseHandle attacker;
    BaseHandle weapon;
    float damage;
    float max_damage;
    float base_damage;
    int bits_damage_type;
    int damage_custom;
    int damage_stats;
    int ammo_type;
};

class ITempEntsSystem : public IPredictionSystem {
public:
	virtual void armor_ricochet(const IRecipientFilter& filter, float delay, const Vector* pos, const Vector* dir) = 0;
	virtual void beam_ent_point(const IRecipientFilter& filter, float delay, int nStartEntity, const Vector *start, int end_entity, const Vector* end, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, float end_width, int fade_length, float amplitude, int r, int g, int b, int a, int speed) = 0;
	virtual void beam_ents(const IRecipientFilter& filter, float delay, int start, int end, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, float end_width, int fade_length, float amplitude, int r, int g, int b, int a, int speed) = 0;
	virtual void beam_follow(const IRecipientFilter& filter, float delay, int ent_index, int model_index, int halo_index, float life, float width, float end_width, float fade_length, float r, float g, float b, float a) = 0;
	virtual void beam_points(const IRecipientFilter& filter, float delay, const Vector* start, const Vector* end, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, float end_width, int fade_length, float amplitude, int r, int g, int b, int a, int speed) = 0;
	virtual void beam_laser(const IRecipientFilter& filter, float delay, int start, int end, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, float end_width, int fade_length, float amplitude, int r, int g, int b, int a, int speed) = 0;
	virtual void beam_ring(const IRecipientFilter& filter, float delay, int start, int end, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, int spread, float amplitude, int r, int g, int b, int a, int speed, int flags = 0) = 0;
	virtual void beam_ring_point(const IRecipientFilter& filter, float delay, const Vector& center, float start_radius, float end_radius, int model_index, int halo_index, int start_frame, int frame_rate, float life, float width, int spread, float amplitude, int r, int g, int b, int a, int speed, int flags = 0) = 0;
	virtual void beam_spline(const IRecipientFilter& filter, float delay, int num_points, Vector* points) = 0;
	virtual void blood_stream(const IRecipientFilter& filter, float delay, const Vector* src, const Vector* dir, int r, int g, int b, int a, int amount) = 0;
	virtual void blood_sprite(const IRecipientFilter& filter, float delay, const Vector* src, const Vector *dir, int r, int g, int b, int a, int size) = 0;
	virtual void break_model(const IRecipientFilter& filter, float delay, const Vector& pos, const QAngle &angle, const Vector& size, const Vector& vel, int model_index, int randomization, int count, float time, int flags) = 0;
	virtual void bsp_decal(const IRecipientFilter& filter, float delay, const Vector* pos, int entity, int index) = 0;
	virtual void project_decal(const IRecipientFilter& filter, float delay, const Vector* pos, const QAngle* angles, float distance, int index) = 0;
	virtual void bubbles(const IRecipientFilter& filter, float delay, const Vector* mins, const Vector* maxs, float height, int model_index, int count, float speed) = 0;
	virtual void bubble_trail(const IRecipientFilter& filter, float delay, const Vector* mins, const Vector* maxs, float height, int model_index, int count, float speed) = 0;
	virtual void decal(const IRecipientFilter& filter, float delay, const Vector* pos, const Vector* start, int entity, int hitbox, int index) = 0;
	virtual void dynamic_light(const IRecipientFilter& filter, float delay, const Vector* src, int r, int g, int b, int exponent, float radius, float time, float decay) = 0;
	virtual void expolosion(const IRecipientFilter& filter, float delay, const Vector* pos, int model_index, float scale, int frame_rate, int flags, int radius, int magnitude, const Vector* normal=nullptr, unsigned char material_type='C') = 0;
	virtual void shatter_surface(const IRecipientFilter& filter, float delay, const Vector* pos, const QAngle* angle, const Vector* force, const Vector* force_pos, float width, float height, float shardsize, ShatterSurface_t surface_type, int front_r, int front_g, int front_b, int back_r, int back_g, int back_b) = 0;
	virtual void glow_sprite(const IRecipientFilter& filter, float delay, const Vector* pos, int model_index, float life, float size, int brightness) = 0;
	virtual void footprint_decal(const IRecipientFilter& filter, float delay, const Vector *origin, const Vector* right, int entity, int index, unsigned char material_type) = 0;
	virtual void fizz(const IRecipientFilter& filter, float delay, const BaseEntity* entity, int model_index, int density, int current) = 0;
	virtual void kill_player_attachments(const IRecipientFilter& filter, float delay, int player) = 0;
	virtual void large_funnel(const IRecipientFilter& filter, float delay, const Vector* pos, int model_index, int reversed) = 0;
	virtual void metal_sparks(const IRecipientFilter& filter, float delay, const Vector* pos, const Vector* dir) = 0;
	virtual void energy_splash(const IRecipientFilter& filter, float delay, const Vector* pos, const Vector* dir, bool explosive) = 0;
	virtual void player_decal(const IRecipientFilter& filter, float delay, const Vector* pos, int player, int entity) = 0;
	virtual void show_line(const IRecipientFilter& filter, float delay, const Vector* start, const Vector* end) = 0;
	virtual void smoke(const IRecipientFilter& filter, float delay, const Vector* pos, int model_index, float scale, int frame_rate) = 0;
	virtual void sparks(const IRecipientFilter& filter, float delay, const Vector* pos, int magnitude, int trail_length, const Vector* dir) = 0;
	virtual void sprite(const IRecipientFilter& filter, float delay, const Vector* pos, int model_index, float size, int brightness) = 0;
	virtual void sprite_spray(const IRecipientFilter& filter, float delay, const Vector* pos, const Vector* dir, int model_index, int speed, float noise, int count) = 0;
	virtual void world_decal(const IRecipientFilter& filter, float delay, const Vector* pos, int index) = 0;
	virtual void muzzle_flash(const IRecipientFilter& filter, float delay, const Vector& start, const QAngle& angles, float scale, int type) = 0;
	virtual void dust(const IRecipientFilter& filter, float delay, const Vector& pos, const Vector& dir, float size, float speed) = 0;
	virtual void gauss_explosion(const IRecipientFilter& filter, float delay, const Vector& pos, const Vector& dir, int type) = 0;
	virtual void dispatch_effect(const IRecipientFilter& filter, float delay, const Vector& pos, const char* name, const EffectData& data) = 0;
	virtual void physics_prop(const IRecipientFilter& filter, float delay, int model_index, int skin, const Vector& pos, const QAngle& angles, const Vector& vel, int flags, int effects) = 0;
	virtual void trigger_temp_entity(KeyValues* key_values) = 0;
	virtual void client_projectile(const IRecipientFilter& filter, float delay, const Vector* origin, const Vector* velocity, int model_index, int life_time, BaseEntity* owner) = 0;
};

class ITraceFilter {
public:
	virtual bool should_hit_entity(IHandleEntity* e, int mask) = 0;
	virtual TraceType get_trace_type() const = 0;
};

class TraceFilterWorldOnly : public ITraceFilter {
public:
	virtual bool should_hit_entity(IHandleEntity* e, int mask);
	virtual TraceType get_trace_type() const;
};

class SendProxyRecipients {
public:
	BitVec<absolute_player_limit> bits;
};

class PackedEntity {
public:
	ServerClass* server_class;
	ClientClass* client_class;
	int entity_index;
	int reference_count;

private:
	UtlVector<SendProxyRecipients> recipients;
	void* data;
	int bits;
	IChangeFrameList* change_frame_list;
	unsigned int snapshot_creation_tick : 31;
	unsigned int should_check_creation_tick : 1;
};

class EntityInfo {
public:
	virtual ~EntityInfo();

	bool as_delta;
	ClientFrame* from;
	ClientFrame* to;
	UpdateType update_type;
	int old_entity;
	int new_entity;
	int header_base;
	int header_count;
};

class EntityWriteInfo : public EntityInfo {
public:
	BfWrite* buf;
	int client_entity;
	PackedEntity* old_pack;
	PackedEntity* new_pack;
	BitVec<max_edicts> deletion_flags;
	FrameSnapshot* from_snapshot;
	FrameSnapshot* to_snapshot;
	FrameSnapshot* base_line;
	BaseServer* server;
	int full_props;
	bool cull_props;
};

class ICommandLine {
public:
	virtual void create_cmd_line(const char* command_line) = 0;
	virtual void create_cmd_line(int argc, char** argv) = 0;
	virtual const char* get_cmd_line() const = 0;
	virtual	const char* check_parm(const char* s, const char** value=nullptr) const = 0;
	virtual void remove_parm(const char* s) = 0;
	virtual void append_parm(const char* s, const char* values) = 0;
	virtual const char* parm_value(const char* s, const char* default_val=nullptr) const = 0;
	virtual int parm_value(const char* s, int default_val) const = 0;
	virtual float parm_value(const char* s, float default_val) const = 0;
	virtual int parm_count() const = 0;
	virtual int find_parm(const char* s) const = 0;
	virtual const char* get_parm(int index) const = 0;
	virtual void set_parm(int index, char const* new_parm) =0;
};

class BaseTempEntity {
public:
	virtual ServerClass* get_server_class();
	virtual int you_forgot_to_implement_or_declare_server_class();
	virtual ~BaseTempEntity();
	virtual void test(const Vector&, const QAngle&);
	virtual void create(IRecipientFilter&, float delay=0.0f);
	virtual void precache();

	const char* name;
	BaseTempEntity* next;
};

class TEFireBullets : public BaseTempEntity {
public:
	virtual ~TEFireBullets();

	int player;
	Vector origin;
	QAngle angles;
	int weapon_id;
	int mode;
	int seed;
	float inaccuracy;
	float spread;
};

class UserMessage {
	using UserMsgHook = void (*)(BfRead&);
public:
	int size;
	const char* name;
	UtlVector<UserMsgHook> client_hooks;
};

class UserMessages {
public:
	UtlDict<UserMessage*, int> user_messages;
};

struct HudTextParms {
	float x;
	float y;
	int effect;
	Color32 color1;
	Color32 color2;
	float fade_in_time;
	float fade_out_time;
	float hold_time;
	float fx_time;
	int channel;
};

// functions
inline
bool TraceFilterWorldOnly::should_hit_entity(IHandleEntity* e, int mask) {
    return true;
}

inline
TraceType TraceFilterWorldOnly::get_trace_type() const {
    return TraceType::WORLD_ONLY;
}

inline
bool SteamServer::lan_only() const {
    return this->mode == ServerMode::NO_AUTHENTICATION;
}

inline
IRecipientFilter::~IRecipientFilter() {

}

inline
SRecipientFilter::SRecipientFilter(int i, bool reliable) {
	this->recipient = i + 1;
	this->reliable = reliable;
}

inline
bool SRecipientFilter::is_reliable() const {
    return this->reliable;
}

inline
bool SRecipientFilter::is_init_message() const {
    return false;
}

inline
int SRecipientFilter::get_recipient_count() const {
    return 1;
}

inline
int SRecipientFilter::get_recipient_index(int slot) const {
    return recipient;
}

inline
MRecipientFilter::MRecipientFilter() {
	this->count = 0;
	this->init_message = false;
	this->reliable = false;
}

inline
void MRecipientFilter::add_recipient(int i) {
	this->recipients[this->count++] = i + 1;
}

inline
bool MRecipientFilter::is_reliable() const {
	return this->reliable;
}

inline
bool MRecipientFilter::is_init_message() const {
	return this->init_message;
}

inline
int MRecipientFilter::get_recipient_count() const {
	return count;
}

inline
int MRecipientFilter::get_recipient_index(int slot) const {
	return recipients[slot];
}

inline
void Ray::init(const Vector& start) {
    this->is_ray = true;
    this->is_swept = false;
    this->extents.zero();
    this->start_offset.zero();
    this->start = start;
}

inline
void Ray::init(const Vector& start, const Vector& delta) {
    this->is_ray = true;
    this->is_swept = true;
    this->extents.zero();
    this->start_offset.zero();
    this->start = start;
    this->delta = delta;
}

inline
float ConVar::get_float() const {
	return parent->float_value;
}

inline
int ConVar::get_int() const {
	return parent->int_value;
}

inline
const char* Command::operator[](int index) const {
	return this->args[index];
}

inline
int Command::count() const {
	return this->args_count;
}

inline
ConCommandBase::~ConCommandBase() {

}

inline
bool ConCommandBase::is_command() const {
	return true;
}

inline
bool ConCommandBase::is_flag_set(int f) const {
    return this->flags & f;
}

inline
void ConCommandBase::add_flags(int f) {
    this->flags |= f;
}

inline
const char* ConCommandBase::get_name() const {
	return this->name;
}

inline
const char* ConCommandBase::get_help_text() const {
	return this->help_string;
}

inline
bool ConCommandBase::is_registered() const {
	return this->registered;
}

inline
int ConCommandBase::get_dll_identifier() const {
	return 0;
}

inline
void ConCommandBase::create_base(const char* n, const char* hs, int f) {
	
}

inline
void ConCommandBase::init() {

}

inline
ConCommand::~ConCommand() {

}

inline
void ConCommand::dispatch(const Command& c) {
    if (this->command_callback)
		this->command_callback(c);
}

inline
int ConCommand::suggest_auto_complete(const char* partial, UtlVector<UtlString>& commands) {
    return 0;
}

inline
bool ConCommand::can_auto_complete() {
    return this->has_completion_callback;
}

inline
IGameEventListener2::~IGameEventListener2() {

}

inline
Vector::Vector() {
	
}

inline
Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

inline
void Vector::zero() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

inline
float& Vector::operator[](int i) {
	return reinterpret_cast<float*>(this)[i];
}

inline
float Vector::operator[](int i) const {
	return reinterpret_cast<const float*>(this)[i];
}

inline
Vector Vector::operator+(const Vector& v) const {
	Vector r;
	r.x = x + v.x;
	r.y = y + v.y;
	r.z = z + v.z;
	return r;
}

inline
Vector Vector::operator-(const Vector& v) const {
	Vector r;
	r.x = x - v.x;
	r.y = y - v.y;
	r.z = z - v.z;
	return r;
}

inline
Vector Vector::operator*(const Vector& v) const {
	Vector r;
	r.x = x * v.x;
	r.y = y * v.y;
	r.z = z * v.z;
	return r;
}

inline
Vector Vector::operator/(const Vector& v) const {
	Vector r;
	r.x = x / v.x;
	r.y = y / v.y;
	r.z = z / v.z;
	return r;
}

inline
bool Vector::operator==(const Vector& v) const {
	return (v.x == x) && (v.y == y) && (v.z == z);
}

inline
bool Vector::operator!=(const Vector& v) const {
	return (v.x != x) || (v.y != y) || (v.z != z);
}

inline
Vector Vector::operator*(const float v) const {
	Vector r;
	r.x = x * v;
	r.y = y * v;
	r.z = z * v;
	return r;
}

inline
Vector Vector::min(const Vector& v) const {
	Vector r;
	r.x = this->x < v.x ? this->x : v.x;
	r.y = this->y < v.y ? this->y : v.y;
	r.z = this->z < v.z ? this->z : v.z;
	return r;
}

inline
Vector Vector::max(const Vector& v) const {
	Vector r;
	r.x = this->x > v.x ? this->x : v.x;
	r.y = this->y > v.y ? this->y : v.y;
	r.z = this->z > v.z ? this->z : v.z;
	return r;
}

inline
float Vector::normalize() {
	float radius = std::sqrt(x * x + y * y + z * z);
	float iradius = 1.0f / (radius + __FLT_EPSILON__);
	
	x *= iradius;
	y *= iradius;
	z *= iradius;

	return radius;
}

inline
float Vector::dist_to(const Vector& v) const {
	return this->operator-(v).length();
}

inline
float Vector::dot(const Vector& v) const {
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

inline
float Vector::length_2d() const {
	return std::sqrt(this->x * this->x + this->y * this->y);
}

inline
float Vector::length() const {
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

inline
float Vector::length_sqr() const {
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

inline
Vector& Vector::operator+=(const Vector& v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;	
	return *this;
}

inline
Vector& Vector::operator-=(const Vector& v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

inline
Vector& Vector::operator*=(const Vector& v) {
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	return *this;
}

inline
Vector& Vector::operator/=(const Vector& v) {
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return *this;
}

inline
Vector Vector::operator-() {
	Vector r;
	r.x = -this->x;
	r.y = -this->y;
	r.z = -this->z;
	return r;
}

inline
bool BaseHandle::operator==(const BaseHandle& other) const {
	return index == other.index;
}

inline
float get_degrees_from_radians(float x) {
	return x * (180.0f / m_pi_f);
}

inline
float get_radians_from_degrees(float x) {
	return x * (m_pi_f / 180.0f);
}

inline
void get_sin_cos_from_radians(float rad, float* sin, float* cos) {
	double __cosr, __sinr;
	__asm ("fsincos" : "=t" (__cosr), "=u" (__sinr) : "0" (rad));
  	*sin = __sinr;
  	*cos = __cosr;
}

inline
void QAngle::get_angle_vectors(Vector* forward) const {
    float sp, sy, cp, cy;
    get_sin_cos_from_radians(get_radians_from_degrees(this->x), &sp, &cp);
    get_sin_cos_from_radians(get_radians_from_degrees(this->y), &sy, &cy);

    forward->x = cp * cy;
    forward->y = cp * sy;
    forward->z = -sp;
}

inline
void QAngle::get_angle_vectors(Vector* forward, Vector* right, Vector* up) const {
    float sr, sp, sy, cr, cp, cy;
    get_sin_cos_from_radians(get_radians_from_degrees(this->x), &sp, &cp);
    get_sin_cos_from_radians(get_radians_from_degrees(this->y), &sy, &cy);
    get_sin_cos_from_radians(get_radians_from_degrees(this->z), &sr, &cr);

    if (forward) {
        forward->x = cp * cy;
        forward->y = cp * sy;
        forward->z = -sp;
    }

    if (right) {
        right->x = -1 * sr * sp * cy + -1 * cr * -sy;
        right->y = -1 * sr * sp * sy + -1 * cr * cy;
        right->z = -1 * sr * cp;
    }

    if (up) {
        up->x = cr * sp * cy + -sr * -sy;
        up->y = cr * sp * sy + -sr * cy;
        up->z = cr * cp;
    }
}

inline
bool QAngle::operator!=(const QAngle& v) const  {
    return (v.x != this->x) || (v.y != this->y) || (v.z != this->z);
}

inline
bool BaseEdict::is_free() const {
	return (state_flags & EdictFlags::FREE) != 0;
}

inline
BitWriteMasksInit::BitWriteMasksInit() {
    for (unsigned int start_bit = 0; start_bit < 32; ++start_bit) {
        for (unsigned int bits_left = 0; bits_left < 33; ++bits_left) {
            unsigned int end_bit = start_bit + bits_left;

            bit_write_masks[start_bit][bits_left] = 1 << ((start_bit & (32 - 1)) - 1);

            if (end_bit < 32)
                bit_write_masks[start_bit][bits_left] |= ~(1 << ((end_bit & (32 - 1)) - 1));
        }
	}
	
	for (unsigned int mask_bit = 0; mask_bit < 32; ++mask_bit)
		extra_masks[mask_bit] = (1 << (mask_bit & (32 - 1))) - 1;

	extra_masks[32] = ~0ul;

    for (unsigned int little_bit = 0; little_bit < 32; ++little_bit)
        little_bits[little_bit] = 1u << little_bit;
}

inline
int bit_byte(int bits) {
	return (bits + 7) >> 3;
}

inline
BfWrite::BfWrite(void* data, int bytes, int bits) {
    this->assert_on_overflow = true;
    this->debug_name = nullptr;
    this->start_writing(data, bytes, 0, bits);
}

inline
void BfWrite::start_writing(void* data, int bytes, int start_bit, int bits) {
    bytes &= ~3;

    this->data = static_cast<unsigned long*>(data);
    this->data_bytes = bytes;

    if (bits == -1)
        this->data_bits = bytes << 3;
    else
        this->data_bits = bits;

    this->cur_bit = start_bit;
    this->overflow = false;
}

inline
void BfWrite::write_u_bit_long(unsigned int cur_data, int num_bits) __restrict {
    int cur_bit_masked = this->cur_bit & 31;
    int dword = this->cur_bit >> 5;

    this->cur_bit += num_bits;

    unsigned long* __restrict out = &this->data[dword];

    cur_data = (cur_data << cur_bit_masked) | (cur_data >> (32 - cur_bit_masked));

    unsigned int temp = 1 << (num_bits - 1);
    unsigned int mask1 = (temp * 2 - 1) << cur_bit_masked;
    unsigned int mask2 = (temp - 1) >> (31 - cur_bit_masked);

    int i = mask2 & 1;
    unsigned long dword1 = out[0];
    unsigned long dword2 = out[i];

    dword1 ^= mask1 & (cur_data ^ dword1);
    dword2 ^= mask2 & (cur_data ^ dword2);

    out[i] = dword2;
    out[0] = dword1;
}

inline
void BfWrite::write_s_bit_long(int data, int num_bits) {
    int preserve_bits = 0x7fffffff >> (32 - num_bits);
    int sign_extension = (data >> 31) & ~preserve_bits;

    data &= preserve_bits;
    data |= sign_extension;

    this->write_u_bit_long(data, num_bits);
}

inline
void BfWrite::write_bits(const void* in_data, int bits) {
    const unsigned char* out = reinterpret_cast<const unsigned char*>(in_data);
    int bits_left = bits;

    while ((reinterpret_cast<unsigned long>(out) & 3) != 0 && bits_left >= 8) {
        this->write_u_bit_long(*out, 8);
        ++out;
        bits_left -= 8;
    }

    if (bits_left >= 32 && (this->cur_bit & 7) == 0) {
        int num_bytes = bits_left >> 3;
        int num_bits = num_bytes << 3;

        std::memcpy(reinterpret_cast<char*>(this->data) + (this->cur_bit >> 3), out, num_bytes);
        out += num_bytes;
        bits_left -= num_bits;
        this->cur_bit += num_bits;
    }

    if (bits_left >= 32) {
        unsigned long bits_right = this->cur_bit & 31;
        unsigned long bits_left = 32 - bits_right;
        unsigned long bit_mask_left = bit_write_masks[bits_right][32];
        unsigned long bit_mask_right = bit_write_masks[0][bits_right];

        unsigned long* data = &this->data[this->cur_bit >> 5];

        while (bits_left >= 32) {
            unsigned long cur_data = *reinterpret_cast<const unsigned long*>(out);
            out += sizeof(unsigned long);

            *data &= bit_mask_left;
            *data |= (cur_data << bits_right);

            ++data;

            if (bits_left < 32) {
                cur_data >>= bits_left;
                *data &= bit_mask_right;
                *data |= cur_data;
            }

            bits_left -= 32;
            this->cur_bit += 32;
        }
    }

    while (bits_left >= 8) {
        this->write_u_bit_long(*out, 8);
        ++out;
        bits_left -= 8;
    }

    if (bits_left)
        this->write_u_bit_long(*out, bits_left);
}

inline
void BfWrite::write_char(int value) {
    this->write_s_bit_long(value, sizeof(char) << 3);
}

inline
void BfWrite::write_byte(int value) {
    this->write_u_bit_long(value, sizeof(unsigned char) << 3);
}

inline
void BfWrite::write_short(int value) {
    this->write_s_bit_long(value, sizeof(short) << 3);
}

inline
void BfWrite::write_word(int value) {
    this->write_u_bit_long(value, sizeof(unsigned short) << 3);
}

inline
void BfWrite::write_long(long value) {
    this->write_s_bit_long(value, sizeof(long) << 3);
}

inline
void BfWrite::write_long_long(long long value) {
    unsigned int* longs = reinterpret_cast<unsigned int*>(&value);

    const short endian_index = 0x100;
    const unsigned char* idx = reinterpret_cast<const unsigned char*>(&endian_index);

    this->write_u_bit_long(longs[*idx++], sizeof(long) << 3);
    this->write_u_bit_long(longs[*idx], sizeof(long) << 3);
}

inline
void BfWrite::write_float(float value) {
    this->write_bits(&value, sizeof(float) << 3);
}

inline
void BfWrite::write_bytes(const void* buf, int bytes) {
    this->write_bits(buf, bytes << 3);
}

inline
void BfWrite::write_string(const char* str) {
    do {
        this->write_char(*str);
        ++str;
    } while (*(str - 1) != 0);
}

inline
void BfWrite::write_one_bit(int value) {
    if (value)
        this->data[this->cur_bit >> 5] |= little_bits[this->cur_bit & 31];
    else
        this->data[this->cur_bit >> 5] &= ~little_bits[this->cur_bit & 31];
}

template <int NUM_BITS> inline
unsigned* FixedBitVecBase<NUM_BITS>::base() {
    return this->ints;
}

template <int NUM_BITS> inline
const unsigned* FixedBitVecBase<NUM_BITS>::base() const {
    return this->ints;
}

template <class BASE_OPS> inline
unsigned BitVecT<BASE_OPS>::get(unsigned bit_num) const {
    const auto p = this->base() + (bit_num >> 5);
    return *p & (1 << (bit_num & (32 - 1)));
}

template <class BASE_OPS> inline
void BitVecT<BASE_OPS>::set(int bit_num) {
    const auto p = this->base() + (bit_num >> 5);
    *p |= (1 << (bit_num & (32 - 1)));
}

template <class BASE_OPS> inline
void BitVecT<BASE_OPS>::clear(int bit_num) {
    auto p = this->base() + (bit_num >> 5);
    *p &= ~(1 << (bit_num & (32 - 1)));
}

inline constexpr
unsigned long long steamid64_from_account_id(unsigned id) {
	return 76561197960265728 + id;
}

inline constexpr
unsigned account_id_from_steamid64(unsigned long long id) {
	return id - 76561197960265728;
}

}
