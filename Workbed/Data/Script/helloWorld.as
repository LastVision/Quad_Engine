float timer = 1.f;
int updateIntervals = 0;
void main()
{
	Print("Hello World!");
}

void Update(float aDeltaTime)
{
	UpdateTimer(aDeltaTime);
}

void UpdateTimer(float aDeltaTime)
{
	timer -= aDeltaTime;
	if(timer <= 0.0f)
	{
		timer = 1.0f;
		updateIntervals += 1;
		Print("Update times");
		Print(updateIntervals);
	}
}