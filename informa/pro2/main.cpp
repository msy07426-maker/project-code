
#include <iostream>

using namespace std;

int main()
{
    int h_start, m_start; // ساعات ودقائق وقت البداية Tn
    int h_end, m_end;     // ساعات ودقائق وقت النهاية Tk

    cout << "====================================================\n";
    cout << "             Time Difference Calculator             \n";
    cout << "====================================================\n\n";

    // 1. إدخال وقت البداية والتحقق من الشروط
    cout << "[+] Enter Start Time (Tn):\n";
    cout << "Enter Hours (0-23): ";
    cin >> h_start;
    cout << "Enter Minutes (0-59): ";
    cin >> m_start;

    if (h_start < 0 || h_start >= 24 || m_start < 0 || m_start >= 60)
    {
        cout << " Error: Invalid time constraints! (H < 24 and M < 60).\n";
        return 1; // إنهاء البرنامج بسبب إدخال خاطئ
    }

    // 2. إدخال وقت النهاية والتحقق من الشروط
    cout << "\n[+] Enter End Time (Tk):\n";
    cout << "Enter Hours (0-23): ";
    cin >> h_end;
    cout << "Enter Minutes (0-59): ";
    cin >> m_end;

    if (h_end < 0 || h_end >= 24 || m_end < 0 || m_end >= 60)
    {
        cout << " Error: Invalid time constraints! (H < 24 and M < 60).\n";
        return 1; // إنهاء البرنامج بسبب إدخال خاطئ
    }

    // 3. الحسابات الرياضية البرمجية
    // تحويل الوقتين بالكامل إلى دقائق لتسهيل عملية الطرح
    int total_minutes_start = (h_start * 60) + m_start;
    int total_minutes_end = (h_end * 60) + m_end;

    // إذا كان وقت النهاية أصغر من وقت البداية، نفترض أن الوقت عبر منتصف الليل (اليوم التالي)
    if (total_minutes_end < total_minutes_start)
     {
        total_minutes_end += 24 * 60; // إضافة دقائق يوم كامل (1440 دقيقة)
    }

    // تطبيق القانون: Delta t = Tk - Tn
    int diff_minutes = total_minutes_end - total_minutes_start;

    // إعادة تحويل الفارق الزمني الصافي إلى ساعات ودقائق
    int diff_hours = diff_minutes / 60;
    int diff_remaining_minutes = diff_minutes % 60;

    // 4. طباعة النتائج للمستخدم
    cout << "----------------------------------------------------\n";
    cout << "                     RESULTS                        \n";
    cout << "----------------------------------------------------\n";
    cout << " Time Duration (Delta t): " << diff_hours << " Hours and " << diff_remaining_minutes << " Minutes.\n";
    cout << "====================================================\n";

    return 0;
}
