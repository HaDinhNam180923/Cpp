#include <bits/stdc++.h>
using namespace std;

// kiem tra xem co so dien thoai k hop le hay k (co 10 cs) 
bool checkPhone(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    return s.length() == 10;
}

// tinh thoi gian goi - (xet tung ki tu - ki tu '0' va bo qua :) 
int countTime(string stTime, string eTime)
{
    int startTime = 3600 * ((stTime[0] - '0') * 10 + stTime[1] - '0') + 60 * ((stTime[3] - '0') * 10 + stTime[4] - '0') + ((stTime[6] - '0') * 10 + stTime[7] - '0');
    int endTime = 3600 * ((eTime[0] - '0') * 10 + eTime[1] - '0') + 60 * ((eTime[3] - '0') * 10 + eTime[4] - '0') + ((eTime[6] - '0') * 10 + eTime[7] - '0');
    return endTime - startTime;
}

map<string, int> numberCalls, timeCalls;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0, incorrectPhone = 0;
    
    // first block 
    do
    {
        cin >> type;
            if (type == "#")
            continue;
        ++totalCalls; // moi dong la 1 cuoc goi 
        string fNum, tNum, date, stTime, eTime;
        cin >> fNum >> tNum >> date >> stTime >> eTime;
        if (!checkPhone(fNum) || !checkPhone(tNum))
            ++incorrectPhone;
        numberCalls[fNum]++; // key la sdt goi den co kieu dl string, value la so luot goi di tu sdt do  
        timeCalls[fNum] += countTime(stTime, eTime); // tinh thoi gian  
    } while (type != "#");

	// second block 
    do
    {
        cin >> type;
        if (type == "#")
            continue;
        if (type == "?check_phone_number")
        {
            cout << !incorrectPhone << endl;
        }
        else if (type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << numberCalls[phone] << endl;
        }
        else if (type == "?number_total_calls")
            cout << totalCalls << endl;
        else if (type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << timeCalls[phone] << endl;
        }
    } while (type != "#");
    return 0;
}

