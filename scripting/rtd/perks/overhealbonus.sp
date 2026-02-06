/**
* Overheal Bonus perk.
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

#define Scale Float[0]

DEFINE_CALL_APPLY_REMOVE(OverhealBonus)

public void OverhealBonus_Init(const Perk perk)
{
	Events.OnResupply(perk, OverhealBonus_Apply);
	Events.OnEntitySpawned(perk, OverhealBonus_OnDroppedWeaponSpawn, Classname_DroppedWeapon, Retriever_AccountId);
}

void OverhealBonus_ApplyPerk(int client, const Perk perk)
{
	Cache[client].Scale = perk.GetPrefFloat("scale", 5.0);

	OverhealBonus_Apply(client);
}

public void OverhealBonus_RemovePerk(int client, const RTDRemoveReason eRemoveReason)
{
	int iMediGun = GetPlayerWeaponSlot(client, 1);
	if (iMediGun > MaxClients && IsValidEntity(iMediGun))
	{
		TFEntity weapon = TFEntity(iMediGun);
		weapon.RemoveAttribute(Attribs.OverhealBonus);
	}
}

void OverhealBonus_Apply(int client)
{
	int iMediGun = GetPlayerWeaponSlot(client, 1);
	if (iMediGun <= MaxClients || !IsValidEntity(iMediGun))
		return;
	TFEntity weapon = TFEntity(iMediGun);
	weapon.AddAttribute(Attribs.OverhealBonus, Cache[client].Scale);
}

public void OverhealBonus_OnDroppedWeaponSpawn(int client, const int iEnt)
{
	AcceptEntityInput(iEnt, "Kill");
}

#undef Scale
