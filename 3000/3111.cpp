#include <iostream>

#include <string>

#include <deque>

#include <algorithm>

using namespace std;

 

const int MAX = 30000;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        string target, s;

        cin >> target >> s;

 

        deque<char> left, right;

        int low = 0, high = s.length() - 1;

 

        while(low <= high)

        {

                 //2번

                 while (low <= high)

                 {

                         bool flag = false;

                         left.push_back(s[low++]);

 

                         if (left.size() >= target.size())

                         {

                                 flag = true;

                                 for(int i=0; i<target.size(); i++)

                                          if (target[i] != left[left.size() - target.size() + i])

                                          {

                                                  flag = false;

                                                  break;

                                          }

                         }

                         if (flag)

                         {

                                 for (int i = 0; i < target.size(); i++)

                                          left.pop_back();

                                 break;

                         }

                 }

                 //4번

                 while (low <= high)

                 {

                         right.push_front(s[high--]);

                         bool flag = false;

                         if (right.size() >= target.size())

                         {

                                 flag = true;

                                 for(int i=0; i<target.size(); i++)

                                          if (target[i] != right[i])

                                          {

                                                  flag = false;

                                                  break;

                                          }

                         }

                         if (flag)

                         {

                                 for (int i = 0; i < target.size(); i++)

                                          right.pop_front();

                                 break;

                         }

                 }

        }

 

        string result;

        for (int i = 0; i < left.size(); i++)

                 result += left[i];

        for (int i = 0; i < right.size(); i++)

                 result += right[i];

 

        //두 덱을 합쳤을 때 나올 수 있는 target 지워주기

        while (result.find(target) < MAX)

                 result.erase(result.find(target), target.size());

       

        cout << result << "\n";

        return 0;

}

