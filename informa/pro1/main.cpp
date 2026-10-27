#include <iostream>
#include <algorithm> // For max and min functions

using namespace std;

int main()
 {
    double a1, b1, a2, b2;

    cout << "====================================================\n";
    cout << "     Interval Intersection & Distance Calculator    \n";
    cout << "====================================================\n\n";

    // 1. Input for the First Interval
    cout << "[+] Enter details for Interval 1 (A1):\n";
    cout << "Enter start point (a1): ";
    cin >> a1;
    cout << "Enter end point (b1): ";
    cin >> b1;

    // Validation: Ensure start is less than or equal to end
    if (a1 > b1) 
    {
        cout << " Warning: Start point is greater than end point. Swapping them automatically.\n";
        swap(a1, b1);
    }
    cout << "Interval 1 set to: [" << a1 << ", " << b1 << "]\n\n";

    // 2. Input for the Second Interval
    cout << "[+] Enter details for Interval 2 (A2):\n";
    cout << "Enter start point (a2): ";
    cin >> a2;
    cout << "Enter end point (b2): ";
    cin >> b2;

    // Validation: Ensure start is less than or equal to end
    if (a2 > b2)
     {
        cout << " Warning: Start point is greater than end point. Swapping them automatically.\n";
        swap(a2, b2);
    }
    cout << "Interval 2 set to: [" << a2 << ", " << b2 << "]\n\n";

    cout << "----------------------------------------------------\n";
    cout << "                     RESULTS                        \n";
    cout << "----------------------------------------------------\n";

    // Mathematical determination of potential intersection points
    double start_intersect = max(a1, a2);
    double end_intersect = min(b1, b2);

    // Requirement 1 & 2: Check for intersection, length, or distance
    if (start_intersect <= end_intersect) 
    {
        // The intervals intersect
        cout << " Status: The intervals [INTERSECT].\n";
        cout << " Intersection Region: [" << start_intersect << ", " << end_intersect << "]\n";
        
        // Calculate intersection length
        double intersect_length = end_intersect - start_intersect;
        cout << " Length of Intersection: " << intersect_length << "\n";
    } 
    else 
    {
        // The intervals do not intersect
        cout << " Status: The intervals [DO NOT INTERSECT].\n";
        
        // Calculate the distance between them
        double distance = start_intersect - end_intersect;
        cout << " Distance between the intervals: " << distance << "\n";
    }

    cout << "====================================================\n";
    return 0;
}