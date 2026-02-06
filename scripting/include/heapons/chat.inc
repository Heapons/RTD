stock void GetPlayerName(int client, char[] name, int maxlen)
{
	int r, g, b, a, color;
	GetEntityRenderColor(client, r, g, b, a);
	color = (r << 16) | (g << 8) | b;
	if (color != 0xFFFFFF)
	{
		Format(name, maxlen, "\x07%06X%N\x01", color, client);
	}
	else
	{
		Format(name, maxlen, "\x03%N\x01", client);
	}
}