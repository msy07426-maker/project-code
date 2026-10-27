
#include <iostream>
#include <cmath>

using namespace std;

// This function draws a hollow square based on the side length
void drawHollowSquare(int side)
{
    // Loop for rows
    for (int i = 0; i < side; i++)
    {
        // Loop for columns
        for (int j = 0; j < side; j++)
        {
            // Print asterisk only on the outer boundaries
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1)
            {
                cout << "* ";
            }
            else
            {
                // Print spaces inside the square to keep it hollow
                cout << "  ";
            }
        }
        // Move to the next line after completing a row
        cout << endl;
    }
}

// This function draws a hollow rectangle based on height and width
void drawHollowRectangle(int rows, int cols)
 {
    // Loop for rows (height)
    for (int i = 0; i < rows; i++)
    {
        // Loop for columns (width)
        for (int j = 0; j < cols; j++)
        {
            // Print asterisk only on the outer boundaries
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
            {
                cout << "* ";
            }
            else
            {
                // Print spaces inside the rectangle
                cout << "  ";
            }
        }
        // Move to the next line
        cout << endl;
    }
}

// This function draws an isosceles hollow triangle based on height
void drawHollowTriangle(int height)
{
    // Loop to control the rows of the triangle
    for (int i = 1; i <= height; i++)
    {
        // Print leading spaces to center the triangle
        for (int j = i; j < height; j++)
        {
            cout << " ";
        }
        // Print asterisks for the boundaries of the triangle
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            // Print at the start, end, or the entire last row (base)
            if (j == 1 || j == (2 * i - 1) || i == height)
            {
                cout << "*";
            }
            else
            {
                // Print space inside the triangle
                cout << " ";
            }
        }
        // Move to the next line
        cout << endl;
    }
}

// This function draws a hollow rhombus based on the size of half the shape
void drawHollowRhombus(int n)
{
    // Upper part of the rhombus (top triangle)
    for (int i = 1; i <= n; i++)
    {
        // Leading spaces for the top half
        for (int j = i; j < n; j++) cout << " ";
        // Boundaries for the top half
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            if (j == 1 || j == (2 * i - 1))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    // Lower part of the rhombus (inverted bottom triangle)
    for (int i = n - 1; i >= 1; i--)
    {
        // Leading spaces for the bottom half
        for (int j = n; j > i; j--) cout << " ";
        // Boundaries for the bottom half
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            if (j == 1 || j == (2 * i - 1)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

// This function draws a hollow circle using the circle equation
void drawHollowCircle(int r)
{
    // Aspect ratio constant (2.0 matches standard console fonts where height ≈ 2x width)
     double aspect_ratio = 2.0;
     // Dynamic thickness to prevent missing pixels on larger circles
     double thickness = 0.5;
     // Loop through the vertical axis (rows from -r to +r)
     for (int i = -r; i <= r; i++)
        {
          // Loop through the horizontal axis adjusted by font aspect ratio
          for (int j = (int)(-r * aspect_ratio); j <= (int)(r * aspect_ratio); j++)
             {
               // Normalize X coordinate to eliminate font elongation
               double x = j / aspect_ratio;
               double y= i;
               // Calculate actual distance from the center (0,0) using Pythagoras theorem
               double dist= sqrt(x * x + y * y);
               // Check if the current coordinate sits on the shell boundary
               if (dist> r - thickness && dist < r + thickness)
                 {
                     cout << "*";
                 }
               else
                {
                    cout << " ";
                }
            }
            // Move to the next row
            cout << endl;
        }
}


// The main function where the program execution starts
int main()
{
    int choice;

    // Main execution loop that runs until the user exits
    do
     {
        // Display the menu selection to the user
        cout << "\n==============================\n";
        cout << "Select a geometric shape to draw (Hollow):\n";
        cout << "1. Square\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Rhombus\n";
        cout << "5. Circle\n";
        cout << "6. Exit Program\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cout << "==============================\n";

        // Execute the corresponding function based on user choice
        switch (choice)
        {
            case 1:
            {
                int side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                drawHollowSquare(side);
                break;
            }
            case 2:
            {
                int rows, cols;
                cout << "Enter the height of the rectangle (rows): ";
                cin >> rows;
                cout << "Enter the width of the rectangle (columns): ";
                cin >> cols;
                drawHollowRectangle(rows, cols);
                break;
            }
            case 3:
            {
                int height;
                cout << "Enter the height of the triangle: ";
                cin >> height;
                drawHollowTriangle(height);
                break;
            }
            case 4:
            {
                int size;
                cout << "Enter the size of the rhombus (half height): ";
                cin >> size;
                drawHollowRhombus(size);
                break;
            }
            case 5:
            {
                int radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                drawHollowCircle(radius);
                break;
            }
            case 6:
                // Exit message
                cout << "Thank you for using the program!\n";
                break;
            default:
                // Error handling for invalid menu options
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    // Repeat the process as long as choice is not 6
    }
     while (choice != 6);

    return 0;
}
