#ifndef NEO_WEAPON_ZR68_S_H
#define NEO_WEAPON_ZR68_S_H
#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"
#include "npcevent.h"
#include "in_buttons.h"

#ifdef CLIENT_DLL
#include "c_neo_player.h"
#else
#include "neo_player.h"
#endif

#include "weapon_neobasecombatweapon.h"

#ifdef CLIENT_DLL
#define CWeaponZR68S C_WeaponZR68S
#endif

class CWeaponZR68S : public CNEOBaseCombatWeapon
{
	DECLARE_CLASS(CWeaponZR68S, CNEOBaseCombatWeapon);
public:
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

#ifdef GAME_DLL
	DECLARE_ACTTABLE();
#endif

	CWeaponZR68S();

	virtual void	ItemPostFrame(void);
	virtual void	ItemPreFrame(void);
	virtual void	ItemBusyFrame(void);
	virtual void	PrimaryAttack(void) OVERRIDE { if (!ShootingIsPrevented()) { BaseClass::PrimaryAttack(); } }
	virtual void	SecondaryAttack(void) OVERRIDE { if (!ShootingIsPrevented()) { BaseClass::SecondaryAttack(); } }
	virtual void	AddViewKick(void);

	void	DryFire(void);

	virtual void Spawn(void);
	virtual bool Deploy(void);

	virtual int GetNeoWepBits(void) const { return NEO_WEP_ZR68_S; }
	virtual int GetNeoWepXPCost(const int neoClass) const { return 0; }

	virtual float GetSpeedScale(void) const { return 155.0 / 170.0; }

	void	UpdatePenaltyTime(void);

	virtual Activity	GetPrimaryAttackActivity(void);

	virtual float GetFireRate(void) OVERRIDE { return 0.1f; }
protected:
	virtual float GetFastestDryRefireTime() const OVERRIDE { return 0.2f; }
	virtual float GetAccuracyPenalty() const OVERRIDE { return 0.2f; }
	virtual float GetMaxAccuracyPenalty() const OVERRIDE { return 1.5f; }

private:
	CWeaponZR68S(const CWeaponZR68S &other);
};

#endif // NEO_WEAPON_ZR68_S_H