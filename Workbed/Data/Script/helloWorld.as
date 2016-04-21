float timer = 1.f;
int updateIntervals = 0;
class Position
{
	void SetPosition(float aX, float aY)
	{
		myX = aX;
		myY = aY;
	}
	
	void AddPosition(float aX, float aY)
	{
		myX += aX;
		myY += aY;
	}
	
	float myX;
	float myY;
}

Position pos = Position();

void main()
{
	pos.SetPosition(5, 6);
	Print("Hello World!");
}

void Update(float aDeltaTime)
{
	UpdateTimer(aDeltaTime);
}

void UpdateTimer(float aDeltaTime)
{
	timer -= aDeltaTime;
	pos.AddPosition(0.1f, 0);
	if(timer <= 0.0f)
	{
		timer = 1.0f;
		updateIntervals += 1;
		
		Print("Pos");
		Print(pos.myX);
		Print(pos.myY);
	}
}