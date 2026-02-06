/**
* Scary Bullets perk.
* Copyright (C) 2023 Filip Tomaszewski
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define SCARYBULLETS_PARTICLE "ghost_glow"

#define MinDamage Int[0]
#define Duration Float[0]
#define Particle EntSlot_1

DEFINE_CALL_APPLY(ScaryBullets)

public void ScaryBullets_Init(const Perk perk)
{
	Events.OnPlayerAttacked(perk, ScaryBullets_OnPlayerAttacked);
}

void ScaryBullets_ApplyPerk(int client, const Perk perk)
{
	Cache[client].MinDamage = perk.GetPrefCell("min_damage", 5);
	Cache[client].Duration = perk.GetPrefFloat("duration", 3.0);
	Cache[client].SetEnt(Particle, CreateParticle(client, SCARYBULLETS_PARTICLE));
}

public void ScaryBullets_OnPlayerAttacked(int client, const int victim, const int damage, const int health)
{
	if (client == victim)
		return;

	if (health <= 0)
		return;

	if (damage < Cache[client].MinDamage)
		return;

	if (!TF2_IsPlayerInCondition(victim, TFCond_Dazed))
		TF2_StunPlayer(victim, Cache[client].Duration, _, TF_STUNFLAGS_GHOSTSCARE, client);
}

#undef SCARYBULLETS_PARTICLE

#undef MinDamage
#undef Duration
#undef Particle
