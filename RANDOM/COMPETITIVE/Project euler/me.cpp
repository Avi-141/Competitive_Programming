#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

char low(char c)
{
	return((char)((c >= 'A' && c <= 'Z') ? c + 32 : c));
}

void stackReverseInput(stack<int> &s, int n, string a)
{
	if(n == 0)
	{
		return;
	}
	s.push((int)(low(a[n - 1]) - 'a'));
	stackReverseInput(s, n - 1, a);
}

int carChoice(vector<int> car_pos, int destination, vector<int> road_dynamic, int* mov_to)
{
	int curr_min = 0x7FFFFFFF, index = -1;
	for(int i = 0;i < car_pos.size();i++)
	{
		int destination_index = -1;
		for(int j = car_pos[i] + 1;j < road_dynamic.size();j++)
		{
			if(road_dynamic[j] == destination)
			{
				destination_index = j;
				break;
			}
		}
		if(destination_index != -1)
		{
			if(car_pos[i] - i < curr_min)
			{
				*mov_to = destination_index;
				index = i;
				curr_min = car_pos[i] - i;
			}
		}
	}
	return(index);
}

void Put(vector<int> a)
{
	for(int i = 0;i < a.size();i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void PutStack(stack<int> a)
{
	while(!a.empty())
	{
		int val = a.top();
		a.pop();
		cout << val << " ";
	}
	cout << endl;
}

int main()
{
	vector<vector<int> > ans;
	int road_len = 0, stack_size = 0, hand_capacity = 0, cars_num = 0;
	cin >> road_len >> stack_size >> hand_capacity >> cars_num;
	vector<int> car_pos;
	for(int i = 0;i < cars_num;i++)
	{
		car_pos.push_back(i);
	}
	// cout << "Cars: ";
	// Put(car_pos);
	vector<int> road;
	string road_s;
	cin >> road_s;
	for(int i = 0;i < road_len;i++)
	{
		road.push_back((int)(low(road_s[i]) - 'a'));
	}
	// cout << "Road: ";
	// Put(road);
	vector<int> road_dynamic(road.begin(), road.end());
	for(int i = 0;i < cars_num;i++)
	{
		road_dynamic[i] = -1;
	}
	// cout << "Dynamic road: ";
	// Put(road_dynamic);
	stack<int> keys;
	string keys_s;
	cin >> keys_s;
	stackReverseInput(keys, stack_size, keys_s);
	vector<int> hand;
	// cout << "Keys: ";
	// PutStack(keys);
	while(hand_capacity > 0 && !keys.empty())
	{
		int pop_val = keys.top();
		keys.pop();
		hand.push_back(pop_val);
		hand_capacity--;
	}
	// cout << "Hand: ";
	// Put(hand);
	// cout << "\n" << "Tried to enter main loop with values: ";
	// printf("Road size = %d\nStack size = %d\nHand capacity = %d\nHand size = %d\n", road_len, stack_size, hand_capacity, hand.size());
	while(hand.size() > 0)
	{
		// printf("here 0\n");
		int best_key_index = -1;
		int best_car = -1;
		int mov_to = -1;
		int best_displacement = 0x80000000;
		for(int i = 0;i < hand.size();i++)
		{
			// printf("here%d\n", i);
			int temp_car = carChoice(car_pos, hand[i], road_dynamic, &mov_to);
			if(temp_car != -1)
			{
				if(mov_to - car_pos[temp_car] > best_displacement)
				{
					best_car = temp_car;
					best_key_index = i;
					best_displacement = mov_to - car_pos[temp_car];
				}
			}
		}
		// printf("here 1\n");
		if(best_car == -1)
		{
			break;
		}
		vector<int> pair_wise;
		pair_wise.push_back(best_car);
		pair_wise.push_back(hand[best_key_index] + 'a');
		ans.push_back(pair_wise);
		road_dynamic[car_pos[best_car]] = road[car_pos[best_car]];
		road_dynamic[mov_to] = -1;
		car_pos[best_car] = mov_to;
		hand.erase(hand.begin() + best_key_index);
		hand_capacity++;
		// printf("here 2 with Hand capacity = %d\n", hand_capacity);
		while(hand_capacity > 0)
		{
			if(!keys.empty())
			{
				int pop_val = keys.top();
				keys.pop();
				hand.push_back(pop_val);
				hand_capacity--;
			}
			else
			{
				break;
			}
			// printf("Hand capacity at end = %d\n", hand_capacity);
		}
	}
	// cout << "\n" << "Exited main loop with values: ";
	// printf("Road size = %d\nStack size = %d\nHand capacity = %d\nHand size = %d\nAns size = %d\n", road_len, stack_size, hand_capacity, hand.size(), ans.size());
	for(int i = 0;i < ans.size();i++)
	{
		cout << ans[i][0] << " " << (char)ans[i][1] << endl;
	}
}