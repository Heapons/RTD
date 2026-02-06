methodmap GameInfo
{
    /**
     * Gets the app id from gameinfo.txt.
     *
     * @return Game appid.
     */
    property int appid
    {
        public get()
        {
            KeyValues kv = new KeyValues("GameInfo");
            kv.ImportFromFile("gameinfo.txt")
            kv.JumpToKey("FileSystem")
            int appid = kv.GetNum("SteamAppId");
            delete kv;
            return appid;
        }
    }

    /**
     * Whether the mod is using the modern TF2 SDK.
     * 
     * @return True if using TF2 SDK, false otherwise.
     */
    property bool tf2_mod
    {
        public get()
        {
            EngineVersion engine = GetEngineVersion();
            char gameDir[64];
            GetGameFolderName(gameDir, sizeof(gameDir));
	        if (!StrEqual(gameDir, "tf"))
	        {
	        	if (engine == Engine_SDK2013 && FileExists("resource/tf.ttf"))
	        	{
	        		engine = Engine_TF2;
	        	}
	        	else
	        	{
	        		KeyValues kv = new KeyValues("GameInfo");
	        		if (kv.ImportFromFile("gameinfo.txt") && kv.GetNum("DependsOnAppID") == 440)
	        		{
	        			engine = Engine_TF2;
	        		}
	        		delete kv;
	        	}
	        }
            return engine == Engine_TF2;
        }
    }

    /**
     * Gets the game name from gameinfo.txt.
     * 
     * @param buffer Buffer to store game name.
     * @param maxlen Maximum length of buffer.
     */
    public void GetKey(const char[] key, char[] buffer, int maxlen)
    {
        KeyValues kv = new KeyValues("GameInfo");
        if (!kv.ImportFromFile("gameinfo.txt"))
        {
            delete kv;
            return;
        }
        kv.GetString(key, buffer, maxlen);
        delete kv;
    }

    /**
     * Gets the game name from gameinfo.txt.
     * 
     * @param buffer Buffer to store game name.
     * @param maxlen Maximum length of buffer.
     */
    public void GetGameName(char[] buffer, int maxlen)
    {
        this.GetKey("game", buffer, maxlen);
    }

    /**
     * Gets the developer name from gameinfo.txt.
     * 
     * @param buffer Buffer to store developer name.
     * @param maxlen Maximum length of buffer.
     */
    public void GetDeveloperName(char[] buffer, int maxlen)
    {
        this.GetKey("developer", buffer, maxlen);
    }

    /**
     * Gets the developer URL from gameinfo.txt.
     * 
     * @param buffer Buffer to store developer URL.
     * @param maxlen Maximum length of buffer.
     */
    public void GetDeveloperURL(char[] buffer, int maxlen)
    {
        this.GetKey("developer_url", buffer, maxlen);
    }
}