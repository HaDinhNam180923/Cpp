// Có n nhà kho nằm trên một đoạn thẳng.
// Nhà kho i có toạ độ là i và chứa lượng vàng là ai
// .Yêu cầu:Chọn một số nhà kho sao cho:Tổng lượng vàng lớn nhất.2 nhà kho liên tiếp có khoảng cách nằm trong đoạn[L1,L2].
// Giới hạn:1≤n≤100000.1≤L1≤L2≤n.
#include <bits/stdc++.h>
using namespace std;

int n, l1, l2;
#define MAX 1000002
int a[MAX];
int f[MAX];
void input()
{
    cin >> n >> l1 >> l2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    input();
    f[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (i < l1)
            f[i] = max(a[i], f[i - 1]);
        if (i >= l1)
            f[i] = max(a[i] + f[i - l1], f[i - 1]);
    }
    cout << f[n - 1];

    return 0;
}