#include <tf2_stocks>

// https://developer.valvesoftware.com/wiki/Team_Fortress_2/Scripting/Script_Functions/Constants#TF_DEATH
#define TF_DEATH_DOMINATION          (1<<0)
#define TF_DEATH_ASSISTER_DOMINATION (1<<1)
#define TF_DEATH_REVENGE             (1<<2)
#define TF_DEATH_ASSISTER_REVENGE    (1<<3)
#define TF_DEATH_FIRST_BLOOD         (1<<4)
#define TF_DEATH_FEIGN_DEATH         (1<<5)
#define TF_DEATH_INTERRUPTED         (1<<6)
#define TF_DEATH_GIBBED              (1<<7)
#define TF_DEATH_PURGATORY           (1<<8)
#define TF_DEATH_MINIBOSS            (1<<9)
#define TF_DEATH_AUSTRALIUM          (1<<10)

// https://developer.valvesoftware.com/wiki/Team_Fortress_2/Scripting/Script_Functions/Constants#FHideHUD
#define HIDEHUD_WEAPONSELECTION      (1<<0)
#define HIDEHUD_FLASHLIGHT           (1<<1)
#define HIDEHUD_ALL                  (1<<2)
#define HIDEHUD_HEALTH               (1<<3)
#define HIDEHUD_PLAYERDEAD           (1<<4)
#define HIDEHUD_BITCOUNT             18
#define HIDEHUD_NEEDSUIT             (1<<5)
#define HIDEHUD_MISCSTATUS           (1<<6)
#define HIDEHUD_CHAT                 (1<<7)
#define HIDEHUD_CROSSHAIR            (1<<8)
#define HIDEHUD_VEHICLE_CROSSHAIR    (1<<9)
#define HIDEHUD_INVEHICLE            (1<<10)
#define HIDEHUD_BONUS_PROGRESS       (1<<11)
#define HIDEHUD_BUILDING_STATUS      (1<<12)
#define HIDEHUD_CLOAK_AND_FEIGN      (1<<13)
#define HIDEHUD_PIPES_AND_CHARGE     (1<<14)
#define HIDEHUD_METAL                (1<<15)
#define HIDEHUD_TARGET_ID            (1<<16)
#define HIDEHUD_MATCH_STATUS         (1<<17)

// https://developer.valvesoftware.com/wiki/Team_Fortress_2/Scripting/Script_Functions/Constants#ETFDmgCustom
enum TFDamageCustom
{
    None,
    Headshot,
    Backstab,
    Burning,
    Wrench_Fix,
    Minigun,
    Suicide,
    Tauntatk_Hadouken,
    Burning_Flare,
    Tauntatk_High_Noon,
    Tauntatk_Grand_Slam,
    Penetrate_My_Team,
    Penetrate_All_Players,
    Tauntatk_Fencing,
    Penetrate_Nonburning_Teammate,
    Tauntatk_Arrow_Stab,
    Telefrag,
    Burning_Arrow,
    Flyingburn,
    Pumpkin_Bomb,
    Decapitation,
    Tauntatk_Grenade,
    Baseball,
    Charge_Impact,
    Tauntatk_Barbarian_Swing,
    Air_Sticky_Burst,
    Defensive_Sticky,
    Pickaxe,
    Rocket_Directhit,
    Tauntatk_Uberslice,
    Player_Sentry,
    Standard_Sticky,
    Shotgun_Revenge_Crit,
    Tauntatk_Engineer_Guitar_Smash,
    Bleeding,
    Gold_Wrench,
    Carried_Building,
    Combo_Punch,
    Tauntatk_Engineer_Arm_Kill,
    Fish_Kill,
    Trigger_Hurt,
    Decapitation_Boss,
    Stickbomb_Explosion,
    Aegis_Round,
    Flare_Explosion,
    Boots_Stomp,
    Plasma,
    Plasma_Charged,
    Plasma_Gib,
    Practice_Sticky,
    Eyeball_Rocket,
    Headshot_Decapitation,
    Tauntatk_Armageddon,
    Flare_Pellet,
    Cleaver,
    Cleaver_Crit,
    Sapper_Recorder_Death,
    Merasmus_Player_Bomb,
    Merasmus_Grenade,
    Merasmus_Zap,
    Merasmus_Decapitation,
    Cannonball_Push,
    Tauntatk_Allclass_Guitar_Riff,
    Throwable,
    Throwable_Kill,
    Spell_Teleport,
    Spell_Skeleton,
    Spell_Mirv,
    Spell_Meteor,
    Spell_Lightning,
    Spell_Fireball,
    Spell_Monoculus,
    Spell_Blastjump,
    Spell_Bats,
    Spell_Tiny,
    Kart,
    Giant_Hammer,
    Rune_Reflect,
    Dragons_Fury_Ignite,
    Dragons_Fury_Bonus_Burning,
    Slap_Kill,
    Croc,
    Tauntatk_Gasblast,
    Axtinguisher_Boosted,
    Krampus_Melee,
    Krampus_Ranged,
    Tauntatk_Trickshot,
    End
};

// https://developer.valvesoftware.com/wiki/Team_Fortress_2/Scripting/Script_Functions/Constants#LIFE
enum LifeState
{
    Alive,
    Dying,
    Dead,
    Respawnable,
    Discardbody
};

const TFClassType TFClass_Civilian = view_as<TFClassType>(10);
const TFClassType TFClass_Mercenary = view_as<TFClassType>(10);

const TFTeam TFTeam_Green = view_as<TFTeam>(4);
const TFTeam TFTeam_Yellow = view_as<TFTeam>(5);

methodmap TFEntity
{
    public TFEntity(int entity)
    {
        return view_as<TFEntity>(entity);
    }

    property int index
    {
        public get()
        {
            return view_as<int>(this);
        }
    }

    property int userid
    {
        public get()
        {
            return GetClientUserId(this.index);
        }
    }

    property int health
    {
        public get()
        {
            return GetEntProp(this.index, Prop_Send, "m_iHealth");
        }
        public set(int value)
        {
            SetEntProp(this.index, Prop_Send, "m_iHealth", value);
        }
    }

    property int max_health
    {
        public get()
        {
            return GetEntProp(this.index, Prop_Send, "m_iMaxHealth");
        }
        public set(int value)
        {
            SetEntProp(this.index, Prop_Send, "m_iMaxHealth", value);
        }
    }

    property int currency
    {
        public get()
        {
            return GetEntProp(this.index, Prop_Send, "m_nCurrency");
        }
        public set(int value)
        {
            SetEntProp(this.index, Prop_Send, "m_nCurrency", value < 0 ? 0 : value > 30000 ? 30000 : value);
        }
    }

    property float scale
    {
        public get()
        {
            return GetEntPropFloat(this.index, Prop_Send, "m_flModelScale");
        }
        public set(float value)
        {
            SetEntPropFloat(this.index, Prop_Send, "m_flModelScale", value);
        }
    }

    property TFTeam team
    {
        public get()
        {
            return TF2_GetClientTeam(this.index);
        }
        public set(TFTeam team)
        {
            int lifeState = GetEntProp(this.index, Prop_Send, "m_lifeState");
            SetEntProp(this.index, Prop_Send, "m_lifeState", view_as<LifeState>(Dead));
            TF2_ChangeClientTeam(this.index, team);
            SetEntProp(this.index, Prop_Send, "m_lifeState", lifeState);
        }
    }

    property TFClassType class
    {
        public get()
        {
            return view_as<TFClassType>(GetEntProp(this.index, Prop_Send, "m_iClass"));
        }
        public set(TFClassType classType)
        {
            SetEntProp(this.index, Prop_Send, "m_iClass", view_as<int>(classType));
		    SetEntProp(this.index, Prop_Send, "m_iDesiredPlayerClass", view_as<int>(classType));
        }
    }

    property int render_color
    {
        public get()
        {
            int red, green, blue, alpha, color;
            GetEntityRenderColor(this.index, red, green, blue, alpha);
            color = (red << 16) | (green << 8) | blue;
            return color;
        }
        public set(int color)
        {
            int red = (color >> 16) & 0xFF;
            int green = (color >> 8) & 0xFF;
            int blue = color & 0xFF;

            SetEntityRenderColor(this.index, red, green, blue, 255);
            int wearable = -1;
            while ((wearable = FindEntityByClassname(wearable, "tf_wearable")) != -1)
            {
                if (GetEntPropEnt(wearable, Prop_Send, "m_hOwnerEntity") == this.index)
                {
                    SetEntProp(wearable, Prop_Send, "m_nRenderMode", GetEntProp(this.index, Prop_Send, "m_nRenderMode"));
                    SetEntityRenderColor(wearable, red, green, blue, 255);
                }
            }
        }
    }

    property bool boss_health_bar
    {
        public get()
        {
            return view_as<bool>(GetEntProp(this.index, Prop_Send, "m_bUseBossHealthBar"));
        }
        public set(bool state)
        {
            SetEntProp(this.index, Prop_Send, "m_bUseBossHealthBar", state);
        }
    }

    property bool glow_enabled
    {
        public get()
        {
            return view_as<bool>(GetEntProp(this.index, Prop_Send, "m_bGlowEnabled"));
        }
        public set(bool state)
        {
            SetEntProp(this.index, Prop_Send, "m_bGlowEnabled", state);
        }
    }

    public char[] GetName()
    {
        static char buffer[MAX_NAME_LENGTH + 16];
        int color = this.render_color;
        if (color != 0xFFFFFF)
        {
            Format(buffer, sizeof(buffer), "\x07%06X%N\x01", color, this.index);
        }
        else
        {
            Format(buffer, sizeof(buffer), "\x03%N\x01", this.index);
        }
        return buffer;
    }

    public bool IsArenaSpectator()
    {
        return view_as<bool>(GetEntProp(this.index, Prop_Send, "m_bArenaSpectator"));
    }

    public bool AcceptInput(const char[] input, any ...)
    {
        return AcceptEntityInput(this.index, input);
    }

    public bool SetCustomModel(const char[] model, any ...)
    {
        if (!PrecacheModel(model)) PrecacheModel(model);
        SetVariantString(model);
        return this.AcceptInput("SetCustomModelWithClassAnimations");
    }

    public bool RunScriptCode(const char[] script)
    {
        int len = strlen(script) + 2;
        char[] buffer = new char[len];
        strcopy(buffer, len, script);

        GameInfo game;
        if (game.appid == 3545060) // Team Fortress 2 Classified
        {
            StrCat(buffer, len, ";");
        }

        SetVariantString(buffer);
        return this.AcceptInput("RunScriptCode");
    }

    public bool ForceRespawn()
    {
        SetEntProp(this.index, Prop_Send, "m_iDesiredPlayerClass", view_as<int>(this.class));
        SetVariantString("self.ForceRespawn()");
        return this.AcceptInput("RunScriptCode");
    }

    public bool AddAttribute(const char[] name, float value = 1.0, float duration = -1.0)
    {
        int len = strlen(name) + 64;
        char[] buffer = new char[len];

        Format(buffer, len, "self.Add%sAttribute(\"%s\", %f, %f)", 0 < this.index <= MaxClients ? "Custom" : "", name, value, duration);
        return this.RunScriptCode(buffer);
    }

    public bool RemoveAttribute(const char[] name)
    {
        int len = strlen(name) + 64;
        char[] buffer = new char[len];

        Format(buffer, len, "self.Remove%sAttribute(\"%s\")", 0 < this.index <= MaxClients ? "Custom" : "", name);
        return this.RunScriptCode(buffer);
    }

    public float GetAttribute(const char[] name, float default_value = 1.0)
    {
        int len = strlen(name) + 128;
        char[] buffer = new char[len];
        Format(buffer, len, "NetProps.SetPropFloat(self, \"m_flPoseParameter\", self.Get%sAttribute(\"%s\", %f))", 0 < this.index <= MaxClients ? "Custom" : "", name, default_value);

        this.RunScriptCode(buffer);
        return GetEntPropFloat(this.index, Prop_Data, "m_flPoseParameter");
    }

    public bool DropFlag(bool silent = false)
    {
        char buffer[32];
        Format(buffer, sizeof(buffer), "self.DropFlag(%b)", silent);
        return this.RunScriptCode(buffer);
    }

    public bool SetForcedTauntCam(bool toggle = true)
    {
        SetVariantBool(toggle);
        return this.AcceptInput("SetForcedTauntCam");
    }

    public bool AddHudHideFlags(int flags)
    {
        char buffer[48];
        Format(buffer, sizeof(buffer), "self.AddHudHideFlags(%d)", flags);
        return this.RunScriptCode(buffer);
    }

    public bool CancelTaunt()
    {
        char buffer[24];
        Format(buffer, sizeof(buffer), "self.CancelTaunt()");
        return this.RunScriptCode(buffer);
    }

    public bool AddCond(int condition, float duration = -1.0)
    {
        char buffer[64];
        Format(buffer, sizeof(buffer), "self.AddCondEx(%d, %f, null)", condition, duration);
        return this.RunScriptCode(buffer);
    }

    public bool RemoveCond(int condition)
    {
        char buffer[48];
        Format(buffer, sizeof(buffer), "self.RemoveCond(%d)", condition);
        return this.RunScriptCode(buffer);
    }
}
