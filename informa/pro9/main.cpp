#include <iostream>
#include <vector>

using namespace std;

// 1. تعريف الثوابت والحالات كمتغيرات عامة بسيطة
const int MAX_SIZE = 10000;
enum State { q1, q2, HALT };

// دالة طباعة الجدول (تبقى كما هي لأنها مجرد نصوص)
void printTransitionTable()
{
    cout << "\n=============================================\n";
    cout << "          TURING MACHINE TRANSITION TABLE      \n";
    cout << "=============================================\n";
    cout << " Current State | Read Symbol | Write | Move | Next State \n";
    cout << "---------------------------------------------------------\n";
    cout << "      q1       |      '0'    |  '1'  |  R   |     q1     \n";
    cout << "      q1       |      '1'    |  '1'  |  R   |     q1     \n";
    cout << "      q1       |      'B'    |  'B'  |  L   |    HALT    \n";
    cout << "=============================================\n\n";
}

// 2. دالة التشغيل تستقبل المتغيرات بشكل مستقل (باستخدام & للتعديل المباشر)
void runTuringMachine(char arr[], int &head, State &currentState)
 {
    cout << "--- Starting Turing Machine Simulation ---\n";

    while (currentState != HALT)
        {
        char currentSymbol = arr[head];

        if (currentState == q1)
         {
            if (currentSymbol == '0')
             {
                arr[head] = '1';
                head++;            // تحرك يميناً
                currentState = q1;
             }
            else if (currentSymbol == '1')
             {
                arr[head] = '1';
                head++;            // تحرك يميناً
                currentState = q1;
             }
            else if (currentSymbol == 'B')
            {
                head--;            // تحرك يساراً
                currentState = HALT;
            }
        }
    }
    cout << "Simulation Finished Successfully!\n\n";
}

int main()
 {
    // 3. تعريف مكونات الآلة كمتغيرات منفصلة داخل الـ main
    char tape[MAX_SIZE];      // المصفوفة (الشريط) بشكل مستقل
    int head = 0;             // المؤشر يبدأ من 0
    State currentState = q1;  // الحالة الابتدائية تبدأ من q1

    // تصفير الشريط بوضع فراغات 'B'
    for (int i = 0; i < MAX_SIZE; i++)
        {
        tape[i] = 'B';
        }

    // إدخال البيانات التجريبية
    string input = "01001";
    for (size_t i = 0; i < input.length(); i++)
        {
        tape[i] = input[i];
        }

    // طباعة شريط المدخلات قبل التعديل
    cout << "Initial Tape Content: ";
    for (size_t i = 0; i < input.length(); i++)
        {
        cout << "[" << tape[i] << "] ";
        }
    cout << "\n";

    // رسم جدول الانتقالات
    printTransitionTable();

    // 4. استدعاء دالة التشغيل وتمرير المتغيرات الثلاثة لها
    runTuringMachine(tape, head, currentState);

    // طباعة شريط المخرجات النهائي
    cout << "Final Tape Content (Output): ";
    for (size_t i = 0; i < input.length(); i++)
        {
        cout << "[" << tape[i] << "] ";
        }
    cout << "\n=============================================\n";

    return 0;
}
