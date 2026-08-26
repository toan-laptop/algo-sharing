// Bước 1 – Gom nhóm theo giá trị b
// Những phần tử có cùng b bắt buộc phải có cùng giá trị a (vì "tổng các phần tử nhỏ hơn nó" bằng nhau). Gom nhóm và sắp theo b tăng dần:
//
// Nhóm 1: b=0, có 2 phần tử
// Nhóm 2: b=4, có 2 phần tử
// Nhóm 3: b=14, có 1 phần tử
//
// Bước 2 – Nhóm b nhỏ nhất phải là 0
// Phần tử nhỏ nhất trong mảng gốc luôn không có phần tử nào nhỏ hơn nó → shadow = 0. Nên nhóm đầu tiên (sau khi sort) bắt buộc có b=0. Ở đây đúng là 0 → hợp lệ, tiếp tục.
//
// Bước 3 – Suy ra giá trị a của từng nhóm dựa vào nhóm kế tiếp
// Ý chính: b của một nhóm chính là tổng giá trị a của tất cả phần tử ở các nhóm trước nó (tổng dồn/prefix sum). Vậy nếu biết nhóm trước có cnt phần tử, và nhóm sau có b_sau, thì:
//
// cnt * a_nhóm_trước = b_sau  →  a_nhóm_trước = b_sau / cnt

// Áp dụng:
// Nhóm 1 (b=0, cnt=2) → nhìn sang nhóm 2 có b=4: a₁ = 4 / 2 = 2. Kiểm tra chia hết: 4 % 2 = 0 ✓.
// Nhóm 2 (b=4, cnt=2) → nhìn sang nhóm 3 có b=14: hiệu 14 - 4 = 10 là phần "mới thêm vào" nhờ nhóm 2 đóng góp, chia cho cnt=2 → a₂ = 5. Kiểm tra: (14-4) % 2 = 0 ✓.
// Nhóm 3 (b=14, cnt=1): đây là nhóm cuối cùng, không còn nhóm nào sau để "đối chiếu" nữa, nên chỉ cần chọn giá trị nhỏ nhất có thể mà vẫn lớn hơn a₂ → a₃ = a₂ + 1 = 6.
//
// Bước 4 – Kiểm tra tính hợp lệ khi đi qua từng nhóm
// Mỗi bước tính a của nhóm trước, luôn cần đảm bảo 2 điều:
//
// Hiệu b_sau - b_hiện_tại phải chia hết cho số lượng phần tử của nhóm hiện tại (nếu không → không tồn tại số nguyên hợp lệ → in -1).
// Giá trị a mới tính ra phải lớn hơn giá trị a đã gán cho nhóm ngay trước nó (đảm bảo các nhóm có a tăng dần đúng theo thứ tự b tăng dần — vì nếu không tăng dần thì mâu thuẫn với chính định nghĩa "nhóm b lớn hơn phải đứng sau các phần tử có a nhỏ hơn").
//
// Kết quả cuối: a[0]=2, a[4]=5, a[14]=6 → ánh xạ ngược lại theo thứ tự ban đầu của b = [0,4,0,4,14] ta được:
// a = [2, 5, 2, 5, 6]

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<long long> nums;
    map<long long, int> mp;
    map<long long, long long> newVal;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            mp[nums[i]]++;
        }

        int i = 0;
        long long nVal = 0, preVal, preCount;
        for (auto [val, c] : mp) {
            if (i != 0) {
                if ((val - preVal) / preCount > nVal && (val - preVal) % preCount == 0) {
                    nVal = (val - preVal) / preCount;
                    newVal[preVal] = nVal;
                } else {
                    i = -1;
                    break;
                }

            } else {
                if (val != 0) {
                    i = -1;
                    break;
                }
            }

            ++i;
            preVal = val;
            preCount = c;

            if (i == mp.size()) newVal[val] = nVal+1;
        }

        if (i == -1) cout << -1;
        else {
            for (int i = 0; i < n; i++) {
                cout << newVal[nums[i]] << (i == n-1 ? "" : " ");
            }
        }
        cout << "\n";

        mp.clear();
        newVal.clear();
    }
    return 0;
}
