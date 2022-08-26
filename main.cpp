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
	int x, y;//store pos of the ball
	int originalX, originalY;//initial positions
	EnumerationOfDirections direction;
public:
	Ball(int posX, int posY)//constructor(set initial X, and Y, also current X, Y)
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
		direction = ( EnumerationOfDirections ) ((rand() % 6) + 1);//cast the int into enum; rand num from 1 ~ 6
	}

	void Move()//ball doesn't go straight left and right
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
		default:
			break;
		}
	}
	friend ostream& operator<<(ostream& o, Ball c)
	{
		o << "Ball [" << c.x << "," << c.y << "]"<< "["<< c.direction << "]";
		return o;
	}
};

int main()
{
	Ball c(0, 0);
	cout << c << endl;

	c.RandomDirection();
	cout << c << endl;

	c.Move();
	cout << c << endl;

	c.RandomDirection();
	c.Move();
	cout << c << endl;

	c.RandomDirection();
	c.Move();
	cout << c << endl;


	return 0;
}