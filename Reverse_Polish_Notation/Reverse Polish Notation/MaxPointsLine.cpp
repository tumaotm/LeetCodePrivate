#include "iostream"
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <stack>
#include <map>

using namespace std;
//using namespace string;
//using namespace map;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/*class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int maxNum = 0;
		map<float,int> num;
		int duplicate;

		if ((points.size()!=0) && (points.size()!=1))
		{
			for (int i=0;i<points.size();i++)
			{
				num.clear();
				num[INT_MIN]=0;
				int duplicate = 1;
				for (int j=0; j<points.size();j++)
				{
					if (i==j)
					{
						continue;
					}
					if (points[i].x == points[j].x && points[i].y == points[j].y)
					{
						duplicate+=1;
						continue;
					}
					float slope = points[i].x == points[j].x ? INT_MIN : (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
					num[slope]++;
				}
			

			for (auto iter:num)
			{
				if (iter.second + duplicate > maxNum)
				{
					maxNum = iter.second + duplicate;
				}
			}
		
			}
		}

		else{
			maxNum= points.size()==0? 0:1;
		}


		return maxNum;
	}
};*/  ///Accepted

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};


int maxPoints(vector<Point> &points) {
	int maxNum = 0;
	map<float,int> num;
	int duplicate;

	if ((points.size()!=0) && (points.size()!=1))
	{
		for (int i=0;i<points.size();i++)
		{
			num.clear();
			num[INT_MIN]=0;
			int duplicate = 1;
			for (int j=0; j<points.size();j++)
			{
				if (i==j)
				{
					continue;
				}
				if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate+=1;
					continue;
				}
				float slope = points[i].x == points[j].x ? INT_MIN : (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
				num[slope]++;
			}


		//for (auto iter:num)
			for (std::vector::iterator iter=num.begin();iter!=end();iter++)
			{
				if (iter.second + duplicate > maxNum)
				{
					maxNum = iter.second + duplicate;
				}
			}

		}
	}

	else{
		maxNum= points.size()==0? 0:1;
	}


	return maxNum;
}



int main()
{
//	* Definition for a point.

//vector<Point> points(2) = [(0,0),(0,0)];



Point temp;

vector<Point> points;

for (int i=0;i<4;++i)
{
	cin>>temp.x>>temp.y;
	points.push_back(temp);
	cout<<points[i].x<<","<<points[i].y<<endl;
}





int results = maxPoints(points); 


cout<<results<<endl;


	return 0;
};


