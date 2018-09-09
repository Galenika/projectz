#pragma once
#include "SDK.h"
#include "singleton.h"

class CAnnouncer : public Singleton<CAnnouncer>, public IGameEventListener2
{
public:
	CAnnouncer()
	{
		streak_timeout = 4.0f;
		memset(current_sound, 0, sizeof(current_sound));
	}

	void FireGameEvent(IGameEvent *pEvent) override;

	void Initialize();
	void Run();

private:
	void play_sound(const char *soundFile);
	char current_sound[50];

protected: 
	float last_kill_time;
	int   kill_counter;
	int   streak_counter;
	float streak_timeout;
};

enum class tf_customkills : int
{
	HEADSHOT = 1,
	BACKSTAB,
	BURNING,
	WRENCH_FIX,
	MINIGUN,
	SUICIDE,
	TAUNT_HADOUKEN,
	BURNING_FLARE,
	TAUNT_HIGH_NOON,
	TAUNT_GRAND_SLAM,
	PENETRATE_MY_TEAM,
	PENETRATE_ALL_PLAYERS,
	TAUNT_FENCING,
	PENETRATE_HEADSHOT,
	TAUNT_ARROW_STAB,
	TELEFRAG,
	BURNING_ARROW,
	FLYINGBURN,
	PUMPKIN_BOMB,
	DECAPITATION,
	TAUNT_GRENADE,
	BASEBALL,
	CHARGE_IMPACT,
	TAUNT_BARBARIAN_SWING,
	AIR_STICKY_BURST,
	DEFENSIVE_STICKY,
	PICKAXE,
	ROCKET_DIRECTHIT,
	TAUNT_UBERSLICE,
	PLAYER_SENTRY,
	STANDARD_STICKY,
	SHOTGUN_REVENGE_CRIT,
	TAUNT_ENGINEER_SMASH,
	BLEEDING,
	GOLD_WRENCH,
	CARRIED_BUILDING,
	COMBO_PUNCH,
	TAUNT_ENGINEER_ARM,
	FISH_KILL,
	TRIGGER_HURT,
	DECAPITATION_BOSS,
	STICKBOMB_EXPLOSION,
	AEGIS_ROUND,
	FLARE_EXPLOSION,
	BOOTS_STOMP,
	PLASMA,
	PLASMA_CHARGED,
	PLASMA_GIB,
	PRACTICE_STICKY,
	EYEBALL_ROCKET,
	HEADSHOT_DECAPITATION,
	TAUNT_ARMAGEDDON,
	FLARE_PELLET,
	CLEAVER,
	CLEAVER_CRIT,
	SAPPER_RECORDER_DEATH,
	MERASMUS_PLAYER_BOMB,
	MERASMUS_GRENADE,
	MERASMUS_ZAP,
	MERASMUS_DECAPITATION,
	CANNONBALL_PUSH,
};