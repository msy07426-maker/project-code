#include <iostream>
#include <cmath> // لاستخدام دالة abs للحساب المطلق

using namespace std;

int main()
{
    // تعريف متغيرات الوقتين
    int h1, m1, h2, m2;

    // 1. إدخال بيانات التوقيت الأول T1 والتحقق من الشروط
    cout << "Enter Time 1 -> Hours   (0-23)  : ..... hours= ";
    cin >> h1 ;
    cout << "Enter Time 1 -> Minutes (0-59): .....   minutes= ";
    cin>> m1;
    if (h1 < 0 || h1 > 23 || m1 < 0 || m1 > 59)
    {
        cout << "Error: Invalid Time 1! Hours must be <= 23 and Minutes <= 59." << endl;
        return 1; // إنهاء البرنامج بسبب مدخلات خاطئة
    }

    // 2. إدخال بيانات التوقيت الثاني T2 والتحقق من الشروط
    cout << "Enter Time 2 -> Hours (0-23) ...... hours= ";
    cin >> h2;
    cout << "Enter Time 2 -> Minutes (0-59): .....   minutes= ";
    cin>> m1;
    if (h2 < 0 || h2 > 23 || m2 < 0 || m2 > 59)
    {
        cout << "Error: Invalid Time 2! Hours must be <= 23 and Minutes <= 59." << endl;
        return 1; // إنهاء البرنامج بسبب مدخلات خاطئة
    }

    cout << "\n================ RESULTS ================" << endl;

    // 3. المقارنة بين التوقيتين (Comparison)
    if (h1 < h2 || (h1 == h2 && m1 < m2))
    {
        cout << " Comparison: Time 1 is EARLIER than Time 2." << endl;
    }
    else if (h1 > h2 || (h1 == h2 && m1 > m2))
    {
        cout << " Comparison: Time 1 is LATER than Time 2." << endl;
    }
    else
    {
        cout << " Comparison: Both times are EQUAL." << endl;
    }

    // 4. حساب الفارق الزمني (Time Difference)
    // تحويل الوقتين بالكامل إلى دقائق لتسهيل الطرح الدقيق
    int total_minutes1 = (h1 * 60) + m1;
    int total_minutes2 = (h2 * 60) + m2;

    // الفارق المطلق بالدقائق
    int diff_minutes = abs(total_minutes1 - total_minutes2);

    // إعادة تحويل الفارق الدقيق إلى ساعات ودقائق
    int diff_hours = diff_minutes / 60;
    int final_min_diff = diff_minutes % 60;

    cout << " Time Difference: " << diff_hours << " Hours and " << final_min_diff << " Minutes." << endl;

    return 0;
}
