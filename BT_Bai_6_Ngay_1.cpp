/*
 * ============================================================================
 * BÀI TẬP: Sắp xếp Danh sách Thí sinh
 * NGUỒN:   Bài tập Ôn thi OLP - Buổi 1
 * ----------------------------------------------------------------------------
 * ĐỀ BÀI TÓM TẮT:
 *   Cho N thí sinh với (ID, Toán, Lập trình). Sắp xếp danh sách giảm dần theo
 *   Tổng điểm (Toán + Lập trình). Nếu tổng điểm bằng nhau, ID nhỏ hơn xếp trước.
 *
 * INPUT / OUTPUT:
 *   - Input:  N; N dòng tiếp theo chứa (ID, Math, Prog).
 *   - Output: N dòng, mỗi dòng chứa (ID, Tổng điểm) sau khi sắp xếp.
 *
 * GIỚI HẠN & QUI TẮC:
 *   - N <= 10^5, ID <= 10^9, Điểm <= 100.
 *   - Tiêu chí 1: (Math + Prog) giảm dần.
 *   - Tiêu chí 2: ID tăng dần khi trùng tổng điểm.
 *
 * Ý TƯỞNG:
 *   - Dùng struct Candidate hoặc std::pair.
 *   - Định nghĩa comparator cmp(a, b): so sánh tổng điểm trước, sau đó so sánh ID.
 * ============================================================================
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

struct STUDENT // Cach 1 su dung struct
{
    int ID;
    int Math;
    int Prog;
};

//Cach 2 su dung pair long trong pair vi du: typedef pair<int, pair<int, int>> STUDENT; first, second.first, second.second
//Cach 3 su dung tuple cho phep tu 3 tro len (khac phuc duoc han che cua pair) tuple <int, int, int> c ={ , , };
//Lay gia tri theo chi so 0 1 2 bang std::get id = get<0>(c)

bool compareStudent(const STUDENT& a, const STUDENT& b)
{
    if(a.Math + a.Prog != b.Math + b.Prog)
        return a.Math + a.Prog > b.Math + b.Prog;
    else 
        return a.ID < b.ID;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin >> n)) return 0;

    vector<STUDENT> students(n);
    for(int i=0; i<n; i++)
    {
        cin >> students[i].ID >> students[i].Math >> students[i].Prog;
    }

    sort(students.begin(), students.end(), compareStudent);

    for(const auto &s : students)
    {
        cout << s.ID << " " << s.Math << " " << s.Prog << "\n";
    }
    return 0;
}
