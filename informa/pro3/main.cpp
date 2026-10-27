#include <iostream>
#include <algorithm> // لاستخدام دالتي max و min

using namespace std;

int main()
 {
    // تعريف متغيرات الفترتين
    double a1, b1, a2, b2;

    // إدخال قيم الفترة الأولى A1
    cout << "Enter the first interval A1 (start and end): ";
    cin >> a1 >> b1;

    // إدخال قيم الفترة الثانية A2
    cout << "Enter the second interval A2 (start and end): ";
    cin >> a2 >> b2;

    // التأكد من ترتيب البداية والنهاية تصاعدياً تلقائياً
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);

    // 1. حساب حدود منطقة التقاطع (Intersection)
    double start_inter = max(a1, a2);
    double end_inter = min(b1, b2);

    cout << "\n================ RESULTS ================" << endl;

    // التحقق مما إذا كان هناك تقاطع فعلي
    if (start_inter <= end_inter) 
    {
        // طباعة التقاطع وطوله
        cout << "[1] Intersection: [" << start_inter << ", " << end_inter << "]" << endl;
        cout << "[3] Length of Intersection: " << (end_inter - start_inter) << endl;
        
        // 2. حساب الاتحاد (Union) في حال وجود تقاطع أو تلامس
        double start_union = min(a1, a2);
        double end_union = max(b1, b2);
        cout << "[2] Union: [" << start_union << ", " << end_union << "]" << endl;
    } 
    else 
    {
        // في حال عدم وجود تقاطع بين الفترتين
        cout << "[1] Intersection: No intersection (Empty set)" << endl;
        cout << "[3] Length of Intersection: 0" << endl;
        
        // الاتحاد عبارة عن مجموع الفترتين منفصلتين
        cout << "[2] Union: [" << a1 << ", " << b1 << "] U [" << a2 << ", " << b2 << "]" << endl;
    }

    return 0;
}