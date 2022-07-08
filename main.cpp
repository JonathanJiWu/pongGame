#include <iostream>
using namespace std;

enum EnumerationOfDirections
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};

class Ball
{
private:
	int x, y;
	int originalX, originalY;
	EnumerationOfDirections direction;
public:
	Ball(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
		direction = STOP;
	}
	void  ResetBall()
	{
		x = originalX;
		y = originalY;
		direction = STOP;
	}
	void SetDirection(EnumerationOfDirections dir)
	{
		direction = dir;
	}
	inline int GetX() { return x; }
	inline int GetY() { return y; }
	inline int GetDir() { return direction; }

	void RandomDirection()
	{
		direction = ( EnumerationOfDirections ) ((rand() % 6) + 1);
	}

	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--;
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT:
			x++;
			y++;
			break;
		}
	}
	
};

int main()
{
	
	return 0;
}